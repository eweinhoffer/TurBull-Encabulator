TurBull-Encabulator
===================

Arduino code for controlling Red Bull's TurBull Encabulator board. 
For the Arduino library, head over to Google Code: https://code.google.com/p/turbull-encabulator/

To see the announcement blog post on MAKE, head here: http://blog.makezine.com/2013/04/08/red-bull-turbull-encabulator/

A few tips (and reminders) for using the TurBull Encabulator: 

1. You'll need a 12V supply to power the RGB LED strips and another way to power the Arduino.
2. In order to solder to the LED Strips, remove the waterproof coating with a hobbyknife. Use the knife to scrape all coating off each solder pad; you won't be able to tin them otherwise.
3. Tinning the strips and connecting wires before soldering will make connecting multiple sections of LED strips together much easier.
4. Test your LED reel before cutting it up, in case the individual LEDs aren't working properly. My code flashes R, G, and B for all letters in the setup to test that all three LEDs are working in each.

The 1D Pong game is still in progress. This initial sketch bounces the light back and forth between two sides of the Adafruit RGB LED strip, 
increasing in speed before maxing out and staying at a certain level (5ms delays). The color of the light changes each time it hits a wall, 
and the user can attach a button to try and hit it at the right time.
