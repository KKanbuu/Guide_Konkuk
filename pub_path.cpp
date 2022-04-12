//#include "local_planning/position.h"

//STD header
#include<vector>
#include<cmath>
#include<string>
#include<iostream>

//ROS header
#include<ros/ros.h>
#include<tf/tf.h>
#include<tf/transform_broadcaster.h>

//Message header
#include<geometry_msgs/Pose.h>
#include<geometry_msgs/PoseStamped.h>
#include<nav_msgs/Path.h>
#include<std_msgs/Float64MultiArray.h>
#include<std_msgs/Float64.h>
#include<std_msgs/Int32.h>

//Using
using std::pow;
using std::cos;
using std::sin;
using std::tan;
using std::abs;
using std::to_string;
using std::cout;
using std::vector;


class pointPub{
    public:
        pointPub(){
            
            //point_information();
            sub_x_init= nh.subscribe("/x_init",100,&pointPub::x_init_Callback,this);
            sub_y_init= nh.subscribe("/y_init",100,&pointPub::y_init_Callback,this);
                // 초기 위치 받아옴
            sub_x_goal= nh.subscribe("/x_slot",100,&pointPub::x_Callback,this); 
	            // Subscriber 객체 선언, topic의 이름 x/slot_idx, 메시지 큐의 크기가 100
            sub_y_goal= nh.subscribe("/y_slot",100,&pointPub::y_Callback,this);
	            // Subscriber 객체 선언, topic의 이름 y/slot_idx, 메시지 큐의 크기가 100
            pub_pose=nh.advertise<nav_msgs::Path>("xy_pose",100);
	            // Publisher 객체 선언, topic의 이름 xy_pose, 메시지 큐의 크기가 100
            path_.header.frame_id = "/map"; 
            init.header.frame_id="/map";    
            goal.header.frame_id="/map";  // rviz에서 frame을 map으로 정해줌
            
            
        }
    private:
        ros::NodeHandle nh;  // 시스템과의 소통을 위해 객체 선언
        ros::Publisher pub_pose;
        
        ros::Subscriber sub_x_init;
        ros::Subscriber sub_y_init;
        ros::Subscriber sub_x_goal;
        ros::Subscriber sub_y_goal;
        geometry_msgs::PoseStamped goal;
        geometry_msgs::PoseStamped init;
        nav_msgs::Path path_;
        tf::Quaternion slope;
        
        double o[2]={0,0};  // 임의로 정한 원의 중심
        double r=6;   // 임의로 정한 원의 반지름
        double theta_init;  // 임의로 정한 각
        double theta_final;
        double theta;
        double PI = 3.141592;

        double a,b;
        double c,d;
        double m;
        int k=50;     // 초기 점과 최종 점을 포함하여 15개의 점을 찍어서 path를 생성할 것

        double point_info[50][3];
        
    public:
        void point_information(){
            //ROS_INFO_STREAM(point_info[0][1]);
            //ROS_INFO_STREAM(point_info[0][0]);

            if(atan2(point_info[0][1],point_info[0][0])<0){
                theta_init=2*PI+atan2(point_info[0][1],point_info[0][0]);
            }
            else{
                theta_init=atan2(point_info[0][1],point_info[0][0]);
            }

            if(atan2(d,c)<0){
                theta_final=2*PI+atan2(d,c);
            }
            else{
                theta_final=atan2(d,c);
            }

            theta=abs((theta_init-theta_final));

            if(theta>PI){
                theta=2*PI-theta;
                if(theta_init>theta_final){
                    matrix_init_angle();
                }
                else{
                    matrix_final_angle();
                }
            }
            else{
                if(theta_init>theta_final){
                    matrix_final_angle();
                }
                else{
                    matrix_init_angle();
                }
            }
        }

        void matrix_init_angle(){
            for(int i=0;i<k;i++){     // 경로의 점들의 위치를 지정
                double x = (theta_init+(i*theta/(k-1)));
                point_info[i][0]=cos(x);
                point_info[i][1]=sin(x);
                ROS_INFO_STREAM(point_info[i][0] << "  "<<point_info[i][1]);  
                //ROS_INFO_STREAM(theta-(i*180/(k-1)));
            }
            for(int i=0;i<k-1;i++){   // 최종 점을 제외한 경로의 점들의 yaw값을 저장
                point_info[i][2]=atan((point_info[i][1]-point_info[i+1][1])/(point_info[i][0]-point_info[i+1][0]));
            }
            point_info[k-1][2]=atan2(-point_info[k-1][0],point_info[k-1][1]);
            // 나중에 최종 점의 yaw 값은 경계조건에 포함되어 있다.

            cal_point();
        }

        void matrix_final_angle(){
            for(int i=0;i<k;i++){     // 최종 점을 제외한 경로의 점들의 위치를 지정
                double x = (theta_init-(i*theta/(k-1)));
                point_info[i][0]=cos(x);
                point_info[i][1]=sin(x);
                ROS_INFO_STREAM(point_info[i][0] << "  "<<point_info[i][1]);  
                //ROS_INFO_STREAM(theta-(i*180/(k-1)));
            }
            for(int i=0;i<k-1;i++){   // 최종 점을 제외한 경로의 점들의 yaw값을 저장
                point_info[i][2]=atan((point_info[i][1]-point_info[i+1][1])/(point_info[i][0]-point_info[i+1][0]));
            }
            point_info[k-1][2]=atan2(-point_info[k-1][0],point_info[k-1][1]);
            // 나중에 최종 점의 yaw 값은 경계조건에 포함되어 있다.

            cal_point();
        }

        void x_init_Callback(const std_msgs::Float64ConstPtr &msg){
            init.pose.position.x=msg->data;
            a = init.pose.position.x;
            point_info[0][0]=a;
            //ROS_INFO_STREAM(point_info[0][0]);
        }
        void y_init_Callback(const std_msgs::Float64ConstPtr &msg){
            init.pose.position.y=msg->data;
            b = init.pose.position.y;
            point_info[0][1]=b;
            //ROS_INFO_STREAM(point_info[0][1]);
        }
        void x_Callback(const std_msgs::Float64ConstPtr &msg){
            goal.pose.position.x=msg->data;
            c= goal.pose.position.x;
            point_info[k-1][0]=c;
        }
        void y_Callback(const std_msgs::Float64ConstPtr &msg){
            goal.pose.position.y=msg->data;
            d=goal.pose.position.y;
            point_info[k-1][1]=d;
            point_information();
        }

        void cal_point(){
            geometry_msgs::PoseStamped local_point;

            for(int j=0;j<k;j++){   // 초기 점과 최종 점을 포함하여 k개의 점을 찍어서 path를 생성할 것
                local_point.pose.position.x=point_info[j][0];  // theta*(i/k)
                local_point.pose.position.y=point_info[j][1];
                local_point.pose.position.z=0.0;
    
                m = point_info[j][2];
                slope = tf::createQuaternionFromRPY(0,0,m);   // (roll, pitch, yaw)를 createQuaternionFromRPY를 통해 쿼터니안으로 변환.
                local_point.pose.orientation.x = slope[0];
                local_point.pose.orientation.y = slope[1];
                local_point.pose.orientation.z = slope[2];
                local_point.pose.orientation.w = slope[3];

                //ROS_INFO_STREAM("point: "<<local_point.pose.position.x<<" "<<local_point.pose.position.y);
                //ROS_INFO_STREAM(theta);
                path_.poses.push_back(local_point);
            }       

                    

        }
        void pubpoint(){
            pub_pose.publish(path_);
        }

};

int main(int argc, char **argv){

    ros::init(argc,argv,"pub_path");    
    pointPub pub;

    ros::Rate rate(0.5);

    while(ros::ok()){
        pub.pubpoint();
        ros::spinOnce();
        rate.sleep();
    }
    

    return 0;
}
