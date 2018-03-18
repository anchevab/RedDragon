/*
 * DRV8833 test one motor 
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
 Ain1 and Ain2 DRV8833 pins.
 Attach the Arduino's pin numbers below to the
*/
const int inputA1 = 9, inputA2 = 10;

void setup() {
    
  // Start the serial port:
  Serial.begin(9600);
  
  // Wait for the serial port to connect. Needed for Leonardo.
  while (!Serial);
  
  // Attach a motor to the input pins:
  driver.attachMotorA(inputA1, inputA2);
  Serial.println("Ready!");

}

void loop() {
    
  Serial.println("Forward:");
  // Put the motor in forward:
  driver.motorAForward();
  // Wait to see the effect:
  delay(500);
  
  // Pause the motor for stability:
  driver.motorAStop();
  delay(50);
  
  Serial.println("Reverse:");
  // Put the motor in reverse:
  driver.motorAReverse();
  // Wait to see the effect:
  delay(500);
  
  Serial.println("Stop:");
  // Stop the motor:
  driver.motorAStop();
  // Wait to see the effect:
  delay(50);

}
