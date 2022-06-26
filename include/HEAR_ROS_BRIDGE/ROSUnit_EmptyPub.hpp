#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "std_msgs/Empty.h"
#include "HEAR_msg/DoubleMsg.hpp"

class ROSUnit_EmptyPub : public ROSUnit
{
    public:
        double rate;
        enum ports_id {IP_0};
        void process(DataMsg* t_msg, Port* t_port);
        ROSUnit_EmptyPub(std::string, ros::NodeHandle&);
        ~ROSUnit_EmptyPub();

    private:
        Port* _input_port_0;
        ros::Publisher m_pub;
};