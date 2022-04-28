cmake_minimum_required(VERSION 2.8.3)
project(global_planning)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  message_runtime
  roscpp
  rospy
  std_msgs
  geometry_msgs
  nav_msgs
  tf
  tf2

)

# find_package(PCL 1.7 REQUIRED COMPONENTS common io)

catkin_package(
  INCLUDE_DIRS src
  CATKIN_DEPENDS 
    roscpp 
    rospy
    tf
    tf2 
    # tf2_ros
    # tf2_geometry_msgs
    nav_msgs
    geometry_msgs
    std_msgs
)

catkin_install_python(PROGRAMS src/Get_GPS.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
add_executable(${PROJECT_NAME} 
    src/control_kkanbu.cpp
)
add_dependencies(${PROJECT_NAME} 
    ${${PROJECT_NAME}_EXPORTED_TARGETS} 
    ${catkin_EXPORTED_TARGETS}
    kkanbu_msgs_generate_messages_cpp
)
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
