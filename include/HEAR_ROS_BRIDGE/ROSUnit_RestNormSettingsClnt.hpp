#pragma once
#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "HEAR_msg/RestrictedNormRefSettingsMsg.hpp"
#include <hear_ros_bridge/Restricted_Norm_Settings.h>
class ROSUnit_RestNormSettingsClnt :  public ROSUnit{
    private:
        Port* _input_port_0;
        ros::ServiceClient _clnt_rest_norm_settings;
    public:
        enum ports_id {IP_0};
        void process(DataMsg* t_msg, Port* t_port);
        ROSUnit_RestNormSettingsClnt(ros::NodeHandle&);
        ~ROSUnit_RestNormSettingsClnt();
};