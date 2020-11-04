#include "HEAR_ROS_BRIDGE/ROSUnit_SetPoseSrv.hpp"

ROSUnit_SetPoseSrv* ROSUnit_SetPoseSrv::m_ptr[ROSUnit_capacity];
int ROSUnit_SetPoseSrv::internal_counter=0;

bool(*ROSUnit_SetPoseSrv::callbackFunctionPointer[ROSUnit_capacity])(hear_msgs::set_pose::Request&, hear_msgs::set_pose::Response&){
  ROSUnit_SetPoseSrv::srv_callback1,
  ROSUnit_SetPoseSrv::srv_callback2,
  ROSUnit_SetPoseSrv::srv_callback3,
  ROSUnit_SetPoseSrv::srv_callback4,
  ROSUnit_SetPoseSrv::srv_callback5
};

Port* ROSUnit_SetPoseSrv::_output_port_0 = new OutputPort(ports_id::OP_0, NULL);
Port* ROSUnit_SetPoseSrv::_output_port_1 = new OutputPort(ports_id::OP_1, NULL);
Port* ROSUnit_SetPoseSrv::_output_port_2 = new OutputPort(ports_id::OP_2, NULL);
Port* ROSUnit_SetPoseSrv::_output_port_3 = new OutputPort(ports_id::OP_3, NULL);
Port* ROSUnit_SetPoseSrv::_output_port_4 = new OutputPort(ports_id::OP_4, NULL);

ROSUnit_SetPoseSrv::ROSUnit_SetPoseSrv (std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    m_server = t_main_handler.advertiseService(t_name, ROSUnit_SetPoseSrv::callbackFunctionPointer[internal_counter]);
    m_ptr[internal_counter] = this;
    internal_counter++;
    _ports = {_output_port_0, _output_port_1, _output_port_2, _output_port_3, _output_port_4};
}

ROSUnit_SetPoseSrv::~ROSUnit_SetPoseSrv () {

}

bool ROSUnit_SetPoseSrv::srv_callback1(hear_msgs::set_pose::Request& req, hear_msgs::set_pose::Response& res) {
    PoseMsg t_msg;
    t_msg.pose.x = req.pose.point.x;
    t_msg.pose.y = req.pose.point.y;
    t_msg.pose.z = req.pose.point.z;
    t_msg.pose.yaw = req.pose.yaw.data;
    _output_port_0->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetPoseSrv::srv_callback2(hear_msgs::set_pose::Request& req, hear_msgs::set_pose::Response& res) {
    PoseMsg t_msg;
    t_msg.pose.x = req.pose.point.x;
    t_msg.pose.y = req.pose.point.y;
    t_msg.pose.z = req.pose.point.z;
    t_msg.pose.yaw = req.pose.yaw.data;
    _output_port_1->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetPoseSrv::srv_callback3(hear_msgs::set_pose::Request& req, hear_msgs::set_pose::Response& res) {
    PoseMsg t_msg;
    t_msg.pose.x = req.pose.point.x;
    t_msg.pose.y = req.pose.point.y;
    t_msg.pose.z = req.pose.point.z;
    t_msg.pose.yaw = req.pose.yaw.data;
    _output_port_2->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetPoseSrv::srv_callback4(hear_msgs::set_pose::Request& req, hear_msgs::set_pose::Response& res) {
    PoseMsg t_msg;
    t_msg.pose.x = req.pose.point.x;
    t_msg.pose.y = req.pose.point.y;
    t_msg.pose.z = req.pose.point.z;
    t_msg.pose.yaw = req.pose.yaw.data;
    _output_port_3->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetPoseSrv::srv_callback5(hear_msgs::set_pose::Request& req, hear_msgs::set_pose::Response& res) {
    PoseMsg t_msg;
    t_msg.pose.x = req.pose.point.x;
    t_msg.pose.y = req.pose.point.y;
    t_msg.pose.z = req.pose.point.z;
    t_msg.pose.yaw = req.pose.yaw.data;
    _output_port_4->receiveMsgData(&t_msg);
    return true;
}