//STD header
#include<vector>
#include<cmath>
#include<string>
#include<iostream>

//ROS header
#include <ros/ros.h>
#include <tf/tf.h>
#include "local_planning/SensorPointArray.h"
#include "local_planning/SensorPoint.h"


//Message header
#include<std_msgs/Int32.h>
#include<std_msgs/Float64.h>


using namespace std;

class indexPub{
    public:
        indexPub(){
            pub_goal_x = nh_.advertise<std_msgs::Float64>("/x_slot",10);
	        pub_goal_y = nh_.advertise<std_msgs::Float64>("/y_slot",10);
            pub_obstacle = nh_.advertise<local_planning::SensorPointArray>("/obs",15);
        }
    
    private:
        ros::NodeHandle nh_;

        ros::Publisher pub_goal_x;
	    ros::Publisher pub_goal_y;
        ros::Publisher pub_obstacle;

        std_msgs::Float64 x_slot;
	    std_msgs::Float64 y_slot;
        local_planning::SensorPointArray HurdleArray;
        local_planning::SensorPoint point;

        int num=3;
        bool obs_state[10];
        double exam_matrix[10][3];

    public:
        void test_mat(){
            exam_matrix[0][0] = -4;  exam_matrix[0][1] = 7;  exam_matrix[0][2] = 1;  obs_state[0]=true;
            exam_matrix[1][0] = -4;  exam_matrix[1][1] = 5;  exam_matrix[1][2] = 1;  obs_state[1]=true;
            exam_matrix[2][0] = 0;  exam_matrix[2][1] = 6;  exam_matrix[2][2] = 1;   obs_state[2]=true;
            exam_matrix[3][0] = 7;  exam_matrix[3][1] = 8;  exam_matrix[3][2] = 1;   obs_state[3]=true;
            test_obs();
        }
        void test_obs(){
            for(int i=0;i<2;i++){
                point.x=exam_matrix[i][0];
                point.y=exam_matrix[i][1];
                point.r=exam_matrix[i][2];
                point.mode=obs_state[i];
                HurdleArray.obs_info.push_back(point);
            }
            pub_obstacle.publish(HurdleArray);
            HurdleArray.obs_info.clear();
        }
        void pubIdx(){
            x_slot.data = 5;   //  offset distance: 0.5m(x좌표 최종값)
	        y_slot.data = 20;   // look ahead distance:2m (y좌표 최종값)
            pub_goal_x.publish(x_slot); 
	        pub_goal_y.publish(y_slot); 
        }
};

int main(int argc, char **argv){
    ros::init(argc, argv,"pub_index");
    indexPub pubI;

    ros::Rate rate(20);
    
    while(ros::ok()){
        pubI.pubIdx();
        pubI.test_mat();
        ros::spinOnce();
        rate.sleep();
    }
}

