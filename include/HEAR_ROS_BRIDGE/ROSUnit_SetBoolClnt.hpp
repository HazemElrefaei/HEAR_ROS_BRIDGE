#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <hear_msgs/set_bool.h>
#include "HEAR_msg/BoolMsg.hpp"

class ROSUnit_SetBoolClnt : public ROSUnit {
    public:
        enum ports_id {IP_0};
        void process(DataMsg* t_msg, Port* t_port);
        ROSUnit_SetBoolClnt(std::string, ros::NodeHandle&);
        ~ROSUnit_SetBoolClnt();
    private:
        Port* _input_port_0;
        ros::ServiceClient m_client;
};