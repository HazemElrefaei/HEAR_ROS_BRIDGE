#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <hear_msgs/PID_param.h>
#include <hear_msgs/MRFT_param.h>
#include <hear_msgs/BB_param.h>
#include <hear_msgs/Update_Controller_PID.h>
#include <hear_msgs/Update_Controller_MRFT.h>
#include <hear_msgs/Update_Controller_BB.h>
#include "HEAR_msg/ControllerMsg.hpp"

class ROSUnit_UpdateControllerClnt :  public ROSUnit{
private:
    control_system _id;
    ROSUnit_UpdateControllerClnt* _instance_ptr;
    ControllerMsg _update_controller_msg; 
    ros::ServiceClient m_client_pid_outer;
    ros::ServiceClient m_client_pid_inner;
    ros::ServiceClient m_client_mrft;
    ros::ServiceClient m_client_bb;
    Port* _input_port_0;
    Port* _input_port_1;
    Port* _input_port_2;
public:
    enum ports_id {IP_0_PID, IP_1_MRFT, IP_2_BB};
    void process(DataMsg* t_msg, Port* t_port);
    ROSUnit_UpdateControllerClnt(ros::NodeHandle&);
    ~ROSUnit_UpdateControllerClnt();
};