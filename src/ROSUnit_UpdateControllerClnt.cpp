#include "HEAR_ROS_BRIDGE/ROSUnit_UpdateControllerClnt.hpp"


ROSUnit_UpdateControllerClnt::ROSUnit_UpdateControllerClnt(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    m_client_pid = t_main_handler.serviceClient<hear_msgs::Update_Controller_PID>("update_controller/pid");
    m_client_mrft = t_main_handler.serviceClient<hear_msgs::Update_Controller_MRFT>("update_controller/mrft");
    m_client_bb = t_main_handler.serviceClient<hear_msgs::Update_Controller_BB>("update_controller/bb");
    _instance_ptr = this;
    _input_port_0 = new InputPort(ports_id::IP_0_PID, this);
    _input_port_1 = new InputPort(ports_id::IP_1_MRFT, this);
    _input_port_2 = new InputPort(ports_id::IP_2_BB, this);
    _ports = {_input_port_0, _input_port_1, _input_port_2};
}   

ROSUnit_UpdateControllerClnt::~ROSUnit_UpdateControllerClnt() {

}

void ROSUnit_UpdateControllerClnt::process(DataMsg* t_msg, Port* t_port) {
    ControllerMsg* _update_msg = (ControllerMsg*)t_msg;
    if(t_port->getID() == ports_id::IP_0_PID) {
        hear_msgs::Update_Controller_PID srv;
        srv.request.controller_parameters.id = static_cast<int>(_update_msg->pid_param.id);
        srv.request.controller_parameters.pid_kp = _update_msg->pid_param.kp;
        srv.request.controller_parameters.pid_ki = _update_msg->pid_param.ki;
        srv.request.controller_parameters.pid_kd = _update_msg->pid_param.kd;
        srv.request.controller_parameters.pid_kdd = _update_msg->pid_param.kdd;
        srv.request.controller_parameters.pid_anti_windup = _update_msg->pid_param.anti_windup;
        srv.request.controller_parameters.pid_en_pv_derivation = _update_msg->pid_param.en_pv_derivation;
        srv.request.controller_parameters.pid_dt = _update_msg->pid_param.dt;
        bool success = m_client_pid.call(srv);
        if (success) {
            ROS_INFO("CONTROLLER UPDATED. id: %d", static_cast<int>(srv.request.controller_parameters.id));
        }
        else {
            ROS_ERROR("Failed to call service /update_controller");
        }
    }
    else if(t_port->getID() == ports_id::IP_1_MRFT) {
        hear_msgs::Update_Controller_MRFT srv;
        srv.request.controller_parameters.id = static_cast<int>(_update_msg->mrft_param.id);
        srv.request.controller_parameters.mrft_beta = _update_msg->mrft_param.beta;
        srv.request.controller_parameters.mrft_relay_amp = _update_msg->mrft_param.relay_amp;
        srv.request.controller_parameters.mrft_bias = _update_msg->mrft_param.bias;
        srv.request.controller_parameters.mrft_no_switch_delay = _update_msg->mrft_param.no_switch_delay_in_ms;
        srv.request.controller_parameters.mrft_conf_samples = _update_msg->mrft_param.num_of_peak_conf_samples;
        bool success = m_client_mrft.call(srv);
        if (success) {
            ROS_INFO("CONTROLLER UPDATED. id: %d", static_cast<int>(srv.request.controller_parameters.id));
        }
        else {
            ROS_ERROR("Failed to call service /update_controller");
        }
    }
    else if(t_port->getID() == ports_id::IP_2_BB){
        hear_msgs::Update_Controller_BB srv;
        srv.request.controller_parameters.id = static_cast<int>(_update_msg->bb_param.id);
        srv.request.controller_parameters.bb_alpha1 = _update_msg->bb_param.alpha1;
        srv.request.controller_parameters.bb_alpha2 = _update_msg->bb_param.alpha2;
        srv.request.controller_parameters.bb_h1 = _update_msg->bb_param.h1;
        srv.request.controller_parameters.bb_h2 = _update_msg->bb_param.h2;
        bool success = m_client_bb.call(srv);
        if (success) {
            ROS_INFO("CONTROLLER UPDATED. id: %d", static_cast<int>(srv.request.controller_parameters.id));
        }
        else {
            ROS_ERROR("Failed to call service /update_controller");
        }
    }
}