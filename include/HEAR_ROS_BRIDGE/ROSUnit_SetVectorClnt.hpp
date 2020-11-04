#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <hear_msgs/set_vector.h>
#include "HEAR_msg/VectorMsg.hpp"

class ROSUnit_SetVectorClnt : public ROSUnit {
    public:
        enum ports_id {IP_0};
        void process(DataMsg* t_msg, Port* t_port);
        ROSUnit_SetVectorClnt(std::string, ros::NodeHandle&);
        ~ROSUnit_SetVectorClnt();
    private:
        Port* _input_port_0;
        ros::ServiceClient m_client;
};