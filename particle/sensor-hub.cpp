char *versionString = "1.1.0";

int photoResistorValue = 0;
int potValue = 0;
int tempSensorValue = 0;

double temperature = 0.0;

void setup() {
    Particle.variable("lightSensor", photoResistorValue);
    Particle.variable("trimPot", potValue);
    Particle.variable("temperature", temperature);
    Particle.variable("version", versionString);
    
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(D5, INPUT);
}

void loop() {
    photoResistorValue = analogRead(A0);
    potValue = analogRead(A1);
    
    temperature = (((tempSensorValue * 3.3)/4095) - 0.5) * 100;
    
    delay(500);
}
