#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <hear_ros_bridge/set_bool.h>
#include "HEAR_msg/BoolMsg.hpp"

class ROSUnit_SetBoolSrv : public ROSUnit {
public:
    enum ports_id {OP_0, OP_1, OP_2, OP_3, OP_4};
    void process(DataMsg* t_msg, Port* t_port) {};
    ROSUnit_SetBoolSrv(std::string, ros::NodeHandle&);
    ~ROSUnit_SetBoolSrv();
private:
    static Port* _output_port_0;
    static Port* _output_port_1;
    static Port* _output_port_2;
    static Port* _output_port_3;
    static Port* _output_port_4;
    ros::ServiceServer m_server;
    static int internal_counter;
    static ROSUnit_SetBoolSrv* m_ptr[ROSUnit_capacity];
    static bool(*callbackFunctionPointer[ROSUnit_capacity])(hear_ros_bridge::set_bool::Request&, hear_ros_bridge::set_bool::Response&);
    static bool srv_callback1(hear_ros_bridge::set_bool::Request&, hear_ros_bridge::set_bool::Response&);//TODO refactor through templates
    static bool srv_callback2(hear_ros_bridge::set_bool::Request&, hear_ros_bridge::set_bool::Response&);
    static bool srv_callback3(hear_ros_bridge::set_bool::Request&, hear_ros_bridge::set_bool::Response&);
    static bool srv_callback4(hear_ros_bridge::set_bool::Request&, hear_ros_bridge::set_bool::Response&);
    static bool srv_callback5(hear_ros_bridge::set_bool::Request&, hear_ros_bridge::set_bool::Response&);
};