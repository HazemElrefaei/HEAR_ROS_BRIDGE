#include "HEAR_ROS_BRIDGE/ROSUnit_SetInt8Clnt.hpp"

ROSUnit_SetInt8Clnt::ROSUnit_SetInt8Clnt(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
    m_client = t_main_handler.serviceClient<hear_msgs::set_int8>(t_name);
}

ROSUnit_SetInt8Clnt::~ROSUnit_SetInt8Clnt() {

}

void ROSUnit_SetInt8Clnt::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0) {
        hear_msgs::set_int8 t_srv;
        Int8Msg* t_vector = (Int8Msg*) t_msg;
        t_srv.request.data = t_vector->data;
        if(m_client.call(t_srv)) {
            //TODO: add success condition
        }
        else {
            //TODO: add error
        }
    }
}