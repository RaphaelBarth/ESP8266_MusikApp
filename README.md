# ESP8266_MusikApp

## Doku
- [Arduino IDE](https://www.arduino.cc/en/software)
- [Set-up Arduino IDE](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/)
- [Pin Layout Wemos D1 Mini](https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/)
- [HTERM](https://www.der-hammer.info/pages/terminal.html)

## How to Use
1. Kommunikation herstellen → Microcontroller mit PC verbinden und
    - Arduino IDE installieren und Seriellen Monitor öffnen
    - HTerm starten
    -Datenrate beträgt 9600
2. Neu SSID und zugehöriges Passwort eingeben 
    - Bei der Arduino IDE auf No Line Ending umstellen
    - wenn Arduino IDE 2.* benutzt wird senden mit strg + enter
3. Nach automatischem Neustart des Microcontrollers (blaue LED → alles gut) 
im Browser http://esp8266.local oder IP-Adresse eingeben. 
    - Die Domain Adresse funktioniert nicht bei Android
4. Magie…🦄


## Development
Nach Änderungen im Code muss zum neuen Flashen des Mikrocontrollers der 
Wemos D1 mini clone verwendet werden.

