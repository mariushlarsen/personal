const byte ledPin = 13;
const int timeUnit = 500;

// the setup function runs once when you press reset or power the board
void setup() {

  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(timeUnit);
    digitalWrite(ledPin, LOW);
    delay(timeUnit);
  }
  
  delay(timeUnit * 2);

  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(timeUnit * 3);
    digitalWrite(ledPin, LOW);
    delay(timeUnit);            
  }

  delay(timeUnit * 2);

  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(timeUnit);
    digitalWrite(ledPin, LOW);
    delay(timeUnit);
  }

  delay(timeUnit * 6);

}  
