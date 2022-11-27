#include <Arduino.h>
#include <SPI.h>
#include <ctype.h>

uint8_t chipSelectPin = 10;
uint8_t arr[5] = {0xDE, 0xAD, 0xBE, 0xEF, 0x00};
int i =0;
void setup() {
  Serial.begin(9600);
  SPI.begin();
  pinMode(chipSelectPin, OUTPUT);
  digitalWrite(chipSelectPin, HIGH);
}

void loop() {
  spiWrite(arr[i%5]);
  int result = spiRead();
  Serial.println(result, HEX);
  delay(1000);
  i++;
}

uint16_t spiRead() {
  uint16_t result = 0;
  SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE1));
  digitalWrite(chipSelectPin, LOW);
  result = SPI.transfer(0x00);
  digitalWrite(chipSelectPin, HIGH);
  SPI.endTransaction();
  return (result);
} 
void spiWrite(uint8_t thisValue) {
  SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE1));
  digitalWrite(chipSelectPin, LOW);
  SPI.transfer(thisValue);
  digitalWrite(chipSelectPin, HIGH);
  SPI.endTransaction();
}