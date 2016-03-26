// version of the app
char *versionString = "1.0.0";

// raw sensor values
int photoResistorValue = 0;
int tempSensorValue = 0;

// in the case of the temp sensor, the doctored value
double temperature = 0.0;

void setup() {
    // publish some variables that can be gotten using GET /device_id/variable_name
    Particle.variable("lightSensor", photoResistorValue);
    Particle.variable("tempSensor", temperature);
    Particle.variable("version", versionString);
    
    // set pin modes for Analog 0 and 1
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
}

void loop() {
    // get the raw values from the pins
    photoResistorValue = analogRead(A0);
    tempSensorValue = analogRead(A1);
    
    // figure out what the temp value is (in celsius I think)
    temperature = (((tempSensorValue * 3.3)/4095) - 0.5) * 100;
    
    // do this every half a second
    delay(500);
}
