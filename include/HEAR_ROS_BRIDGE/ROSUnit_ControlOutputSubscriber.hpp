#pragma once

#include <std_msgs/Float64MultiArray.h>
#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "HEAR_msg/VectorDoubleMsg.hpp"

class ROSUnit_ControlOutputSubscriber : public ROSUnit{
private:
    static Port* _output_port_0;
    ros::Subscriber _sub_controloutput;
    static ROSUnit_ControlOutputSubscriber* _instance_ptr;
    static void callbackControlOutput(const std_msgs::Float64MultiArray& msg);
public:
    enum ports_id {OP_0};
    void process(DataMsg* t_msg, Port* t_port) {};
    ROSUnit_ControlOutputSubscriber(ros::NodeHandle&);
    ~ROSUnit_ControlOutputSubscriber();
};