const byte ledPin = 13;
const int timeUnit = 300;

// the setup function runs once when you press reset or power the board
void setup() {

  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

MorseCodeM();
MorseCodeA();
MorseCodeR();
MorseCodeI();
MorseCodeU();
MorseCodeS();

delay(timeUnit * 4);

}  

void MorseCodeLine() {
  digitalWrite(ledPin, HIGH);
  delay(timeUnit * 3);
  digitalWrite(ledPin, LOW);
  delay(timeUnit);
}

void MorseCodeDot() {
  digitalWrite(ledPin, HIGH);
  delay(timeUnit);
  digitalWrite(ledPin, LOW);
  delay(timeUnit);  
}

void MorseCodeM() {
  MorseCodeLine();
  MorseCodeLine();
  delay(timeUnit * 2);
}

void MorseCodeA() {
  MorseCodeDot();
  MorseCodeLine();
  delay(timeUnit * 2);
}

void MorseCodeR() {
  MorseCodeDot();
  MorseCodeLine();
  MorseCodeDot();
  delay(timeUnit * 2);
}

void MorseCodeI() {
  MorseCodeDot();
  MorseCodeDot();
  delay(timeUnit * 2);
}

void MorseCodeU() {
  MorseCodeDot();
  MorseCodeDot();
  MorseCodeLine();
  delay(timeUnit * 2);
}

void MorseCodeS() {
  for (int i = 0; i < 3; i++) {
    MorseCodeDot();
  }
  delay(timeUnit * 2);
}
