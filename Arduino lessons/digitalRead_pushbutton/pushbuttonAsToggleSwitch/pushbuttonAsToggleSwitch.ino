//pushbutton as a toggle switch

//GPIO 4 or D2
int buttonPin = 4;

int buttonNew;

int buttonOld=1;

int buttonState=0;

int dt = 200;

void setup() {
 Serial.begin(9600);

 pinMode(buttonPin, INPUT);

}

void loop() {

  buttonNew=digitalRead(buttonPin);

  if ((buttonOld==0) && (buttonNew==1)) {
    

    if (buttonState==0) {
      //set an output her(digitalWrite - HIGH)
      buttonState = 1;
    }
    else {
      //reset an output here (digitalWrite - LOW)
      buttonState = 0;
    }
    
  }
  buttonOld=buttonNew;
  
  Serial.print("current state of button: ");
  Serial.println(buttonState);
  delay(dt);
}
