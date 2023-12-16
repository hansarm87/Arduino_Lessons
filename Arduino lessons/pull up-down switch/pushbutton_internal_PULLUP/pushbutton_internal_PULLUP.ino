//simply connct one leg to pin D2 or wchich ever and other leg to GND

int buttonPin = D2;

int buttonValue;

int dt = 100;

void setup() {
Serial.begin(115200);
pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonValue=digitalRead(buttonPin);

  Serial.print("Button is: ");
  Serial.println(buttonValue);
  delay(dt);
}
