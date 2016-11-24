#include "Arduino.h"
#include "StripLED.h"
#include <Adafruit_NeoPixel.h>
#include "Color.h"

#ifndef STRIPCOMMAND_H
#define STRIPCOMMAND_H


class StripCommand
{
  public:
    uint16_t NumberOfPixel = 0;
    uint16_t NumberOfStrip = 0;
    uint16_t PixelPerStrip[];
    Adafruit_NeoPixel *strip[];

    Color GlobalColor;

    StripLED pixels[];
    
    uint32_t previousColor = 0;

    StripCommand(uint8_t NOfStrip, uint16_t PixPerStrip[]);
    void begin(Adafruit_NeoPixel *Striptable[]);
    
    void fadeToHSV(float H, float S, float V, uint8_t Delay);
    void setToHSV(float H, float S, float V);
    void fadeToRGB(uint16_t R, uint16_t G, uint16_t B, uint8_t Delay);
    void setToRGB(uint16_t R, uint16_t G, uint16_t B);

    void fadePixelToHSV(uint16_t pixel, float H, float S, float V, uint8_t Delay);
    void setPixelToHSV(uint16_t pixel, float H, float S, float V);
    void fadePixelToRGB(uint16_t pixel, uint16_t R, uint16_t G, uint16_t B, uint8_t Delay);
    void setPixelToRGB(uint16_t pixel, uint16_t R, uint16_t G, uint16_t B);
    

    void rainbow(uint8_t wait);
    void colorWipe(uint32_t c, uint8_t wait);
    void rainbowCycle(uint8_t wait);
    void theaterChase(uint32_t c, uint8_t wait);
    void theaterChaseRainbow(uint8_t wait);
    uint32_t Wheel(byte WheelPos);


  private:
};



#endif

