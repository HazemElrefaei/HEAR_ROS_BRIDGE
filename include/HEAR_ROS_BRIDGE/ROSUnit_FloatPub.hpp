#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "std_msgs/Float32.h"
//Change the msg type to match your received msg
#include "HEAR_msg/FloatMsg.hpp"

class ROSUnit_FloatPub : public ROSUnit
{
    public:

        enum ports_id {IP_0};
        void process(DataMsg* t_msg, Port* t_port);
        ROSUnit_FloatPub(std::string, ros::NodeHandle&);
        ~ROSUnit_FloatPub();
        //Change the receiveMsgData code to reflect your system
        //void receiveMsgData(DataMsg* t_msg);

    private:
        Port* _input_port_0;
        ros::Publisher m_pub;
};