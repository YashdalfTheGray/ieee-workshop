// This #include statement was automatically added by the Particle IDE.
#include "application.h"
#include "neopixel/neopixel.h"

SYSTEM_MODE(AUTOMATIC);

/* ======================= prototypes =============================== */

void colorAll(uint32_t c, uint8_t wait);
void colorWipe(uint32_t c, uint8_t wait);
void rainbow(uint8_t wait);
void rainbowCycle(uint8_t wait);
void allOff();
uint32_t Wheel(byte WheelPos);

int allOnRemote(String command);
int allOffRemote(String command);
int colorSweepRemote(String command);
int ledOnRemote(String command);
int ledOffRemote(String command);
int sweepOffRemote(String command);
int rainbowRemote(String command);
int rainbowCycleRemote(String command);

/* ======================= extra-examples.cpp ======================== */

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 24
#define PIXEL_PIN D6
#define PIXEL_TYPE WS2812B

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
//               note: if not specified, D2 is selected for you.
// Parameter 3 = pixel type [ WS2812, WS2812B, WS2811, TM1803 ]
//               note: if not specified, WS2812B is selected for you.
//               note: RGB order is automatically applied to WS2811,
//                     WS2812/WS2812B/TM1803 is GRB order.
//
// 800 KHz bitstream 800 KHz bitstream (most NeoPixel products ...
//                         ... WS2812 (6-pin part)/WS2812B (4-pin part) )
//
// 400 KHz bitstream (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//                   (Radio Shack Tri-Color LED Strip - TM1803 driver
//                    NOTE: RS Tri-Color LED's are grouped in sets of 3)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'

    Particle.function("ledOn", ledOnRemote);
    Particle.function("ledOff", ledOffRemote);
    Particle.function("allOn", allOnRemote);
    Particle.function("allOff", allOffRemote);
    Particle.function("colorSweep", colorSweepRemote);
    Particle.function("sweepOff", sweepOffRemote);
    Particle.function("rainbow", rainbowRemote);
    Particle.function("rainbowCycle", rainbowCycleRemote);
}

void loop() {
    // Some example procedures showing how to display to the pixels:
    // Do not run more than one of these at a time, or the b/g tasks
    // will be blocked.
    //--------------------------------------------------------------

    //strip.setPixelColor(0, strip.Color(255, 0, 255));
    //strip.show();

    //colorWipe(strip.Color(255, 0, 0), 50); // Red

    //colorWipe(strip.Color(0, 255, 0), 50); // Green

    //colorWipe(strip.Color(0, 0, 255), 50); // Blue

    //colorWipe(strip.Color(255, 255, 255), 50); // White

    //rainbow(20);
    //delay(5000);
    //allOff();
    //delay(5000);

    //rainbowCycle(20);

    //colorAll(strip.Color(0, 255, 255), 50); // Cyan
}

// Set all pixels in the strip to a solid color, then wait (ms)
void colorAll(uint32_t c, uint8_t wait) {
    uint16_t i;

    for(i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, c);
    }
    strip.show();
    delay(wait);
}

// Fill the dots one after the other with a color, wait (ms) after each one
void colorWipe(uint32_t c, uint8_t wait) {
    for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, c);
        strip.show();
        delay(wait);
    }
}

void rainbow(uint8_t wait) {
    uint16_t i, j;

    for(j=0; j<256; j++) {
        for(i=0; i<strip.numPixels(); i++) {
            strip.setPixelColor(i, Wheel((i+j) & 255));
        }
        strip.show();
        delay(wait);
    }
}

// Slightly different, this makes the rainbow equally distributed throughout, then wait (ms)
void rainbowCycle(uint8_t wait) {
    uint16_t i, j;

    for(j=0; j<256; j++) { // 1 cycle of all colors on wheel
        for(i=0; i< strip.numPixels(); i++) {
            strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
        }
        strip.show();
        delay(wait);
    }
}

void allOff() {
    for(int i = 0; i<PIXEL_COUNT; i++){
        strip.setPixelColor(i, strip.Color(0, 0, 0));
    }
    strip.show();
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
    if(WheelPos < 85) {
        return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    }
    else if(WheelPos < 170) {
        WheelPos -= 85;
        return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    else {
        WheelPos -= 170;
        return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
}

int allOnRemote(String command) {
    if(command.equals("red") || command.equals("Red")){
        colorAll(strip.Color(255, 0, 0), 50);
    }
    else if(command.equals("green") || command.equals("Green")){
        colorAll(strip.Color(0, 255, 0), 50);
    }
    else if(command.equals("blue") || command.equals("Blue")){
        colorAll(strip.Color(0, 0, 255), 50);
    }
    else if(command.equals("white") || command.equals("White")){
        colorAll(strip.Color(255, 255, 255), 50);
    }
    else {

        char inputStr[20];
        command.toCharArray(inputStr,20);
        char *p = strtok(inputStr,",");
        int red = atoi(p);
        p = strtok(NULL,",");
        int grn = atoi(p);
        p = strtok(NULL,",");
        int blu = atoi(p);
        p = strtok(NULL,",");
        colorAll(strip.Color(red,grn,blu), 50);
    }
    return 1;
}

int allOffRemote(String Command) {
    allOff();
    return 1;
}

int colorSweepRemote(String command) {
    if(command.equals("red") || command.equals("Red")){
        colorWipe(strip.Color(255, 0, 0), 50);
    }
    else if(command.equals("green") || command.equals("Green")){
        colorWipe(strip.Color(0, 255, 0), 50);
    }
    else if(command.equals("blue") || command.equals("Blue")){
        colorWipe(strip.Color(0, 0, 255), 50);
    }
    else if(command.equals("white") || command.equals("White")){
        colorWipe(strip.Color(255, 255, 255), 50);
    }
    else {

        char inputStr[20];
        command.toCharArray(inputStr,20);
        char *p = strtok(inputStr,",");
        int red = atoi(p);
        p = strtok(NULL,",");
        int grn = atoi(p);
        p = strtok(NULL,",");
        int blu = atoi(p);
        p = strtok(NULL,",");
        colorWipe(strip.Color(red,grn,blu), 50);
    }
    return 1;
}

int ledOnRemote(String command) {
    int i = 0;

    char inputStr[20];
    command.toCharArray(inputStr,20);
    char *p = strtok(inputStr,",");
    i = atoi(p);
    p = strtok(NULL,",");
    if (String(p).equals("red") || String(p).equals("Red")){
        strip.setPixelColor(i, strip.Color(255, 0, 0));
    }
    else if (String(p).equals("green") || String(p).equals("Green")){
        strip.setPixelColor(i, strip.Color(0, 255, 0));
    }
    else if (String(p).equals("blue") || String(p).equals("Blue")){
        strip.setPixelColor(i, strip.Color(0, 0, 255));
    }
    else if (String(p).equals("white") || String(p).equals("White")){
        strip.setPixelColor(i, strip.Color(255, 255, 255));
    }
    else {
        //parse out CSV colors

        uint8_t red = atoi(p);
        p = strtok(NULL,",");
        uint8_t grn = atoi(p);
        p = strtok(NULL,",");
        uint8_t blu = atoi(p);

        strip.setPixelColor(i, strip.Color(red, grn, blu));
    }
    strip.show();
    return 1;
}

int ledOffRemote(String command) {
    char inputStr[10];
    command.toCharArray(inputStr,10);
    char *p = strtok(inputStr,",");
    int i = atoi(p);
    strip.setPixelColor(i, strip.Color(0, 0, 0));
    strip.show();
    return 1;
}

int sweepOffRemote(String command) {
    colorWipe(strip.Color(0, 0, 0), 50);
    return 1;
}

int rainbowRemote(String command) {
    char inputStr[10];
    command.toCharArray(inputStr,10);
    int i = atoi(inputStr);

    long startMillis = millis();
    while(millis() < startMillis + i*1000){
        rainbow(20);
    }

    allOff();
    return 1;
}

int rainbowCycleRemote(String command) {
    char inputStr[10];
    command.toCharArray(inputStr,10);
    int i = atoi(inputStr);

    long startMillis = millis();
    while(millis() < startMillis + i*1000){
        rainbowCycle(20);
    }

    allOff();
    return 1;
}
