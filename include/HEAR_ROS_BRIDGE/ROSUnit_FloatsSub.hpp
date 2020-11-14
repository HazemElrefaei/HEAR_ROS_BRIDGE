#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "std_msgs/Float32MultiArray.h"
#include "HEAR_msg/FloatArrayMsg.hpp"

class ROSUnit_FloatsSub : public ROSUnit
{
    public:
        enum ports_id {OP_0, OP_1, OP_2, OP_3, OP_4};
        void process(DataMsg* t_msg, Port* t_port) {};
        ROSUnit_FloatsSub(std::string, ros::NodeHandle&);
        ~ROSUnit_FloatsSub();

    private:

        static Port* _output_port_0;
        static Port* _output_port_1;
        static Port* _output_port_2;
        static Port* _output_port_3;
        static Port* _output_port_4;

        ros::Subscriber m_sub;
        static int internal_counter;
        static ROSUnit_FloatsSub* m_ptr[ROSUnit_capacity];
        static void(*callbackFunctionPointer[ROSUnit_capacity])(const std_msgs::Float32MultiArray::ConstPtr&);
        static void callback1(const std_msgs::Float32MultiArray::ConstPtr&);//TODO refactor through templates
        static void callback2(const std_msgs::Float32MultiArray::ConstPtr&);
        static void callback3(const std_msgs::Float32MultiArray::ConstPtr&);
        static void callback4(const std_msgs::Float32MultiArray::ConstPtr&);
        static void callback5(const std_msgs::Float32MultiArray::ConstPtr&);

};