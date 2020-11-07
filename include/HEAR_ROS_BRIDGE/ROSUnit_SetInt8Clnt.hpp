#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <hear_msgs/set_int8.h>
#include "HEAR_msg/Int8Msg.hpp"

class ROSUnit_SetInt8Clnt : public ROSUnit{
    public:
        enum ports_id {IP_0};
        void process(DataMsg* t_msg, Port* t_port);
        ROSUnit_SetInt8Clnt(std::string, ros::NodeHandle&);
        ~ROSUnit_SetInt8Clnt();
    private:
        Port* _input_port_0;
        ros::ServiceClient m_client;
};