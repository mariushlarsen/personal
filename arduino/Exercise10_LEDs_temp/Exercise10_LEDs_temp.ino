#define LIGHTPIN A0
#define ANALOGVALUE 1023

#define REDLED 3
#define YELLOWLED 5
#define GREENLED 6

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
 
  pinMode(LIGHTPIN, INPUT);

  pinMode(REDLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);    
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int sensorValue = analogRead(LIGHTPIN);
  
  Serial.println(sensorValue);

    
  if(sensorValue < 200){
    //Low - green LED on
    TurnOnRightLED(0,1,0);
    
  } else if (sensorValue >= 200 && sensorValue < 600){
    //Medium - yellow LED on
    TurnOnRightLED(0,0,1);
  } else {
    //High - red LED on
    TurnOnRightLED(1,0,0);
  }

  delay(100);

}


void TurnOnRightLED(byte red, byte green, byte yellow){
    digitalWrite(GREENLED, green);
    digitalWrite(REDLED, red);
    digitalWrite(YELLOWLED, yellow);
}