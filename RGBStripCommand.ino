// BOF preprocessor bug prevent - insert me on top of your arduino-code
// From: http://www.a-control.de/arduino-fehler/?lang=en
#if 1
__asm volatile ("nop");
#endif

#include "define.h"
#include "FastLED.h"
#include <ArduinoJson.h>
#include "StripLED.h"
#include "StripCommand.h"

StripCommand StripCommander;

elapsedMillis RefreshOutputTimer = 0;
#define OUTPUT_REFRESH_RATE 7

DynamicJsonBuffer jsonBuffer;
char input[100];


void setup()
{
  FastLED.addLeds<NEOPIXEL, 2>(StripCommander.leds, 0, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 3>(StripCommander.leds, NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 4>(StripCommander.leds, 2 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 5>(StripCommander.leds, 3 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  Serial.begin(115200);
  while (!Serial);
#ifdef VERBOSE
  Serial.println("Port Opened.");
  Serial.println("Start StripCommander Begin");
#endif
  StripCommander.begin();
#ifdef VERBOSE
  Serial.println("StripCommander successfully begun.");
#endif
  FastLED.show();
}

void loop()
{
  tasker();
}

void tasker()
{
  serialParse();

  if (RefreshOutputTimer >= OUTPUT_REFRESH_RATE)
  {
    RefreshOutputTimer = 0;
    StripCommander.dynamicStateUpdate();
    if (true);//StripCommander.StateChanged)
    {
      StripCommander.StateChanged = false;
      FastLED.show();
    }

  }
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
    else if (strcmp(method, "setToHSV") == 0)
    {
      Serial.println("set to HSV value");
      StripCommander.setToHSV(root["H"], root["S"], root["V"]);
    }
    else if (strcmp(method, "rainbow") == 0)
    {
      Serial.println("Rainbow");
      StripCommander.rainbow();
    }
    else if (strcmp(method, "flash") == 0)
    {
      Serial.println("Flash");
      uint8_t FlashCount = random(1, 15);
      for (uint8_t i = 0; i <= FlashCount; i++)
      {
        StripCommander.flash(random(0, NUM_LEDS));
      }
    }
    else if (strcmp(method, "groupFlash") == 0)
    {
      uint8_t gr = root["G"];
      Serial.print("Flash Group");
      Serial.println(gr);
      for (uint8_t i = 0; i <= NUM_LEDS; i++)
      {
        if (StripCommander.Group[i] = gr)
        {
          StripCommander.flash(i);
        }
      }
    }
    else
    {
      Serial.println("ca ne marche pas ^^");
    }
    Serial.println(micros() - time);
  }
}





