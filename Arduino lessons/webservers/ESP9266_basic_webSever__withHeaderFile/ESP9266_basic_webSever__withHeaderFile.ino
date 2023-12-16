#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "webPageCode.h"

//--------------------------------------------------------

ESP8266WebServer server(80);

const char SSID[] = SECRET_SSID;
const char PASSWORD[] = SECRET_PASSWORD;

//--------------------------------------------------------

void webPage() {
  server.send(200, "text/html", webPageCode);
}



//--------------------------------------------------------

void setup(){
  Serial.begin(9600);
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() !=WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }

  Serial.print("");
  Serial.println("WiFi Connected, local IP: ");
  Serial.print(WiFi.localIP());

  server.on("/", webPage);
  server.begin();
}
  //--------------------------------------------------------
  
void loop() {
  server.handleClient();
  
}
