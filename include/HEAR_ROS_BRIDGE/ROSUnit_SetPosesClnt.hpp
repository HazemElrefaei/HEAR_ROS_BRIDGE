#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <hear_msgs/Pose.h>
#include <hear_msgs/set_poses.h>
#include "HEAR_msg/PosesMsg.hpp"

class ROSUnit_SetPosesClnt : public ROSUnit {
    public:
        enum ports_id {IP_0};
        void process(DataMsg* t_msg, Port* t_port);
        ROSUnit_SetPosesClnt(std::string, ros::NodeHandle&);
        ~ROSUnit_SetPosesClnt();
    private:
        Port* _input_port_0;
        ros::ServiceClient m_client;
};