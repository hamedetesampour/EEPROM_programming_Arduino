#include <OneWire.h>

OneWire ds(2);
void setup() {
  Serial.begin(9600);
}


void loop() {
  byte i=0;
  byte present=0;
  byte addr[8];
  char newstring[]="Hamregis";
  byte c[8];
  
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
  }
  if (OneWire::crc8(addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");
      return;
  }
  Serial.println();

  
  ds.reset();
  ds.select(addr);
  ds.write(0x99);
  ds.write(0x00);
 for (byte j=0;j<sizeof(newstring)-1;j++)
    ds.write(newstring[j]);

  ds.reset();
  ds.select(addr);
  ds.write(0xC3);
  ds.write(0x00);
  Serial.print("register content is: ");
  for (i=0;i<8;i++){
    byte c=ds.read();
    Serial.print(char(c));
  }
  Serial.println();
}
