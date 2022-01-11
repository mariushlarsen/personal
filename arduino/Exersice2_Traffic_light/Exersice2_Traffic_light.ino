
const byte RED_LED = 13;
const byte YELLOW_LED = 12;
const byte GREEN_LED = 11;
int timeUnit = 1000;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //Red light
  digitalWrite(RED_LED, HIGH);
  Serial.println("STOP!");
  delay(timeUnit * 5);
  digitalWrite(RED_LED, LOW);

  //Yellow light
  digitalWrite(YELLOW_LED, HIGH);
  delay(timeUnit);
  digitalWrite(YELLOW_LED, LOW);

  //Green light
  digitalWrite(GREEN_LED, HIGH);
  Serial.println("GO!");
  delay(timeUnit * 5);
  digitalWrite(GREEN_LED, LOW);

  //Yellow light
  digitalWrite(YELLOW_LED, HIGH);
  delay(timeUnit);
  digitalWrite(YELLOW_LED, LOW);


}
