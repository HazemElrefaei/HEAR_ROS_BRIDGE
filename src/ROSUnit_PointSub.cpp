#include "HEAR_ROS_BRIDGE/ROSUnit_PointSub.hpp"

ROSUnit_PointSub* ROSUnit_PointSub::m_ptr[ROSUnit_capacity];
int ROSUnit_PointSub::internal_counter=0;

void(*ROSUnit_PointSub::callbackFunctionPointer[ROSUnit_capacity])(const geometry_msgs::Point::ConstPtr& t_rec){
  ROSUnit_PointSub::callback1,
  ROSUnit_PointSub::callback2,
  ROSUnit_PointSub::callback3,
  ROSUnit_PointSub::callback4,
  ROSUnit_PointSub::callback5,
  ROSUnit_PointSub::callback6,
  ROSUnit_PointSub::callback7,
  ROSUnit_PointSub::callback8,
  ROSUnit_PointSub::callback9,
  ROSUnit_PointSub::callback10,
  ROSUnit_PointSub::callback11,
  ROSUnit_PointSub::callback12,
  ROSUnit_PointSub::callback13,
  ROSUnit_PointSub::callback14,
  ROSUnit_PointSub::callback15
};

Port* ROSUnit_PointSub::_output_port_0 = new OutputPort(ports_id::OP_0, NULL);
Port* ROSUnit_PointSub::_output_port_1 = new OutputPort(ports_id::OP_1, NULL);
Port* ROSUnit_PointSub::_output_port_2 = new OutputPort(ports_id::OP_2, NULL);
Port* ROSUnit_PointSub::_output_port_3 = new OutputPort(ports_id::OP_3, NULL);
Port* ROSUnit_PointSub::_output_port_4 = new OutputPort(ports_id::OP_4, NULL);
Port* ROSUnit_PointSub::_output_port_5 = new OutputPort(ports_id::OP_5, NULL);
Port* ROSUnit_PointSub::_output_port_6 = new OutputPort(ports_id::OP_6, NULL);
Port* ROSUnit_PointSub::_output_port_7 = new OutputPort(ports_id::OP_7, NULL);
Port* ROSUnit_PointSub::_output_port_8 = new OutputPort(ports_id::OP_8, NULL);
Port* ROSUnit_PointSub::_output_port_9 = new OutputPort(ports_id::OP_9, NULL);
Port* ROSUnit_PointSub::_output_port_10 = new OutputPort(ports_id::OP_10, NULL);
Port* ROSUnit_PointSub::_output_port_11 = new OutputPort(ports_id::OP_11, NULL);
Port* ROSUnit_PointSub::_output_port_12 = new OutputPort(ports_id::OP_12, NULL);
Port* ROSUnit_PointSub::_output_port_13 = new OutputPort(ports_id::OP_13, NULL);
Port* ROSUnit_PointSub::_output_port_14 = new OutputPort(ports_id::OP_14, NULL);

ROSUnit_PointSub::ROSUnit_PointSub(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    m_sub = t_main_handler.subscribe(t_name, 1, ROSUnit_PointSub::callbackFunctionPointer[internal_counter]);
    m_ptr[internal_counter] = this;
    internal_counter++;
    _ports = {_output_port_0, _output_port_1, _output_port_2, _output_port_3, _output_port_4, _output_port_5, _output_port_6, _output_port_7, _output_port_8, _output_port_9, _output_port_10, _output_port_11, _output_port_12, _output_port_13, _output_port_14};
}

ROSUnit_PointSub::~ROSUnit_PointSub() {

}

void ROSUnit_PointSub::callback1(const geometry_msgs::Point::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->x;
    t_vec.y = t_rec->y;
    t_vec.z = t_rec->z;
    t_msg.data = t_vec;
    _output_port_0->receiveMsgData(&t_msg);
}

void ROSUnit_PointSub::callback2(const geometry_msgs::Point::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->x;
    t_vec.y = t_rec->y;
    t_vec.z = t_rec->z;
    t_msg.data = t_vec;
    _output_port_1->receiveMsgData(&t_msg);
}

void ROSUnit_PointSub::callback3(const geometry_msgs::Point::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->x;
    t_vec.y = t_rec->y;
    t_vec.z = t_rec->z;
    t_msg.data = t_vec;
    _output_port_2->receiveMsgData(&t_msg);
}

void ROSUnit_PointSub::callback4(const geometry_msgs::Point::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->x;
    t_vec.y = t_rec->y;
    t_vec.z = t_rec->z;
    t_msg.data = t_vec;
    _output_port_3->receiveMsgData(&t_msg);
}

void ROSUnit_PointSub::callback5(const geometry_msgs::Point::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->x;
    t_vec.y = t_rec->y;
    t_vec.z = t_rec->z;
    t_msg.data = t_vec;
    _output_port_4->receiveMsgData(&t_msg);
}

void ROSUnit_PointSub::callback6(const geometry_msgs::Point::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->x;
    t_vec.y = t_rec->y;
    t_vec.z = t_rec->z;
    t_msg.data = t_vec;
    _output_port_5->receiveMsgData(&t_msg);
}

void ROSUnit_PointSub::callback7(const geometry_msgs::Point::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->x;
    t_vec.y = t_rec->y;
    t_vec.z = t_rec->z;
    t_msg.data = t_vec;
    _output_port_6->receiveMsgData(&t_msg);
}

void ROSUnit_PointSub::callback8(const geometry_msgs::Point::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->x;
    t_vec.y = t_rec->y;
    t_vec.z = t_rec->z;
    t_msg.data = t_vec;
    _output_port_7->receiveMsgData(&t_msg);
}

void ROSUnit_PointSub::callback9(const geometry_msgs::Point::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->x;
    t_vec.y = t_rec->y;
    t_vec.z = t_rec->z;
    t_msg.data = t_vec;
    _output_port_8->receiveMsgData(&t_msg);
}

void ROSUnit_PointSub::callback10(const geometry_msgs::Point::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->x;
    t_vec.y = t_rec->y;
    t_vec.z = t_rec->z;
    t_msg.data = t_vec;
    _output_port_9->receiveMsgData(&t_msg);
}

void ROSUnit_PointSub::callback11(const geometry_msgs::Point::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->x;
    t_vec.y = t_rec->y;
    t_vec.z = t_rec->z;
    t_msg.data = t_vec;
    _output_port_10->receiveMsgData(&t_msg);
}

void ROSUnit_PointSub::callback12(const geometry_msgs::Point::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->x;
    t_vec.y = t_rec->y;
    t_vec.z = t_rec->z;
    t_msg.data = t_vec;
    _output_port_11->receiveMsgData(&t_msg);
}

void ROSUnit_PointSub::callback13(const geometry_msgs::Point::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->x;
    t_vec.y = t_rec->y;
    t_vec.z = t_rec->z;
    t_msg.data = t_vec;
    _output_port_12->receiveMsgData(&t_msg);
}

void ROSUnit_PointSub::callback14(const geometry_msgs::Point::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->x;
    t_vec.y = t_rec->y;
    t_vec.z = t_rec->z;
    t_msg.data = t_vec;
    _output_port_13->receiveMsgData(&t_msg);
}

void ROSUnit_PointSub::callback15(const geometry_msgs::Point::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->x;
    t_vec.y = t_rec->y;
    t_vec.z = t_rec->z;
    t_msg.data = t_vec;
    _output_port_14->receiveMsgData(&t_msg);
}