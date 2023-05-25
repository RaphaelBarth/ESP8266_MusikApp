#include "myServer.h"
#include "myHTMLpage.h"


void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}


AsyncWebServer server(80);
void SERVERsetup(void (*callback)(int)) {

  // Send web page to client
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", index_html);
  });

  // Receive an HTTP GET request
  server.on("/on1", HTTP_GET, [callback](AsyncWebServerRequest *request) {
    callback(0);
    request->send(200, "text/plain", "ok");
  });

  // Receive an HTTP GET request
  server.on("/on2", HTTP_GET, [callback](AsyncWebServerRequest *request) {
    callback(1);
    request->send(200, "text/plain", "ok");
  });

  server.onNotFound(notFound);
}


void WIFIbegin(String ssid, String password, String dnsname) {
  WiFi.mode(WIFI_STA);
  WiFi.hostname("ESP8266");
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Failed");
    return;
  }
  Serial.println();
  Serial.println("ESP IP Address:");
  Serial.print("\thttp://");
  Serial.println(WiFi.localIP());

  if (MDNS.begin(dnsname)) {
    Serial.println("\thttp://" + String(dnsname) + ".local");
  }
}
void SERVERbegin(String ssid, String password) {
  WIFIbegin(ssid, password, "esp8266");
  server.begin();
}