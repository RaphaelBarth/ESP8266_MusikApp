#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266mDNS.h>
#include <Arduino.h>

#ifndef MYSERVER_H
#define MYSERVER_H

void SERVERsetup(void (*callback)(int));
void SERVERbegin(String ssid, String password);

#endif //MYSERVER_H