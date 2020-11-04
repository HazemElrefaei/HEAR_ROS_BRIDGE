#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <hear_ros_bridge/PID_param.h>
#include <hear_ros_bridge/MRFT_param.h>
#include <hear_ros_bridge/BB_param.h>
#include <hear_ros_bridge/Update_Controller_PID.h>
#include <hear_ros_bridge/Update_Controller_MRFT.h>
#include <hear_ros_bridge/Update_Controller_BB.h>
#include "HEAR_msg/ControllerMsg.hpp"

class ROSUnit_UpdateController :  public ROSUnit{
private:
    static control_system _id;
    static ROSUnit_UpdateController* _instance_ptr;
    static ControllerMsg _update_controller_msg; 
    ros::ServiceServer _srv_update_controller_pid;
    ros::ServiceServer _srv_update_controller_mrft;
    ros::ServiceServer _srv_update_controller_sm;

    static bool callbackUpdateControllerPID(hear_ros_bridge::Update_Controller_PID::Request  &req, 
                                            hear_ros_bridge::Update_Controller_PID::Response &res);
    static bool callbackUpdateControllerMRFT(hear_ros_bridge::Update_Controller_MRFT::Request  &req, 
                                            hear_ros_bridge::Update_Controller_MRFT::Response &res);
    static bool callbackUpdateControllerSM(hear_ros_bridge::Update_Controller_BB::Request  &req, 
                                            hear_ros_bridge::Update_Controller_BB::Response &res);
    static Port* _output_port_0;
    static Port* _output_port_1;
    static Port* _output_port_2;
public:
    enum ports_id {OP_0_PID, OP_1_MRFT, OP_2_BB};
    void process(DataMsg* t_msg, Port* t_port) {};
    // enum unicast_addresses {broadcast, pid, mrft, sm};
    ROSUnit_UpdateController(ros::NodeHandle&);
    ~ROSUnit_UpdateController();
};