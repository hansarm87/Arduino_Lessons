int pbpin = D2;

void setup() {
  // put your setup code
  Serial.begin(9600);
  // uncomment to use built in pullup resistor
  //pinMode(pbpin, INPUT_PULLUP);

  // with this we need a hardware setup with a 10kohm resistor to either GND og + to make a pull-up or down switch
  pinMode(pbpin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int state = digitalRead(pbpin);
  Serial.println(state);
  delay(100);
}
