#include <Encabulator.h>
#include <Wire.h>

void setup() 
{               

  // startup sequence 
  
  Encabulator.upUpDownDownLeftRightLeftRightBA();

  // enable some debugging on the serial port

  Encabulator.setVerbose(true);
  
  // test the lights
  
  Encabulator.stripBankA.jumpHeaderToRGB(1, 255, 0, 0);  // Make the strip plugged into Bank A1 turn Red
  Encabulator.stripBankA.jumpHeaderToRGB(2, 255, 0, 0);
  Encabulator.stripBankA.jumpHeaderToRGB(3, 255, 0, 0);
  Encabulator.stripBankA.jumpHeaderToRGB(4, 255, 0, 0);
  delay(1000);                                           // Delay 1 second
  Encabulator.stripBankA.jumpHeaderToRGB(1, 0, 255, 0);  // A1 goes Blue
  Encabulator.stripBankA.jumpHeaderToRGB(2, 0, 255, 0);
  Encabulator.stripBankA.jumpHeaderToRGB(3, 0, 255, 0);
  Encabulator.stripBankA.jumpHeaderToRGB(4, 0, 255, 0);
  delay(1000);
  Encabulator.stripBankA.jumpHeaderToRGB(1, 0, 0, 255);  // Al goes Green
  Encabulator.stripBankA.jumpHeaderToRGB(2, 0, 0, 255);
  Encabulator.stripBankA.jumpHeaderToRGB(3, 0, 0, 255);
  Encabulator.stripBankA.jumpHeaderToRGB(4, 0, 0, 255);
  delay(1000);

  Encabulator.blackout(); // turn all LEDs off
 
  delay(500);
    
}

void loop() 
{
  for (int i = 0; i < 10; i++) 
 { 
    Encabulator.stripBankA.jumpHeaderToRGB(1, 255, 0, 0); // jumpHeadertoRGB([Screw terminal number], [Red value], [Green], [Blue])
    Encabulator.stripBankA.jumpHeaderToRGB(2, 0, 0, 0);
    Encabulator.stripBankA.jumpHeaderToRGB(3, 0, 0, 0); 
    Encabulator.stripBankA.jumpHeaderToRGB(4, 0, 0, 0); 
    delay(500);
    Encabulator.stripBankA.jumpHeaderToRGB(1, 0, 0, 0); 
    Encabulator.stripBankA.jumpHeaderToRGB(2, 255, 255, 0); 
    Encabulator.stripBankA.jumpHeaderToRGB(3, 0, 0, 0); 
    Encabulator.stripBankA.jumpHeaderToRGB(4, 0, 0, 0); 
    delay(500);
    Encabulator.stripBankA.jumpHeaderToRGB(1, 0, 0, 0); 
    Encabulator.stripBankA.jumpHeaderToRGB(2, 0, 0, 0); 
    Encabulator.stripBankA.jumpHeaderToRGB(3, 0, 0, 255); 
    Encabulator.stripBankA.jumpHeaderToRGB(4, 0, 0, 0); 
    delay(500);
    Encabulator.stripBankA.jumpHeaderToRGB(1, 0, 0, 0); 
    Encabulator.stripBankA.jumpHeaderToRGB(2, 0, 0, 0); 
    Encabulator.stripBankA.jumpHeaderToRGB(3, 0, 0, 0); 
    Encabulator.stripBankA.jumpHeaderToRGB(4, 255, 0, 255); 
    delay(500);
 }
 Encabulator.blackout();
 delay(500);
  for (int i = 0; i < 5; i++) // Flash all letters on and off in red.
  {
    Encabulator.stripBankA.jumpHeaderToRGB(1, 255, 0, 0);
    Encabulator.stripBankA.jumpHeaderToRGB(2, 255, 0, 0);
    Encabulator.stripBankA.jumpHeaderToRGB(3, 255, 0, 0);
    Encabulator.stripBankA.jumpHeaderToRGB(4, 255, 0, 0);
    delay(750);
    Encabulator.blackout();
    delay(750);
  }
 Encabulator.blackout();
 delay(500);
    for (int i = 0; i < 30; i++) // Flash all letters on and off in a random color.
  {
    int randR = random(10, 255);
    int randG = random(10, 255);
    int randB = random(10, 255);
    Encabulator.stripBankA.jumpHeaderToRGB(1, randR, randG, randB);
    Encabulator.stripBankA.jumpHeaderToRGB(2, randR, randG, randB);
    Encabulator.stripBankA.jumpHeaderToRGB(3, randR, randG, randB);
    Encabulator.stripBankA.jumpHeaderToRGB(4, randR, randG, randB);
    delay(750);
    Encabulator.blackout();
    delay(750);
  }
}
