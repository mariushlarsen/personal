#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 9

void setup() {
  // put your setup code here, to run once:

  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Enter R, G, and B values to light up LED");

}

void loop() {
  // put your main code here, to run repeatedly:

  while(Serial.available() > 0){
    
    int red = Serial.parseInt();
    int green = Serial.parseInt();
    int blue = Serial.parseInt();

    analogWrite(REDPIN, red);
    analogWrite(GREENPIN, green);    
    analogWrite(BLUEPIN, blue);    

  }

}
