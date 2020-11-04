#include "HEAR_ROS_BRIDGE/ROSUnit_SetPointClnt.hpp"

ROSUnit_SetPointClnt::ROSUnit_SetPointClnt(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
    m_client = t_main_handler.serviceClient<hear_msgs::set_point>(t_name);
}

ROSUnit_SetPointClnt::~ROSUnit_SetPointClnt() {

}

void ROSUnit_SetPointClnt::process(DataMsg* t_msg, Port* t_port) {
    //Change the below code to match your received msg
    if(t_port->getID() == ports_id::IP_0)     {
        hear_msgs::set_point t_srv;
        Vector3DMsg* t_vector = (Vector3DMsg*) t_msg;
        t_srv.request.p.x = t_vector->data.x;
        t_srv.request.p.y = t_vector->data.y;
        t_srv.request.p.z = t_vector->data.z;
        if(m_client.call(t_srv)) {
            //TODO: add success condition
        }
        else {
            //TODO: add error
        }
    }
}
