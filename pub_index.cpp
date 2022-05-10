//STD header
#include<vector>
#include<cmath>
#include<string>
#include<iostream>

//ROS header
#include <ros/ros.h>
#include <tf/tf.h>
#include "local_planning/MyFirstMsg.h"
#include "local_planning/SensorPoint.h"


//Message header
#include<std_msgs/Int32.h>
#include<std_msgs/Float64.h>


using namespace std;

class indexPub{
    public:
        indexPub(){
            //pub_init_x=nh_.advertise<std_msgs::Float64>("/x_init",100);
            //pub_init_y=nh_.advertise<std_msgs::Float64>("/y_init",100);
            pub_goal_x = nh_.advertise<std_msgs::Float64>("/x_slot",100);
	        pub_goal_y = nh_.advertise<std_msgs::Float64>("/y_slot",100);
            pub_obstacle = nh_.advertise<local_planning::SensorPoint>("/obs",100);
        }
    
    private:
        ros::NodeHandle nh_;
        //ros::Publisher pub_init_x;
        //ros::Publisher pub_init_y;
        ros::Publisher pub_goal_x;
	    ros::Publisher pub_goal_y;
        ros::Publisher pub_obstacle;
        
        ros::Publisher number_of_obstacle;


        std_msgs::Float64 x_slot;
	    std_msgs::Float64 y_slot;
        std_msgs::Float64 obs_info[3];
        local_planning::MyFirstMsg times;
        local_planning::SensorPoint point;

        int num=3;

        bool obs_state[10];

        double exam_matrix[10][3];


    public:
        /*void pubInit(){
            x_init.data = 0;   // x좌표 초기 값 원점
            y_init.data = 0;   // y좌표 초기 값 원점
            pub_init_x.publish(x_init);
            pub_init_y.publish(y_init);
        }*/
        void test_mat(){
            exam_matrix[0][0] = -4;  exam_matrix[0][1] = 7;  exam_matrix[0][2] = 1;  obs_state[0]=true;
            exam_matrix[1][0] = -1;  exam_matrix[1][1] = 5;  exam_matrix[1][2] = 1;  obs_state[1]=true;
            exam_matrix[2][0] = 0;  exam_matrix[2][1] = 6;  exam_matrix[2][2] = 1;   obs_state[2]=true;
            exam_matrix[3][0] = 7;  exam_matrix[3][1] = 8;  exam_matrix[3][2] = 1;   obs_state[3]=true;
        }
        void test_obs(){
            for(int i=0;i<3;i++){
                point.x=exam_matrix[i][0];
                point.y=exam_matrix[i][1];
                point.r=exam_matrix[i][2];
                point.mode=obs_state[i];
                times.obs_info.push_back(point);
            }
        }
        void pubIdx(){
            x_slot.data = 5;   //  offset distance: 0.5m(x좌표 최종값)
	        y_slot.data = 20;   // look ahead distance:2m (y좌표 최종값)
            pub_goal_x.publish(x_slot); 
	        pub_goal_y.publish(y_slot); 
        }
        void pubObstacle(){
            obs_info[0].data=7;
            obs_info[1].data=8;
            obs_info[2].data=5;
            pub_obstacle.publish(obs_info);
        }
};

int main(int argc, char **argv){
    ros::init(argc, argv,"pub_index");
    indexPub pubI;

    ros::Rate rate(0.5);
    
    while(ros::ok()){
        //pubI.pubInit();
        pubI.pubIdx();
        pubI.pubObstacle();
        ros::spinOnce();
        rate.sleep();
    }
}

