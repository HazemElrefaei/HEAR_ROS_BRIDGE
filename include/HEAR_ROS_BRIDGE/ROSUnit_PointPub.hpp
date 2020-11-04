#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "geometry_msgs/Point.h"
#include "HEAR_msg/Vector3DMsg.hpp"
class ROSUnit_PointPub : public ROSUnit {
public:
    enum ports_id {IP_0};
    void process(DataMsg* t_msg, Port* t_port);
    ROSUnit_PointPub(std::string, ros::NodeHandle&);
    ~ROSUnit_PointPub();

private:
    Port* _input_port_0;
    ros::Publisher m_pub;
};