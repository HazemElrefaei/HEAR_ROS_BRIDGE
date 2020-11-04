#include "HEAR_ROS_BRIDGE/ROSUnit_SetPointsClnt.hpp"

ROSUnit_SetPointsClnt::ROSUnit_SetPointsClnt(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
    m_client = t_main_handler.serviceClient<hear_msgs::set_points>(t_name);
}

ROSUnit_SetPointsClnt::~ROSUnit_SetPointsClnt() {

}

void ROSUnit_SetPointsClnt::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0) {
        hear_msgs::set_points t_srv;
        PointsMsg* t_points = (PointsMsg*) t_msg;
        for(int i = 0; i < t_points->points.size(); i++) {
            geometry_msgs::Point t_point;
            t_point.x =  t_points->points.at(i).x;
            t_point.y =  t_points->points.at(i).y;
            t_point.z =  t_points->points.at(i).z;
            t_srv.request.p.push_back(t_point);
        }
        if(m_client.call(t_srv)) {
            //TODO: add success condition
        }
        else {
            //TODO: add error
        }
    }
}