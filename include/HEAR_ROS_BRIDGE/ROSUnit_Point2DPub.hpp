#pragma once

#include <hear_ros_bridge/Point2D.h>
#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "HEAR_msg/Vector2DMsg.hpp"

class ROSUnit_Point2DPub : public ROSUnit {
public:
    enum ports_id {IP_0};
    void process(DataMsg* t_msg, Port* t_port);
    ROSUnit_Point2DPub(std::string, ros::NodeHandle&);
    ~ROSUnit_Point2DPub();
private:
    Port* _input_port_0;
    ros::Publisher m_pub;
};