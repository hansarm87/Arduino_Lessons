#include <ESP8266WiFi.h>

#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "IPUP";
const char* password = "HansOgPeter2300";

IPAddress staticIP(192,168,0,22);
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Connect to Wi-Fi
  connectToWiFi();
}

void loop() {
  // Main program loop
  // Your code goes here...
}

void connectToWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println("Connected to WiFi. IP Address: " + WiFi.localIP().toString());
}
