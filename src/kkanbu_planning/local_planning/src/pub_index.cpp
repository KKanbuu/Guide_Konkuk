//STD header
#include<vector>
#include<cmath>
#include<string>
#include<iostream>

//ROS header
#include<ros/ros.h>
#include<tf/tf.h>


//Message header
#include<std_msgs/Int32.h>
#include<std_msgs/Float64.h>


using namespace std;

class indexPub{
    public:
        indexPub(){
            pub_init_x=nh_.advertise<std_msgs::Float64>("/x_init",100);
            pub_init_y=nh_.advertise<std_msgs::Float64>("/y_init",100);
            pub_goal_x = nh_.advertise<std_msgs::Float64>("/x_slot",100);
	        pub_goal_y = nh_.advertise<std_msgs::Float64>("/y_slot",100);

        }
    
    private:
        ros::NodeHandle nh_;
        ros::Publisher pub_init_x;
        ros::Publisher pub_init_y;
        ros::Publisher pub_goal_x;
	    ros::Publisher pub_goal_y;

        std_msgs::Float64 x_init;
	    std_msgs::Float64 y_init;
        std_msgs::Float64 x_slot;
	    std_msgs::Float64 y_slot;

    public:
        void pubInit(){
            x_init.data = 0;   // x좌표 초기 값 
            y_init.data = 0;   // y좌표 초기 값
            pub_init_x.publish(x_init);
            pub_init_y.publish(y_init);
        }
        void pubIdx(){
            x_slot.data = 3;   // x좌표 최종 값
	        y_slot.data = 4;   // y좌표 최종 값
            pub_goal_x.publish(x_slot); 
	        pub_goal_y.publish(y_slot); 
        }
};

int main(int argc, char **argv){
    ros::init(argc, argv,"pub_index");
    indexPub pubI;

    ros::Rate rate(1);
    /*
    if(ros::ok()){
        pubI.pubIdx();
        ros::spinOnce();
    }*/
    
    while(ros::ok()){
        pubI.pubInit();
        pubI.pubIdx();
        ros::spinOnce();
        rate.sleep();
    }
}

