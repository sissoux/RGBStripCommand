#ifndef STRIPLED_H
#define STRIPLED_H

#include "Arduino.h"
#include "FastLED.h"


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
    boolean Trigger = false;
    elapsedMillis t;
    LightMode Mode = Flash;
    
    uint16_t TRise = 10;
    uint16_t THigh = 30;
    uint16_t TFall = 100;
    uint16_t MaxBrightness = 100;
    uint16_t Brightness;
    uint16_t Offset = 0;

    StripLED();
    void update();
    void init(uint16_t ID, uint8_t Group);
    
    private:
    uint16_t SumTRise;
    uint16_t SumTHigh;
    uint16_t SumTFall;
    uint16_t UpStep;
    uint16_t DownStep;
    boolean Active = false;
};


#endif
