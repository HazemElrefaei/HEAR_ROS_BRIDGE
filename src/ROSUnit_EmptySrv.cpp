#include "HEAR_ROS_BRIDGE/ROSUnit_EmptySrv.hpp"

ROSUnit_EmptySrv* ROSUnit_EmptySrv::m_ptr[ROSUnit_capacity];
int ROSUnit_EmptySrv::internal_counter=0;

bool(*ROSUnit_EmptySrv::callbackFunctionPointer[ROSUnit_capacity])(std_srvs::Empty::Request&, std_srvs::Empty::Response&){
  ROSUnit_EmptySrv::srv_callback1,
  ROSUnit_EmptySrv::srv_callback2,
  ROSUnit_EmptySrv::srv_callback3,
  ROSUnit_EmptySrv::srv_callback4,
  ROSUnit_EmptySrv::srv_callback5
};

Port* ROSUnit_EmptySrv::_output_port_0 = new OutputPort(ports_id::OP_0, NULL);
Port* ROSUnit_EmptySrv::_output_port_1 = new OutputPort(ports_id::OP_1, NULL);
Port* ROSUnit_EmptySrv::_output_port_2 = new OutputPort(ports_id::OP_2, NULL);
Port* ROSUnit_EmptySrv::_output_port_3 = new OutputPort(ports_id::OP_3, NULL);
Port* ROSUnit_EmptySrv::_output_port_4 = new OutputPort(ports_id::OP_4, NULL);

ROSUnit_EmptySrv::ROSUnit_EmptySrv(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    m_server = t_main_handler.advertiseService(t_name, ROSUnit_EmptySrv::callbackFunctionPointer[internal_counter]);
    m_ptr[internal_counter] = this;
    internal_counter++;
    _ports = {_output_port_0, _output_port_1, _output_port_2, _output_port_3, _output_port_4};
}

ROSUnit_EmptySrv::~ROSUnit_EmptySrv() {

}

bool ROSUnit_EmptySrv::srv_callback1(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res) {
    EmptyMsg t_msg;
    _output_port_0->receiveMsgData(&t_msg);
    return true;
}
bool ROSUnit_EmptySrv::srv_callback2(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res) {
    EmptyMsg t_msg;
    _output_port_1->receiveMsgData(&t_msg);
    return true;
}
bool ROSUnit_EmptySrv::srv_callback3(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res) {
    EmptyMsg t_msg;
    _output_port_2->receiveMsgData(&t_msg);
    return true;
}
bool ROSUnit_EmptySrv::srv_callback4(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res) {
    EmptyMsg t_msg;
    _output_port_3->receiveMsgData(&t_msg);
    return true;
}
bool ROSUnit_EmptySrv::srv_callback5(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res) {
    EmptyMsg t_msg;
    _output_port_4->receiveMsgData(&t_msg);
    return true;
}