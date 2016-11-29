#include "StripLED.h"

StripLED::StripLED()
{
}

void StripLED::init(uint16_t ID, uint8_t Group)
{
  this->ID = ID;
  this->Group = Group;
}

void StripLED::update()
{
  if (Trigger && !Active)
  {
    Active = true;
    Trigger = false;
    TRise = random(5, 25);
    THigh = random(5, 25);
    TFall = random(50, 200);
    Offset = random(0, 300);
    SumTRise = TRise + Offset;
    SumTHigh = SumTRise + THigh;
    SumTFall = SumTHigh + TFall;
    UpStep = 100 * MaxBrightness / TRise;
    DownStep = 100 * MaxBrightness / TFall;
    t = 0;
#ifdef VERBOSE
    Serial.print("LED ");
    Serial.print(this->ID);
    Serial.print(" Trigger received, ");
    Serial.print("Offset = ");
    Serial.print(this->Offset);
    Serial.print("TR = ");
    Serial.print(this->TRise);
    Serial.print(", TH = ");
    Serial.print(this->THigh);
    Serial.print(", TF = ");
    Serial.println(this->TFall);
#endif
  }
  if (Active)
  {
    if (this->Mode == Flash)
    {
      if (t <= Offset)
      {
        Brightness = 0;
      }
      else if (t <= SumTRise)
      {
        Brightness = (UpStep * t) / 100;
      }
      else if (t <= SumTHigh)
      {
        Brightness = MaxBrightness;
      }
      else if (t <= SumTFall)
      {
        Brightness = (MaxBrightness - DownStep * (t - SumTHigh) / 100);
      }
      else
      {
        Active = false;
        Brightness = 0;
      }
    }
  }
}


