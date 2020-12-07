#include "HEAR_ROS_BRIDGE/ROSUnit_SLAM.hpp"

ROSUnit_SLAM* ROSUnit_SLAM::_instance_ptr = NULL;
tf2_ros::Buffer ROSUnit_SLAM::tf_Buffer;
Port* ROSUnit_SLAM::_output_port_0;
Port* ROSUnit_SLAM::_output_port_1;
Port* ROSUnit_SLAM::_output_port_2;
tf2_ros::TransformListener ROSUnit_SLAM::tfListener(ROSUnit_SLAM::tf_Buffer);
tf2_ros::StaticTransformBroadcaster ROSUnit_SLAM::static_broadcaster;
std::string ROSUnit_SLAM::ref_frame = "map";

ROSUnit_SLAM::ROSUnit_SLAM(ros::NodeHandle& t_main_handler): ROSUnit(t_main_handler){
    _sub_odometry = t_main_handler.subscribe<nav_msgs::Odometry>("rtabmap/pose", 2, callbackOdom, ros::TransportHints().tcpNoDelay());
    _instance_ptr = this;
    _output_port_0 = new OutputPort(ports_id::OP_0_POS, this);
    _output_port_1 = new OutputPort(ports_id::OP_1_ORI, this);
    _output_port_2 = new OutputPort(ports_id::OP_2_VEL, this);
    _input_port_0 = new InputPort(ports_id::IP_0_POS, this);
    _input_port_1 = new InputPort(ports_id::IP_1_ORI, this);
    _input_port_2 = new InputPort(ports_id::IP_2_TRIGGER, this);
    _ports = {_output_port_0, _output_port_1, _output_port_1, _input_port_0,_input_port_1, _input_port_2};
}

void ROSUnit_SLAM::callbackOdom(const nav_msgs::Odometry::ConstPtr& od_msg){
    Vector3DMsg pos_msg, vel_msg, ori_msg;
    Vector3D<float> pos_data, vel_data, ori_data;
    geometry_msgs::PoseStamped pos, tf_pos;
    geometry_msgs::Vector3Stamped vel, tf_vel;
    pos.header = od_msg->header;
    vel.header = od_msg->header;
    pos.pose = (*od_msg).pose.pose;
    vel.vector = (*od_msg).twist.twist.linear;
    try{
        tf_Buffer.transform(pos, tf_pos, ref_frame, ros::Duration(0.05));
    }
    catch (tf2::TransformException &ex) {
        ROS_WARN("Failure %s\n", ex.what()); //Print exception which was caught
    }
    try{
        tf_Buffer.transform(vel, tf_vel, ref_frame, ros::Duration(0.05));
    }
    catch (tf2::TransformException &ex) {
        ROS_WARN("Failure %s\n", ex.what()); //Print exception which was caught
    }
    pos_data.x = tf_pos.pose.position.x;
    pos_data.y = tf_pos.pose.position.y;
    pos_data.z = tf_pos.pose.position.z;

    tf2::Quaternion quat(tf_pos.pose.orientation.x, tf_pos.pose.orientation.y, tf_pos.pose.orientation.z, tf_pos.pose.orientation.w);
    tf2::Matrix3x3 mat(quat);
    tf2Scalar yaw, pitch, roll;
    mat.getRPY(roll, pitch, yaw);
    ori_data.x = (float)roll;
    ori_data.y = (float)pitch;
    ori_data.z = (float)yaw;

    vel_data.x = tf_vel.vector.x;
    vel_data.y = tf_vel.vector.y;
    vel_data.z = tf_vel.vector.z;

    pos_msg.data = pos_data;
    vel_msg.data = vel_data;
    ori_msg.data = ori_data;

    _instance_ptr->_output_port_0->receiveMsgData(&pos_msg);
    _instance_ptr->_output_port_1->receiveMsgData(&ori_msg);
    _instance_ptr->_output_port_2->receiveMsgData(&vel_msg);
}

void ROSUnit_SLAM::process(DataMsg* t_msg, Port* t_port){
    if(t_port->getID() == ports_id::IP_0_POS){
        this->_position = ((Vector3DMsg*)t_msg)->data;
    }
    else if(t_port->getID() == ports_id::IP_1_ORI){
        this->_orientation = ((Vector3DMsg*)t_msg)->data;
    }
    else if(t_port->getID() == ports_id::IP_2_TRIGGER){
        if (((BoolMsg*)t_msg)->data){
            this->pub_static_transform();
            ref_frame = "opti_frame";
        }
    }
}

void ROSUnit_SLAM::pub_static_transform(){
    geometry_msgs::TransformStamped static_transformStamped;
    static_transformStamped.header.stamp = ros::Time::now();
    static_transformStamped.header.frame_id = "opti_frame";
    static_transformStamped.child_frame_id = "map";
    static_transformStamped.transform.translation.x = this->_position.x;
    static_transformStamped.transform.translation.y = this->_position.y;
    static_transformStamped.transform.translation.z = this->_position.z;
    tf2::Quaternion quat;
    quat.setRPY(this->_orientation.x, this->_orientation.y, this->_orientation.z);
    static_transformStamped.transform.rotation.x = quat.x();
    static_transformStamped.transform.rotation.y = quat.y();
    static_transformStamped.transform.rotation.z = quat.z();
    static_transformStamped.transform.rotation.w = quat.w();
    static_broadcaster.sendTransform(static_transformStamped);
}