/*
 * DRV8833 test two motors with PWM
 *
 * Created by eng.A.Anchev
 * Byala Robots Club 
 * Byala, July 24, 2015,
 */

#include <DRV8833.h>

// Create an instance of the DRV8833:
DRV8833 driver = DRV8833();

/*
 Pin numbers. Replace with your own!
 For this example sketch, these pin numbers MUST be PWM.
 Ain1, Ain2, Bin1, and Bin2 DRV8833 pins.
 Attach the Arduino's pin numbers below to the
*/
const int inputA1 = 5, inputA2 = 6, inputB1 = 9, inputB2 = 10;

// The speed of the motors:
const int motorSpeed = 128; // Half speed (255 / 2).

void setup() {
   
  // Start the serial port:
  Serial.begin(9600);
  
  // Wait for the serial port to connect. Needed only for Leonardo.
  while (!Serial);
  
  // Attach the motors to the input pins:
  driver.attachMotorA(inputA1, inputA2);
  driver.attachMotorB(inputB1, inputB2);
  Serial.println("Ready!");

}

void loop() {
    
  Serial.println("Forward:");
  // Put the motors in forward using the speed:
  driver.motorAForward(motorSpeed);
  driver.motorBForward(motorSpeed);
  // Wait to see the effect:
  delay(500);
  
  // Pause the motors for stability:
  driver.motorAStop();
  driver.motorBStop();
  delay(50);
  
  Serial.println("Reverse:");
  // Put the motors in reverse using the speed:
  driver.motorAReverse(motorSpeed);
  driver.motorBReverse(motorSpeed);
  // Wait to see the effect:
  delay(500);
  
  Serial.println("Stop:");
  // Stop the motors:
  // You don't specify a speed for stop().
  driver.motorAStop();
  driver.motorBStop();
  // Wait to see the effect:
  delay(50);
}
