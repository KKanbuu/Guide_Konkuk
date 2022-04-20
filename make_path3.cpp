#include<vector>
#include<cmath>
#include<string>
#include<iostream>

#include<ros/ros.h>
#include<tf/tf.h>
#include<tf/transform_broadcaster.h>

#include<geometry_msgs/Pose.h>
#include<geometry_msgs/PoseStamped.h>
#include<nav_msgs/Path.h>
#include<std_msgs/Float64MultiArray.h>
#include<std_msgs/Float64.h>
#include<std_msgs/Int32.h>

using std::pow;
using std::cos;
using std::sin;
using std::tan;
using std::abs;
using std::to_string;
using std::cout;
using std::vector;

class path_Make{
    public:
        path_Make(){
            sub_first_x=ns.subscribe("/first_x",100,&path_Make::first_x_Callback,this);
            sub_first_y=ns.subscribe("/first_y",100,&path_Make::first_y_Callback,this);
            sub_last_x=ns.subscribe("/last_x",100,&path_Make::last_x_Callback,this);
            sub_last_y=ns.subscribe("/last_y",100,&path_Make::last_y_Callback,this);


            pub1_pose=ns.advertise<nav_msgs::Path>("curve1_pose1",100);
            pub2_pose=ns.advertise<nav_msgs::Path>("curve1_pose2",100);
            pub3_pose=ns.advertise<nav_msgs::Path>("curve2_pose1",100);
            pub4_pose=ns.advertise<nav_msgs::Path>("curve2_pose2",100);
            pub5_pose=ns.advertise<nav_msgs::Path>("straight1",100);
            pub6_pose=ns.advertise<nav_msgs::Path>("straight2",100);
            pub7_pose=ns.advertise<nav_msgs::Path>("real_curve1",100);
            pub8_pose=ns.advertise<nav_msgs::Path>("real_curve2",100);


            curve1_path1_.header.frame_id = "/map";
            curve1_path2_.header.frame_id = "/map";
            curve2_path1_.header.frame_id = "/map";
            curve2_path2_.header.frame_id = "/map";
            realcurve1_path1_.header.frame_id = "/map";
            realcurve2_path1_.header.frame_id = "/map";
            straight1_path1_.header.frame_id = "/map";
            straight2_path1_.header.frame_id = "/map";

            first.header.frame_id = "/map";
            last.header.frame_id = "/map";

            point_information();
            make_point();
        }

    private:
        ros::NodeHandle ns;

        geometry_msgs::PoseStamped first;
        geometry_msgs::PoseStamped last;

        ros::Publisher pub1_pose;
        ros::Publisher pub2_pose;
        ros::Publisher pub3_pose;
        ros::Publisher pub4_pose;
        ros::Publisher pub5_pose;
        ros::Publisher pub6_pose;
        ros::Publisher pub7_pose;
        ros::Publisher pub8_pose;

        ros::Subscriber sub_first_x;
        ros::Subscriber sub_first_y;
        ros::Subscriber sub_last_x;
        ros::Subscriber sub_last_y;

        nav_msgs::Path curve1_path1_;
        nav_msgs::Path curve1_path2_;
        nav_msgs::Path curve2_path1_;
        nav_msgs::Path curve2_path2_;
        nav_msgs::Path straight1_path1_;
        nav_msgs::Path straight2_path1_;
        nav_msgs::Path realcurve1_path1_;
        nav_msgs::Path realcurve2_path1_;

        tf::Quaternion slope1;
        tf::Quaternion slope2;
        tf::Quaternion slope3;
        tf::Quaternion slope4;
        tf::Quaternion slope5;
        tf::Quaternion slope6;
        tf::Quaternion slope7;
        tf::Quaternion slope8;

        double a,b,c,d,m;
        double a1,b1,c1,d1,m1;
        double PI = 3.141592;
        double r1 = 10;
        double r2 = 8;
        double r3 = 20;
        double theta1 = atan2(9.39,10-6.561);
        double theta2 = atan2(20-12.504,2.8);


        int k = 50;
        double point_info1[50][3];
        double point_info2[50][3];
        double point_info3[50][3];
        double point_info4[50][3];
        double point_info5[50][3];
        double point_info6[50][3];
        double point_info7[50][3];

    public:
            bool Is_Callback_first_x = false;
            bool Is_Callback_first_y = false;
            bool Is_Callback_last_x = false;
            bool Is_Callback_last_y = false;

        void first_x_Callback(const std_msgs::Float64ConstPtr &msg){
            first.pose.position.x=msg->data;
            a = first.pose.position.x;
            point_info1[0][0]=a;
            Is_Callback_first_x = true;
        }
        void first_y_Callback(const std_msgs::Float64ConstPtr &msg){
            first.pose.position.y=msg->data;
            b = first.pose.position.y;
            point_info1[0][1]=b;
            Is_Callback_first_y = true;
        }
        void last_x_Callback(const std_msgs::Float64ConstPtr &msg){
            last.pose.position.x=msg->data;
            c = last.pose.position.x;
            point_info1[k-1][0]=c;
            Is_Callback_last_x = true;
        }
        void last_y_Callback(const std_msgs::Float64ConstPtr &msg){
            last.pose.position.y=msg->data;
            d = last.pose.position.y;
            point_info1[k-1][1]=d;
            Is_Callback_last_y = true;

            make_point2();
        }

        void point_information(){
            
            ROS_INFO_STREAM(theta1);
            ROS_INFO_STREAM(PI/4);

            for(int i=0;i<k;i++){
                point_info1[i][0]=r1-(r1*cos((i*theta1)/(k)));  
                point_info1[i][1]=r1*sin((i*theta1)/(k));  
            }
            for(int i=1;i<k-1;i++){
                point_info1[i][2]=atan((point_info1[i][1]-point_info1[i+1][1])/(point_info1[i][0]-point_info1[i+1][0]));
            }

            for(int i=0;i<k;i++){
                point_info2[i][0]=12+(r2*cos((i*theta2)/(k)));  
                point_info2[i][1]=20-r2*sin((i*theta2)/(k));   
            }
            for(int i=1;i<k-1;i++){
                point_info2[i][2]=atan((point_info2[i][1]-point_info2[i+1][1])/(point_info2[i][0]-point_info2[i+1][0]));
            }

            for(int i=0;i<k;i++){
                point_info3[i][0]=-r1+(r1*cos((i*theta1)/(k)));  
                point_info3[i][1]=r1*sin((i*theta1)/(k));  
            }
            for(int i=1;i<k-1;i++){
                point_info3[i][2]=atan((point_info3[i][1]-point_info3[i+1][1])/(point_info3[i][0]-point_info3[i+1][0]));
            }

            for(int i=0;i<k;i++){
                point_info4[i][0]=-12-(r2*cos((i*theta2)/(k)));  
                point_info4[i][1]=20-r2*sin((i*theta2)/(k));   
            }
            for(int i=1;i<k-1;i++){
                point_info4[i][2]=atan((point_info4[i][1]-point_info4[i+1][1])/(point_info4[i][0]-point_info4[i+1][0]));
            }

            for(int i=0;i<k;i++){
                point_info6[i][0]=20-(r3*cos((i*PI)/(2*k)));  
                point_info6[i][1]=r3*sin((i*PI)/(2*k));   
            }
            for(int i=1;i<k-1;i++){
                point_info6[i][2]=atan((point_info6[i][1]-point_info6[i+1][1])/(point_info6[i][0]-point_info6[i+1][0]));
            }

            for(int i=0;i<k;i++){
                point_info7[i][0]=-20+(r3*cos((i*PI)/(2*k)));  
                point_info7[i][1]=r3*sin((i*PI)/(2*k));   
            }
            for(int i=1;i<k-1;i++){
                point_info7[i][2]=atan((point_info7[i][1]-point_info7[i+1][1])/(point_info7[i][0]-point_info7[i+1][0]));
            }

        }

        void make_point(){
            geometry_msgs::PoseStamped point1;
            geometry_msgs::PoseStamped point2;
            geometry_msgs::PoseStamped point3;
            geometry_msgs::PoseStamped point4;
            geometry_msgs::PoseStamped point7;
            geometry_msgs::PoseStamped point8;

            for(int j=0;j<k;j++){
                point1.pose.position.x=point_info1[j][0];  
                point1.pose.position.y=point_info1[j][1];
                point1.pose.position.z=0.0;
             
                m = point_info1[j][2];
                slope1 = tf::createQuaternionFromRPY(0,0,m);  
                point1.pose.orientation.x = slope1[0];
                point1.pose.orientation.y = slope1[1];
                point1.pose.orientation.z = slope1[2];
                point1.pose.orientation.w = slope1[3];

                curve1_path1_.poses.push_back(point1);
            }  
                
            pub1_pose.publish(curve1_path1_);

            for(int j=0;j<k;j++){
                point2.pose.position.x=point_info2[j][0];  
                point2.pose.position.y=point_info2[j][1];
                point2.pose.position.z=0.0;
             
                m = point_info2[j][2];
                slope2 = tf::createQuaternionFromRPY(0,0,m);  
                point2.pose.orientation.x = slope2[0];
                point2.pose.orientation.y = slope2[1];
                point2.pose.orientation.z = slope2[2];
                point2.pose.orientation.w = slope2[3];

                curve1_path2_.poses.push_back(point2);
            }  

            pub2_pose.publish(curve1_path2_);

            for(int j=0;j<k;j++){
                point3.pose.position.x=point_info3[j][0];  
                point3.pose.position.y=point_info3[j][1];
                point3.pose.position.z=0.0;
             
                m = point_info3[j][2];
                slope3 = tf::createQuaternionFromRPY(0,0,m);  
                point3.pose.orientation.x = slope3[0];
                point3.pose.orientation.y = slope3[1];
                point3.pose.orientation.z = slope3[2];
                point3.pose.orientation.w = slope3[3];

                curve2_path1_.poses.push_back(point3);
            }  

            pub3_pose.publish(curve2_path1_);

            for(int j=0;j<k;j++){
                point4.pose.position.x=point_info4[j][0];  
                point4.pose.position.y=point_info4[j][1];
                point4.pose.position.z=0.0;
             
                m = point_info4[j][2];
                slope4 = tf::createQuaternionFromRPY(0,0,m);  
                point4.pose.orientation.x = slope4[0];
                point4.pose.orientation.y = slope4[1];
                point4.pose.orientation.z = slope4[2];
                point4.pose.orientation.w = slope4[3];

                curve2_path2_.poses.push_back(point4);
            }  

            pub4_pose.publish(curve2_path2_);


            for(int j=0;j<k;j++){
                point7.pose.position.x=point_info6[j][0];  
                point7.pose.position.y=point_info6[j][1];
                point7.pose.position.z=0.0;
             
                m = point_info6[j][2];
                slope7 = tf::createQuaternionFromRPY(0,0,m);  
                point7.pose.orientation.x = slope7[0];
                point7.pose.orientation.y = slope7[1];
                point7.pose.orientation.z = slope7[2];
                point7.pose.orientation.w = slope7[3];

                realcurve1_path1_.poses.push_back(point7);
            }  

            pub7_pose.publish(realcurve1_path1_);

            for(int j=0;j<k;j++){
                point8.pose.position.x=point_info7[j][0];  
                point8.pose.position.y=point_info7[j][1];
                point8.pose.position.z=0.0;
             
                m = point_info7[j][2];
                slope8 = tf::createQuaternionFromRPY(0,0,m);  
                point8.pose.orientation.x = slope8[0];
                point8.pose.orientation.y = slope8[1];
                point8.pose.orientation.z = slope8[2];
                point8.pose.orientation.w = slope8[3];

                realcurve2_path1_.poses.push_back(point8);
            }  

            pub8_pose.publish(realcurve2_path1_);

        }

        void make_point2(){
            geometry_msgs::PoseStamped point5;
            geometry_msgs::PoseStamped point6;
                int k = 50;
                m = (d-b)/(c-a);
                double g = c-a;
                b=6.91;
                a1=-a;
            for(int j=0;j<=k;j++){

                point5.pose.position.x= a + ((g)/k*j);  
                point5.pose.position.y=point5.pose.position.x*m + b;
                point5.pose.position.z=0.0;
             
                slope5 = tf::createQuaternionFromRPY(0,0,m);  
                point5.pose.orientation.x = slope5[0];
                point5.pose.orientation.y = slope5[1];
                point5.pose.orientation.z = slope5[2];
                point5.pose.orientation.w = slope5[3];

                straight1_path1_.poses.push_back(point5);
            }  

            pub5_pose.publish(straight1_path1_);

            for(int j=0;j<=k;j++){

                point6.pose.position.x= a1 - ((g)/k*j);  
                point6.pose.position.y=-point6.pose.position.x*m + b;
                point6.pose.position.z=0.0;
             
                slope6 = tf::createQuaternionFromRPY(0,0,m);  
                point6.pose.orientation.x = slope6[0];
                point6.pose.orientation.y = slope6[1];
                point6.pose.orientation.z = slope6[2];
                point6.pose.orientation.w = slope6[3];

                straight2_path1_.poses.push_back(point6);
            }  

            pub6_pose.publish(straight2_path1_);
        }

        void pubpoint(){
            pub1_pose.publish(curve1_path1_);
            pub2_pose.publish(curve1_path2_);
            pub3_pose.publish(curve2_path1_);
            pub4_pose.publish(curve2_path2_);
            pub5_pose.publish(straight1_path1_);
            pub6_pose.publish(straight2_path1_);
            pub7_pose.publish(realcurve1_path1_);
            pub8_pose.publish(realcurve2_path1_);

        }


};

int main(int argc, char **argv){

    ros::init(argc, argv, "make_path2");
    path_Make make;
    ros::Rate r(0.5);

    while(ros::ok()){
        make.pubpoint();
        ros::spinOnce();
        r.sleep();
    }

    return 0;

}