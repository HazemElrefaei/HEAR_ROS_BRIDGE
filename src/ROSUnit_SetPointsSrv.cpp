#include "HEAR_ROS_BRIDGE/ROSUnit_SetPointsSrv.hpp"

ROSUnit_SetPointsSrv* ROSUnit_SetPointsSrv::m_ptr[ROSUnit_capacity];
int ROSUnit_SetPointsSrv::internal_counter=0;

bool(*ROSUnit_SetPointsSrv::callbackFunctionPointer[ROSUnit_capacity])(hear_msgs::set_points::Request&, hear_msgs::set_points::Response&){
  ROSUnit_SetPointsSrv::srv_callback1,
  ROSUnit_SetPointsSrv::srv_callback2,
  ROSUnit_SetPointsSrv::srv_callback3,
  ROSUnit_SetPointsSrv::srv_callback4,
  ROSUnit_SetPointsSrv::srv_callback5
};

Port* ROSUnit_SetPointsSrv::_output_port_0 = new OutputPort(ports_id::OP_0, NULL);
Port* ROSUnit_SetPointsSrv::_output_port_1 = new OutputPort(ports_id::OP_1, NULL);
Port* ROSUnit_SetPointsSrv::_output_port_2 = new OutputPort(ports_id::OP_2, NULL);
Port* ROSUnit_SetPointsSrv::_output_port_3 = new OutputPort(ports_id::OP_3, NULL);
Port* ROSUnit_SetPointsSrv::_output_port_4 = new OutputPort(ports_id::OP_4, NULL);

ROSUnit_SetPointsSrv::ROSUnit_SetPointsSrv(std::string t_name, ros::NodeHandle& t_main_handler) : ROSUnit(t_main_handler) {
    m_server = t_main_handler.advertiseService(t_name, ROSUnit_SetPointsSrv::callbackFunctionPointer[internal_counter]);
    m_ptr[internal_counter] = this;
    internal_counter++;
    _ports = {_output_port_0, _output_port_1, _output_port_2, _output_port_3, _output_port_4};
}

ROSUnit_SetPointsSrv::~ROSUnit_SetPointsSrv() {

}

bool ROSUnit_SetPointsSrv::srv_callback1(hear_msgs::set_points::Request& req, hear_msgs::set_points::Response& res) {
    PointsMsg t_msg;
    for(int i = 0; i < req.p.size(); i++) {
        Vector3D<float> t_vec;
        t_vec.x = req.p.at(i).x;
        t_vec.y = req.p.at(i).y;
        t_vec.z = req.p.at(i).z;
        t_msg.points.push_back(t_vec);
    }
    _output_port_0->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetPointsSrv::srv_callback2(hear_msgs::set_points::Request& req, hear_msgs::set_points::Response& res) {
    PointsMsg t_msg;
    for(int i = 0; i < req.p.size(); i++) {
        Vector3D<float> t_vec;
        t_vec.x = req.p.at(i).x;
        t_vec.y = req.p.at(i).y;
        t_vec.z = req.p.at(i).z;
        t_msg.points.push_back(t_vec);
    }
    _output_port_1->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetPointsSrv::srv_callback3(hear_msgs::set_points::Request& req, hear_msgs::set_points::Response& res) {
    PointsMsg t_msg;
    for(int i = 0; i < req.p.size(); i++) {
        Vector3D<float> t_vec;
        t_vec.x = req.p.at(i).x;
        t_vec.y = req.p.at(i).y;
        t_vec.z = req.p.at(i).z;
        t_msg.points.push_back(t_vec);
    }
    _output_port_2->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetPointsSrv::srv_callback4(hear_msgs::set_points::Request& req, hear_msgs::set_points::Response& res) {
    PointsMsg t_msg;
    for(int i = 0; i < req.p.size(); i++) {
        Vector3D<float> t_vec;
        t_vec.x = req.p.at(i).x;
        t_vec.y = req.p.at(i).y;
        t_vec.z = req.p.at(i).z;
        t_msg.points.push_back(t_vec);
    }
    _output_port_3->receiveMsgData(&t_msg);
    return true;
}

bool ROSUnit_SetPointsSrv::srv_callback5(hear_msgs::set_points::Request& req, hear_msgs::set_points::Response& res) {
    PointsMsg t_msg;
    for(int i = 0; i < req.p.size(); i++) {
        Vector3D<float> t_vec;
        t_vec.x = req.p.at(i).x;
        t_vec.y = req.p.at(i).y;
        t_vec.z = req.p.at(i).z;
        t_msg.points.push_back(t_vec);
    }
    _output_port_4->receiveMsgData(&t_msg);
    return true;
}
