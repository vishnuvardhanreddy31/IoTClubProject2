#define BLYNK_TEMPLATE_ID "TMPLZ4_MFhfx"
#define BLYNK_DEVICE_NAME "SMART UART"
#define RXp2 16
#define TXp2 17
#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
#define APP_DEBUG
#define USE_WROVER_BOARD
#include "BlynkEdgent.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  BlynkEdgent.begin();
}

void readvalue()
{
 String v=Serial2.readString();
 v=v.toFloat();


  Serial.print("Message received: ");
  Serial.println(v);
  
  Blynk.virtualWrite(V2, v);
  delay(1000);
}



void loop() {
  BlynkEdgent.run();
  readvalue();
  
}
