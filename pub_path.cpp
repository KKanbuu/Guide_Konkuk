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
#include "local_planning/SensorPointArray.h"
#include "local_planning/SensorPoint.h"


//Using
using namespace std;
/*using std::pow;
using std::cos;
using std::sin;
using std::tan;
using std::abs;
using std::to_string;
using std::cout;
using std::vector;*/

bool execute_cal = true;


class pointPub{
    public:
        pointPub(){
            
                // 초기 위치 받아옴
            sub_x_goal= nh.subscribe("/x_slot",10,&pointPub::x_Callback,this); 
	            // Subscriber 객체 선언, topic의 이름 x/slot_idx, 메시지 큐의 크기가 100
            sub_y_goal= nh.subscribe("/y_slot",10,&pointPub::y_Callback,this);
	            // Subscriber 객체 선언, topic의 이름 y/slot_idx, 메시지 큐의 크기가 100
            sub_obstacle=nh.subscribe("/obs",15,&pointPub::Hurdle,this);
            //pub_pose=nh.advertise<nav_msgs::Path>("xy_pose",100);   //(5,20)
	            // Publisher 객체 선언, topic의 이름 xy_pose, 메시지 큐의 크기가 100
            pub_pose_1=nh.advertise<nav_msgs::Path>("xy_pose_1",100);  
            pub_pose_2=nh.advertise<nav_msgs::Path>("xy_pose_2",100);   
            pub_pose_3=nh.advertise<nav_msgs::Path>("xy_pose_3",100);   
            pub_pose_4=nh.advertise<nav_msgs::Path>("xy_pose_4",100);   
            //path_.header.frame_id = "/ego";
            path_1.header.frame_id = "/map";
            path_2.header.frame_id = "/map";
            path_3.header.frame_id = "/map";
            path_4.header.frame_id = "/map";
             // rviz에서 frame을 map으로 정해줌
            
            
        }
    private:
        ros::NodeHandle nh;  // 시스템과의 소통을 위해 객체 선언
        ros::Publisher pub_pose_1;
        ros::Publisher pub_pose_2;
        ros::Publisher pub_pose_3;
        ros::Publisher pub_pose_4;
        ros::Subscriber sub_x_goal;
        ros::Subscriber sub_y_goal;
        ros::Subscriber sub_obstacle;
         
        geometry_msgs::PoseStamped goal;
        geometry_msgs::PoseStamped init;
        nav_msgs::Path path_1;
        nav_msgs::Path path_2;
        nav_msgs::Path path_3;
        nav_msgs::Path path_4;
        local_planning::SensorPointArray HurdleArray;

        tf::Quaternion slope_1;
        tf::Quaternion slope_2;
        tf::Quaternion slope_3;
        tf::Quaternion slope_4;        
       
        double r1=17;
        double r2=25.5;
        double r3=10;
        double r4=15;
        double angle_1;
        double angle_2;
        double vehicle_r = 1;
        double hurdle_x;
        double hurdle_y;
        double hurdle_r;
        bool hurdle_state;
        bool path_collision[4]={true,true,true,true};  // false면 충돌, true면 충돌x
        int obs_num;
        
        double PI = 3.141592;
        double m;
        double c,d;
        double second_m;
        double third_m;
        double fourth_m;
        double pass_through_x;
        double pass_through_y;
        double pass_through_x_2;
        double pass_through_y_2;
        int k=3;     // 초기 점과 최종 점을 포함하여 2*5개의 점을 찍어서 path를 생성할 것
        double first_point_info[7][3];
        double third_point_info[7][3];
        
        
    public:
            bool Is_Callback_final_1 = false;
            bool Is_Callback_final_2 = false;
            bool Is_Callback_hurdle = false;


        void offset_exam(){  // pub_index에서 입력받은 경계조건에 따라 경로의 전환점을 계산함
            m=d/c;
            pass_through_x=2*r1/(m*m+1);  // 2
            pass_through_y=m*pass_through_x;  // 8
            angle_1= atan2(pass_through_y,(r1-pass_through_x));  // arctan(8/15)

            pass_through_x_2=4;
            pass_through_y_2=8;
            angle_2=atan2(pass_through_y_2,(r3-pass_through_x_2));  // arctan(8/6)
            
            first_circle_matrix();
        }
        
        void first_circle_matrix(){    // 초기 조건부터 전환점까지의 경로를 생성하여 행렬로 값을 저장하였다.
            for (int i=0;i<k;i++){
                double x1= PI-(i*angle_1/(k-1));
                first_point_info[i][0]=r1*cos(x1)+r1;   first_point_info[i][1]=r1*sin(x1);

                double x3= PI-(i*angle_2/(k-1));
                third_point_info[i][0]=r3*cos(x3)+r3;   third_point_info[i][1]=r3*sin(x3);
            }
            for(int i=0;i<k-1;i++){   // 최종 점을 제외한 경로의 점들의 yaw값을 저장
                first_point_info[i][2]=atan((first_point_info[i][1]-first_point_info[i+1][1])/(first_point_info[i][0]-first_point_info[i+1][0]));
                third_point_info[i][2]=atan((third_point_info[i][1]-third_point_info[i+1][1])/(third_point_info[i][0]-third_point_info[i+1][0]));
            }
            first_point_info[k-1][2]=(PI/2-angle_1);
            third_point_info[k-1][2]=(PI/2-angle_2);

            second_circle_matrix();
        }

        void second_circle_matrix(){    // 전환점부터 최종 목적지까지의 경로를 생성하여 행렬로 값을 저장한다.
            for(int j=k;j<2*k;j++){
                double x2= 2*PI-angle_1+((j-k)*angle_1/(k-1));
                first_point_info[j][0]=r2*cos(x2)-20.5;  
                first_point_info[j][1]=r2*sin(x2)+20;  

                double x4 = 2*PI-angle_2+((j-k)*angle_2/(k-1));
                third_point_info[j][0]=r4*cos(x4)-5;
                third_point_info[j][1]=r4*sin(x4)+20;
            }
            for(int j=k;j<2*k;j++){   // 최종 점을 제외한 경로의 점들의 yaw값을 저장
                first_point_info[j][2]=atan((first_point_info[j][1]-first_point_info[j+1][1])/(first_point_info[j][0]-first_point_info[j+1][0]));
                third_point_info[j][2]=atan((third_point_info[j][1]-third_point_info[j+1][1])/(third_point_info[j][0]-third_point_info[j+1][0]));
            }
            first_point_info[99][2]=atan(PI/2);
            third_point_info[99][2]=atan(PI/2);

            check_collision();
        }

        void check_collision(){
            if(obs_num == 0){      // 장애물 갯수가 없다면 모든 회피 경로 publish 가능 
                cal_point();
            }
            else{
                for(int i=0;i<obs_num;i++){
                    hurdle_x=HurdleArray.obs_info[i].x;
                    hurdle_y=HurdleArray.obs_info[i].y;
                    hurdle_r=HurdleArray.obs_info[i].r;
                    hurdle_state = HurdleArray.obs_info[i].mode;

                    if(hurdle_state==false){    // 동적 장애물이 있다면 어떤 회피 경로도 publish 못하게 함. 충돌 계산 종료. 
                        path_collision[0]=false;
                        path_collision[1]=false;
                        path_collision[2]=false;
                        path_collision[3]=false;
                        break;
                    }

                    double collision_dis = hurdle_r + vehicle_r;
                    double w= hurdle_x;
                    double e= hurdle_y;
                
                    for(int i=0;i<2*k;i++){
                        if(collision_dis>=sqrt(pow((first_point_info[i][0]-w),2)+pow((first_point_info[i][1]-e),2))){
                            path_collision[0]=false;
                        }
                        if(collision_dis>=sqrt(pow((-first_point_info[i][0]-w),2)+pow((first_point_info[i][1]-e),2))){
                            path_collision[1]=false;
                        }
                        if(collision_dis>=sqrt(pow((third_point_info[i][0]-w),2)+pow((third_point_info[i][1]-e),2))){
                            path_collision[2]=false;
                        }
                        if(collision_dis>=sqrt(pow((-third_point_info[i][0]-w),2)+pow((third_point_info[i][1]-e),2))){
                            path_collision[3]=false;
                        }
                    }
                }
                int sum_test=0;
                for(int p=0;p<5;p++){
                    if(path_collision[p]){
                        sum_test++;
                    }
                }
                ROS_INFO_STREAM("path_sum " << sum_test);
                cal_point();
            }
            
        }

        void x_Callback(const std_msgs::Float64ConstPtr &msg){
            goal.pose.position.x=msg->data;
            c=goal.pose.position.x;
            first_point_info[k-1][0]=c;
            Is_Callback_final_1=true;
        }
        void y_Callback(const std_msgs::Float64ConstPtr &msg){
            goal.pose.position.y=msg->data;
            d=goal.pose.position.y;
            first_point_info[k-1][1]=d;
            Is_Callback_final_2=true;
            //ROS_INFO_STREAM("I RECEIVED SENSOR POINT!");

        }
        void Hurdle(const local_planning::SensorPointArray::ConstPtr &msg){     // 장애물의 x,y,r,mode의 정보를 받아오는 콜백함수 
            HurdleArray.obs_info=msg->obs_info;
            obs_num=HurdleArray.obs_info.size();
            Is_Callback_hurdle=true;
        }

        void cal_point(){
            geometry_msgs::PoseStamped local_point_1;
            geometry_msgs::PoseStamped local_point_2;
            geometry_msgs::PoseStamped local_point_3;
            geometry_msgs::PoseStamped local_point_4;

            for(int j=0;j<2*k;j++){   // 초기 점과 최종 점을 포함하여 k개의 점을 찍어서 path를 생성할 것
                if(path_collision[0]==true){
                    local_point_1.pose.position.x=first_point_info[j][0];  // theta*(i/k)
                    local_point_1.pose.position.y=first_point_info[j][1];
                    local_point_1.pose.position.z=0.0;

                     m = first_point_info[j][2];
                    slope_1 = tf::createQuaternionFromRPY(0,0,m);   // (roll, pitch, yaw)를 createQuaternionFromRPY를 통해 쿼터니안으로 변환.
                    local_point_1.pose.orientation.x = slope_1[0];
                    local_point_1.pose.orientation.y = slope_1[1];
                    local_point_1.pose.orientation.z = slope_1[2];
                    local_point_1.pose.orientation.w = slope_1[3];

                    path_1.poses.push_back(local_point_1);
                }
                if(path_collision[1]==true){
                    local_point_2.pose.position.x=-first_point_info[j][0];
                    local_point_2.pose.position.y=first_point_info[j][1];
                    local_point_2.pose.position.z=0.0;

                    second_m=-first_point_info[j][2];
                    slope_2 = tf::createQuaternionFromRPY(0,0,second_m);
                    local_point_2.pose.orientation.x = slope_2[0];
                    local_point_2.pose.orientation.y = slope_2[1];
                    local_point_2.pose.orientation.z = slope_2[2];
                    local_point_2.pose.orientation.w = slope_2[3];

                    path_2.poses.push_back(local_point_2);
                }
                if(path_collision[2]==true){
                    local_point_3.pose.position.x=third_point_info[j][0];
                    local_point_3.pose.position.y=third_point_info[j][1];
                    local_point_3.pose.position.z=0.0;

                    third_m=third_point_info[j][2];
                    slope_3=tf::createQuaternionFromRPY(0,0,third_m);
                    local_point_3.pose.orientation.x = slope_3[0];
                    local_point_3.pose.orientation.y = slope_3[1];
                    local_point_3.pose.orientation.z = slope_3[2];
                    local_point_3.pose.orientation.w = slope_3[3];

                    path_3.poses.push_back(local_point_3);
                }
                if(path_collision[3]==true){
                    local_point_4.pose.position.x=-third_point_info[j][0];
                    local_point_4.pose.position.y=third_point_info[j][1];
                    local_point_4.pose.position.z=0.0;

                    fourth_m=-third_point_info[j][2];
                    slope_4=tf::createQuaternionFromRPY(0,0,fourth_m);
                    local_point_4.pose.orientation.x = slope_4[0];
                    local_point_4.pose.orientation.y = slope_4[1];
                    local_point_4.pose.orientation.z = slope_4[2];
                    local_point_4.pose.orientation.w = slope_4[3];

                    path_4.poses.push_back(local_point_4);
                }
            }
           

        }
        void pubpoint(){
            if(path_collision[0]==true)
                pub_pose_1.publish(path_1);
            if(path_collision[1]==true)
                pub_pose_2.publish(path_2);
            if(path_collision[2]==true)
                pub_pose_3.publish(path_3);
            if(path_collision[3]==true)
                pub_pose_4.publish(path_4);
        }

};


int main(int argc, char **argv){

    ros::init(argc,argv,"pub_path");    
    pointPub pub;

    ros::Rate rate(0.5);

    while(ros::ok()){
        if(pub.Is_Callback_final_1 && pub.Is_Callback_final_2 && execute_cal){
            pub.offset_exam();
            execute_cal = false;
        }
        pub.pubpoint();
        ros::spinOnce();
        rate.sleep();
    }
    

    return 0;
}
