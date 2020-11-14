#include "HEAR_ROS_BRIDGE/ROSUnit_GeoVecPub.hpp"

ROSUnit_GeoVecPub::ROSUnit_GeoVecPub(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
    m_pub = t_main_handler.advertise<geometry_msgs::Vector3Stamped>(t_name, 1, true);
}

ROSUnit_GeoVecPub::~ROSUnit_GeoVecPub() {

}

void ROSUnit_GeoVecPub::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0) {
        Vector3DMsg* t_vec = (Vector3DMsg*) t_msg;
        geometry_msgs::Vector3Stamped t_point;
        t_point.header.frame_id = " ";
        t_point.header.seq = ++_seq;
        t_point.header.stamp = ros::Time::now();
        t_point.vector.x = t_vec->data.x;
        t_point.vector.y = t_vec->data.y;
        t_point.vector.z = t_vec->data.z;
        m_pub.publish(t_point);
    }
}