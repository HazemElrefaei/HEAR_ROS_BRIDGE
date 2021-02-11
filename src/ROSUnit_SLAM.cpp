#include "HEAR_ROS_BRIDGE/ROSUnit_SLAM.hpp"

ROSUnit_SLAM* ROSUnit_SLAM::_instance_ptr = NULL;
Port* ROSUnit_SLAM::_output_port_0;
Port* ROSUnit_SLAM::_output_port_1;
Port* ROSUnit_SLAM::_output_port_2;

ROSUnit_SLAM::ROSUnit_SLAM(ros::NodeHandle& t_main_handler): ROSUnit(t_main_handler){
    _sub_pos = t_main_handler.subscribe<geometry_msgs::PointStamped>("slam/position", 2, callbackPos, ros::TransportHints().tcpNoDelay());
    _sub_ori = t_main_handler.subscribe<geometry_msgs::PointStamped>("slam/orientation", 2, callbackOri, ros::TransportHints().tcpNoDelay());
    _sub_vel = t_main_handler.subscribe<geometry_msgs::Vector3Stamped>("slam/velocity", 2, callbackVel, ros::TransportHints().tcpNoDelay());
    
    _pub_ref_frame = t_main_handler.advertise<std_msgs::String>("ref_frame", 10);

    _instance_ptr = this;
    _output_port_0 = new OutputPort(ports_id::OP_0_POS, this);
    _output_port_1 = new OutputPort(ports_id::OP_1_ORI, this);
    _output_port_2 = new OutputPort(ports_id::OP_2_VEL, this);
    _input_port_0 = new InputPort(ports_id::IP_0_POS, this);
    _input_port_1 = new InputPort(ports_id::IP_1_ORI, this);
    _input_port_2 = new InputPort(ports_id::IP_2_TRIGGER, this);
    _ports = {_output_port_0, _output_port_1, _output_port_1, _input_port_0,_input_port_1, _input_port_2};
}

void ROSUnit_SLAM::callbackPos(const geometry_msgs::PointStamped::ConstPtr& _msg){
    Vector3DMsg pos_msg;

    pos_msg.data.x = (*_msg).point.x;
    pos_msg.data.y = (*_msg).point.y;
    pos_msg.data.z = (*_msg).point.z;
    
    _instance_ptr->_output_port_0->receiveMsgData(&pos_msg);
}

void ROSUnit_SLAM::callbackVel(const geometry_msgs::Vector3Stamped::ConstPtr& _msg){
    Vector3DMsg vel_msg;

    vel_msg.data.x = (*_msg).vector.x;
    vel_msg.data.y = (*_msg).vector.y;
    vel_msg.data.z = (*_msg).vector.z;
    
    _instance_ptr->_output_port_2->receiveMsgData(&vel_msg);
}

void ROSUnit_SLAM::callbackOri(const geometry_msgs::PointStamped::ConstPtr& _msg){
    Vector3DMsg ori_msg;

    ori_msg.data.x = (*_msg).point.x;
    ori_msg.data.y = (*_msg).point.y;
    ori_msg.data.z = (*_msg).point.z;
    
    _instance_ptr->_output_port_1->receiveMsgData(&ori_msg);
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
            std_msgs::String str;
            str.data = ref_frame;
            _pub_ref_frame.publish(str); 
        }
    }
}

void ROSUnit_SLAM::pub_static_transform(){

    static tf2_ros::StaticTransformBroadcaster static_broadcaster;

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