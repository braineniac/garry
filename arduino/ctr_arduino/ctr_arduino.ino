#include <Wire.h>

#define SLAVE_ADDR 0x04

#define ENABLE_LOG //comment out to disable logging
#define VALID_DATA 42

/* macro functions */
#ifdef ENABLE_LOG
#define LOG(x)  {  Serial.println(x); }
#else
#define LOG(x) // do nothing
#endif
 
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
      
    /* define callbacks for i2c */
    Wire.onReceive(receive_data_cb);
    Wire.onRequest(send_data_cb);
    LOG("[INIT] I2C callbacks defined")

    LOG("[INIT] Initialisation completed")

}

/* main loop */
void loop() {
  /*
        digitalWrite(12, 0); // A motor forward
        digitalWrite(9, LOW); // disable A motor brake 
        analogWrite(3, 100);

        digitalWrite(13, 1); // B motor forward
        digitalWrite(8, LOW); // disable A motor brake 
        analogWrite(11, 100);

        delay(500); // run motor for 200 microseconds

        digitalWrite(9, HIGH); // enable A motor brake
        digitalWrite(8, HIGH); // enable B motor brake

        delay(2000);
        */
    //LOG("[LOOP] Starting loop")
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

          default:
              LOG("Invalid function call");
              break;
    }
    
}

void motor_move(int A_dir, int B_dir, int A_speed, int B_speed) {

        LOG("In the motor function");
        int n;
        for(n=0;n<100;n++) {
        digitalWrite(12, !A_dir); // A motor forward(weird wiring)
        digitalWrite(9, LOW); // disable A motor brake 
        analogWrite(3, A_speed);

        digitalWrite(13, B_dir); // A motor forward
        digitalWrite(8, LOW); // disable A motor brake 
        analogWrite(11, B_speed);

        delay(1000); // run motor for 200 microseconds

        digitalWrite(9, HIGH); // enable A motor brake
        digitalWrite(8, HIGH); // enable B motor brake
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
