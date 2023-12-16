#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESPAsyncTCP.h>

const char* ssid ="IPUP";
const char* password = "HansOgPeter2300";

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

int randomNumber = 0;

const char webpage [] PROGMEM = R"rawliteral( 
<!DOCTYPE HTML>
<html>
<head>
  <title>ESP Web Server</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <script>
    var gateway = `ws://${window.location.hostname}/ws`;
    var websocket;

    window.addEventListener('load', onLoad);

    function initWebSocket() {
      console.log('Trying to open a WebSocket connection...');
      websocket = new WebSocket(gateway);
      websocket.onopen = onOpen;
      websocket.onclose = onClose;
      websocket.onmessage = onMessage;
    }

    function onOpen(event) {
      console.log('Connection opened');
    }

    function onClose(event) {
      console.log('Connection closed');
      setTimeout(initWebSocket, 2000);
    }

    function onMessage(event) {
      document.getElementById('state').innerHTML = 'Random Number: ' + event.data;
    }

    function onLoad(event) {
      initWebSocket();
    }
  </script>
</head>
<body>
  <div>
    <h2>Random Number</h2>
    <p id="state">Random Number: </p>
  </div>
</body>
</html>
)rawliteral";

int interval = 1000;
unsigned long previousMillis = 0;


void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", webpage, processor);
  });

  ws.onEvent(onEvent);
  server.addHandler(&ws);

  server.begin();
}

void loop() {
  ws.cleanupClients();

  // Generate a random number between 0 and 100
  randomNumber = random(101);

  // Notify clients about the new random number
  ws.textAll(String(randomNumber));

  delay(1000);  // Wait for 1 second
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
             void *arg, uint8_t *data, size_t len) {
  // Handle WebSocket events
}

String processor(const String& var) {
  if (var == "STATE") {
    return String(randomNumber);
  }
  return String();
}
