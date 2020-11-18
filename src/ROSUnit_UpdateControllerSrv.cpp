#include "HEAR_ROS_BRIDGE/ROSUnit_UpdateControllerSrv.hpp"
//#include <iostream>
ROSUnit_UpdateControllerSrv* ROSUnit_UpdateControllerSrv::_instance_ptr = NULL;
ControllerMsg ROSUnit_UpdateControllerSrv::_update_controller_msg;
control_system ROSUnit_UpdateControllerSrv::_id;
Port* ROSUnit_UpdateControllerSrv::_output_port_0 = new OutputPort(ports_id::OP_0_PID, nullptr);
Port* ROSUnit_UpdateControllerSrv::_output_port_1 = new OutputPort(ports_id::OP_1_MRFT, nullptr);
Port* ROSUnit_UpdateControllerSrv::_output_port_2 = new OutputPort(ports_id::OP_2_BB, nullptr);

ROSUnit_UpdateControllerSrv::ROSUnit_UpdateControllerSrv(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    _srv_update_controller_pid = t_main_handler.advertiseService("update_controller/pid", callbackUpdateControllerPID);
    _srv_update_controller_mrft = t_main_handler.advertiseService("update_controller/mrft", callbackUpdateControllerMRFT);
    _srv_update_controller_bb = t_main_handler.advertiseService("update_controller/bb", callbackUpdateControllerBB);
    _instance_ptr = this;
    _ports = {_output_port_0, _output_port_1, _output_port_2};
}   

ROSUnit_UpdateControllerSrv::~ROSUnit_UpdateControllerSrv() {

}

bool ROSUnit_UpdateControllerSrv::callbackUpdateControllerPID(hear_msgs::Update_Controller_PID::Request &req, 
                                                           hear_msgs::Update_Controller_PID::Response &res){

    block_id _id = static_cast<block_id>((int)req.controller_parameters.id);
    PID_parameters pid_data;
    pid_data.kp = req.controller_parameters.pid_kp;
    pid_data.ki = req.controller_parameters.pid_ki;
    pid_data.kd = req.controller_parameters.pid_kd;
    pid_data.kdd = req.controller_parameters.pid_kdd;
    pid_data.anti_windup = req.controller_parameters.pid_anti_windup;
    pid_data.en_pv_derivation = req.controller_parameters.pid_en_pv_derivation;
    pid_data.dt = req.controller_parameters.pid_dt;
    pid_data.id = _id;
    _update_controller_msg.pid_param = pid_data;
    _instance_ptr->_output_port_0->receiveMsgData(&_update_controller_msg);
    //std::cout << "rec pid update:" << (int) req.controller_parameters.id << "\n";
    return true;
}

bool ROSUnit_UpdateControllerSrv::callbackUpdateControllerMRFT(hear_msgs::Update_Controller_MRFT::Request &req, 
                                                                    hear_msgs::Update_Controller_MRFT::Response &res){
    
    block_id _id = static_cast<block_id>((int)req.controller_parameters.id);
    MRFT_parameters mrft_data;
    mrft_data.beta = req.controller_parameters.mrft_beta;
    mrft_data.relay_amp = req.controller_parameters.mrft_relay_amp;
    mrft_data.bias = req.controller_parameters.mrft_bias;
    mrft_data.num_of_peak_conf_samples = req.controller_parameters.mrft_conf_samples;
    mrft_data.no_switch_delay_in_ms = req.controller_parameters.mrft_no_switch_delay;
    mrft_data.id = _id;
    _update_controller_msg.mrft_param = mrft_data;
    _instance_ptr->_output_port_1->receiveMsgData(&_update_controller_msg);
    return true;
}

bool ROSUnit_UpdateControllerSrv::callbackUpdateControllerBB(hear_msgs::Update_Controller_BB::Request &req, 
                                                                hear_msgs::Update_Controller_BB::Response &res){
    
    block_id _id = static_cast<block_id>((int)req.controller_parameters.id);
    BB_parameters bb_param;
    bb_param.alpha1 = req.controller_parameters.bb_alpha1;
    bb_param.alpha2 = req.controller_parameters.bb_alpha2;
    bb_param.h1 = req.controller_parameters.bb_h1;
    bb_param.h2 = req.controller_parameters.bb_h2;
    bb_param.id = _id;
    _update_controller_msg.bb_param = bb_param;
    _instance_ptr->_output_port_2->receiveMsgData(&_update_controller_msg);
    return true;
}