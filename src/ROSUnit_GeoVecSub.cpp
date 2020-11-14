#include "HEAR_ROS_BRIDGE/ROSUnit_GeoVecSub.hpp"

ROSUnit_GeoVecSub* ROSUnit_GeoVecSub::m_ptr[ROSUnit_capacity];
int ROSUnit_GeoVecSub::internal_counter=0;

void(*ROSUnit_GeoVecSub::callbackFunctionPointer[ROSUnit_capacity])(const geometry_msgs::Vector3Stamped::ConstPtr& t_rec){
  ROSUnit_GeoVecSub::callback1,
  ROSUnit_GeoVecSub::callback2,
  ROSUnit_GeoVecSub::callback3,
  ROSUnit_GeoVecSub::callback4,
  ROSUnit_GeoVecSub::callback5,
  ROSUnit_GeoVecSub::callback6,
  ROSUnit_GeoVecSub::callback7
};

Port* ROSUnit_GeoVecSub::_output_port_0 = new OutputPort(ports_id::OP_0, NULL);
Port* ROSUnit_GeoVecSub::_output_port_1 = new OutputPort(ports_id::OP_1, NULL);
Port* ROSUnit_GeoVecSub::_output_port_2 = new OutputPort(ports_id::OP_2, NULL);
Port* ROSUnit_GeoVecSub::_output_port_3 = new OutputPort(ports_id::OP_3, NULL);
Port* ROSUnit_GeoVecSub::_output_port_4 = new OutputPort(ports_id::OP_4, NULL);
Port* ROSUnit_GeoVecSub::_output_port_5 = new OutputPort(ports_id::OP_5, NULL);
Port* ROSUnit_GeoVecSub::_output_port_6 = new OutputPort(ports_id::OP_6, NULL);



ROSUnit_GeoVecSub::ROSUnit_GeoVecSub(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    m_sub = t_main_handler.subscribe(t_name, 1, ROSUnit_GeoVecSub::callbackFunctionPointer[internal_counter]);
    m_ptr[internal_counter] = this;
    internal_counter++;
    _ports = {_output_port_0, _output_port_1, _output_port_2, _output_port_3, _output_port_4, _output_port_5, _output_port_6};
}

ROSUnit_GeoVecSub::~ROSUnit_GeoVecSub() {

}

void ROSUnit_GeoVecSub::callback1(const geometry_msgs::Vector3Stamped::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->vector.x;
    t_vec.y = t_rec->vector.y;
    t_vec.z = t_rec->vector.z;
    t_msg.data = t_vec;
    _output_port_0->receiveMsgData(&t_msg);
}

void ROSUnit_GeoVecSub::callback2(const geometry_msgs::Vector3Stamped::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->vector.x;
    t_vec.y = t_rec->vector.y;
    t_vec.z = t_rec->vector.z;
    t_msg.data = t_vec;
    _output_port_1->receiveMsgData(&t_msg);
}

void ROSUnit_GeoVecSub::callback3(const geometry_msgs::Vector3Stamped::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->vector.x;
    t_vec.y = t_rec->vector.y;
    t_vec.z = t_rec->vector.z;
    t_msg.data = t_vec;
    _output_port_2->receiveMsgData(&t_msg);
}

void ROSUnit_GeoVecSub::callback4(const geometry_msgs::Vector3Stamped::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->vector.x;
    t_vec.y = t_rec->vector.y;
    t_vec.z = t_rec->vector.z;
    t_msg.data = t_vec;
    _output_port_3->receiveMsgData(&t_msg);
}

void ROSUnit_GeoVecSub::callback5(const geometry_msgs::Vector3Stamped::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->vector.x;
    t_vec.y = t_rec->vector.y;
    t_vec.z = t_rec->vector.z;
    t_msg.data = t_vec;
    _output_port_4->receiveMsgData(&t_msg);
}

void ROSUnit_GeoVecSub::callback6(const geometry_msgs::Vector3Stamped::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->vector.x;
    t_vec.y = t_rec->vector.y;
    t_vec.z = t_rec->vector.z;
    t_msg.data = t_vec;
    _output_port_5->receiveMsgData(&t_msg);
}

void ROSUnit_GeoVecSub::callback7(const geometry_msgs::Vector3Stamped::ConstPtr& t_rec) {
    Vector3DMsg t_msg;
    Vector3D<float> t_vec;
    t_vec.x = t_rec->vector.x;
    t_vec.y = t_rec->vector.y;
    t_vec.z = t_rec->vector.z;
    t_msg.data = t_vec;
    _output_port_6->receiveMsgData(&t_msg);
}