#include "Arduino.h"
#include "StripLED.h"
#include "FastLED.h"
#include "define.h"

#ifndef STRIPCOMMAND_H
#define STRIPCOMMAND_H

class StripCommand
{
  public:
    uint8_t Group[NUM_LEDS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5};
    CRGB leds[NUM_LEDS];
    boolean StateChanged = true;

    LightMode CurrentMode = Flash;


    StripLED pixels[NUM_LEDS];

    StripCommand();
    void begin();

    void dynamicStateUpdate();
    void flash(uint16_t Id);

    void fadeToHSV(float H, float S, float V, uint8_t Delay);
    void setToHSV(float H, float S, float V);
    void fadeToRGB(uint16_t R, uint16_t G, uint16_t B, uint8_t Delay);
    void setToRGB(uint16_t R, uint16_t G, uint16_t B);

    void fadePixelToHSV(uint16_t pixel, float H, float S, float V, uint8_t Delay);
    void setPixelToHSV(uint16_t pixel, float H, float S, float V);
    void fadePixelToRGB(uint16_t pixel, uint16_t R, uint16_t G, uint16_t B, uint8_t Delay);
    void setPixelToRGB(uint16_t pixel, uint16_t R, uint16_t G, uint16_t B);
    void rainbow(void);


    void rainbow(uint8_t wait);
    void colorWipe(uint32_t c, uint8_t wait);
    void rainbowCycle(uint8_t wait);
    void theaterChase(uint32_t c, uint8_t wait);
    void theaterChaseRainbow(uint8_t wait);
    uint32_t Wheel(byte WheelPos);


  private:
};



#endif

