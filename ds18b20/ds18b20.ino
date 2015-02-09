#include <OneWire.h>

OneWire ds(10);

void setup() {
  Serial.begin(9600);
}

void loop() {
  ds.reset();
  ds.skip();
  ds.write(0x44);

  delay(750);

  ds.reset();
  ds.skip();
  ds.write(0xBE);
  
  const byte lsb = ds.read();
  const byte msb = ds.read();
  
  const float temp = ((msb << 8) | lsb) / 16.0f;
  Serial.println(temp);
}
