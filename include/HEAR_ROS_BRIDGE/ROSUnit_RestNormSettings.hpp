#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "HEAR_msg/RestrictedNormRefSettingsMsg.hpp"
#include <hear_ros_bridge/Restricted_Norm_Settings.h>
#include "HEAR_math/Vector3D.hpp"
#include "HEAR_core/OutputPort.hpp"

class ROSUnit_RestNormSettings :  public ROSUnit{
private:
    static ROSUnit_RestNormSettings* _instance_ptr;
    static RestrictedNormRefSettingsMsg _settings_msg; 
    ros::ServiceServer _srv_rest_norm_settings;
    static bool callbackSettings(hear_ros_bridge::Restricted_Norm_Settings::Request  &req, 
                                    hear_ros_bridge::Restricted_Norm_Settings::Response &res);
    Port* _output_port;
public:
    enum ports_id {OP_0_DATA};
    void process(DataMsg* t_msg, Port* t_port);
    DataMsg* runTask(DataMsg*);
    void receiveMsgData(DataMsg* t_msg);  
    ROSUnit_RestNormSettings(ros::NodeHandle&);
    ~ROSUnit_RestNormSettings();
};