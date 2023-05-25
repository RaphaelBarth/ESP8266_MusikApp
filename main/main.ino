#include "myEEPROM.h"
#include "myServer.h"
#include "music.h"

bool playMusic = false;
int numberMusik = 0;
void serverCallback(int number) {
  //Serial.println("pressed Button: " + String(number));
  playMusic = true;
  numberMusik = number;
}

void setup() {
  Serial.begin(9600);
  Serial.println();

  Serial.println("read Data from EEPROM:");
  String temp_pwd, temp_ssid;
  EEPROMreadWord(temp_pwd, EEPROMaddress1);
  EEPROMreadWord(temp_ssid, EEPROMaddress2);
  Serial.println("\tPWD: " + String(temp_pwd));
  Serial.println("\tSSID: " + String(temp_ssid));

  SERVERsetup(serverCallback);
  SERVERbegin(temp_ssid, temp_pwd);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);  
}

bool waitForData(size_t period, size_t repetitions) {
  while (!(Serial.available() > 0)) {
    delay(period);
    if (repetitions-- == 0) {
      return false;
    }
  }
  return true;
}

void changeSettings() {
  Serial.print("\tnewSSID: ");
  if (!waitForData(1000, 10)) {
    return;
  }
  String newSSID = Serial.readString();
  Serial.println(newSSID);
  Serial.print("\tnewPWD: ");
  if (!waitForData(1000, 10)) {
    return;
  }
  String newPWD = Serial.readString();
  Serial.println(newPWD);

  EEPROMwriteWord(newPWD, EEPROMaddress1);
  EEPROMwriteWord(newSSID, EEPROMaddress2);

  ESP.restart();
}

void loop() {

  Serial.println("Change WIFI settings ? (yes)");

  do {
    MDNS.update();
    if (waitForData(10, 1)) {
      if (Serial.readString().equals("yes")) {
        changeSettings();
      }
    }
  } while (!playMusic);

  delay(10);
  Serial.println("playMusic " + String(numberMusik));
  delay(10);
  MUSICplay(numberMusik);
  Serial.println("endMusic");
  playMusic = false;
}