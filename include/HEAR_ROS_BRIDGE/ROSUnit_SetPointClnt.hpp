#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "HEAR_msg/Vector3DMsg.hpp"
#include <hear_msgs/set_point.h>

class ROSUnit_SetPointClnt : public ROSUnit {
    public:
        enum ports_id {IP_0};
        void process(DataMsg* t_msg, Port* t_port);
        ROSUnit_SetPointClnt(std::string, ros::NodeHandle&);
        ~ROSUnit_SetPointClnt();
    private:
        Port* _input_port_0;
        ros::ServiceClient m_client;
};