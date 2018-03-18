// RemoteXY select connection mode and include library
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>
#include <Ultrasonic.h>
#include <RemoteXY.h>

// RemoteXY connection settings
#define REMOTEXY_SERIAL_RX 4
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600

// RemoteXY configurate
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
{ 255, 1, 0, 12, 0, 104, 0, 8, 162, 1,
  130, 1, 3, 4, 57, 44, 175, 130, 1, 3,
  53, 57, 43, 175, 2, 0, 13, 74, 38, 15,
  36, 26, 31, 31, 79, 78, 0, 79, 70, 70,
  0, 129, 0, 16, 61, 12, 6, 166, 76, 69,
  68, 0, 65, 4, 37, 59, 10, 10, 67, 5,
  12, 23, 39, 19, 2, 175, 11, 129, 0, 5,
  10, 53, 5, 166, 208, 148, 208, 184, 209, 129,
  209, 130, 208, 176, 208, 189, 209, 134, 208, 184,
  209, 143, 32, 208, 180, 208, 190, 32, 209, 128,
  208, 190, 208, 177, 208, 190, 209, 130, 208, 176,
  0
};

// ----- this structure defines all the variables of your control interface
struct {
  // input variable
  uint8_t switch_1; // =1 if switch ON and =0 if OFF
  // output variable
  uint8_t led_1_r; // =0..255 LED Red brightness
  char text_1[11];  // string UTF8 end zero
  // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)
// ---------- END RemoteXY include --------------------

#define PIN_SWITCH_1 13
Ultrasonic ultrasonic(7, 8);

// ================== SETUP ======================
void setup()
{
  Serial.begin(9600);
  RemoteXY_Init ();
  pinMode (PIN_SWITCH_1, OUTPUT);
}

// ================= LOOP =======================
void loop()
{
  RemoteXY_Handler ();
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1 == 0) ? LOW : HIGH);
  if (RemoteXY.switch_1 == 1) {
    RemoteXY.led_1_r = 255;       // turn on red color
  } else {
    RemoteXY.led_1_r = 0;         // turn off red color
  }
  int distance = ultrasonic.distanceRead();
  dtostrf(distance, 0, 1, RemoteXY.text_1);
  //  Serial.println(distance);
  delay(10);

}
