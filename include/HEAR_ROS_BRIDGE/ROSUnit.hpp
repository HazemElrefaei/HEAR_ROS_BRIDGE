#pragma once
#include "ros/ros.h"
#include <string>
#include "std_msgs/String.h"
#include "HEAR_core/Block.hpp"
#include "HEAR_core/InputPort.hpp"
#include "HEAR_core/OutputPort.hpp"

const int ROSUnit_capacity=15;
class ROSUnit : public Block{

    private:
        ros::NodeHandle _main_handler;

    public:
        ros::NodeHandle getNodeHandle();
        ROSUnit(ros::NodeHandle&);
        ~ROSUnit();
        //CHECK
        void process(DataMsg* t_msg, Port* t_port) {}
};