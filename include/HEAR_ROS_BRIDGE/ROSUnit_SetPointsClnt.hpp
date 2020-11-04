#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <geometry_msgs/Point.h>
#include <hear_ros_bridge/set_points.h>
#include "HEAR_msg/PointsMsg.hpp"

class ROSUnit_SetPointsClnt : public ROSUnit {
    public:
        enum ports_id {IP_0};
        void process(DataMsg* t_msg, Port* t_port);
        ROSUnit_SetPointsClnt(std::string, ros::NodeHandle&);
        ~ROSUnit_SetPointsClnt();
    private:
        Port* _input_port_0;
        ros::ServiceClient m_client;
};