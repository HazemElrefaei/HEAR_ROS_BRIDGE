#include "HEAR_ROS_BRIDGE/ROSUnit_PoseProvider.hpp"

ROSUnit_PoseProvider* ROSUnit_PoseProvider::_instance_ptr = NULL;
Port* ROSUnit_PoseProvider::_output_port_0;
Port* ROSUnit_PoseProvider::_output_port_1;
Port* ROSUnit_PoseProvider::_output_port_2;
Port* ROSUnit_PoseProvider::_output_port_3;
Port* ROSUnit_PoseProvider::_output_port_4;

tf2::Matrix3x3 ROSUnit_PoseProvider::rot_offset;
tf2::Vector3 ROSUnit_PoseProvider::trans_offset;

ROSUnit_PoseProvider::ROSUnit_PoseProvider(ros::NodeHandle& t_main_handler): ROSUnit(t_main_handler){
    _instance_ptr = this;
    m_server = t_main_handler.advertiseService("set_height_offset", &srv_callback);
    
    opti_sub = t_main_handler.subscribe("/Robot_1/pose", 10, &callback_opti_pose, ros::TransportHints().tcpNoDelay());
    xsens_ori_sub = t_main_handler.subscribe("filter/quaternion", 10, callback_ori, ros::TransportHints().tcpNoDelay());
    xsens_ang_vel_sub = t_main_handler.subscribe("imu/angular_velocity", 10, &callback_angular_vel, ros::TransportHints().tcpNoDelay());
    xsens_free_acc_sub = t_main_handler.subscribe("imu/acceleration", 10, &callback_free_acc, ros::TransportHints().tcpNoDelay());

    _output_port_0 = new OutputPort(ports_id::OP_0_POS, this);
    _output_port_1 = new OutputPort(ports_id::OP_1_ORI_OPTI, this);
    _output_port_2 = new OutputPort(ports_id::OP_2_ORI_IMU, this);
    _output_port_3 = new OutputPort(ports_id::OP_3_BODY_RATE, this);
    _output_port_4 = new OutputPort(ports_id::OP_4_FREE_ACCELERATION, this);

    rot_offset.setRPY(0.0, 0.0, -M_PI/2.0);

    _ports = {_output_port_0, _output_port_1, _output_port_2, _output_port_3, _output_port_4};

}

bool ROSUnit_PoseProvider::srv_callback(hear_msgs::set_float::Request& req, hear_msgs::set_float::Response& res) {
    trans_offset.setZ(req.data);
    return true;
}

void ROSUnit_PoseProvider::callback_opti_pose(const geometry_msgs::PoseStamped::ConstPtr& msg){
    Vector3DMsg vec, vec_ori;
    auto pos = tf2::Vector3({msg->pose.position.x, msg->pose.position.y, msg->pose.position.z});
    auto calib_pos = rot_offset*pos - trans_offset;

    vec.data = Vector3D<double>({calib_pos.x(), calib_pos.y(), calib_pos.z()});

    auto R_mat = tf2::Matrix3x3(tf2::Quaternion(msg->pose.orientation.x, msg->pose.orientation.y, msg->pose.orientation.z, msg->pose.orientation.w ));

    tf2Scalar yaw, pitch, roll;
    R_mat.getEulerYPR(yaw, pitch, roll);

    vec_ori.data = Vector3D<double>({roll, pitch, yaw});

    _instance_ptr->_output_port_0->receiveMsgData(&vec);
    _instance_ptr->_output_port_1->receiveMsgData(&vec_ori);
}

void ROSUnit_PoseProvider::callback_ori(const geometry_msgs::QuaternionStamped::ConstPtr& msg){
    Vector3DMsg vec;
    
    auto R_mat = tf2::Matrix3x3(tf2::Quaternion(msg->quaternion.x, msg->quaternion.y, msg->quaternion.z, msg->quaternion.w));

    tf2Scalar yaw, roll, pitch;
    R_mat.getEulerYPR(yaw, pitch, roll);

    vec.data = Vector3D<double>({roll, pitch, yaw});

    _instance_ptr->_output_port_2->receiveMsgData(&vec);
}

void ROSUnit_PoseProvider::callback_angular_vel(const geometry_msgs::Vector3Stamped::ConstPtr& msg){
    Vector3DMsg vec;
    vec.data = Vector3D<double>({msg->vector.x, msg->vector.x, msg->vector.z});

    _instance_ptr->_output_port_3->receiveMsgData(&vec);
}

void ROSUnit_PoseProvider::callback_free_acc(const geometry_msgs::Vector3Stamped::ConstPtr& msg){
    Vector3DMsg vec;
    vec.data = Vector3D<double>({msg->vector.x, msg->vector.y, msg->vector.z});

    _instance_ptr->_output_port_4->receiveMsgData(&vec);
}

