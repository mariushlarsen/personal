#define LIGHTPIN A0
#define ANALOGVALUE 1023.0
#define MAXVOLTS 5.0

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(LIGHTPIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  char degChar = 176;
  
  int sensorValue = analogRead(LIGHTPIN);
  float mV = sensorValue * MAXVOLTS / ANALOGVALUE * 1000;
  float deg = (mV - 500)/10;
  
  Serial.print(deg, 1);
  Serial.print(" C");
  Serial.write(degChar);
  Serial.println();

  delay(200);
}
