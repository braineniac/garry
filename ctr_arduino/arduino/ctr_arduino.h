#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>

#include <ros.h>
#include <std_msgs/Bool.h>


/* function definitions */
void call_function(int fnum, int param1, int param2, int param3,int param4);
void set_LEDs(int led1, int led2);
void motor_move(int A_dir, int B_dir, int A_speed, int B_speed);
void servo_move(int posA, int posB);
void receive_data_cb(int byteCount);
void send_data_cb();

void led_left_eye_cb(const std_msgs::Bool& msg);
void led_right_eye_cb(const std_msgs::Bool& msg);
