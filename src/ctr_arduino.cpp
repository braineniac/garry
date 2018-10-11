#include "ros/ros.h"
#include "std_msgs/String.h"

#include "sstream"

void ctr_arduino_cb(const std_msgs::String::ConstPtr& msg) {
	
	ROS_INFO("CTR_ARDUINO recieved: [%s]", msg->data.c_str());
}

int main(int argc, int *argv[]) {
	
	ros::init(argc,argv,"ctr_arduino");
	ros::NodeHandle nh;
	ros::Publisher ctr_arduino_pub = nh.advertise<std_msgs::String>("ctr_arduino_pub", 1000);
	ros::Subscriber ctr_arduino_sub = nh.subscribe("move", 1000, ctr_arduino_cb);
	ros::Rate loop_rate(10);

	while (ros::ok()) {
		
		std_msgs::String msg;

		std::stringstream ss;
		ss << "Arduino test successful" << count;
		msg.data = ss.str();

		ROS_INFO("%s", msg.data.c_str());
		ctr_arduino_pub.publish(msg);

		ros::spin();
	}

	return 0;
}
