/*
 * DRV8833 test two motors with PWM from analog port A0
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
int motorSpeed = 0;

// The potentiometer's pin:
const int potPin = A0;

void setup() {
  // put your setup code here, to run once:
  
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
  
  int reading = analogRead(potPin);
  motorSpeed = map(reading, 0, 1023, 0, 255);
  Serial.print(reading);
  Serial.print('\t');
  Serial.println(motorSpeed);
  
  // Put the motors in forward using the speed:
  driver.motorAForward(motorSpeed);
  driver.motorBForward(motorSpeed);
  delay(50);
}
