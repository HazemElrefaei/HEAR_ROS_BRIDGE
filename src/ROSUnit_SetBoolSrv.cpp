#include "HEAR_ROS_BRIDGE/ROSUnit_SetBoolSrv.hpp"

ROSUnit_SetBoolSrv* ROSUnit_SetBoolSrv::m_ptr[ROSUnit_capacity];
int ROSUnit_SetBoolSrv::internal_counter=0;

bool(*ROSUnit_SetBoolSrv::callbackFunctionPointer[ROSUnit_capacity])(hear_ros_bridge::set_bool::Request&, hear_ros_bridge::set_bool::Response&){
  ROSUnit_SetBoolSrv::srv_callback1,
  ROSUnit_SetBoolSrv::srv_callback2,
  ROSUnit_SetBoolSrv::srv_callback3,
  ROSUnit_SetBoolSrv::srv_callback4,
  ROSUnit_SetBoolSrv::srv_callback5
};

Port* ROSUnit_SetBoolSrv::_output_port_0 = new OutputPort(ports_id::OP_0, NULL);
Port* ROSUnit_SetBoolSrv::_output_port_1 = new OutputPort(ports_id::OP_1, NULL);
Port* ROSUnit_SetBoolSrv::_output_port_2 = new OutputPort(ports_id::OP_2, NULL);
Port* ROSUnit_SetBoolSrv::_output_port_3 = new OutputPort(ports_id::OP_3, NULL);
Port* ROSUnit_SetBoolSrv::_output_port_4 = new OutputPort(ports_id::OP_4, NULL);


ROSUnit_SetBoolSrv::ROSUnit_SetBoolSrv(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    m_server = t_main_handler.advertiseService(t_name, ROSUnit_SetBoolSrv::callbackFunctionPointer[internal_counter]);
    m_ptr[internal_counter] = this;
    internal_counter++;
    _ports = {_output_port_0, _output_port_1, _output_port_2, _output_port_3, _output_port_4};
}

ROSUnit_SetBoolSrv::~ROSUnit_SetBoolSrv() {

}

bool ROSUnit_SetBoolSrv::srv_callback1(hear_ros_bridge::set_bool::Request& req, hear_ros_bridge::set_bool::Response& res) {
    BoolMsg t_msg;
    t_msg.data = req.data;
    _output_port_0->receiveMsgData(&t_msg);
    return true;
}
bool ROSUnit_SetBoolSrv::srv_callback2(hear_ros_bridge::set_bool::Request& req, hear_ros_bridge::set_bool::Response& res) {
    BoolMsg t_msg;
    t_msg.data = req.data;
    _output_port_1->receiveMsgData(&t_msg);
    return true;
}
bool ROSUnit_SetBoolSrv::srv_callback3(hear_ros_bridge::set_bool::Request& req, hear_ros_bridge::set_bool::Response& res) {
    BoolMsg t_msg;
    t_msg.data = req.data;
    _output_port_2->receiveMsgData(&t_msg);
    return true;
}
bool ROSUnit_SetBoolSrv::srv_callback4(hear_ros_bridge::set_bool::Request& req, hear_ros_bridge::set_bool::Response& res) {
    BoolMsg t_msg;
    t_msg.data = req.data;
    _output_port_3->receiveMsgData(&t_msg);
    return true;
}
bool ROSUnit_SetBoolSrv::srv_callback5(hear_ros_bridge::set_bool::Request& req, hear_ros_bridge::set_bool::Response& res) {
    BoolMsg t_msg;
    t_msg.data = req.data;
    _output_port_4->receiveMsgData(&t_msg);
    return true;
}