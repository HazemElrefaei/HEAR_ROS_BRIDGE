#include "HEAR_ROS_BRIDGE/ROSUnit_SetBoolClnt.hpp"

ROSUnit_SetBoolClnt::ROSUnit_SetBoolClnt(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
    m_client = t_main_handler.serviceClient<hear_msgs::set_bool>(t_name);
}

ROSUnit_SetBoolClnt::~ROSUnit_SetBoolClnt() {

}

void ROSUnit_SetBoolClnt::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0)
    {
        hear_msgs::set_bool t_srv;
        t_srv.request.data = ((BoolMsg*) t_msg)->data;
        if(m_client.call(t_srv)) {
            //TODO: add success condition
        }
        else {
            //TODO: add error
        }
    }
}