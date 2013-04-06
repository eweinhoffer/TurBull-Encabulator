#include <Encabulator.h>
#include <Wire.h>

int loopCounter = 0;

int tempR = 0;
int tempG = 0;
int tempB = 0;
int i = 0;

float tempX = 0.0;
float tempY = 0.0;

int palindrome = 0; 

void setup() {               

  // secret startup sequence 
  
  Encabulator.upUpDownDownLeftRightLeftRightBA();

  // enable some debugging on the serial port

  Encabulator.setVerbose(true);

  // check the temperature
  
  float weatherReport = Encabulator.temperature.getFahrenheit();
  Serial.print("Currrent operating temperature is: ");
  Serial.print(weatherReport);
  Serial.println("F");

  // check EEPROM   

  for (uint16_t i = 0 ; i < 52 ; i++) {
    Serial.print((char) Encabulator.eeprom.readAddress(i));
  }  
  Serial.println();

  // check the DAC

  Encabulator.dac.write(100);

  // check the XYZ

  int x = Encabulator.accelerometer.x();
  int y = Encabulator.accelerometer.y();
  int z = Encabulator.accelerometer.z();

  Encabulator.stripBankA.jumpHeaderToRGB(1, 255, 0, 0); 
  delay(1000);
  Encabulator.stripBankA.jumpHeaderToRGB(1, 0, 255, 0);
  delay(1000);
  Encabulator.stripBankA.jumpHeaderToRGB(1, 0, 0, 255);
  delay(1000);

  Encabulator.blackout();
  
  delay(500);
    
}

void loop() 
{
    Encabulator.stripBankA.jumpHeaderToRGB(1, 255, 0, 0);
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
