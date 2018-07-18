/*
   RedDragon RC Bluetooth Car
   Byala Robots Club
   Author eng.Anton Anchev
   Byala, january 2018
*/

#include <SoftwareSerial.h>
#include <DRV8833.h>

// ----- motors
DRV8833 driver = DRV8833();
const int inputA1 = 5, inputA2 = 6;
const int inputB1 = 9, inputB2 = 10;

// ---- bluetooth
int bluetoothTx = 4;
int bluetoothRx = 3;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

int speed;

// ==================== SETUP ===============
void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  while (!Serial);
  // -- Attach a motor
  driver.attachMotorA(inputA1, inputA2);           // left motor T1
  driver.attachMotorB(inputB1, inputB2);           // right motor T2
  //  Serial.println("Ready!");
}

// =================== LOOP ================
void loop() {

  char inp_char;
  if (bluetooth.available() > 0)
  {
    inp_char = bluetooth.read();
    //    Serial.println(inp_char);
    switch (inp_char)
    {
      case  '0':                                                 // speed 0
        speed = 0;
        delay(30);
        break;
      case  '1':                                                 // speed 30
        speed = 30;
        delay(30);
        break;
      case  '2':                                                 // speed 50
        speed = 50;
        delay(30);
        break;
      case  '3':                                                 // speed 70
        speed = 70;
        delay(30);
        break;
      case  '4':                                                 // speed 90
        speed = 90;
        delay(30);
        break;
      case  '5':                                                 // speed 110
        speed = 110;
        delay(30);
        break;
      case  '6':                                                 // speed 130
        speed = 130;
        delay(30);
        break;
      case  '7':                                                 // speed 150
        speed = 150;
        delay(30);
        break;
      case  '8':                                                 // speed 180
        speed = 180;
        delay(30);
        break;
      case  '9':                                                 // speed 200
        speed = 200;
        delay(30);
        break;
      case  'q':                                                 // speed 250
        speed = 250;
        delay(30);
        break;
    }
    //--------------------------- FORWARD -----------------------------
    if (inp_char == 'F') {
      //      Serial.println("Forward:");
      driver.motorAForward(speed);
      driver.motorBForward(speed);
    }
    //------------------------ FORWARD-LEFT ---------------------------
    if (inp_char == 'G') {
      //      Serial.println("Forward-Left:");
      driver.motorAForward(speed * 0.65);              // left motor T1
      driver.motorBForward(speed);                     // right motor T2
    }
    //------------------------- FORWARD-RIGHT -------------------------
    if (inp_char == 'I') {
      //      Serial.println("Forward-Right:");
      driver.motorAForward(speed);                     // left motor T1
      driver.motorBForward(speed * 0.65);              // right motor T2
    }
    // -------------------------------------------- BACKWARD ------------------------------------------
    if (inp_char == 'B') {
      //      Serial.println("Reverse:");
      driver.motorAReverse(speed);
      driver.motorBReverse(speed);
    }
    // -------------------------------------------- BACKWARD-LEFT ------------------------------------------
    if (inp_char == 'H') {
      //      Serial.println("Reverse-Left:");
      driver.motorAReverse(speed * 0.65);              // left motor T1
      driver.motorBReverse(speed);                     // right motor T2
    }
    // -------------------------------------------- BACKWARD-RIGHT ------------------------------------------
    if (inp_char == 'J') {
      //      Serial.println("Reverse-Right:");
      driver.motorAReverse(speed);                     // left motor T1
      driver.motorBReverse(speed * 0.65);              // right motor T2
    }
    // ------------------------------------------- TURN RIGHT ------------------------------------------
    if (inp_char == 'R') {
      //      Serial.println("Right:");
      driver.motorAForward(speed);                    // left motor T1
      driver.motorBForward(speed * 0.3);              // right motor T2
    }
    // ------------------------------------------- TURN LEFT --------------------------------------------
    if (inp_char == 'L') {
      //      Serial.println("Left:");
      driver.motorAForward(speed * 0.3);              // left motor T1
      driver.motorBForward(speed);                    // right motor T2
    }
    // ------------------------------------------ STOP ----------------------------------------------------
    if ((inp_char == 'S') ) {
      //      Serial.println("Stop:");
      driver.motorAStop();
      driver.motorBStop();
    }
  }
}
