#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <hear_msgs/set_int.h>
#include "HEAR_msg/IntegerMsg.hpp"

class ROSUnit_SetIntSrv : public ROSUnit {
public:
        enum ports_id {OP_0, OP_1, OP_2, OP_3, OP_4, 
                        OP_5, OP_6, OP_7, OP_8, OP_9,
                        OP_10, OP_11, OP_12, OP_13, OP_14};
        void process(DataMsg* t_msg, Port* t_port) {};
        ROSUnit_SetIntSrv(std::string, ros::NodeHandle&);
        ~ROSUnit_SetIntSrv();
private:
    static Port* _output_port_0;
    static Port* _output_port_1;
    static Port* _output_port_2;
    static Port* _output_port_3;
    static Port* _output_port_4;
    static Port* _output_port_5;
    static Port* _output_port_6;
    static Port* _output_port_7;
    static Port* _output_port_8;
    static Port* _output_port_9;
    static Port* _output_port_10;
    static Port* _output_port_11;
    static Port* _output_port_12;
    static Port* _output_port_13;
    static Port* _output_port_14;
    ros::ServiceServer m_server;
    static int internal_counter;
    static ROSUnit_SetIntSrv* m_ptr[ROSUnit_capacity];
    static bool(*callbackFunctionPointer[ROSUnit_capacity])(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);
    static bool srv_callback1(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);//TODO refactor through templates
    static bool srv_callback2(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);
    static bool srv_callback3(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);
    static bool srv_callback4(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);
    static bool srv_callback5(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);
    static bool srv_callback6(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);
    static bool srv_callback7(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);
    static bool srv_callback8(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);
    static bool srv_callback9(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);
    static bool srv_callback10(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);
    static bool srv_callback11(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);
    static bool srv_callback12(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);
    static bool srv_callback13(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);
    static bool srv_callback14(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);
    static bool srv_callback15(hear_msgs::set_int::Request&, hear_msgs::set_int::Response&);

};