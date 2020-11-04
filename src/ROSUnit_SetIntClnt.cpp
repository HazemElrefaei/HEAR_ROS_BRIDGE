#include "HEAR_ROS_BRIDGE/ROSUnit_SetIntClnt.hpp"

ROSUnit_SetIntClnt::ROSUnit_SetIntClnt(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
    m_client = t_main_handler.serviceClient<hear_msgs::set_int>(t_name);
}

ROSUnit_SetIntClnt::~ROSUnit_SetIntClnt() {

}

void ROSUnit_SetIntClnt::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0)
    {
        hear_msgs::set_int t_srv;
        IntegerMsg* t_vector = (IntegerMsg*) t_msg;
        t_srv.request.data = t_vector->data;
        if(m_client.call(t_srv)) {
            //TODO: add success condition
        }
        else {
            //TODO: add error
        }
    }
}