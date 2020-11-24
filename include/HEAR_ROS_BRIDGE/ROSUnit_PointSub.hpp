#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "geometry_msgs/Point.h"
#include "HEAR_msg/Vector3DMsg.hpp"
class ROSUnit_PointSub : public ROSUnit
{
public:
    enum ports_id {OP_0, OP_1, OP_2, OP_3, OP_4, OP_5, OP_6, OP_7, OP_8, OP_9, OP_10, OP_11, OP_12, OP_13, OP_14};
    void process(DataMsg* t_msg, Port* t_port) {};
    ROSUnit_PointSub(std::string, ros::NodeHandle&);
    ~ROSUnit_PointSub();
private:
    static Port* _output_port_0;
    static Port* _output_port_1;
    static Port* _output_port_2;
    static Port* _output_port_3;
    static Port* _output_port_4;
    static Port* _output_port_5;
    static Port* _output_port_6;
    static Port* _output_port_7;
    static Port* _output_port_8;
    static Port* _output_port_9;
    static Port* _output_port_10;
    static Port* _output_port_11;
    static Port* _output_port_12;
    static Port* _output_port_13;
    static Port* _output_port_14;
    ros::Subscriber m_sub;
    static int internal_counter;
    static ROSUnit_PointSub* m_ptr[ROSUnit_capacity];
    static void(*callbackFunctionPointer[ROSUnit_capacity])(const geometry_msgs::Point::ConstPtr&);
    static void callback1(const geometry_msgs::Point::ConstPtr&);//TODO refactor through templates
    static void callback2(const geometry_msgs::Point::ConstPtr&);
    static void callback3(const geometry_msgs::Point::ConstPtr&);
    static void callback4(const geometry_msgs::Point::ConstPtr&);
    static void callback5(const geometry_msgs::Point::ConstPtr&);
    static void callback6(const geometry_msgs::Point::ConstPtr&);
    static void callback7(const geometry_msgs::Point::ConstPtr&);
    static void callback8(const geometry_msgs::Point::ConstPtr&);
    static void callback9(const geometry_msgs::Point::ConstPtr&);
    static void callback10(const geometry_msgs::Point::ConstPtr&);
    static void callback11(const geometry_msgs::Point::ConstPtr&);
    static void callback12(const geometry_msgs::Point::ConstPtr&);
    static void callback13(const geometry_msgs::Point::ConstPtr&);
    static void callback14(const geometry_msgs::Point::ConstPtr&);
    static void callback15(const geometry_msgs::Point::ConstPtr&);
};