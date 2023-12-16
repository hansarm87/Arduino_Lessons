
#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>
#include "webPageCode.h"


//--------------------------------------------------------

AsyncWebServer server(80);

const char SSID[] = SECRET_SSID;
const char PASSWORD[] = SECRET_PASSWORD;

//--------------------------------------------------------


/*void webPage() {
  server.send(200, "text/html", webPageCode);
}
*/

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

//--------------------------------------------------------

void setup(){
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);

  pinMode(D4, INPUT);

  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() !=WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }

  Serial.print("");
  Serial.print("WiFi Connected, local IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", webPageCode);
  });

  // Receive an HTTP GET request
  server.on("/runningLights", HTTP_GET, [] (AsyncWebServerRequest *request) {
    runningLights();
    request->send(200, "text/plain", "ok");
  });

  server.on("/stop", HTTP_GET, [] (AsyncWebServerRequest *request) {
    onStop();
    request->send(200, "text/plain", "ok");
  });
  
  server.onNotFound(notFound);
  //server.on("/", webPage);
  server.begin();
  Serial.println("HTTP server started");
}
  //--------------------------------------------------------
  
void loop() {
  
  
}

void runningLights() {
  digitalWrite(D0, HIGH);
  delay(500);
  digitalWrite(D1, HIGH);
  delay(500);
  digitalWrite(D2, HIGH);
  delay(500);
  digitalWrite(D3, HIGH);
  delay(500);
}

void onStop(){
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
}
