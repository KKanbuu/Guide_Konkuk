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


class pointPub{
    public:
        pointPub(){
            
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
        
        double a,b;
        double c,d;
        double m;
        
    public:
        void x_init_Callback(const std_msgs::Float64ConstPtr &msg){
            init.pose.position.x=msg->data;
            a = init.pose.position.x;
        }
        void y_init_Callback(const std_msgs::Float64ConstPtr &msg){
            init.pose.position.y=msg->data;
            b = init.pose.position.y;
        }
        void x_Callback(const std_msgs::Float64ConstPtr &msg){
            goal.pose.position.x=msg->data;
            c= goal.pose.position.x;
        }
        void y_Callback(const std_msgs::Float64ConstPtr &msg){
            goal.pose.position.y=msg->data;
            d=goal.pose.position.y;
            // m=(d-b)/(c-a);
            pubpoint();
        }
        void pubpoint(){
            geometry_msgs::PoseStamped local_point;
            int k=10;     // 초기 점과 최종 점을 포함하여 10개의 점을 찍어서 path를 생성할 것
            m=(d-b)/(c-a);  // yaw 값. 직선이기 때문에 일차함수의 기울기로 표현

            for(int i=0;i<=k;i++){   // 초기 점과 최종 점을 포함하여 k개의 점을 찍어서 path를 생성할 것
                local_point.pose.position.x=init.pose.position.x + (d/k*i);
                local_point.pose.position.y=local_point.pose.position.x*m;
                local_point.pose.position.z=0.0;
                slope = tf::createQuaternionFromRPY(0,0,m);   // (roll, pitch, yaw)를 createQuaternionFromRPY를 통해 쿼터니안으로 변환.
                local_point.pose.orientation.x = slope[0];
                local_point.pose.orientation.y = slope[1];
                local_point.pose.orientation.z = slope[2];
                local_point.pose.orientation.w = slope[3];
                path_.poses.push_back(local_point);
            }

            //pub_pose.publish(init);
            //pub_pose.publish(goal);
            pub_pose.publish(path_);
            
            ROS_INFO_STREAM("goal point: "<<goal.pose.position.x<<" "<<goal.pose.position.y);
            ROS_INFO_STREAM("slope: " << m);

        }

};

int main(int argc, char **argv){

    ros::init(argc,argv,"pub_path");    
    pointPub pub;
    //ub.pubpoint();
    ros::spin();

    return 0;
}
