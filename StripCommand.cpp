
#include "StripCommand.h"
#include "FastLED.h"

StripCommand::StripCommand()
{
}

void StripCommand::begin()
{
  for (uint8_t i = 0; i< NUM_LEDS ; i++ ) 
  {
    pixels[i].init(i,Group[i]);
  }
}

void StripCommand::dynamicStateUpdate()
{
  for (uint8_t i = 0; i< NUM_LEDS ; i++ ) 
  {
    pixels[i].update();
    leds[i]= CRGB(pixels[i].Brightness, pixels[i].Brightness, pixels[i].Brightness); //To be changed (Brightness update?)
  }
}

void StripCommand::flash(uint16_t Id)
{
  pixels[Id].Trigger = 1;
}

void StripCommand::fadeToHSV(float H, float S, float V, uint8_t Delay)
{

}

void StripCommand::setToHSV(float H, float S, float V)
{
  fill_solid(leds,NUM_LEDS,CHSV(H,S,V));
  StateChanged = true;
}

void StripCommand::fadeToRGB(uint16_t R, uint16_t G, uint16_t B, uint8_t Delay)
{

}

//{method:setToRGB,R:15,G:10,B:120}
void StripCommand::setToRGB(uint16_t R, uint16_t G, uint16_t B)
{
  fill_solid(leds,NUM_LEDS,CRGB(R,G,B));
  StateChanged = true;
}

void StripCommand::rainbow()
{
  fill_rainbow(leds,56,10,5);
  StateChanged = true;
}

