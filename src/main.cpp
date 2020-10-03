#include <Arduino.h>
#include <DHT.h>
#define DHTPIN 27
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

String readDHTTemperature() {
  float t = dht.readTemperature();
  if (isnan(t)) {    
    return "--";
  }
  else {
    Serial.println(t);
    return String(t);
  }
}

String readDHTHumidity() {
  float h = dht.readHumidity();
  if (isnan(h)) {
    return "--";
  }
  else {
    return String(h);
  }
}

void setup() {
  pinMode(DHTPIN, INPUT_PULLUP);
  Serial.begin(57600);
  dht.begin();
}

void loop() { 
    Serial.println(readDHTTemperature().c_str());
    Serial.println(readDHTHumidity().c_str());
    delay(1000);
  
}