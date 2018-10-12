#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sstream"

#define ARDUINO_I2C_ADDR 0x09

int file_i2c;
unsigned char buffer[60] = {0};

/* I2C functions */
int open_i2c_bus() {

	char *filename = (char *)"/dev/i2c-1";
	if ((file_i2c = open(filename, O_RDWR)) < 0) {

		printf("Failed to open I2C bus");
		return -1;
	}
	else {
		printf("Opened I2C bus\n");
		return 0;
	}
}

int access_arduino() {

	if (ioctl(file_i2c, I2C_SLAVE, ARDUINO_I2C_ADDR) < 0) {

		printf("Failed to acquire bus access and/or talk to slave.\n");
		return -1;
	}
	else {
		printf("Accessed I2C device\n");
		return 0;
	}
}

int read_arduino() {
	
	int length = 4;
	unsigned char buffer[60] = {0};
	if (read(file_i2c,buffer,length) != length) {

		printf("Failed to read from I2C bus\n");
		return -1;
	}
	else {
		printf("Data read: %s\n",buffer);
		return 0;
	}
}

int write_arduino() {

	int length = 2;
	unsigned char buffer[60] = {0};

	buffer[0] = 0x01;
	buffer[1] = 0x02;

	if (write(file_i2c, buffer, length) != length) {

		printf("Failed to write to I2C bus\n");
		return -1;
	}
	else {
		printf("Written data to I2C bus\n");
		return 0;
	}

}

/* Handlers */ 
void ctr_arduino_cb(const std_msgs::String::ConstPtr& msg) {
	
	ROS_INFO("CTR_ARDUINO recieved: [%s]", msg->data.c_str());
}

/* main function */
int main(int argc, char **argv) {
	
	ros::init(argc,argv,"ctr_arduino");
	ros::NodeHandle nh;
	ros::Publisher ctr_arduino_pub = nh.advertise<std_msgs::String>("ctr_arduino_pub", 1000);
	ros::Subscriber ctr_arduino_sub = nh.subscribe("move", 1000, ctr_arduino_cb);
	ros::Rate loop_rate(10);

	while (ros::ok()) {
		
		std_msgs::String msg;

		std::stringstream ss;
		ss << "Arduino test successful";
		msg.data = ss.str();

		ROS_INFO("%s", msg.data.c_str());
		ctr_arduino_pub.publish(msg);
		
		if( open_i2c_bus() == 0)
			if (access_arduino() == 0)
				write_arduino();	

		ros::spin();
	}

	return 0;
}
