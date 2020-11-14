#include "HEAR_ROS_BRIDGE/ROSUnit_FloatsPub.hpp"

ROSUnit_FloatsPub::ROSUnit_FloatsPub(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler)
{
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
    m_pub = t_main_handler.advertise<std_msgs::Float32MultiArray>(t_name, 1, true);
}

ROSUnit_FloatsPub::~ROSUnit_FloatsPub() {

}

void ROSUnit_FloatsPub::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0)
    {
        std_msgs::Float32MultiArray t_data;
        t_data.data = ((FloatArrayMsg*) t_msg)->data;
        m_pub.publish(t_data);
    }
}