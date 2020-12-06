#pragma once
#include "ros/ros.h"
#include <nav_msgs/Odometry.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/PointStamped.h>

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "HEAR_msg/Vector3DMsg.hpp"
#include "HEAR_core/Timer.hpp"

class ROSUnit_SLAM : public ROSUnit {
private:
    static ROSUnit_SLAM* _instance_ptr; 
    static tf2_ros::Buffer tf_Buffer;
    static tf2_ros::TransformListener tfListener;
    ros::Subscriber _sub_odometry;
    static Port* _output_port_0;
    static Port* _output_port_1;
    static void callbackOdom(const nav_msgs::Odometry::ConstPtr&);

public:
    ROSUnit_SLAM(ros::NodeHandle&);
    enum ports_id {OP_0_POS, OP_1_VEL};
    void process(DataMsg* t_msg, Port* t_port) {};
    ~ROSUnit_SLAM();
};