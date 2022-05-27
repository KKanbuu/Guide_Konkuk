#include "get_wp.h"
// #include <ros/ros.h>

Entire_Path::Entire_Path(){
   
    //Publisher
    pub_entirepath = nh_.advertise<nav_msgs::Path>("/map/best_entire_path",10);
    // Subscriber
    sub_LandmarkPoint = nh_.subscribe("/map/landmark_point",10,&Entire_Path::Get_LandmarkPoint,this);
    //sub_dstPoint = nh_.subscribe("/map/dst_point",10,&Entire_Path::get_dstpoint,this);
}

Entire_Path::~Entire_Path(){}

void Entire_Path::Get_LandmarkPoint(const kkanbu_msgs::LandmarkPath msg) {
    landmark_point_ = msg;
    land_ = true;
     }
    
void Entire_Path::Save_Node(){
        int i=0;
        
        if(land_&&cnt<=54){
            while(i<landmark_point_.path.size()){
                Node_Info wp;
            wp.x= landmark_point_.path[i].x;
            wp.y=landmark_point_.path[i].y;
            wp.yaw=landmark_point_.path[i].yaw;
            wp.point_num = 0;
            node.push_back(wp);
            land_ = false;
            i++;
            cnt++;
             //cout<<"idx : "<< i << " "<<node[i].x<<" "<<node[i].y<<" "<< node[i].yaw<< '\n';
            }
        }
        //printf("Node Size : %d\n",node.size());       
}
// void Entire_Path::Get_startPoint(const kkanbu_msgs::LandmarkPath:ConstPtr& msg) {
//     start = *msg;
// }



// void Entire_Path::Get_dstPoint(const kkanbu_msgs::LandmarkPath:ConstPtr& msg) {
//     dst = *msg;
// }


void Entire_Path::Get_Graph(){
    if(node.size() > 0){
        for(int i=0; i<node.size();i++){
            for(int j=0; j<node.size();j++){
                if(i == j){
                    continue;
                }
                // cout << "wow1\n"; 
                float distance = sqrt(pow(node[i].x-node[j].x,2)+pow(node[i].y-node[j].y,2));
                // cout << "wow2\n";
                // cout << "my idx : " << i << " your idx : " << j << "\n";
                // cout << "distance : " << distance << "\n";
                if(distance>0.0&&distance<3.0){
                    // float cost= distance;
                    // cost=(int)round(cost);
                    // cout << "wow3\n";
                    graph[i].push_back({j,distance}); 
                    // cout << "wow4\n";
                    node[i].point_num = i;
                    // cout << "wow5\n";
                    // cout << " Distance is under 3m \n";
                     cout << "my idx : " << i << " your idx : " << j << "\n";
                     cout << "Distance : " << distance << "\n"; 
                    }   
                } 
        }
    }
}

void Entire_Path::Get_ShortestPath(int start, int dst){
    priority_queue<pair<int, int> > pq;
    // 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    pq.push({0, start});
    d[start] = 0;
    while (!node.empty()&&!pq.empty()&&pq.top().second==dst) { // 큐가 비어있지 않다면
        // 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        int dist = -pq.top().first; // 현재 노드까지의 비용 
        int now = pq.top().second; // 현재 노드
        pq.pop();
        
        float x= node[now].x;
        float y=node[now].y;
        float yaw=node[now].yaw;

        //shortest_path[x].push_back(y);

        pose.pose.position.x=x;
        pose.pose.position.y=y;
        pose.pose.position.z=0;

        q=tf::createQuaternionFromRPY(0,0,yaw);
        pose.pose.orientation.x=q[0];
        pose.pose.orientation.y=q[1];
        pose.pose.orientation.z=q[2];
        pose.pose.orientation.w=q[3];

        path.poses.push_back(pose);

       cout << pose.pose.position.x << " " <<pose.pose.position.y << '\n';
        // 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if (d[now] < dist) continue;
        // 현재 노드와 연결된 다른 인접한 노드들을 확인
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = dist + graph[now][i].second;
            // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

void Entire_Path::Publish_entirepath(){
    pub_entirepath.publish(path);
}

int main(int argc, char ** argv) {
    ros::init(argc,argv,"global_planner");
    // cout <<"misiion1";
    Entire_Path path_map;
    fill_n(path_map.d,1001,INF);
    ros::Rate loop_rate(20);
    //path_map.Save_Node();
    while (ros::ok()) {
        // printf("wow1\n");
        path_map.Save_Node();
        // cout << "wow2\n";
        path_map.Get_Graph();
        // path_map.Get_ShortestPath(0,70);
        // path_map.Publish_entirepath();
    
        ros::spinOnce();
        loop_rate.sleep();
    }

  return 0;
}