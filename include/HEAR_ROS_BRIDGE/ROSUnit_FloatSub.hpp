#pragma once

#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "std_msgs/Float32.h"
//Change the msg type to match your received msg
#include "HEAR_msg/FloatMsg.hpp"

class ROSUnit_FloatSub : public ROSUnit
{
    public:
        enum ports_id {OP_0, OP_1, OP_2, OP_3, OP_4};
        void process(DataMsg* t_msg, Port* t_port) {};
        ROSUnit_FloatSub(std::string, ros::NodeHandle&);
        ~ROSUnit_FloatSub();
        //void receiveMsgData(DataMsg* t_msg) {};

    private:

        static Port* _output_port_0;
        static Port* _output_port_1;
        static Port* _output_port_2;
        static Port* _output_port_3;
        static Port* _output_port_4;

        ros::Subscriber m_sub;
        static int internal_counter;
        static ROSUnit_FloatSub* m_ptr[ROSUnit_capacity];
        //Change the callback code to reflect your system
        //static void callback(const std_msgs::Float32::ConstPtr&);
        static void(*callbackFunctionPointer[ROSUnit_capacity])(const std_msgs::Float32::ConstPtr&);
        static void callback1(const std_msgs::Float32::ConstPtr&);//TODO refactor through templates
        static void callback2(const std_msgs::Float32::ConstPtr&);
        static void callback3(const std_msgs::Float32::ConstPtr&);
        static void callback4(const std_msgs::Float32::ConstPtr&);
        static void callback5(const std_msgs::Float32::ConstPtr&);

};