#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>
#include "StripLED.h"
#include "StripCommand.h"

//const uint16_t NumberOfPixels = 56;

uint16_t pixPerStrip[4] = {14, 14, 14, 14};
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(14, 9, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(14, 10, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(14, 11, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(14, 12, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel *stripTable[4];

//StripLED pixel[NumberOfPixels];

StripCommand StripCommander(stripTable, 4, pixPerStrip);

DynamicJsonBuffer jsonBuffer;
char input[100];

void setup()
{
  stripTable[0] = &strip1;
  stripTable[1] = &strip2;
  stripTable[2] = &strip3;
  stripTable[3] = &strip4;
  Serial.begin(115200);
  while (!Serial);
  // Some example procedures showing how to display to the pixels:
  /*StripCommander.colorWipe(strip1.Color(255, 0, 0), 50); // Red
    StripCommander.colorWipe(strip1.Color(0, 255, 0), 50); // Green
    StripCommander.colorWipe(strip1.Color(0, 0, 255), 50); // Blue
    StripCommander.theaterChase(strip1.Color(127, 127, 127), 50); // White
    StripCommander.theaterChase(strip1.Color(127, 0, 0), 50); // Red
    StripCommander.theaterChase(strip1.Color(0, 0, 127), 50); // Blue

    StripCommander.rainbow(20);
    StripCommander.rainbowCycle(20);
    StripCommander.theaterChaseRainbow(50);*/
  Serial.println("Port Opened.");

  Serial.println("Start StripCommander Begin");
  StripCommander.begin();
  Serial.println("StripCommander successfully begun.");

}

void loop()
{
  tasker();
}

void tasker()
{
  serialParse();
}


void serialParse()
{
  if (Serial.available()) {
    Serial.println("Serial received.");
    unsigned long time = micros();
    char lastChar = '\0';
    int i = 0;

    while (lastChar != '\r') {
      if (Serial.available()) {
        lastChar = Serial.read();
        input[i] = lastChar;
        i++;
      }
    }

    JsonObject& root = jsonBuffer.parseObject(input);
    const char* method = root["method"];
    Serial.println(method);
    if (strcmp(method, "fadeToRGB") == 0)
    {
      StripCommander.fadeToRGB(root["R"], root["G"], root["B"], root["Delay"]);
    }
    else if (strcmp(method, "setToRGB") == 0)
    {
      Serial.println("set to RGB value");
      StripCommander.setToRGB(root["R"], root["G"], root["B"]);
    }
    else
    {
      Serial.println("ca ne marche pas ^^");
    }
    Serial.println(micros() - time);
  }
}





