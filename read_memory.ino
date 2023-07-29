#include <OneWire.h>

OneWire ds(2);// OneWire bus on digital pin 2


void setup() {
  Serial.begin (9600);
}


void loop() {
  byte i=0;
  byte present=0;
  byte addr[8];
  byte data[32];

    if ( !ds.search(addr)) {
    Serial.println("No more addresses.");
    Serial.println();
    ds.reset_search();
    delay(250);
    return;
  }
    Serial.print("ROM =");
  for( i = 0; i < 8; i++) {
    Serial.write(' ');
    Serial.print(addr[i], HEX);
    Serial.println();
  }
  if (OneWire::crc8(addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");
      return;
  }

 
  ds.reset();
  ds.select(addr);
  ds.write(0xF0);
  ds.write(0x00);
    Serial.print("memory content is: ");
  for (i=0;i<32;i++){
    byte c=ds.read();
      Serial.print(c, HEX);
  }
      Serial.println();

}
    
