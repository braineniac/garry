#include <Wire.h>

void setup() {

  // I2C setup
  Wire.begin(9);
  Wire.onRequest(requestEvent);
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin

}  

void loop() {

  
  
  digitalWrite(12, HIGH); // A forward
  digitalWrite(12, LOW);  // A no break
  analogWrite(3, 30);     // 1/4 speed

  digitalWrite(13, LOW); // B backward
  digitalWrite(8, LOW);  // B no break
  digitalWrite(11, 30);  // 1/4 speed

  //delay(3000);
  
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);

  delay(3000);
}

void requestEvent() {
    
    Wire.write("hello ");

}
