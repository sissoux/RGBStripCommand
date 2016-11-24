#include "StripLED.h"

StripLED::StripLED(uint16_t ID, uint8_t Group, Color *GlobalColorPointer):CurrentColor(0,0,0)
{
  this->ID = ID;
  this->Group = Group;
  t = 0;
  this->GlobalColorPtr = GlobalColorPointer;
}

StripLED::StripLED():CurrentColor(0,0,0)
{
}

void StripLED::update()
{
  if (Trigger && !Active)
  {
    Active = true;
    Trigger = false;
    SumTHigh = TRaise + THigh;
    SumTFall = SumTHigh + TFall;
    UpStep = MaxBrightness / TRaise;
    DownStep = MaxBrightness / TFall;
    t = 0;
  }
  if (Active)
  {
    if (this->Mode == Flash)
    {
      if (t < TRaise)
      {
        Brightness = UpStep * t;
      }
      else if (t < SumTHigh)
      {
        Brightness = MaxBrightness;
      }
      else if (t < SumTFall)
      {
        Brightness = MaxBrightness - DownStep*(t-SumTHigh);
      }
      else 
      { 
        Active = false;
      }
    }
    
  }
}


