#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <hear_ros_bridge/set_pose.h>
#include "HEAR_msg/PoseMsg.hpp"

class ROSUnit_SetPoseClnt : public ROSUnit {
    public:
        enum ports_id {IP_0};
        void process(DataMsg* t_msg, Port* t_port);
        ROSUnit_SetPoseClnt(std::string, ros::NodeHandle&);
        ~ROSUnit_SetPoseClnt();
    private:
        Port* _input_port_0;
        ros::ServiceClient m_client;
};