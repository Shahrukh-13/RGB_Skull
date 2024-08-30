#include <FastLED.h>

#define NUM_LEDS  74  // 24(Ring 1) + 24(Ring 2) + 24(Ring 3) + 2(Eyes)
#define LED_PIN   6

CRGB leds[NUM_LEDS];
uint8_t colorIndex[NUM_LEDS];


DEFINE_GRADIENT_PALETTE( bhw3_51_gp ) 
{
    0,   1,  1,  1,
   35,   1,  1, 21,
   61,   5, 13,123,
   86,  27, 35,184,
  127, 252,250,237,
  160, 229, 43,233,
  204,  68,  6,212,
  255,  19,  8, 93};


CRGBPalette16 palette = bhw3_51_gp;

void setup() 
{
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(20);

  //Fill the colorIndex array with random numbers
  for (int i = 0; i < NUM_LEDS; i++) 
  {
    colorIndex[i] = random8();
  }
}

void loop() 
{
  
  // Color each pixel from the palette using the index from colorIndex[]
  for (int i = 0; i < NUM_LEDS; i++) 
  {
    leds[i] = ColorFromPalette(palette, colorIndex[i]);
  }
  
  EVERY_N_MILLISECONDS(5)
  {
    for (int i = 0; i < NUM_LEDS; i++) 
    {
      colorIndex[i]++;
    }
  }
  FastLED.show();
}
