#include "ctr_arduino.h"

#define SLAVE_ADDR 0x04

#define ENABLE_LOG //comment out to disable logging

#define VALID_DATA 42

/* global variables */
Servo servoA;
Servo servoB;

ros::NodeHandle nh;

ros::Subscriber<std_msgs::Bool> sub_led_right_eye("led_right_eye", &led_right_eye_cb);
ros::Subscriber<std_msgs::Bool> sub_led_left_eye("led_left_eye", &led_left_eye_cb);

void setup() {

    /* starting serial */
    Serial.begin(9600);
    LOG("[INIT] Serial begin");
    LOG("[INIT] Starting initialisation")
 
    /* initialize i2c as slave */
    Wire.begin(SLAVE_ADDR);
    LOG("[INIT] I2C slave initialised");

    /* initialise motor shield */

    //Setup Channel A
    pinMode(12, OUTPUT); //Initiates Motor Channel A pin
    pinMode(9, OUTPUT); //Initiates Brake Channel A pin

    //Setup Channel B
    pinMode(13, OUTPUT); //Initiates Motor Channel A pin
    pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
    LOG("[INIT] Motor shield intialised")


    /* initialise servos */
    servoA.attach(5);
    servoB.attach(6);
    LOG("[INIT] Servos initialised");

    /* initialise LEDs */
    pinMode(4, OUTPUT);
    pinMode(7, OUTPUT);
    LOG("[INIT] LEDs initialised");
    
    /* define callbacks for i2c */
    Wire.onReceive(receive_data_cb);
    Wire.onRequest(send_data_cb);
    LOG("[INIT] I2C callbacks defined")

    /* initialising ROS */
    nh.initNode();
    nh.subscribe(sub_led_left_eye);
    nh.subscribe(sub_led_right_eye);

    LOG("[INIT] Initialisation completed")

}

/* main loop */
void loop() {
  
    //LOG("[LOOP] Starting loop")
    nh.spinOnce();
    delay(100);
}

/* function selection */
void call_function(int fnum, int param1, int param2, int param3,int param4) {
    
    switch(fnum) {
          
          case 0:
              break;
          
          case 1:
              LOG("Calling function motor_move");
              motor_move(param1,param2,param3,param4);
              break;
          case 2:
              LOG("Calling servo_move");
              servo_move(param1,param2);
              break;
          case 3:
              LOG("Calling set_LEDs");
              set_LEDs(param1,param2);
              break;
          
          default:
              LOG("Invalid function call");
              break;
    }
    
}
/* callback functions */
void led_left_eye_cb(const std_msgs::Bool& msg) {
	if (msg.data == 1)
		digitalWrite(7, HIGH);
	else
		digitalWrite(7, LOW);
}

void led_right_eye_cb(const std_msgs::Bool& msg) {
	if (msg.data == 1)
		digitalWrite(4, HIGH);
	else
		digitalWrite(4, LOW);
}

void set_LEDs(int led1, int led2) {
  
        digitalWrite(4, led1);
        digitalWrite(7, led2);
}

void motor_move(int A_dir, int B_dir, int A_speed, int B_speed) {

        int n;
        LOG("[MOTOR_MOVE] Motor is moving");
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

void servo_move(int posA, int posB) {
        if (posA >=10 && posA <=200 && posB <=90) {
            LOG("[SERVO_MOVE] Servo moving into position");
            LOG("[SERVO_MOVE] position of A");
            LOG(posA);
            LOG("[SERVO_MOVE] position of B");
            LOG(posB);
            servoA.write(posA); //60
            servoB.write(posB); //90
        }
        else {
            LOG("[SERVO_MOVE] Invalid parameters")
        }
        
        
}

/* callback for received data */
void receive_data_cb(int byteCount){

    int valid_data = 0;
    int function = 0;
    int param1 = 0;
    int param2 = 0;
    int param3 = 0;
    int param4 = 0;

    LOG("[RECEIVE_DATA_CB] Receiving data");
    int c;
    // reading from the I2C bus
    while(Wire.available()) {
        
        // data valiadation check
        valid_data = Wire.read();
        if(valid_data != VALID_DATA) {
            LOG("[RECEIVE_DATA_CB] Data validation check failed");
            break;
        }
        // validation check successful
        else {
            LOG("[RECEIVE_DATA_CB] Data validation check passed");
            
            function = Wire.read();
            LOG("[RECEIVE_DATA_CB] Reading function:");
            LOG(function);
            delay(50);
        
            param1 = Wire.read();
            LOG("[RECEIVE_DATA_CB] Reading param1:");
            LOG(param1);
            delay(50);
        
            param2 = Wire.read();
            LOG("[RECEIVE_DATA_CB] Reading param2:");
            LOG(param2);
            delay(50);

            param3 = Wire.read();
            LOG("[RECEIVE_DATA_CB] Reading param3:");
            LOG(param3);
            delay(50);

            param4 = Wire.read();
            LOG("[RECEIVE_DATA_CB] Reading param4:");
            LOG(param4);
            
            call_function(function,param1,param2,param3,param4);
            
        }
        
        //c = Wire.read();
        //LOG(c);
    }
}
 
/* callback for sending data */
void send_data_cb() {
    LOG("[SEND_DATA_CB] Sending data")
    Wire.write(99); // TODO
}
