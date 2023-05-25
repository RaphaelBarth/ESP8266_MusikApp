#include "myEEPROM.h"

void EEPROMbegin() {
  EEPROM.begin(EEPROMsize);
}
void EEPROMend() {
  EEPROM.end();
  
}
size_t EEPROMwriteWord(const String &word, int address) {
  EEPROMbegin();
  byte len = word.length();
  EEPROM.write(address, len);
  for (size_t i = 0; i < len; i++) {
    EEPROM.write(address + 1 + i, word[i]);
  }
  EEPROM.commit();
  EEPROMend();

  return address + 1 + len;
}



size_t EEPROMreadWord(String &word, int address) {
  EEPROMbegin();
  size_t newStrLen = EEPROM.read(address);
  char data[newStrLen + 1];

  for (int i = 0; i < newStrLen; i++) {
    data[i] = EEPROM.read(address + 1 + i);
  }
  EEPROMend();
  
  data[newStrLen] = '\0';
  word = String(data);
  
  return address + 1 + newStrLen;
}