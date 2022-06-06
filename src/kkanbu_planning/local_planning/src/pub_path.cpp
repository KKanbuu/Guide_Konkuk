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
#include "kkanbu_msgs/SensorPointArray.h"
#include "kkanbu_msgs/SensorPoint.h"
#include "kkanbu_msgs/LocalPathArray.h"
// #include "kkanbu_msgs/LocalPath.h"
#include "kkanbu_msgs/VehicleState.h"


//Using
using namespace std;

bool execute_cal = true;

class pointPub{
    public:
        pointPub(){
            
                // 초기 위치 받아옴
            sub_x_goal= nh.subscribe("/x_slot",10,&pointPub::x_Callback,this); 
            sub_y_goal= nh.subscribe("/y_slot",10,&pointPub::y_Callback,this);
            sub_obstacle=nh.subscribe("/obs",15,&pointPub::Hurdle,this);
            sub_VehicleState = nh.subscribe("/ego/vehicle_state",10,&pointPub::get_VehicleState,this);
            sub_GlobalPath = nh.subscribe("/map/entire_path",10,&pointPub::get_GlobalPath,this);
	            // Publisher 객체 선언, topic의 이름 xy_pose, 메시지 큐의 크기가 100
            // pub_PathArray=nh.advertise<kkanbu_msgs::LocalPathArray>("five_local_path",10);  
            //path_.header.frame_id = "/ego";
            // path_1.header.frame_id = "/map";
            pub_pose_1=nh.advertise<nav_msgs::Path>("xy_pose_1",10);  
            pub_pose_2=nh.advertise<nav_msgs::Path>("xy_pose_2",10);   
            pub_pose_3=nh.advertise<nav_msgs::Path>("xy_pose_3",10);   
            pub_pose_4=nh.advertise<nav_msgs::Path>("xy_pose_4",10);
            pub_pose_st = nh.advertise<nav_msgs::Path>("xy_pose_st",10);
            path_1.header.frame_id = "/ego";
            path_2.header.frame_id = "/ego";
            path_3.header.frame_id = "/ego";
            path_4.header.frame_id = "/ego";
            straight_path.header.frame_id = "/ego";
            
             // rviz에서 frame을 map으로 정해줌
        
            
        }
    private:
        ros::NodeHandle nh;  // 시스템과의 소통을 위해 객체 선언

        geometry_msgs::PoseStamped goal;
        geometry_msgs::PoseStamped init;
        nav_msgs::Path path_1;
        nav_msgs::Path path_2;
        nav_msgs::Path path_3;
        nav_msgs::Path path_4;
        nav_msgs::Path straight_path;
        kkanbu_msgs::LocalPathArray local_array;
        kkanbu_msgs::SensorPointArray HurdleArray;
        // kkanbu_msgs::LocalPath path_tools;
        nav_msgs::Path global_path;
        kkanbu_msgs::VehicleState vehicle_state_;

        ros::Subscriber sub_x_goal;
        ros::Subscriber sub_y_goal;
        ros::Subscriber sub_obstacle;
        ros::Subscriber sub_VehicleState;
        ros::Subscriber sub_LocalPath;
        ros::Subscriber sub_GlobalPath;

        ros::Publisher pub_pose_1;
        ros::Publisher pub_pose_2;
        ros::Publisher pub_pose_3;
        ros::Publisher pub_pose_4;
        ros::Publisher pub_pose_st;

        // ros::Publisher pub_PathArray;
        //Control_Robot control;

        tf::Quaternion slope_1;
        tf::Quaternion slope_2;
        tf::Quaternion slope_3;
        tf::Quaternion slope_4;  
        tf::Quaternion straight_slope;  

        double vehicle_r = 1; // 원래는 반지름 4임 !!!!!!!!!!!!!!!!!!!!반드시 고쳐라!!!!!!!!!!!!!!!!!
        double hurdle_x;
        double hurdle_y;
        double hurdle_r;
        bool hurdle_state;    
        int obs_num;
        bool path_collision[5]={true,true,true,true,true};

        // 경로 계산에 쓰이는 변수들
        double r1=17;
        double r2=25.5;
        double r3=10;
        double r4=15;
        double angle_1;
        double angle_2;
        double PI = 3.141592;
        double m;
        double c,d;
        double second_m;
        double third_m;
        double fourth_m;
        double straight_m;
        double pass_through_x;
        double pass_through_y;
        double pass_through_x_2;
        double pass_through_y_2;
        int k=5;     // 초기 점과 최종 점을 포함하여 2*5개의 점을 찍어서 path를 생성할 것
        double narrow_point_info[11][3];
        double wide_point_info[11][3];
        double straight_point_info[11][2];

        int closest_idx_;
        int sum_possible = 0;
        bool isPath = false;
        int lookAhead_idx_;
        geometry_msgs::PoseStamped lookAhead_Pose_;
        double local_distance[5]={1000,1000,1000,1000,1000};
        double dx[5]={-10.-5,5,10,0};
        double dy=20;
        int proper_idx;

        
    public:
            bool Is_Callback_final_1 = false;
            bool Is_Callback_final_2 = false;
            bool Is_Callback_hurdle = false;
        
        // Callback 함수들
        void x_Callback(const std_msgs::Float64ConstPtr &msg){
            goal.pose.position.x=msg->data;
            c=goal.pose.position.x;
            narrow_point_info[k-1][0]=c;
            Is_Callback_final_1=true;
        }
        void y_Callback(const std_msgs::Float64ConstPtr &msg){
            goal.pose.position.y=msg->data;
            d=goal.pose.position.y;
            narrow_point_info[k-1][1]=d;
            Is_Callback_final_2=true;
        }
         void Hurdle(const kkanbu_msgs::SensorPointArray::ConstPtr &msg){     // 장애물의 x,y,r,mode의 정보를 받아오는 콜백함수 
            HurdleArray.obs_info=msg->obs_info;
            obs_num=HurdleArray.obs_info.size();
            Is_Callback_hurdle = true;
        }
        void get_VehicleState(const kkanbu_msgs::VehicleState::ConstPtr& msg){
            vehicle_state_ = *msg;
        }

        void get_GlobalPath(const nav_msgs::Path::ConstPtr& msg){
            global_path = *msg;
            isPath = true;
        }

        
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
                narrow_point_info[i][0]=r1*cos(x1)+r1;   narrow_point_info[i][1]=r1*sin(x1);

                double x3= PI-(i*angle_2/(k-1));
                wide_point_info[i][0]=r3*cos(x3)+r3;   wide_point_info[i][1]=r3*sin(x3);

                straight_point_info[i][0]=0;   straight_point_info[i][1]= d/(2*k-1)*i;
            }
            for(int i=0;i<k-1;i++){   // 최종 점을 제외한 경로의 점들의 yaw값을 저장
                narrow_point_info[i][2]=atan((narrow_point_info[i][1]-narrow_point_info[i+1][1])/(narrow_point_info[i][0]-narrow_point_info[i+1][0]));
                wide_point_info[i][2]=atan((wide_point_info[i][1]-wide_point_info[i+1][1])/(wide_point_info[i][0]-wide_point_info[i+1][0]));
            }
            narrow_point_info[k-1][2]=(PI/2-angle_1);
            wide_point_info[k-1][2]=(PI/2-angle_2);

            second_circle_matrix();
        }

        void second_circle_matrix(){    // 전환점부터 최종 목적지까지의 경로를 생성하여 행렬로 값을 저장한다.
            for(int j=k;j<2*k;j++){
                double x2= 2*PI-angle_1+((j-k)*angle_1/(k-1));
                narrow_point_info[j][0]=r2*cos(x2)-20.5;  
                narrow_point_info[j][1]=r2*sin(x2)+20;  

                double x4 = 2*PI-angle_2+((j-k)*angle_2/(k-1));
                wide_point_info[j][0]=r4*cos(x4)-5;
                wide_point_info[j][1]=r4*sin(x4)+20;

                straight_point_info[j][0]=0;   straight_point_info[j][1]=d/(2*k-1)*j;
            }
            for(int j=k;j<2*k;j++){   // 최종 점을 제외한 경로의 점들의 yaw값을 저장
                narrow_point_info[j][2]=atan((narrow_point_info[j][1]-narrow_point_info[j+1][1])/(narrow_point_info[j][0]-narrow_point_info[j+1][0]));
                wide_point_info[j][2]=atan((wide_point_info[j][1]-wide_point_info[j+1][1])/(wide_point_info[j][0]-wide_point_info[j+1][0]));
            }
            narrow_point_info[99][2]=atan(PI/2);
            wide_point_info[99][2]=atan(PI/2);

            cal_point();
            
        }

        void cal_point(){
            geometry_msgs::PoseStamped local_point_1;
            geometry_msgs::PoseStamped local_point_2;
            geometry_msgs::PoseStamped local_point_3;
            geometry_msgs::PoseStamped local_point_4;
            geometry_msgs::PoseStamped local_point_straight;

            for(int j=0;j<2*k;j++){   // 초기 점과 최종 점을 포함하여 k개의 점을 찍어서 path를 생성할 것
                local_point_1.pose.position.x=-wide_point_info[j][0];
                local_point_1.pose.position.y=wide_point_info[j][1];
                local_point_1.pose.position.z=0.0;

                m=-wide_point_info[j][2];
                slope_1=tf::createQuaternionFromRPY(0,0,m);
                local_point_1.pose.orientation.x = slope_1[0];
                local_point_1.pose.orientation.y = slope_1[1];
                local_point_1.pose.orientation.z = slope_1[2];
                local_point_1.pose.orientation.w = slope_1[3];

                path_1.poses.push_back(local_point_1);
            
                local_point_2.pose.position.x=-narrow_point_info[j][0];
                local_point_2.pose.position.y=narrow_point_info[j][1];
                local_point_2.pose.position.z=0.0;

                second_m=-narrow_point_info[j][2];
                slope_2 = tf::createQuaternionFromRPY(0,0,second_m);
                local_point_2.pose.orientation.x = slope_2[0];
                local_point_2.pose.orientation.y = slope_2[1];
                local_point_2.pose.orientation.z = slope_2[2];
                local_point_2.pose.orientation.w = slope_2[3];

                path_2.poses.push_back(local_point_2);
            
                local_point_3.pose.position.x=narrow_point_info[j][0];  // theta*(i/k)
                local_point_3.pose.position.y=narrow_point_info[j][1];
                local_point_3.pose.position.z=0.0;

                third_m = narrow_point_info[j][2];
                slope_3 = tf::createQuaternionFromRPY(0,0,third_m);   // (roll, pitch, yaw)를 createQuaternionFromRPY를 통해 쿼터니안으로 변환.
                local_point_3.pose.orientation.x = slope_3[0];
                local_point_3.pose.orientation.y = slope_3[1];
                local_point_3.pose.orientation.z = slope_3[2];
                local_point_3.pose.orientation.w = slope_3[3];

                path_3.poses.push_back(local_point_3);
            
                local_point_4.pose.position.x=wide_point_info[j][0];
                local_point_4.pose.position.y=wide_point_info[j][1];
                local_point_4.pose.position.z=0.0;

                fourth_m=wide_point_info[j][2];
                slope_4=tf::createQuaternionFromRPY(0,0,fourth_m);
                local_point_4.pose.orientation.x = slope_4[0];
                local_point_4.pose.orientation.y = slope_4[1];
                local_point_4.pose.orientation.z = slope_4[2];
                local_point_4.pose.orientation.w = slope_4[3];

                path_4.poses.push_back(local_point_4);
            
                local_point_straight.pose.position.x=straight_point_info[j][0];
                local_point_straight.pose.position.y=straight_point_info[j][1];
                local_point_straight.pose.position.z=0.0;

                straight_m=atan(PI/2);
                straight_slope=tf::createQuaternionFromRPY(0,0,straight_m);
                local_point_straight.pose.orientation.x = straight_slope[0];
                local_point_straight.pose.orientation.y = straight_slope[1];
                local_point_straight.pose.orientation.z = straight_slope[2];
                local_point_straight.pose.orientation.w = straight_slope[3];

                straight_path.poses.push_back(local_point_straight);
            }
        }

        void check_collision(){
            if(obs_num == 0){      // 장애물 개수가 없다면 모든 회피 경로 publish 가능 
                find_ClosestWaypoint();
            }
            else{
                for(int i=0;i<obs_num;i++){
                    hurdle_x=HurdleArray.obs_info[i].x;
                    hurdle_y=HurdleArray.obs_info[i].y;
                    hurdle_r=HurdleArray.obs_info[i].r;
                    hurdle_state = HurdleArray.obs_info[i].mode;

                    // ROS_INFO_STREAM("hurdle_x " << hurdle_x);
                    // ROS_INFO_STREAM("hurdle_y " << hurdle_y);
                    // ROS_INFO_STREAM("hurdle_r " << hurdle_r);
                    // ROS_INFO_STREAM("hurdle_state " << hurdle_state);

                    if(hurdle_state==false){    // 동적 장애물이 있다면 어떤 회피 경로도 publish 못하게 함. 충돌 계산 종료. 
                        path_collision[0]=false;
                        path_collision[1]=false;
                        path_collision[2]=false;
                        path_collision[3]=false;
                        path_collision[4]=false;
                        break;
                    }
                    double collision_dis = hurdle_r + vehicle_r;
                    double w= hurdle_x;
                    double e= hurdle_y;
                
                    for(int j=0;j<2*k;j++){
                        if(collision_dis>=sqrt(pow((-wide_point_info[j][0]-w),2)+pow((wide_point_info[j][1]-e),2))){
                            path_collision[0]=false;
                        }
                        if(collision_dis>=sqrt(pow((-narrow_point_info[j][0]-w),2)+pow((narrow_point_info[j][1]-e),2))){
                            path_collision[1]=false;
                        }
                        if(collision_dis>=sqrt(pow((narrow_point_info[j][0]-w),2)+pow((narrow_point_info[j][1]-e),2))){
                            path_collision[2]=false;
                        }
                        if(collision_dis>=sqrt(pow((wide_point_info[j][0]-w),2)+pow((wide_point_info[j][1]-e),2))){
                            path_collision[3]=false;
                        }
                        if(collision_dis>=sqrt(pow((straight_point_info[j][0]-w),2)+pow((straight_point_info[j][1]-e),2))){
                            path_collision[4]=false;
                        }
                    }
                }
                sum_path();
            }
        }

        void sum_path(){
            sum_possible =0;
            for(int p=0;p<5;p++){
                if(path_collision[p] == true){
                    sum_possible++;
                }
            }
            // ROS_INFO_STREAM(sum_possible);
            find_ClosestWaypoint();
        }


        /// opt_path.cpp


        void find_ClosestWaypoint(){
            double min_distance = 1000;
    
            if(isPath){
                for(int i=0;i<global_path.poses.size();i++){
                    double temp_distance = sqrt(pow(vehicle_state_.x - global_path.poses[i].pose.position.x,2)+pow(vehicle_state_.y - global_path.poses[i].pose.position.y,2));
                    if(temp_distance < min_distance){
                        closest_idx_ = i;
                        min_distance = temp_distance;
                    }
                }
                lookAhead_idx_ = closest_idx_ + 1;
                lookAhead_Pose_ = global_path.poses[lookAhead_idx_];
            }
            measure_distance();
        }

        void find_lowcost_path(){   // 회피 가능한 path가 2개 이상인 경우에 사용
            double short_dis = 999;

            for (int i=0;i<5;i++){
                if(local_distance[i] < short_dis){
                    proper_idx = i;
                }
            }
        }

        void measure_distance(){
            if(sum_possible == 0){
                ROS_INFO_STREAM("STOP!!");
            }
            else if(sum_possible == 1){
                for(int i=0;i<5;i++){
                    if(path_collision[i]){
                        proper_idx = i;
                        break;  // 종료
                    }
                }
            }
            else{
                for(int j=0;j<5;j++){
                    if(path_collision[j]){
                        local_distance[j]=sqrt(pow(vehicle_state_.x + dx[j] - lookAhead_Pose_.pose.position.x,2) + pow(vehicle_state_.y + dy - lookAhead_Pose_.pose.position.y,2));
                    }
                    else{
                        local_distance[j]=1000;
                    }
                }
                find_lowcost_path();
            }
        }

        void publish_local_path(){
            if(proper_idx == 0){
                pub_pose_1.publish(path_1);
            }
            else if(proper_idx == 1){
                pub_pose_2.publish(path_2);
            }
            else if(proper_idx == 2){
                pub_pose_3.publish(path_3);
            }
            else if(proper_idx == 3){
                pub_pose_4.publish(path_4);
            }
            else{
                pub_pose_st.publish(straight_path);
            }
        }
        
        void Publish_Local(){
            if( (execute_cal == false) && Is_Callback_hurdle){
                check_collision();
                ROS_INFO_STREAM("PUBLISH");
            }
        }
};


int main(int argc, char **argv){

    ros::init(argc,argv,"pub_path");    
    pointPub pub;

    ros::Rate rate(20);

    while(ros::ok()){
        if(pub.Is_Callback_final_1 && pub.Is_Callback_final_2 && execute_cal){
            pub.offset_exam();
            execute_cal = false;
        }
        pub.Publish_Local();
        ros::spinOnce();
        rate.sleep();
    }
    // return 0;
}

