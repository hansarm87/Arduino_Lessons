int potPin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop () {
 
   float potRead = analogRead(potPin);
   Serial.print("RAW: ");
   Serial.println(potRead);
   
   float voltage = (potRead/100) * .5;
   Serial.print("Voltage: ");
   Serial.println(voltage);
   
   delay(100);
}
