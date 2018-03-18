/*
   RedDragon robot with BRC motor shield read from LDR
   Author eng.A.Anchev
   Byala, 2018
*/
#define light_sensor A0

int sensorValue = 0;        // value read from the pot

// ================ SETUP ==================
void setup() {
  Serial.begin(9600);
}

// ================ LOOP ==================
void loop() {
  sensorValue = analogRead(light_sensor);
  Serial.print("sensor = ");
  Serial.println(sensorValue);
  delay(2);
}
