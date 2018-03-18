/*
   RedDragon robot with BRC motor shield with DHT11
   Author eng.A.Anchev
   Byala, 2018
*/

#include "DHT.h"
#define DHTPIN 2                                           // пин 2 свързан към сензора
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  dht.begin();
}

void loop() {
  int h = dht.readHumidity();                               // прочитане на данни за влажността
  int t = dht.readTemperature();                            // прочитане на данни за температурата

  if (isnan(t) || isnan(h)) {                               //проверка дали прочетените стойности са числови стойности, ако не са значи има някакъв проблем
    Serial.println("Greshka pri chetene ot DHT senzora");
  } else {
    Serial.print("Vlajnost: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");
  }
  delay(1000);
}
