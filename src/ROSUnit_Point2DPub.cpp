#include "HEAR_ROS_BRIDGE/ROSUnit_Point2DPub.hpp"

ROSUnit_Point2DPub::ROSUnit_Point2DPub(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
    m_pub = t_main_handler.advertise<hear_ros_bridge::Point2D>(t_name, 2, true);
}

ROSUnit_Point2DPub::~ROSUnit_Point2DPub() {

}

void ROSUnit_Point2DPub::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0)
    {
        Vector2DMsg* t_vec = (Vector2DMsg*) t_msg;
        hear_ros_bridge::Point2D t_point;
        t_point.x = t_vec->data.x;
        t_point.y = t_vec->data.y;
        m_pub.publish(t_point);
    }
}