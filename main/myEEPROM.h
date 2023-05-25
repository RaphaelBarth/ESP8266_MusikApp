#include <EEPROM.h>
#include <Arduino.h>

#ifndef MYEEPROM_H
#define MYEEPROM_H

// Change the STORED_WORD is another string
const size_t EEPROMsize = 64;
const size_t EEPROMaddress1 = 0;
const size_t EEPROMaddress2 = 32;

void EEPROMend();
void EEPROMbegin();
size_t EEPROMwriteWord(const String &word, int address);
size_t EEPROMreadWord(String &word, int address);

#endif //MYEEPROM_H