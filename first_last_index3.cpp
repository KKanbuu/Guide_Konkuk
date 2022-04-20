#include<vector>
#include<cmath>
#include<string>
#include<iostream>
#include<ros/ros.h>
#include<tf/tf.h>

#include<std_msgs/Float64.h>

using namespace std;

class first_last_Index{
    public:
        first_last_Index(){
            pub_first_x=n.advertise<std_msgs::Float64>("/first_x",100);
            pub_first_y=n.advertise<std_msgs::Float64>("/first_y",100);
            pub_last_x=n.advertise<std_msgs::Float64>("/last_x",100);
            pub_last_y=n.advertise<std_msgs::Float64>("/last_y",100);
        }

    private:
        ros::NodeHandle n;
        ros::Publisher pub_first_x;
        ros::Publisher pub_first_y;
        ros::Publisher pub_last_x;
	    ros::Publisher pub_last_y;

        std_msgs::Float64 first_x;
	    std_msgs::Float64 first_y;
        std_msgs::Float64 last_x;
	    std_msgs::Float64 last_y;

    public:
        void pub_first_last(){
            //first_x.data = 6.561;
            //first_y.data = 9.39;
            //first_x.data = 6;
            //first_y.data = 9.178;
            first_x.data = 6.280;
            first_y.data = 9.284;
            
            //last_x.data = 14.8;
            //last_y.data = 12.504;
            //last_x.data = 16;
            //last_y.data = 12.985;
            //last_x.data = ;
            //last_y.data = 12.504;
            last_x.data = 15.4;
            last_y.data = 12.744;

            pub_first_x.publish(first_x);
            pub_first_y.publish(first_y);
            pub_last_x.publish(last_x);
            pub_last_y.publish(last_y);

        }
};

int main(int argc, char **argv){
    ros::init(argc, argv, "first_last_index");
    first_last_Index pub_;

    ros::Rate rate(0.5);

    while(ros::ok()){
        pub_.pub_first_last();
        ros::spinOnce();
        rate.sleep();
    }

}