#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <string>


class ROS_PUB{
	public:
		ROS_PUB();
		void ex1_publisher();

	private:
	ros::NodeHandle nh;
	ros::Publisher ex1_pub= nh.advertise<std_msgs::String> ("chatter", 1000);
	};

void ROS_PUB::ex1_publisher(){
	std_msgs::String msg;
	std::string str;
	while(ros::ok()){
		
		std::cout<<"Type your message (type quit to exit): ";
		std::getline (std::cin,str);
		msg.data=str;
		ex1_pub.publish(msg);
		if(!str.compare("quit"))
			return;

	}
}

ROS_PUB::ROS_PUB(){
	
	}


int main(int argc, char **argv){

	ros::init(argc, argv, "ex1_publisher");
	ROS_PUB rs;
	rs.ex1_publisher();		

	return 0;
}
