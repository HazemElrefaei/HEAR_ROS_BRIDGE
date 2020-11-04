#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <hear_ros_bridge/set_poses.h>
#include "HEAR_msg/PosesMsg.hpp"

class ROSUnit_SetPosesSrv : public ROSUnit {
public:
    enum ports_id {OP_0, OP_1, OP_2, OP_3, OP_4};
    void process(DataMsg* t_msg, Port* t_port) {};
    ROSUnit_SetPosesSrv(std::string, ros::NodeHandle&);
    ~ROSUnit_SetPosesSrv();
private:
    static Port* _output_port_0;
    static Port* _output_port_1;
    static Port* _output_port_2;
    static Port* _output_port_3;
    static Port* _output_port_4;
    ros::ServiceServer m_server;
    static int internal_counter;
    static ROSUnit_SetPosesSrv* m_ptr[ROSUnit_capacity];
    static bool(*callbackFunctionPointer[ROSUnit_capacity])(hear_ros_bridge::set_poses::Request&, hear_ros_bridge::set_poses::Response&);
    static bool srv_callback1(hear_ros_bridge::set_poses::Request&, hear_ros_bridge::set_poses::Response&);//TODO refactor through templates
    static bool srv_callback2(hear_ros_bridge::set_poses::Request&, hear_ros_bridge::set_poses::Response&);
    static bool srv_callback3(hear_ros_bridge::set_poses::Request&, hear_ros_bridge::set_poses::Response&);
    static bool srv_callback4(hear_ros_bridge::set_poses::Request&, hear_ros_bridge::set_poses::Response&);
    static bool srv_callback5(hear_ros_bridge::set_poses::Request&, hear_ros_bridge::set_poses::Response&);


};