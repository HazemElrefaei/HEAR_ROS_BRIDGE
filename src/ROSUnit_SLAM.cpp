#include "HEAR_ROS_BRIDGE/ROSUnit_SLAM.hpp"

ROSUnit_SLAM* ROSUnit_SLAM::_instance_ptr = NULL;
tf2_ros::Buffer ROSUnit_SLAM::tf_Buffer;
Port* ROSUnit_SLAM::_output_port_0;
Port* ROSUnit_SLAM::_output_port_1;
tf2_ros::TransformListener ROSUnit_SLAM::tfListener(ROSUnit_SLAM::tf_Buffer);

ROSUnit_SLAM::ROSUnit_SLAM(ros::NodeHandle& t_main_handler): ROSUnit(t_main_handler){
    _sub_odometry = t_main_handler.subscribe<nav_msgs::Odometry>("rtabmap/pose", 2, callbackOdom, ros::TransportHints().tcpNoDelay());
    _instance_ptr = this;
    _output_port_0 = new OutputPort(ports_id::OP_0_POS, this);
    _output_port_1 = new OutputPort(ports_id::OP_1_VEL, this);
    _ports = {_output_port_0, _output_port_1};
}

void ROSUnit_SLAM::callbackOdom(const nav_msgs::Odometry::ConstPtr& od_msg){
    Vector3DMsg pos_msg, vel_msg;
    Vector3D<float> pos_data, vel_data;
    geometry_msgs::PointStamped pos, tf_pos;
    geometry_msgs::Vector3Stamped vel, tf_vel;
    pos.header = od_msg->header;
    vel.header = od_msg->header;
    pos.point = (*od_msg).pose.pose.position;
    vel.vector = (*od_msg).twist.twist.linear;
    try{
        tf_Buffer.transform(pos, tf_pos, "map", ros::Duration(0.05));
    }
    catch (tf2::TransformException &ex) {
        ROS_WARN("Failure %s\n", ex.what()); //Print exception which was caught
    }
    try{
        tf_Buffer.transform(vel, tf_vel, "map", ros::Duration(0.05));
    }
    catch (tf2::TransformException &ex) {
        ROS_WARN("Failure %s\n", ex.what()); //Print exception which was caught
    }
    pos_data.x = tf_pos.point.x;
    pos_data.y = tf_pos.point.y;
    pos_data.z = tf_pos.point.z;

    vel_data.x = tf_vel.vector.x;
    vel_data.y = tf_vel.vector.y;
    vel_data.z = tf_vel.vector.z;

    pos_msg.data = pos_data;
    vel_msg.data = vel_data;

    _instance_ptr->_output_port_0->receiveMsgData(&pos_msg);
    _instance_ptr->_output_port_1->receiveMsgData(&vel_msg);

}
