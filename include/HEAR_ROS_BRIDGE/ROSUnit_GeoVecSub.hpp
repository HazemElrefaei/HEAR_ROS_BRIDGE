#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "geometry_msgs/Vector3Stamped.h"
#include "HEAR_msg/Vector3DMsg.hpp"
class ROSUnit_GeoVecSub : public ROSUnit
{
public:
    enum ports_id {OP_0, OP_1, OP_2, OP_3, OP_4, OP_5, OP_6};
    void process(DataMsg* t_msg, Port* t_port) {};
    ROSUnit_GeoVecSub(std::string, ros::NodeHandle&);
    ~ROSUnit_GeoVecSub();
private:
    static Port* _output_port_0;
    static Port* _output_port_1;
    static Port* _output_port_2;
    static Port* _output_port_3;
    static Port* _output_port_4;
    static Port* _output_port_5;
    static Port* _output_port_6;
    ros::Subscriber m_sub;
    static int internal_counter;
    static ROSUnit_GeoVecSub* m_ptr[ROSUnit_capacity];
    static void(*callbackFunctionPointer[ROSUnit_capacity])(const geometry_msgs::Vector3Stamped::ConstPtr&);
    static void callback1(const geometry_msgs::Vector3Stamped::ConstPtr&);//TODO refactor through templates
    static void callback2(const geometry_msgs::Vector3Stamped::ConstPtr&);
    static void callback3(const geometry_msgs::Vector3Stamped::ConstPtr&);
    static void callback4(const geometry_msgs::Vector3Stamped::ConstPtr&);
    static void callback5(const geometry_msgs::Vector3Stamped::ConstPtr&);
    static void callback6(const geometry_msgs::Vector3Stamped::ConstPtr&);
    static void callback7(const geometry_msgs::Vector3Stamped::ConstPtr&);
};