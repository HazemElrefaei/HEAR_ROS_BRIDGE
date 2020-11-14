#include "HEAR_ROS_BRIDGE/ROSUnit_FloatPub.hpp"

ROSUnit_FloatPub::ROSUnit_FloatPub(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler)
{
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
    m_pub = t_main_handler.advertise<std_msgs::Float32>(t_name, 1, true);
}

ROSUnit_FloatPub::~ROSUnit_FloatPub() {

}

void ROSUnit_FloatPub::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0)
    {
        std_msgs::Float32 t_data;
        t_data.data = ((FloatMsg*) t_msg)->data;
        m_pub.publish(t_data);
    }
}