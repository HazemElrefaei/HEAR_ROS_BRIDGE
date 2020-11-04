#include "HEAR_ROS_BRIDGE/ROSUnit_SetPoseClnt.hpp"

ROSUnit_SetPoseClnt::ROSUnit_SetPoseClnt(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
    m_client = t_main_handler.serviceClient<hear_msgs::set_pose>(t_name);
}

ROSUnit_SetPoseClnt::~ROSUnit_SetPoseClnt() {

}

void ROSUnit_SetPoseClnt::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0) {
        hear_msgs::set_pose t_srv;
        PoseMsg* t_poses = (PoseMsg*) t_msg;
        t_srv.request.pose.point.x = t_poses->pose.x;
        t_srv.request.pose.point.y = t_poses->pose.y;
        t_srv.request.pose.point.z = t_poses->pose.z;
        t_srv.request.pose.yaw.data = t_poses->pose.yaw;
        if(m_client.call(t_srv)) {
            //TODO: add success condition
        }
        else {
            //TODO: add error
        }
    }
}
