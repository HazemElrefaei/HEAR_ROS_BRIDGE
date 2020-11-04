#pragma once
#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include <geometry_msgs/Point.h>
#include "HEAR_msg/Vector3DMsg.hpp"

class ROSUnit_OrientationSubscriber : public ROSUnit {
private:  
    static Port* _output_port_0;
    ros::Subscriber _sub_orientation;
    static ROSUnit_OrientationSubscriber* _instance_ptr;
    static Vector3DMsg orientation_msg; 
    static void callbackOrientation(const geometry_msgs::Point& msg); 
public:
    enum ports_id {OP_0};
    void process(DataMsg* t_msg, Port* t_port) {};
    ROSUnit_OrientationSubscriber(ros::NodeHandle&);
    ~ROSUnit_OrientationSubscriber();
};