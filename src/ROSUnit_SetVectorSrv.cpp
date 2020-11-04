#include "HEAR_ROS_BRIDGE/ROSUnit_SetVectorSrv.hpp"

ROSUnit_SetVectorSrv* ROSUnit_SetVectorSrv::m_ptr[ROSUnit_capacity];
int ROSUnit_SetVectorSrv::internal_counter=0;


bool(*ROSUnit_SetVectorSrv::callbackFunctionPointer[ROSUnit_capacity])(hear_ros_bridge::set_vector::Request&, hear_ros_bridge::set_vector::Response&){
  ROSUnit_SetVectorSrv::srv_callback1,
  ROSUnit_SetVectorSrv::srv_callback2,
  ROSUnit_SetVectorSrv::srv_callback3,
  ROSUnit_SetVectorSrv::srv_callback4,
  ROSUnit_SetVectorSrv::srv_callback5
};

Port* ROSUnit_SetVectorSrv::_output_port_0 = new OutputPort(ports_id::OP_0, NULL);
Port* ROSUnit_SetVectorSrv::_output_port_1 = new OutputPort(ports_id::OP_1, NULL);
Port* ROSUnit_SetVectorSrv::_output_port_2 = new OutputPort(ports_id::OP_2, NULL);
Port* ROSUnit_SetVectorSrv::_output_port_3 = new OutputPort(ports_id::OP_3, NULL);
Port* ROSUnit_SetVectorSrv::_output_port_4 = new OutputPort(ports_id::OP_4, NULL);

ROSUnit_SetVectorSrv::ROSUnit_SetVectorSrv(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    m_server = t_main_handler.advertiseService(t_name, ROSUnit_SetVectorSrv::callbackFunctionPointer[internal_counter]);
    m_ptr[internal_counter] = this;
    internal_counter++;
    _ports = {_output_port_0, _output_port_1, _output_port_2, _output_port_3, _output_port_4};
}

ROSUnit_SetVectorSrv::~ROSUnit_SetVectorSrv() {

}

bool ROSUnit_SetVectorSrv::srv_callback1(hear_ros_bridge::set_vector::Request& req, hear_ros_bridge::set_vector::Response& res) {
    VectorMsg t_msg;
    t_msg.p1.x = req.p1.x;
    t_msg.p1.y = req.p1.y;
    t_msg.p1.z = req.p1.z;
    t_msg.p2.x = req.p2.x;
    t_msg.p2.y = req.p2.y;
    t_msg.p2.z = req.p2.z;
    _output_port_0->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetVectorSrv::srv_callback2(hear_ros_bridge::set_vector::Request& req, hear_ros_bridge::set_vector::Response& res) {
    VectorMsg t_msg;
    t_msg.p1.x = req.p1.x;
    t_msg.p1.y = req.p1.y;
    t_msg.p1.z = req.p1.z;
    t_msg.p2.x = req.p2.x;
    t_msg.p2.y = req.p2.y;
    t_msg.p2.z = req.p2.z;
    _output_port_1->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetVectorSrv::srv_callback3(hear_ros_bridge::set_vector::Request& req, hear_ros_bridge::set_vector::Response& res) {
    VectorMsg t_msg;
    t_msg.p1.x = req.p1.x;
    t_msg.p1.y = req.p1.y;
    t_msg.p1.z = req.p1.z;
    t_msg.p2.x = req.p2.x;
    t_msg.p2.y = req.p2.y;
    t_msg.p2.z = req.p2.z;
    _output_port_2->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetVectorSrv::srv_callback4(hear_ros_bridge::set_vector::Request& req, hear_ros_bridge::set_vector::Response& res) {
    VectorMsg t_msg;
    t_msg.p1.x = req.p1.x;
    t_msg.p1.y = req.p1.y;
    t_msg.p1.z = req.p1.z;
    t_msg.p2.x = req.p2.x;
    t_msg.p2.y = req.p2.y;
    t_msg.p2.z = req.p2.z;
    _output_port_3->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetVectorSrv::srv_callback5(hear_ros_bridge::set_vector::Request& req, hear_ros_bridge::set_vector::Response& res) {
    VectorMsg t_msg;
    t_msg.p1.x = req.p1.x;
    t_msg.p1.y = req.p1.y;
    t_msg.p1.z = req.p1.z;
    t_msg.p2.x = req.p2.x;
    t_msg.p2.y = req.p2.y;
    t_msg.p2.z = req.p2.z;
    _output_port_4->receiveMsgData(&t_msg);
    return true;
}