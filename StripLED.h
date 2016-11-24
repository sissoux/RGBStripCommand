#ifndef STRIPLED_H
#define STRIPLED_H

#include "Arduino.h"
#include "Color.h"


typedef enum{
  Flash,
  Static,
  Chain,
  Standby
} LightMode;

class StripLED
{
  public:
    uint16_t ID = 0;
    uint8_t Group = 0;
    boolean Active = false;
    boolean Trigger = false;
    elapsedMillis t;
    LightMode Mode = Standby;
    uint16_t TRaise = 100;
    uint16_t THigh = 100;
    uint16_t TFall = 100;
    uint16_t SumTHigh;
    uint16_t SumTFall;
    uint16_t UpStep;
    uint16_t DownStep;
    uint16_t MaxBrightness;
    uint16_t Brightness;
    Color CurrentColor;
    Color *GlobalColorPtr;

    StripLED(uint16_t ID, uint8_t Group, Color *GlobalColor);
    StripLED();
    void update();


    private:
};


#endif
