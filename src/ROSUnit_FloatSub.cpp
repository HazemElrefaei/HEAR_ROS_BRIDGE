#include "HEAR_ROS_BRIDGE/ROSUnit_FloatSub.hpp"

ROSUnit_FloatSub* ROSUnit_FloatSub::m_ptr[ROSUnit_capacity];
int ROSUnit_FloatSub::internal_counter=0;

void(*ROSUnit_FloatSub::callbackFunctionPointer[ROSUnit_capacity])(const std_msgs::Float32::ConstPtr& t_rec){
  ROSUnit_FloatSub::callback1,
  ROSUnit_FloatSub::callback2,
  ROSUnit_FloatSub::callback3,
  ROSUnit_FloatSub::callback4,
  ROSUnit_FloatSub::callback5
};

Port* ROSUnit_FloatSub::_output_port_0 = new OutputPort(ports_id::OP_0, NULL);
Port* ROSUnit_FloatSub::_output_port_1 = new OutputPort(ports_id::OP_1, NULL);
Port* ROSUnit_FloatSub::_output_port_2 = new OutputPort(ports_id::OP_2, NULL);
Port* ROSUnit_FloatSub::_output_port_3 = new OutputPort(ports_id::OP_3, NULL);
Port* ROSUnit_FloatSub::_output_port_4 = new OutputPort(ports_id::OP_4, NULL);

ROSUnit_FloatSub::ROSUnit_FloatSub(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler)
{
    m_sub = t_main_handler.subscribe(t_name, 1, ROSUnit_FloatSub::callbackFunctionPointer[internal_counter]);
    m_ptr[internal_counter] = this;
    internal_counter++;
    _ports = {_output_port_0, _output_port_1, _output_port_2, _output_port_3, _output_port_4};
}

ROSUnit_FloatSub::~ROSUnit_FloatSub()
{

}

void ROSUnit_FloatSub::callback1(const std_msgs::Float32::ConstPtr& t_rec)
{
    //Change the below code to match the message you want to emit
    FloatMsg t_msg;
    t_msg.data = t_rec->data;
    _output_port_0->receiveMsgData(&t_msg);
    //m_ptr[0]->emitMsgUnicastDefault((DataMsg*) &t_msg);
}

void ROSUnit_FloatSub::callback2(const std_msgs::Float32::ConstPtr& t_rec)
{
    //Change the below code to match the message you want to emit
    FloatMsg t_msg;
    t_msg.data = t_rec->data;
    _output_port_1->receiveMsgData(&t_msg);
    //m_ptr[1]->emitMsgUnicastDefault((DataMsg*) &t_msg);
}

void ROSUnit_FloatSub::callback3(const std_msgs::Float32::ConstPtr& t_rec)
{
    //Change the below code to match the message you want to emit
    FloatMsg t_msg;
    t_msg.data = t_rec->data;
    _output_port_2->receiveMsgData(&t_msg);
    //m_ptr[2]->emitMsgUnicastDefault((DataMsg*) &t_msg);
}

void ROSUnit_FloatSub::callback4(const std_msgs::Float32::ConstPtr& t_rec)
{
    //Change the below code to match the message you want to emit
    FloatMsg t_msg;
    t_msg.data = t_rec->data;
    _output_port_3->receiveMsgData(&t_msg);
    //m_ptr[3]->emitMsgUnicastDefault((DataMsg*) &t_msg);
}

void ROSUnit_FloatSub::callback5(const std_msgs::Float32::ConstPtr& t_rec)
{
    //Change the below code to match the message you want to emit
    FloatMsg t_msg;
    t_msg.data = t_rec->data;
    _output_port_4->receiveMsgData(&t_msg);
    //m_ptr[4]->emitMsgUnicastDefault((DataMsg*) &t_msg);
}