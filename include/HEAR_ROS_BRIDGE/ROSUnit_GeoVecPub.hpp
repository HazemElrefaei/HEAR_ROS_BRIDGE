#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "geometry_msgs/Vector3Stamped.h"
#include "HEAR_msg/Vector3DMsg.hpp"
class ROSUnit_GeoVecPub : public ROSUnit {
public:
    enum ports_id {IP_0};
    void process(DataMsg* t_msg, Port* t_port);
    ROSUnit_GeoVecPub(std::string, ros::NodeHandle&);
    ~ROSUnit_GeoVecPub();

private:
    uint32_t _seq = 0;
    Port* _input_port_0;
    ros::Publisher m_pub;
};