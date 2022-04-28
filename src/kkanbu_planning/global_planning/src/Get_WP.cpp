//header파일 선언

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
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int32.h>
#include <kkaknbu_msgs/LandmarkPoint.h>
#include <kkanbu_msgs/LandmarkPath.h>

#define INF 1e9    //무한에 해당하는 값을 10억으로 설정
using namespace std;

class Entire_Path {
    private: 
        ros::NodeHandle nh_;
        ros::Subscriber landmark_path_sub_;	//Get_GPS.py가 publish하는 landmark point path를 subscribe
		ros::Publisher best_entire_path_;

    public: 
            Entire_Path();
            ~Entire_Path();

            void Get_landmarkPoint(const kkanbu_msgs::LandmarkPath:ConstPtr& msg) {
                
            }

            //Get_landmarkPoint()로 얻은 그래프를 이용하여 A*알고리즘 적용 후 최단경로 생성
            void path_create(){

            }
            
            //path_create()로 생성한 경로를 publish
            void Pub_entirepath(){

            }

    private:
        float land_x, land_y;
        float edge_distance;//노드사이 거리
        float final_distance; //최종 목적지 거리 

        
};

int main(int argc, char * argv[]) {
    ros::init(argc,argv,"global_entire_path");
    Entire_Path path_map;
    ros::spin();
}