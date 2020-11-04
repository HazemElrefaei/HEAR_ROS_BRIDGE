#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <hear_msgs/set_int.h>
#include "HEAR_msg/IntegerMsg.hpp"

class ROSUnit_SetIntClnt : public ROSUnit{
    public:
        enum ports_id {IP_0};
        void process(DataMsg* t_msg, Port* t_port);
        ROSUnit_SetIntClnt(std::string, ros::NodeHandle&);
        ~ROSUnit_SetIntClnt();
    private:
        Port* _input_port_0;
        ros::ServiceClient m_client;
};