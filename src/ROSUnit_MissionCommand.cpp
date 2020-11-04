// #include "HEAR_ROS_BRIDGE/ROSUnit_MissionCommand.hpp"
// ROSUnit_MissionCommand* ROSUnit_MissionCommand::_instance_ptr = NULL;
// MissionCommandMsg ROSUnit_MissionCommand::_command_msg;
// Port* ROSUnit_MissionCommand::_output_port_0 = new OutputPort(ports_id::OP_0, NULL);

// ROSUnit_MissionCommand::ROSUnit_MissionCommand(ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
//     _srv_flight_command = t_main_handler.advertiseService("mission_command", callbackFlightCommand);
//     _instance_ptr = this;
//     _ports = {_output_port_0};
// }   

// ROSUnit_MissionCommand::~ROSUnit_MissionCommand() {
// }

// bool ROSUnit_MissionCommand::callbackFlightCommand(hear_msgs::set_int::Request  &req, hear_msgs::set_int::Response &res){
//     _command_msg.data = req.data;;
//     _output_port_0->receiveMsgData((DataMsg*) &_command_msg);
//     return true;
// }