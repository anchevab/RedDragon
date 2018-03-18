/*
   RedDragon robot with BRC motor shield LED blink
   Author eng.A.Anchev
   Byala, 2018
*/

#include <SoftwareSerial.h>
int bluetoothTx = 4;                                  // TX-O пин от bluetooth на пин D2
int bluetoothRx = 3;                                  // RX-I пин от bluetooth на пин D3
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);   // създаване на bluetooth

// ======================= SETUP ===================
void setup()
{
  Serial.begin(9600);                                 // Стартиране на сериен монитор със скорост 9600bps
  bluetooth.begin(9600);                              // Стартиране на bluetooth монитор със скорост 9600
}

// ======================= LOOP ===================
void loop()
{
  if (bluetooth.available())
  {
    Serial.print((char)bluetooth.read());            // Получаване на символи от bluetooth и изпращане на серийния монитор
  }

  if (Serial.available())
  {
    bluetooth.print((char)Serial.read());             // извеждане на символите от серийния монитор на андроид устройството
  }
  delay(100);
}
