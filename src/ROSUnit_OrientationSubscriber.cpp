#include "HEAR_ROS_BRIDGE/ROSUnit_OrientationSubscriber.hpp"

ROSUnit_OrientationSubscriber* ROSUnit_OrientationSubscriber::_instance_ptr = NULL;
Vector3DMsg ROSUnit_OrientationSubscriber::orientation_msg;
Port* ROSUnit_OrientationSubscriber::_output_port_0 = new OutputPort(ports_id::OP_0, NULL);

ROSUnit_OrientationSubscriber::ROSUnit_OrientationSubscriber(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler)  {
    _sub_orientation = t_main_handler.subscribe("uav_control/uav_orientation", 2, callbackOrientation);
    _instance_ptr = this;
    _ports = {_output_port_0};
}

ROSUnit_OrientationSubscriber::~ROSUnit_OrientationSubscriber() {

}

void ROSUnit_OrientationSubscriber::callbackOrientation(const geometry_msgs::Point& msg){
    orientation_msg.data.x = msg.x;
    orientation_msg.data.y = msg.y;
    orientation_msg.data.z = msg.z;
    _output_port_0->receiveMsgData((DataMsg*) &orientation_msg); 
}