#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 9
#define ANALOGPIN A0

int sensorValue;
float sensorVolts;

int redValue;
int greenValue;
int blueValue;

int purple[] = {148, 0, 211};
int blue[] = {0, 0, 255};
int green[] = {0, 255, 0};
int yellow[] = {255, 255, 0};
int red[] = {255, 0, 0};

const int MAXVAL = 1023;
const int STEP = 4;

int step1 = MAXVAL/STEP;
int step2 = MAXVAL/STEP * 2;
int step3 = MAXVAL/STEP * 3;
int step4 = MAXVAL/STEP * 4;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  sensorValue = analogRead(ANALOGPIN);
  sensorVolts = sensorValue * 0.0049;
  Serial.println(sensorVolts, 3);
 
  if(sensorValue < step1){
    redValue = map(sensorValue, 0, step1, purple[0], blue[0]);
    greenValue = map(sensorValue, 0, step1, purple[1], blue[1]);
    blueValue = map(sensorValue, 0, step1, purple[2], blue[2]);
  } else if (sensorValue >= step1 && sensorValue < step2){
    redValue = map(sensorValue, step1 + 1, step2, blue[0], green[0]);
    greenValue = map(sensorValue, step1 + 1, step2, blue[1], green[1]);
    blueValue = map(sensorValue, step1 + 1, step2, blue[2], green[2]);
  } else if (sensorValue >= step2 && sensorValue < step3){
    redValue = map(sensorValue, step2 + 1, step3, green[0], yellow[0]);
    greenValue = map(sensorValue, step2 + 1, step3, green[1], yellow[1]);
    blueValue = map(sensorValue, step2 + 1, step3, green[2], yellow[2]);
  } else if (sensorValue >= step3 && sensorValue <= step4){
    redValue = map(sensorValue, step3 + 1, step4, yellow[0], red[0]);
    greenValue = map(sensorValue, step3 + 1, step4, yellow[1], red[1]);
    blueValue = map(sensorValue, step3 + 1, step4, yellow[2], red[2]);
  } 
  
  analogWrite(REDPIN, redValue);  
  analogWrite(GREENPIN, greenValue);
  analogWrite(BLUEPIN, blueValue);
  
  
}
