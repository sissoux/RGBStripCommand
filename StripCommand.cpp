
#include "StripCommand.h"

StripCommand::StripCommand(uint8_t NOfStrip, uint16_t PixPerStrip[]): GlobalColor(0, 0, 0)
{
  for (uint8_t n = 0; n < NOfStrip; n++)
  {
    PixelPerStrip[n] = PixPerStrip[n];
    strip[n] = 0;//Striptable[n];
    NumberOfPixel = NumberOfPixel + PixelPerStrip[n];
  }
  NumberOfStrip = NOfStrip;
  for (uint8_t p = 0; p < NumberOfPixel; p++)
  {
    pixels[p].t = 0;
    pixels[p].GlobalColorPtr = &GlobalColor;
  }
}

void StripCommand::begin(Adafruit_NeoPixel *Striptable[])
{
  for (uint8_t n = 0; n < NumberOfStrip; n++)
  {
    strip[n] = Striptable[n];
    strip[n]->begin();
  }
}



void StripCommand::fadeToHSV(float H, float S, float V, uint8_t Delay)
{

}

void StripCommand::setToHSV(float H, float S, float V)
{

}

void StripCommand::fadeToRGB(uint16_t R, uint16_t G, uint16_t B, uint8_t Delay)
{

}
//{method:setToRGB,R:15,G:10,B:120}
void StripCommand::setToRGB(uint16_t R, uint16_t G, uint16_t B)
{
  uint32_t color = Adafruit_NeoPixel::Color(R, G, B);
  for (uint8_t n = 0; n < NumberOfStrip; n++)
  {
    //for (uint8_t p = 0; p < PixelPerStrip[n]; p++)
    //{
      strip[n]->setPixelColor(1, color);
    //}
    strip[n]->show();
  }
  Serial.print("Color should be set to: ");
  Serial.print(Adafruit_NeoPixel::Color(R, G, B));
  Serial.print(", Actual value is: ");
  Serial.println(strip[0]->getPixelColor(1));
}

/*
  // Fill the dots one after the other with a color
  void StripCommand::colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip[0].numPixels(); i++) {
    strip[0].setPixelColor(i, c);
    strip[0].show();
    delay(wait);
  }
  }

  void StripCommand::rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip[0].numPixels(); i++) {
      strip[0].setPixelColor(i, Wheel((i + j) & 255));
    }
    strip[0].show();
    delay(wait);
  }
  }

  // Slightly different, this makes the rainbow equally distributed throughout
  void StripCommand::rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip[0].numPixels(); i++) {
      strip[0].setPixelColor(i, Wheel(((i * 256 / strip[0].numPixels()) + j) & 255));
    }
    strip[0].show();
    delay(wait);
  }
  }

  //Theatre-style crawling lights.
  void StripCommand::theaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip[0].numPixels(); i = i + 3) {
        strip[0].setPixelColor(i + q, c);  //turn every third pixel on
      }
      strip[0].show();

      delay(wait);

      for (uint16_t i = 0; i < strip[0].numPixels(); i = i + 3) {
        strip[0].setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
  }

  //Theatre-style crawling lights with rainbow effect
  void StripCommand::theaterChaseRainbow(uint8_t wait) {
  for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip[0].numPixels(); i = i + 3) {
        strip[0].setPixelColor(i + q, Wheel( (i + j) % 255)); //turn every third pixel on
      }
      strip[0].show();

      delay(wait);

      for (uint16_t i = 0; i < strip[0].numPixels(); i = i + 3) {
        strip[0].setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
  }

  // Input a value 0 to 255 to get a color value.
  // The colours are a transition r - g - b - back to r.
  uint32_t StripCommand::Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip[0].Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip[0].Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip[0].Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }*/
