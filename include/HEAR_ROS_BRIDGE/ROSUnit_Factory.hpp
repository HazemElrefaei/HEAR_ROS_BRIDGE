#pragma once
#include "ros/ros.h"
#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_FloatPub.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_FloatSub.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_Point2DPub.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_Point2DSub.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_PointPub.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_PointSub.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_EmptyClnt.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_EmptySrv.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_SetFloatClnt.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_SetFloatSrv.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_SetIntClnt.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_SetIntSrv.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_SetPointClnt.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_SetPointsClnt.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_SetPointSrv.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_SetPointsSrv.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_SetPoseClnt.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_SetPosesClnt.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_SetPoseSrv.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_SetPosesSrv.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_SetVectorClnt.hpp"
#include "HEAR_ROS_BRIDGE/ROSUnit_SetVectorSrv.hpp"

#include <string>

enum ROSUnit_tx_rx_type {Client,Subscriber,Server,Publisher};
enum ROSUnit_msg_type {ROSUnit_Empty,ROSUnit_Float,ROSUnit_Int,ROSUnit_Point,ROSUnit_Points,ROSUnit_Pose,ROSUnit_Poses,ROSUnit_Vector,ROSUnit_Point2D};
class ROSUnit_Factory {
private:
    ros::NodeHandle nh;
    ROSUnit_Factory();
public:
    ROSUnit_Factory(ros::NodeHandle&);
    ROSUnit* CreateROSUnit(ROSUnit_tx_rx_type,ROSUnit_msg_type,std::string ROS_path);
};