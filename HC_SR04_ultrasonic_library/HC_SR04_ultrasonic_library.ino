/*
   RedDragon robot with BRC motor shield with HC-SR04
   Author eng.A.Anchev
   Byala, 2018

    ---------------------   
   | HC-SR04 | Arduino |    
   ---------------------    
   |   Vcc   |   5V    |    
   |   Trig  |   12    | 
   |   Echo  |   13    | 
   |   Gnd   |   GND   | 
   ---------------------
*/
#include <Ultrasonic.h>
Ultrasonic ultrasonic(7, 8);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int distance = ultrasonic.distanceRead();
  Serial.println(distance);
  delay(100);
}
