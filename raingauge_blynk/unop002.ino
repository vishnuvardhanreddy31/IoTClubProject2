#include <LiquidCrystal_I2C.h>

//define I2C address......
LiquidCrystal_I2C lcd(0x27,16,2);


#include <Wire.h> 

const float mmPerPulse = 0.17;  //put here the value of rain in mm for each movement of the bucket

float mmTotali = 0;
int sensore = 0;
int statoPrecedente = 0;

void setup() {
  pinMode(9, INPUT);

  //lcd.init();
  lcd.init();
  
  lcd.backlight();
Serial.begin(9600);
  lcd.setCursor(1,0);
  lcd.print("VNR VJI");
 lcd.setCursor(0,1);
  lcd.print("ET");

  
  delay(1900);
 //lcd.clear();
//lcd.print("Civil");
//delay(1500);
 lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("PLUVIO ");
  lcd.setCursor(0,1);
  lcd.print("METER");

  delay(1500);

  lcd.clear();
}

void loop() {
  sensore = digitalRead(9);
  
  if (sensore != statoPrecedente) {
    mmTotali = mmTotali + mmPerPulse;
    Serial.println(mmTotali);
    delay(1500);
  }
  
  delay(500);
  
  statoPrecedente = sensore;

 

  lcd.setCursor(0,0);
  lcd.print("RAINFALL");
  lcd.setCursor(0,1);
  lcd.print(":");

  lcd.setCursor(1,1);
  lcd.print(mmTotali);
  Serial.println(mmTotali);
  lcd.setCursor(6,1);
  lcd.print("mm");

 


  
 delay(500);
}