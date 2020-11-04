#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "std_srvs/Empty.h"
#include "HEAR_msg/EmptyMsg.hpp"

class ROSUnit_EmptySrv : public ROSUnit {
    public:
        enum ports_id {OP_0, OP_1, OP_2, OP_3, OP_4};
        ROSUnit_EmptySrv(std::string, ros::NodeHandle&);
        ~ROSUnit_EmptySrv();
        void process(DataMsg* t_msg, Port* t_port) {};
    private:
    static Port* _output_port_0;
    static Port* _output_port_1;
    static Port* _output_port_2;
    static Port* _output_port_3;
    static Port* _output_port_4;
    ros::ServiceServer m_server;
    static int internal_counter;
    static ROSUnit_EmptySrv* m_ptr[ROSUnit_capacity];
    static bool(*callbackFunctionPointer[ROSUnit_capacity])(std_srvs::Empty::Request&, std_srvs::Empty::Response&);
    static bool srv_callback1(std_srvs::Empty::Request&, std_srvs::Empty::Response&);//TODO refactor through templates
    static bool srv_callback2(std_srvs::Empty::Request&, std_srvs::Empty::Response&);
    static bool srv_callback3(std_srvs::Empty::Request&, std_srvs::Empty::Response&);
    static bool srv_callback4(std_srvs::Empty::Request&, std_srvs::Empty::Response&);
    static bool srv_callback5(std_srvs::Empty::Request&, std_srvs::Empty::Response&);

};