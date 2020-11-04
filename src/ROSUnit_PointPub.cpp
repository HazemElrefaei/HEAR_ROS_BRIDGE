#include "HEAR_ROS_BRIDGE/ROSUnit_PointPub.hpp"

ROSUnit_PointPub::ROSUnit_PointPub(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
    m_pub = t_main_handler.advertise<geometry_msgs::Point>(t_name, 1, true);
}

ROSUnit_PointPub::~ROSUnit_PointPub() {

}

void ROSUnit_PointPub::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0) {
        Vector3DMsg* t_vec = (Vector3DMsg*) t_msg;
        geometry_msgs::Point t_point;
        t_point.x = t_vec->data.x;
        t_point.y = t_vec->data.y;
        t_point.z = t_vec->data.z;
        m_pub.publish(t_point);
    }
}