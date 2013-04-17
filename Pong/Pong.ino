/* 
This is the 1D Pong portion of the MAKE Turbull Encabulator Project. We received the board early and wanted
to create a simple demo with it. This is an expansion of that, intended to become an interactive demo at 
Maker Faire. 
*/

#include <Adafruit_NeoPixel.h>

//   Adafruit_NeoPixel(# of pixels, Arduino pin, pixel type flags);

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 6, NEO_GRB + NEO_KHZ800);

//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip)

const int buttonPin = 2;   
int inc = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  strip.begin();
}

void loop() {
  
int r = random(0,255);
int g = random(0,255);
int b = random(0,255);

  for (int i=0; i < 59; i++) // Going up
  {
    strip.setPixelColor(i,r,g,b);
    strip.show();
    delay(29-inc);
    strip.setPixelColor(i,0,0,0);
    strip.show();
    delay(29-inc);
    int buttonState = digitalRead(buttonPin);
    while (i > 56) {
      if (buttonState == HIGH && i == 57) {
        strip.setPixelColor(30,255,255,255);
        i = 59;
        break;
      }
      else if (buttonState == LOW && i == 57) {
        i = 0;
        strip.setPixelColor(30,255,0,0);
        break; 
      }
    }
  }
  if (inc == 24) {} // Keeps the speed constant once it gets this high
  else {inc=inc+3;} // If it isn't high enough, increase the speed.
  
r = random(0,255);
g = random(0,255);
b = random(0,255);

  for (int i=59; i > 0; i--) // Going down
  {
    strip.setPixelColor(i,r,g,b);
    strip.show();
    delay(29-inc);
    strip.setPixelColor(i,0,0,0);
    delay(29-inc);
    int buttonState = digitalRead(buttonPin);
    while (i > 54) {
      if (buttonState == HIGH) {break;}
      else {break;}
    }
  }
  if (inc == 24) {inc=24;}
  else {inc=inc+3;}
}

