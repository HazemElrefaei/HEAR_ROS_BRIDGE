cmake_minimum_required(VERSION 2.8.3)
project(hear_ros_bridge)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  hear_architecture
  hear_msgs
  geometry_msgs
  tf2_geometry_msgs
  tf2_ros
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS
    hear_msgs
    roscpp
    geometry_msgs
    tf2_geometry_msgs
    tf2_ros
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

FILE(GLOB SOURCE_FILES
        src/*.cpp)

add_library(${PROJECT_NAME}
${SOURCE_FILES}
)

add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})

