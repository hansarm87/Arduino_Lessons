#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>

const char* ssid ="IPUP";
const char* password = "HansOgPeter2300";

AsyncWebServer server(80);

String webpage = "<!DOCTYPE html><html><head><title> page title </title></head><body style='background-color: #EEEEE;'><span style='color: #003366;';><h1> this is a heading </h1><p> this is a paragraph </p></span></body></html>";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("connecting to WIFI");
    delay(500);
  }
  Serial.print("Connected: local IP address is ");
  Serial.println(WiFi.localIP());

  server.on("/", [] (AsyncWebServerRequest *request) {
    request->send(200, "text/html", webpage);
  });

  server.begin();
  
}

void loop() {
  
}
