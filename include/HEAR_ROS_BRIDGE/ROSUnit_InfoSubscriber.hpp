#pragma once
#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "HEAR_msg/InfoMsg.hpp"
#include <hear_ros_bridge/Info.h>

class ROSUnit_InfoSubscriber : public ROSUnit {
private:  
    static Port* _output_port_0;
    ros::Subscriber _sub_info;
    static ROSUnit_InfoSubscriber* _instance_ptr;
    static InfoMsg info_msg; 
    static void callbackInfo(const hear_ros_bridge::Info& msg);
public:
    enum ports_id {OP_0};
    void process(DataMsg* t_msg, Port* t_port) {};
    ROSUnit_InfoSubscriber(ros::NodeHandle&);
    ~ROSUnit_InfoSubscriber();
};