#define RXp2 16
#define TXp2 17



void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
}

void loop() {
  int x;
  // put your main code here, to run repeatedly:
Serial.println("Message Received: ");
x = Serial2.readString().toInt();
    Serial.println(Serial2.readString());
}
