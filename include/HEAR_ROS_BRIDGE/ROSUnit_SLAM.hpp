#pragma once
#include "ros/ros.h"
#include <tf2_ros/static_transform_broadcaster.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/TransformStamped.h>

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "HEAR_msg/BoolMsg.hpp"
#include "HEAR_msg/Vector3DMsg.hpp"
#include "HEAR_core/Timer.hpp"

#include <string>

class ROSUnit_SLAM : public ROSUnit {
private:
    static ROSUnit_SLAM* _instance_ptr; 
    ros::Subscriber _sub_pos;
    ros::Subscriber _sub_vel;
    ros::Subscriber _sub_ori;
    ros::Publisher _pub_ref_frame;

    static Port* _output_port_0;
    static Port* _output_port_1;
    static Port* _output_port_2;
    static void callbackPos(const geometry_msgs::PointStamped::ConstPtr&);
    static void callbackVel(const geometry_msgs::Vector3Stamped::ConstPtr&);
    static void callbackOri(const geometry_msgs::PointStamped::ConstPtr&);

    std::string ref_frame = "map";
    void pub_static_transform();
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