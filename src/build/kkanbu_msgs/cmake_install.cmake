# Install script for directory: /home/kkanbu/git/Kkanbu/src/kkanbu_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kkanbu_msgs/msg" TYPE FILE FILES
    "/home/kkanbu/git/Kkanbu/src/kkanbu_msgs/msg/ControlCommand.msg"
    "/home/kkanbu/git/Kkanbu/src/kkanbu_msgs/msg/VehicleState.msg"
    "/home/kkanbu/git/Kkanbu/src/kkanbu_msgs/msg/SensorPointArray.msg"
    "/home/kkanbu/git/Kkanbu/src/kkanbu_msgs/msg/SensorPoint.msg"
    "/home/kkanbu/git/Kkanbu/src/kkanbu_msgs/msg/C_Obstacle.msg"
    "/home/kkanbu/git/Kkanbu/src/kkanbu_msgs/msg/C_Obstacles.msg"
    "/home/kkanbu/git/Kkanbu/src/kkanbu_msgs/msg/current_state.msg"
    "/home/kkanbu/git/Kkanbu/src/kkanbu_msgs/msg/Obstacles.msg"
    "/home/kkanbu/git/Kkanbu/src/kkanbu_msgs/msg/SegmentObstacle.msg"
    "/home/kkanbu/git/Kkanbu/src/kkanbu_msgs/msg/CircleObstacle.msg"
    "/home/kkanbu/git/Kkanbu/src/kkanbu_msgs/msg/LandmarkPath.msg"
    "/home/kkanbu/git/Kkanbu/src/kkanbu_msgs/msg/LandmarkPoint.msg"
    "/home/kkanbu/git/Kkanbu/src/kkanbu_msgs/msg/LocalPathArray.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kkanbu_msgs/cmake" TYPE FILE FILES "/home/kkanbu/git/Kkanbu/src/build/kkanbu_msgs/catkin_generated/installspace/kkanbu_msgs-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/kkanbu/git/Kkanbu/src/build/devel/include/kkanbu_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/kkanbu/git/Kkanbu/src/build/devel/share/roseus/ros/kkanbu_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/kkanbu/git/Kkanbu/src/build/devel/share/common-lisp/ros/kkanbu_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/kkanbu/git/Kkanbu/src/build/devel/share/gennodejs/ros/kkanbu_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/kkanbu/git/Kkanbu/src/build/devel/lib/python2.7/dist-packages/kkanbu_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/kkanbu/git/Kkanbu/src/build/devel/lib/python2.7/dist-packages/kkanbu_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/kkanbu/git/Kkanbu/src/build/kkanbu_msgs/catkin_generated/installspace/kkanbu_msgs.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kkanbu_msgs/cmake" TYPE FILE FILES "/home/kkanbu/git/Kkanbu/src/build/kkanbu_msgs/catkin_generated/installspace/kkanbu_msgs-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kkanbu_msgs/cmake" TYPE FILE FILES
    "/home/kkanbu/git/Kkanbu/src/build/kkanbu_msgs/catkin_generated/installspace/kkanbu_msgsConfig.cmake"
    "/home/kkanbu/git/Kkanbu/src/build/kkanbu_msgs/catkin_generated/installspace/kkanbu_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kkanbu_msgs" TYPE FILE FILES "/home/kkanbu/git/Kkanbu/src/kkanbu_msgs/package.xml")
endif()

