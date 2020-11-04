#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "std_srvs/Empty.h"
#include "HEAR_msg/EmptyMsg.hpp"

class ROSUnit_EmptyClnt : public ROSUnit {
    public:
        enum ports_id {IP_0};
        ROSUnit_EmptyClnt(std::string, ros::NodeHandle&);
        ~ROSUnit_EmptyClnt();
        void process(DataMsg* t_msg, Port* t_port);
    private:
        Port* _input_port_0;
        ros::ServiceClient m_client;
};