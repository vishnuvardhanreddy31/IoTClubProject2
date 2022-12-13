#define BLYNK_TEMPLATE_ID "TMPLZ4_MFhfx"
#define BLYNK_DEVICE_NAME "SMART UART"
#define RXp2 16
#define TXp2 17
#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
#define APP_DEBUG
#define USE_WROVER_BOARD
#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11
#include "BlynkEdgent.h"
#define Dht D7
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   dht.begin();
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
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  Blynk.virtualWrite(V3, h);
  Blynk.virtualWrite(V1, t);

  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}



void loop() {
  BlynkEdgent.run();
  readvalue();
  
}
