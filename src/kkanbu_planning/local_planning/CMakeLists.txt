cmake_minimum_required(VERSION 2.8.3)
project(local_planning)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++14)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  message_generation
  message_runtime
  nav_msgs
  roscpp
  rospy
  kkanbu_msgs
  std_msgs
  tf
  tf2
)

## System dependencies are found with CMake's conventions
find_package(Boost REQUIRED COMPONENTS system)

catkin_package(
  # INCLUDE_DIRS include
  # LIBRARIES local_planning
  # CATKIN_DEPENDS message_generation roscpp std_msgs
  # DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} 
    src/pub_index.cpp
    src/pub_path.cpp
)

add_dependencies(${PROJECT_NAME} 
    ${${PROJECT_NAME}_EXPORTED_TARGETS} 
    ${catkin_EXPORTED_TARGETS}
    kkanbu_msgs_generate_messages_cpp
)

target_link_libraries(${PROJECT_NAME}
    ${catkin_LIBRARIES}
)
