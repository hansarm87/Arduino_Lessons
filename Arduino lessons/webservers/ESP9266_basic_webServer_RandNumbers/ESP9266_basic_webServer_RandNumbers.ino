#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>

const char* ssid ="IPUP";
const char* password = "HansOgPeter2300";

AsyncWebServer server(80);

String webpage_1 = "<!DOCTYPE html><html><head><title> page title </title></head><body style='background-color: #EEEEE;'><span style='color: #003366;';><h1> Random number generator </h1><p> The random number is : ";
String webpage_2 = "</p></span></body></html>";

String webpage = webpage_1 + String(random(100)) + webpage_2;

int interval = 1000;
unsigned long previousMillis = 0;

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
  
  unsigned long now = millis();
  if (now - previousMillis > interval) {
      webpage = webpage_1 + String(random(100)) + webpage_2;
      previousMillis = now;
  }
  
}
