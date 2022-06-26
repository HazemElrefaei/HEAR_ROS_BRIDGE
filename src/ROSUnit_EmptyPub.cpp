#include "HEAR_ROS_BRIDGE/ROSUnit_EmptyPub.hpp"

ROSUnit_EmptyPub::ROSUnit_EmptyPub(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler)
{
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
    m_pub = t_main_handler.advertise<std_msgs::Empty>(t_name, 1, true);
}

ROSUnit_EmptyPub::~ROSUnit_EmptyPub() {

}

void ROSUnit_EmptyPub::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0)
    {   
        std_msgs::Empty myMsg;
        rate = ((DoubleMsg*) t_msg)->data;
        ros::Rate loop_rate(rate);
        m_pub.publish(myMsg);
    }
}