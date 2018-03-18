/*
   RedDragon robot with BRC motor shield analogRead from potentiometer
   Author eng.A.Anchev
   Byala, 2018
*/
#define potentiometer A1

int sensorValue = 0;        // value read from the pot

// ================ SETUP ==================
void setup() {
  Serial.begin(9600);
}

// ================ LOOP ==================
void loop() {
  sensorValue = analogRead(potentiometer);
  Serial.print("sensor = ");
  Serial.println(sensorValue);
  delay(2);
}
