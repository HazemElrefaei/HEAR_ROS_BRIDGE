#pragma once
#include "ros/ros.h"
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/QuaternionStamped.h>
#include <geometry_msgs/TwistStamped.h>
#include <sensor_msgs/Imu.h>
#include "HEAR_ROS_BRIDGE/ROSUnit.hpp"
#include "HEAR_math/Quaternion.hpp"
#include "HEAR_msg/Vector3DMsg.hpp"
#include "HEAR_core/Timer.hpp"
#include "HEAR_math/ButterFilter_2nd.hpp"

class ROSUnit_IMU : public ROSUnit {
private:
    static ROSUnit_IMU* _instance_ptr;
    ros::Subscriber _sub_attitude;
    ros::Subscriber _sub_accelerometer;
    //ros::Subscriber _sub_velocity;
    ros::Subscriber _sub_body_rate;
    static void callbackXsensFreeAcceleration(const geometry_msgs::Vector3Stamped& msg_free_acceleration);
    static void callbackXsensAttitude(const geometry_msgs::QuaternionStamped& msg_attitude);
    //static void callbackXsensVelocity(const geometry_msgs::TwistStamped& msg_velocity);
    static void callbackXsensBodyRate(const geometry_msgs::Vector3Stamped& msg_bodyrate);
    static ButterFilter_2nd filter_gyro_x;
    static ButterFilter_2nd filter_gyro_y;
    static ButterFilter_2nd filter_gyro_z;
    static Port* _output_port_0;
    static Port* _output_port_1;
    static Port* _output_port_2;
    static Port* _output_port_3;
    static Port* _output_port_4;
    static Port* _output_port_5;
    static Timer t_pedro;
public:
    enum ports_id {OP_0_ROLL, OP_1_PITCH, OP_2_ROLL_RATE, OP_3_PITCH_RATE, OP_4_YAW_RATE, OP_5_FREE_ACCELERATION};
    void process(DataMsg* t_msg, Port* t_port) {};
    enum unicast_addresses {broadcast,unicast_XSens_translation,unicast_XSens_orientation,unicast_XSens_attitude_rate,unicast_XSens_yaw_rate,unicast_XSens_translation_rate, unicast_XSens_acceleration};
    ROSUnit_IMU(ros::NodeHandle&);
    ~ROSUnit_IMU();
};