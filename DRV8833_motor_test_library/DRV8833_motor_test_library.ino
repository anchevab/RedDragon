/*
   DRV8833_Test RedRobot with BRC NANO motor shield
   Byala Robots Club
   Author eng.Anton Anchev
   Byala, july 2018
*/

#include <DRV8833.h>
// ------ Create an instance of the DRV8833:
DRV8833 driver = DRV8833();

const int inputA1 = 5, inputA2 = 6;
const int inputB1 = 9, inputB2 = 10;

//===================== SETUP ================
void setup() {
  Serial.begin(9600);
  while (!Serial);
  driver.attachMotorA(inputA1, inputA2);
  driver.attachMotorB(inputB1, inputB2);
  Serial.println("Ready!");
}

// =================== LOOP ==================
void loop() {

  // ------------- FORWARD -------------
  Serial.println("Forward:");
  driver.motorAForward(255);
  driver.motorBForward(255);
  delay(2000);

  // ------------ STOP ----------------
  Serial.println("Stop:");
  driver.motorAStop();
  driver.motorBStop();
  delay(50);
  // ------------ BACKWARD --------------
  Serial.println("Reverse:");
  driver.motorAReverse(160);
  driver.motorBReverse(160);
  delay(2000);
  // ------------ STOP ----------------
  Serial.println("Stop:");
  driver.motorAStop();
  driver.motorBStop();
  delay(50);

  // ------------ TURN LEFT ------------
  Serial.println("<<<<<<<< Left:");
  driver.motorAReverse(80);                 // speed 80-255
  driver.motorBForward(80);

  delay(2000);
  // ------------ STOP ----------------
  Serial.println("Stop:");
  driver.motorAStop();
  driver.motorBStop();
  delay(50);
  // ----------- TURN RIGHT ----------
  Serial.println("Right >>>>>>>>>>:");
  driver.motorAForward(80);
  driver.motorBReverse(80);
  delay(2000);
  Serial.println("Stop:");
  // ----------- Stop the motor:
  driver.motorAStop();
  driver.motorBStop();
  delay(50);
}
