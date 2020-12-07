#pragma once
#include "ros/ros.h"
#include <nav_msgs/Odometry.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2/LinearMath/Quaternion.h>

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "HEAR_msg/BoolMsg.hpp"
#include "HEAR_msg/Vector3DMsg.hpp"
#include "HEAR_core/Timer.hpp"

#include <string>

class ROSUnit_SLAM : public ROSUnit {
private:
    static ROSUnit_SLAM* _instance_ptr; 
    static tf2_ros::Buffer tf_Buffer;
    static tf2_ros::TransformListener tfListener;
    static tf2_ros::StaticTransformBroadcaster static_broadcaster;
    ros::Subscriber _sub_odometry;
    static Port* _output_port_0;
    static Port* _output_port_1;
    static Port* _output_port_2;
    static void callbackOdom(const nav_msgs::Odometry::ConstPtr&);
    static std::string ref_frame;
    void pub_static_transform();
//    geometry_msgs::TransformStamped static_transformStamped;
    Vector3D<float> _position;
    Vector3D<float> _orientation;
    Port* _input_port_0;
    Port* _input_port_1;
    Port* _input_port_2;
    
public:
    ROSUnit_SLAM(ros::NodeHandle&);
    enum ports_id {OP_0_POS, OP_1_ORI, OP_2_VEL, IP_0_POS, IP_1_ORI, IP_2_TRIGGER};
    void process(DataMsg* t_msg, Port* t_port);
    ~ROSUnit_SLAM();
};