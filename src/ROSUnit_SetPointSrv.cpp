#include "HEAR_ROS_BRIDGE/ROSUnit_SetPointSrv.hpp"

ROSUnit_SetPointSrv* ROSUnit_SetPointSrv::m_ptr[ROSUnit_capacity];
int ROSUnit_SetPointSrv::internal_counter=0;

bool(*ROSUnit_SetPointSrv::callbackFunctionPointer[ROSUnit_capacity])(hear_ros_bridge::set_point::Request&, hear_ros_bridge::set_point::Response&){
  ROSUnit_SetPointSrv::srv_callback1,
  ROSUnit_SetPointSrv::srv_callback2,
  ROSUnit_SetPointSrv::srv_callback3,
  ROSUnit_SetPointSrv::srv_callback4,
  ROSUnit_SetPointSrv::srv_callback5
};

Port* ROSUnit_SetPointSrv::_output_port_0 = new OutputPort(ports_id::OP_0, NULL);
Port* ROSUnit_SetPointSrv::_output_port_1 = new OutputPort(ports_id::OP_1, NULL);
Port* ROSUnit_SetPointSrv::_output_port_2 = new OutputPort(ports_id::OP_2, NULL);
Port* ROSUnit_SetPointSrv::_output_port_3 = new OutputPort(ports_id::OP_3, NULL);
Port* ROSUnit_SetPointSrv::_output_port_4 = new OutputPort(ports_id::OP_4, NULL);

ROSUnit_SetPointSrv::ROSUnit_SetPointSrv(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    m_server = t_main_handler.advertiseService(t_name, ROSUnit_SetPointSrv::callbackFunctionPointer[internal_counter]);
    m_ptr[internal_counter] = this;
    internal_counter++;
    _ports = {_output_port_0, _output_port_1, _output_port_2, _output_port_3, _output_port_4};
}

ROSUnit_SetPointSrv::~ROSUnit_SetPointSrv() {

}

bool ROSUnit_SetPointSrv::srv_callback1(hear_ros_bridge::set_point::Request& req, hear_ros_bridge::set_point::Response& res) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = req.p.x;
    t_vec.y = req.p.y;
    t_vec.z = req.p.z;
    t_msg.data = t_vec;
    _output_port_0->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetPointSrv::srv_callback2(hear_ros_bridge::set_point::Request& req, hear_ros_bridge::set_point::Response& res) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = req.p.x;
    t_vec.y = req.p.y;
    t_vec.z = req.p.z;
    t_msg.data = t_vec;
    _output_port_1->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetPointSrv::srv_callback3(hear_ros_bridge::set_point::Request& req, hear_ros_bridge::set_point::Response& res) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = req.p.x;
    t_vec.y = req.p.y;
    t_vec.z = req.p.z;
    t_msg.data = t_vec;
    _output_port_2->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetPointSrv::srv_callback4(hear_ros_bridge::set_point::Request& req, hear_ros_bridge::set_point::Response& res) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = req.p.x;
    t_vec.y = req.p.y;
    t_vec.z = req.p.z;
    t_msg.data = t_vec;
    _output_port_3->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetPointSrv::srv_callback5(hear_ros_bridge::set_point::Request& req, hear_ros_bridge::set_point::Response& res) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = req.p.x;
    t_vec.y = req.p.y;
    t_vec.z = req.p.z;
    t_msg.data = t_vec;
    _output_port_4->receiveMsgData(&t_msg);
    return true;
}