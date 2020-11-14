#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "std_msgs/Float32MultiArray.h"
#include "HEAR_msg/FloatArrayMsg.hpp"

class ROSUnit_FloatsPub : public ROSUnit
{
    public:

        enum ports_id {IP_0};
        void process(DataMsg* t_msg, Port* t_port);
        ROSUnit_FloatsPub(std::string, ros::NodeHandle&);
        ~ROSUnit_FloatsPub();

    private:
        Port* _input_port_0;
        ros::Publisher m_pub;
};