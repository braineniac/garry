#include "ctr_arduino.h"

/* global variables */
Servo servoA;
Servo servoB;

ros::NodeHandle nh;

ros::Subscriber<std_msgs::Bool> sub_led_right_eye("led_right_eye", &led_right_eye_cb);
ros::Subscriber<std_msgs::Bool> sub_led_left_eye("led_left_eye", &led_left_eye_cb);
ros::Subscriber<geometry_msgs::Twist> sub_motor_left("motor_left", &motor_left_cb);
ros::Subscriber<geometry_msgs::Twist> sub_motor_right("motor_right", &motor_right_cb);
ros::Subscriber<geometry_msgs::Twist> sub_servo_upper("servo_upper", &servo_upper_cb);
ros::Subscriber<geometry_msgs::Twist> sub_servo_lower("servo_lower", &servo_lower_cb);

void setup() {

    /* initialise motor shield */

    //Setup Channel A
    pinMode(12, OUTPUT); //Initiates Motor Channel A pin
    pinMode(9, OUTPUT); //Initiates Brake Channel A pin

    //Setup Channel B
    pinMode(13, OUTPUT); //Initiates Motor Channel A pin
    pinMode(8, OUTPUT);  //Initiates Brake Channel A pin


    /* initialise servos */
    servoA.attach(5);
    servoB.attach(6);

    /* initialise LEDs */
    pinMode(4, OUTPUT);
    pinMode(7, OUTPUT);
    
    /* initialising ROS */
    nh.initNode();
    nh.subscribe(sub_led_left_eye);
    nh.subscribe(sub_led_right_eye);
    nh.subscribe(sub_motor_left);
    nh.subscribe(sub_motor_right);
    nh.subscribe(sub_servo_upper);
    nh.subscribe(sub_servo_lower);
}

/* main loop */
void loop() {
	
	while(!nh.connected()) {
		nh.spinOnce();
	}
	delay(100);
}

/* callback functions */

void led_left_eye_cb(const std_msgs::Bool& msg) {
	
	if (msg.data == 1)
		digitalWrite(4, HIGH);
	else
		digitalWrite(4, LOW);

//	nh.loginfo("[led_left_eye] Setting led_left_eye %i", msg.data);
}

void led_right_eye_cb(const std_msgs::Bool& msg) {
	
	if (msg.data == 1)
		digitalWrite(7, HIGH);
	else
		digitalWrite(7, LOW);
	
//	nh.loginfo("[led_right_eye] Setting led_right_eye %d", msg.data);

}

void motor_left_cb(const geometry_msgs::Twist& msg) {

	nh.loginfo("Left motor is moving");

	float speed = msg.linear.x;

	if (speed > 0)
		digitalWrite(12, LOW); // A motor forward

	else
		digitalWrite(12, HIGH); // A motor backwards	
	
	digitalWrite(9, LOW); // disable A motor brake
	analogWrite(3, speed);

	delay(1000);

	digitalWrite(9, HIGH); //enable motor A brake

}

void motor_right_cb(const geometry_msgs::Twist& msg) {

	nh.loginfo("Right motor is moving");

	float speed = msg.linear.x;

	if (speed > 0)
		digitalWrite(13, LOW); // A motor forward

	else
		digitalWrite(13, HIGH); // A motor backwards	
	
	digitalWrite(8, LOW); // disable A motor brake
	analogWrite(11, speed);

	delay(1000);

	digitalWrite(8, HIGH); //enable motor A brake

}
/*
void motor_left_cb() {

        int n;
        nh.loginfo("[MOTOR_MOVE] Motor is moving");
        for(n=0;n<100;n++) {
        digitalWrite(12, !A_dir); // A motor forward(weird wiring)
        digitalWrite(9, LOW); // disable A motor brake 
        analogWrite(3, A_speed);

        digitalWrite(13, B_dir); // B motor forward
        digitalWrite(8, LOW); // disable B motor brake 
        analogWrite(11, B_speed);

        delay(1000); // run motor for 200 microseconds

        digitalWrite(9, HIGH); // enable A motor brake
        digitalWrite(8, HIGH); // enable B motor brake
        }
}

void servo_upper_cb(int posA, int posB) {
        if (posA >=10 && posA <=200 && posB <=90) {
            nh.loginfo("[SERVO_MOVE] Servo moving into position");
            nh.loginfo("[SERVO_MOVE] position of A");
            nh.loginfo("[SERVO_MOVE] position of B");
            servoA.write(posA); //60
            servoB.write(posB); //90
        }
        else {
            nh.loginfo("[SERVO_MOVE] Invalid parameters");
        }
        
        
}
*/

void servo_upper_cb(const geometry_msgs::Twist& msg) {

	float angle = msg.angular.x;

	nh.loginfo("Upper servo moving");

	servoA.write(angle);

}

void servo_lower_cb(const geometry_msgs::Twist& msg) {

	float angle = msg.angular.x;

	nh.loginfo("Lower servo moving");

	servoB.write(angle);

}

/* callback for received data */

void receive_data_cb(int byteCount) {
	
	nh.loginfo("[RECEIVE_DATA_CB] Receiving data");
	int c = 0;
    	// reading from the I2C bus
    	while(Wire.available()) {
		c = Wire.read();
		char logmsg[100]; 
		snprintf(logmsg, 100, "Data: %d",c);
            	nh.loginfo(logmsg);
		free(logmsg);
        }

}
/* callback for sending data 
void send_data_cb() {
    LOG("[SEND_DATA_CB] Sending data")
    Wire.write(99); // TODO
}
*/
