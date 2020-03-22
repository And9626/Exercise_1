#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

class ROS_SUB{
	public:
		ROS_SUB();
		void ex1_cb( std_msgs::StringConstPtr msg);

	private:
		ros::NodeHandle _nh;
		ros::Subscriber _ex1_sub;
	};

ROS_SUB::ROS_SUB(){
	_ex1_sub = _nh.subscribe("chatter", 1000, &ROS_SUB::ex1_cb, this);
}

void ROS_SUB::ex1_cb(std_msgs::StringConstPtr msg){
	std::cout<<"The message is: "<<msg->data<<std::endl;
}





int main(int argc, char** argv){

	ros::init(argc, argv, "ex1_sub");
	ROS_SUB rs;
	
	ros::spin();

		
	return 0;
}
