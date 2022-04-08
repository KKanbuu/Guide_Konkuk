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
            point_information();
            cal_point();
            
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
        double theta=270;  // 임의로 정한 각
        double PI = 3.141592;

        double a,b;
        double c,d;
        double m;
        int k=15;     // 초기 점과 최종 점을 포함하여 10개의 점을 찍어서 path를 생성할 것

        double point_info[7][3];
        
    public:
        void point_information(){
            
            for(int i=0;i<k;i++){
                point_info[i][0]=r*cos((theta-(i*180/(k-1)))/180*PI);  //(theta/180*PI)-(i/(k-1)*PI)
                point_info[i][1]=r*sin((theta-(i*180/(k-1)))/180*PI);
                //point_info[i][2]=atan2(-point_info[i][0],point_info[i][1]);
                ROS_INFO_STREAM(theta-(i*180/(k-1)));
            }
            for(int i=1;i<k-1;i++){
                point_info[i][2]=atan((point_info[i][1]-point_info[i+1][1])/(point_info[i][0]-point_info[i+1][0]));
            }
            point_info[k-1][2]=atan2(-point_info[k-1][0],point_info[k-1][1]);
            /*point_info[0][0]=0; point_info[0][1]=-6; point_info[0][2]=0;
            point_info[1][0]=-3; point_info[1][1]=-3*sqrt(3); point_info[1][2]=-1/sqrt(3);
            point_info[2][0]=-3*sqrt(3); point_info[2][1]=-3; point_info[2][2]=-sqrt(3);
            point_info[3][0]=-6; point_info[3][1]=0; point_info[3][2]=PI;
            point_info[4][0]=-3*sqrt(3); point_info[4][1]=3; point_info[4][2]=sqrt(3);
            point_info[5][0]=-3; point_info[5][1]=3*sqrt(3); point_info[5][2]=1/sqrt(3);
            point_info[6][0]=0; point_info[6][1]=6; point_info[6][2]=0;*/
        }
        void x_init_Callback(const std_msgs::Float64ConstPtr &msg){
            init.pose.position.x=msg->data;
            a = init.pose.position.x;
            point_info[0][0]=a;
        }
        void y_init_Callback(const std_msgs::Float64ConstPtr &msg){
            init.pose.position.y=msg->data;
            b = init.pose.position.y;
            point_info[0][1]=b;
            //theta=atan2(a,b);
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
            // m=(d-b)/(c-a);
            // cal_point();
        }

        void cal_point(){
            geometry_msgs::PoseStamped local_point;
            /*
            for(int j=0;j<7;j++){
                local_point.pose.position.x=point_info[j][0];
                local_point.pose.position.y=point_info[j][1];
                local_point.pose.position.z=0.0;
                m=point_info[j][2];
                slope = tf::createQuaternionFromRPY(0,0,m);   // (roll, pitch, yaw)를 createQuaternionFromRPY를 통해 쿼터니안으로 변환.
                local_point.pose.orientation.x = slope[0];
                local_point.pose.orientation.y = slope[1];
                local_point.pose.orientation.z = slope[2];
                local_point.pose.orientation.w = slope[3];
                path_.poses.push_back(local_point);
            }*/
            
            // m=(d-b)/(c-a);  // yaw 값. 직선이기 때문에 일차함수의 기울기로 표현

            for(int j=0;j<k;j++){   // 초기 점과 최종 점을 포함하여 k개의 점을 찍어서 path를 생성할 것
                local_point.pose.position.x=point_info[j][0];  // theta*(i/k)
                local_point.pose.position.y=point_info[j][1];
                local_point.pose.position.z=0.0;
                //m = (sin(theta/180*PI*(i+1/k))-sin(theta/180*PI*(i/k))) / (cos(theta/180*PI*(i+1/k))-cos(theta/180*PI*(i/k)));
    
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

            //pub_pose.publish(init);
            //pub_pose.publish(goal);
            pub_pose.publish(path_);
            
            //ROS_INFO_STREAM("goal point: "<<goal.pose.position.x<<" "<<goal.pose.position.y);
            //ROS_INFO_STREAM("slope: " << m);

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
    // pub.cal_point();
    

    return 0;
}
