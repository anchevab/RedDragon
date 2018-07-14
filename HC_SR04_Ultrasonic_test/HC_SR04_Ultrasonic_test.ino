
#include <Ultrasonic.h>
Ultrasonic ultrasonic(7, 8);

// ================== SETUP ======================
void setup()
{
  Serial.begin(9600);
}

// ================= LOOP =======================
void loop()
{
  int distance = ultrasonic.distanceRead();
  Serial.println(distance);
  delay(10);

}
