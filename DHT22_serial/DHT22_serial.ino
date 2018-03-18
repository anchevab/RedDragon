#include "DHT.h"
#define DHTPIN 2                // сензор на цифров пин 2
#define DHTTYPE DHT22           // сензор DHT22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);

// ======================= SETUP ======================
void setup() {
  Serial.begin(9600);
  Serial.println("DHT22 sensor za vlajnost i temperatura!");
  dht.begin();
}

// ====================== LOOP =======================
void loop() {
  float h = dht.readHumidity();                         // прочитане на стойността на влажността
  float t = dht.readTemperature();                      //прочитане на стойността на темп в Целзий
  float hic = dht.computeHeatIndex(t, h, false);
  if (isnan(h) || isnan(t)) {                           // проверка на изправността на сензора
    Serial.println("Greshka pri chetene na danni ot DHT sensor!");
    return;
  }
  Serial.print("Vlajnost: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C\t");
  Serial.print("Useshta se : ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print('\n');
  delay(1000);
}
