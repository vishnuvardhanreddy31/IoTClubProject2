
#include <LiquidCrystal_I2C.h>

//define I2C address......
LiquidCrystal_I2C lcd(0x27,16,2);


#include <Wire.h> 

const float mmPerPulse = 0.173;  //put here the value of rain in mm for each movement of the bucket

float mmTotali = 0;
int sensore = 0;
int statoPrecedente = 0;

void setup() {
  pinMode(9, INPUT);

  lcd.init();
  lcd.init();
  
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("VNR VJIET-Civil");
  lcd.setCursor(2,1);
  lcd.print("Rain Gauge");

  delay(1000);

  lcd.clear();
}

void loop() {
  sensore = digitalRead(9);
  
  if (sensore != statoPrecedente) {
    mmTotali = mmTotali + mmPerPulse;
  }
  
  delay(500);
  
  statoPrecedente = sensore;

 

  lcd.setCursor(2,0);
  lcd.print("Gauage Value:");
  lcd.setCursor(2,1);
  lcd.print(mmTotali);
  lcd.setCursor(7,1);
  lcd.print("mm");
}
