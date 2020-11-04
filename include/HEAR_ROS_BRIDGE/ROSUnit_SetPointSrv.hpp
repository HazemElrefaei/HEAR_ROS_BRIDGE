#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <hear_msgs/set_point.h>
#include "HEAR_msg/Vector3DMsg.hpp"
class ROSUnit_SetPointSrv : public ROSUnit {
public:
    enum ports_id {OP_0, OP_1, OP_2, OP_3, OP_4};
    void process(DataMsg* t_msg, Port* t_port) {};
    ROSUnit_SetPointSrv(std::string, ros::NodeHandle&);
    ~ROSUnit_SetPointSrv();
private:
    static Port* _output_port_0;
    static Port* _output_port_1;
    static Port* _output_port_2;
    static Port* _output_port_3;
    static Port* _output_port_4;
    ros::ServiceServer m_server;
    static int internal_counter;
    static ROSUnit_SetPointSrv* m_ptr[ROSUnit_capacity];
    //Change the srv_callback code to reflect your system
    static bool(*callbackFunctionPointer[ROSUnit_capacity])(hear_msgs::set_point::Request&, hear_msgs::set_point::Response&);
    static bool srv_callback1(hear_msgs::set_point::Request&, hear_msgs::set_point::Response&);//TODO refactor through templates
    static bool srv_callback2(hear_msgs::set_point::Request&, hear_msgs::set_point::Response&);
    static bool srv_callback3(hear_msgs::set_point::Request&, hear_msgs::set_point::Response&);
    static bool srv_callback4(hear_msgs::set_point::Request&, hear_msgs::set_point::Response&);
    static bool srv_callback5(hear_msgs::set_point::Request&, hear_msgs::set_point::Response&);
};