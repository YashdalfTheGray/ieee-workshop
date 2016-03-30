// This #include statement was automatically added by the Particle IDE.
#include "Adafruit_DHT/Adafruit_DHT.h"

#define DHTPIN 5
#define DHTTYPE DHT11

char *versionString = "1.2.0";

int photoResistorValue = 0;
int potValue = 0;
int tempSensorValue = 0;
int humiditySensorValue = 0;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    if (Particle.variable("lightSensor", photoResistorValue)) {
        Particle.publish("Variable lightSensor published", "", 60, PRIVATE);
    }
    if (Particle.variable("trimPot", potValue)) {
        Particle.publish("Variable trimPot published", "", 60, PRIVATE);
    }
    if (Particle.variable("temperature", tempSensorValue)) {
        Particle.publish("Variable temperature published", "", 60, PRIVATE);
    }
    if (Particle.variable("humidity", humiditySensorValue)) {
        Particle.publish("Variable humidity published", "", 60, PRIVATE);
    }
    if (Particle.variable("version", versionString)) {
        Particle.publish("Variable version published", "", 60, PRIVATE);
    }
    
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    
    dht.begin();
}

void loop() {
    photoResistorValue = analogRead(A0);
    potValue = analogRead(A1);
    
    tempSensorValue = dht.getTempFarenheit();
    
    humiditySensorValue = dht.getHumidity();
    
    delay(1000);
}
