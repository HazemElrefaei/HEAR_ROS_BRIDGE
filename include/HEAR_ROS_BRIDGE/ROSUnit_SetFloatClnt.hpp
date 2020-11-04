#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <hear_ros_bridge/set_float.h>
#include "HEAR_msg/FloatMsg.hpp"

class ROSUnit_SetFloatClnt : public ROSUnit {
    public:
        enum ports_id {IP_0};
        void process(DataMsg* t_msg, Port* t_port);
        ROSUnit_SetFloatClnt(std::string, ros::NodeHandle&);
        ~ROSUnit_SetFloatClnt();
    private:
        Port* _input_port_0;
        ros::ServiceClient m_client;
};