#include "HEAR_ROS_BRIDGE/ROSUnit_SetFloatSrv.hpp"

ROSUnit_SetFloatSrv* ROSUnit_SetFloatSrv::m_ptr[ROSUnit_capacity];
int ROSUnit_SetFloatSrv::internal_counter=0;

bool(*ROSUnit_SetFloatSrv::callbackFunctionPointer[ROSUnit_capacity])(hear_msgs::set_float::Request&, hear_msgs::set_float::Response&){
  ROSUnit_SetFloatSrv::srv_callback1,
  ROSUnit_SetFloatSrv::srv_callback2,
  ROSUnit_SetFloatSrv::srv_callback3,
  ROSUnit_SetFloatSrv::srv_callback4,
  ROSUnit_SetFloatSrv::srv_callback5
};

Port* ROSUnit_SetFloatSrv::_output_port_0 = new OutputPort(ports_id::OP_0, NULL);
Port* ROSUnit_SetFloatSrv::_output_port_1 = new OutputPort(ports_id::OP_1, NULL);
Port* ROSUnit_SetFloatSrv::_output_port_2 = new OutputPort(ports_id::OP_2, NULL);
Port* ROSUnit_SetFloatSrv::_output_port_3 = new OutputPort(ports_id::OP_3, NULL);
Port* ROSUnit_SetFloatSrv::_output_port_4 = new OutputPort(ports_id::OP_4, NULL);


ROSUnit_SetFloatSrv::ROSUnit_SetFloatSrv(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    m_server = t_main_handler.advertiseService(t_name, ROSUnit_SetFloatSrv::callbackFunctionPointer[internal_counter]);
    m_ptr[internal_counter] = this;
    internal_counter++;
    _ports = {_output_port_0, _output_port_1, _output_port_2, _output_port_3, _output_port_4};
}

ROSUnit_SetFloatSrv::~ROSUnit_SetFloatSrv() {

}

bool ROSUnit_SetFloatSrv::srv_callback1(hear_msgs::set_float::Request& req, hear_msgs::set_float::Response& res) {
    FloatMsg t_msg;
    t_msg.data = req.data;
    _output_port_0->receiveMsgData(&t_msg);
    return true;
}
bool ROSUnit_SetFloatSrv::srv_callback2(hear_msgs::set_float::Request& req, hear_msgs::set_float::Response& res) {
    FloatMsg t_msg;
    t_msg.data = req.data;
    _output_port_1->receiveMsgData(&t_msg);
    return true;
}
bool ROSUnit_SetFloatSrv::srv_callback3(hear_msgs::set_float::Request& req, hear_msgs::set_float::Response& res) {
    FloatMsg t_msg;
    t_msg.data = req.data;
    _output_port_2->receiveMsgData(&t_msg);
    return true;
}
bool ROSUnit_SetFloatSrv::srv_callback4(hear_msgs::set_float::Request& req, hear_msgs::set_float::Response& res) {
    FloatMsg t_msg;
    t_msg.data = req.data;
    _output_port_3->receiveMsgData(&t_msg);
    return true;
}
bool ROSUnit_SetFloatSrv::srv_callback5(hear_msgs::set_float::Request& req, hear_msgs::set_float::Response& res) {
    FloatMsg t_msg;
    t_msg.data = req.data;
    _output_port_4->receiveMsgData(&t_msg);
    return true;
}