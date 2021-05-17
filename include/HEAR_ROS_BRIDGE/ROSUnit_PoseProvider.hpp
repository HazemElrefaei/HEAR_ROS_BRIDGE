#pragma once
#include "ros/ros.h"
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/QuaternionStamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Quaternion.h>

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "HEAR_msg/Vector3DMsg.hpp"
#include "HEAR_msg/FloatMsg.hpp"
#include <hear_msgs/set_float.h>
#include "HEAR_core/Timer.hpp"
#include "HEAR_math/ButterFilter_2nd.hpp"

class ROSUnit_PoseProvider: public ROSUnit{
private:
    ros::Subscriber opti_sub, xsens_ori_sub, xsens_ang_vel_sub, xsens_free_acc_sub;  
    ros::ServiceServer m_server;
    
    static ROSUnit_PoseProvider* _instance_ptr;
    static Port* _output_port_0;
    static Port* _output_port_1;
    static Port* _output_port_2;
    static Port* _output_port_3;
    static Port* _output_port_4;
    static void callback_opti_pose(const geometry_msgs::PoseStamped::ConstPtr& );
    static void callback_ori(const geometry_msgs::QuaternionStamped::ConstPtr& );
    static void callback_free_acc(const geometry_msgs::Vector3Stamped::ConstPtr& );
    static void callback_angular_vel(const geometry_msgs::Vector3Stamped::ConstPtr&);
    static bool srv_callback(hear_msgs::set_float::Request&, hear_msgs::set_float::Response&);
    static tf2::Matrix3x3 rot_offset;
    static tf2::Vector3 trans_offset;

public:
    enum ports_id {OP_0_POS, OP_1_ORI_OPTI, OP_2_ORI_IMU, OP_3_BODY_RATE, OP_4_FREE_ACCELERATION};
    void process(DataMsg* t_msg, Port* t_port){};
    ROSUnit_PoseProvider(ros::NodeHandle&);
    ~ROSUnit_PoseProvider();

};