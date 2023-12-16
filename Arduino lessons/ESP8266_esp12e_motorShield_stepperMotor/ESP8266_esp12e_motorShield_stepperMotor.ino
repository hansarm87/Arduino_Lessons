/*
   Board pin | NodeMCU GPIO |  Arduino IDE
      A-           1             5 or D1
      A+           3             0 or D3
      B-           2             4 or D2
      B+           4             2 or D4
*/


// (A-)blue, (A+)pink, (B-)yellow, (B+)orange - red goes to VM

const int pwmMotorA = D1;
const int pwmMotorB = D2;
const int dirMotorA = D3;
const int dirMotorB = D4;

int delayBtwnStep = 5;

void setup() {
  Serial.begin ( 115200 );
  Serial.println();

  pinMode(pwmMotorA, OUTPUT);
  pinMode(pwmMotorB, OUTPUT);
  pinMode(dirMotorA, OUTPUT);
  pinMode(dirMotorB, OUTPUT);
  Serial.println("Motor SHield 12E Initialized");
}

void loop() {
  stepperRotate(2048, 0);
  delay(1000);
  stepperRotate(2048, 1);
  delay(1000);
}


void stepperRotate(int nbStep, int dirStep) {
  for (int i = 0; i <= nbStep; i++) {
    if (dirStep == 0) {  // sens horaire
      nextStep(i % 4);
    }
    if (dirStep == 1) {  // sens antihoraire
      nextStep(3 - (i % 4));
    }
    delay(delayBtwnStep);
  }
}


void nextStep(int index) {
  if (index == 0) {
    analogWrite(pwmMotorA, 255);
    analogWrite(pwmMotorB, 0);
    digitalWrite(dirMotorA, true);
    digitalWrite(dirMotorB, false);
  }
  if (index == 1) {
    analogWrite(pwmMotorA, 0);
    analogWrite(pwmMotorB, 255);
    digitalWrite(dirMotorA, true);
    digitalWrite(dirMotorB, false);
  }
  if (index == 2) {
    analogWrite(pwmMotorA, 0);
    analogWrite(pwmMotorB, 255);
    digitalWrite(dirMotorA, false);
    digitalWrite(dirMotorB, true);
  }
  if (index == 3) {
    analogWrite(pwmMotorA, 255);
    analogWrite(pwmMotorB, 0);
    digitalWrite(dirMotorA, false);
    digitalWrite(dirMotorB, true);
  }
}
