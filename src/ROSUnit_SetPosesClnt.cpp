#include "HEAR_ROS_BRIDGE/ROSUnit_SetPosesClnt.hpp"

ROSUnit_SetPosesClnt::ROSUnit_SetPosesClnt(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _input_port_0 = new InputPort(ports_id::IP_0, this);
    _ports = {_input_port_0};
    m_client = t_main_handler.serviceClient<hear_msgs::set_poses>(t_name);
}

ROSUnit_SetPosesClnt::~ROSUnit_SetPosesClnt() {

}

void ROSUnit_SetPosesClnt::process(DataMsg* t_msg, Port* t_port) {
    if(t_port->getID() == ports_id::IP_0) {
        hear_msgs::set_poses t_srv;
        PosesMsg* t_poses = (PosesMsg*) t_msg;
        for(int i = 0; i < t_poses->p.poses.size(); i++) {
            hear_msgs::Pose t_pose;
            t_pose.point.x = t_poses->p.poses.at(i).x;
            t_pose.point.y = t_poses->p.poses.at(i).y;
            t_pose.point.z = t_poses->p.poses.at(i).z;
            t_pose.yaw.data = t_poses->p.poses.at(i).yaw;
            t_srv.request.poses.pose.push_back(t_pose);
            std::cout << " size, x, y, z, yaw: " << t_poses->p.poses.size() << ", " << t_pose.point.x << ", " << t_pose.point.y << ", " << t_pose.point.z << ", " << t_pose.yaw.data << "\n";
        }
        if(m_client.call(t_srv)) {
            //TODO: add success condition
        }
        else {
            //TODO: add error
        }
    }
}