int potPin = A0;

int ledPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop () {
 
   float potRead = analogRead(potPin);
   Serial.print("RAW: ");
   Serial.println(potRead);
   
   float voltage = (potRead/1023) * 5;
   Serial.print("Voltage: ");
   Serial.println(voltage);

   int PWMout = map(potRead,0,1023,0,255); 

   analogWrite(ledPin, PWMout);
   
   delay(100);
}

 
