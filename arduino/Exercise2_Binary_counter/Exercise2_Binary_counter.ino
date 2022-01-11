const byte RED_LED = 13;
const byte YELLOW_LED = 12;
const byte GREEN_LED = 11;
int timeUnit = 2000;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  binaryCount(0,0,1);
  binaryCount(0,1,0);
  binaryCount(0,1,1);
  binaryCount(1,0,0);
  binaryCount(1,0,1);
  binaryCount(1,1,0);
  binaryCount(1,1,1);
  Serial.println("-");
}

void binaryCount(byte x, byte y, byte z) {
  digitalWrite(GREEN_LED, x);
  digitalWrite(YELLOW_LED, y);   
  digitalWrite(RED_LED, z);
  Serial.println(x * 4 + y * 2 + z);
  delay(timeUnit);
}