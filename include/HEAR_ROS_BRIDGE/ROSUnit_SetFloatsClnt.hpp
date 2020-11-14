#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <hear_msgs/set_floats.h>
#include "HEAR_msg/FloatArrayMsg.hpp"

class ROSUnit_SetFloatsClnt : public ROSUnit {
    public:
        enum ports_id {IP_0};
        void process(DataMsg* t_msg, Port* t_port);
        ROSUnit_SetFloatsClnt(std::string, ros::NodeHandle&);
        ~ROSUnit_SetFloatsClnt();
    private:
        Port* _input_port_0;
        ros::ServiceClient m_client;
};