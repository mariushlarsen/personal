#define LED1PIN 2
#define LED2PIN 3
#define LED3PIN 4
#define LED4PIN 5
#define LED5PIN 6


void setup() {
  // put your setup code here, to run once:

  pinMode(LED1PIN, OUTPUT);
  pinMode(LED2PIN, OUTPUT);
  pinMode(LED3PIN, OUTPUT);
  pinMode(LED4PIN, OUTPUT);
  pinMode(LED5PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Enter a letter A - E to light up an LED");
}

void loop() {
  // put your main code here, to run repeatedly:

  char c;

  if (Serial.available() > 0) {
    c = Serial.read();
    c = toupper(c);

    switch (c) {
      case 'A':
        digitalWrite(LED1PIN, HIGH);
        break;

      case 'B':
        digitalWrite(LED2PIN, HIGH);
        break;

      case 'C':
        digitalWrite(LED3PIN, HIGH);
        break;

      case 'D':
        digitalWrite(LED4PIN, HIGH);
        break;

      case 'E':
        digitalWrite(LED5PIN, HIGH);
        break;

      default:
        turnOffAllLEDs();

        break;
    }
  }
}

void turnOffAllLEDs() {
  digitalWrite(LED1PIN, LOW);
  digitalWrite(LED2PIN, LOW);
  digitalWrite(LED3PIN, LOW);
  digitalWrite(LED4PIN, LOW);
  digitalWrite(LED5PIN, LOW);
}