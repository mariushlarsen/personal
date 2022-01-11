const byte LED = 13;
const byte BUTTON = 12;
boolean buttonState = false;
boolean LEDstate = false;

void setup() {
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  
  if(digitalRead(BUTTON) == true && buttonState == false){
    buttonState =! buttonState;
    LEDstate =! LEDstate;
  }  
  
  if(digitalRead(BUTTON) == false && buttonState == true){
    buttonState =! buttonState;
  }

  digitalWrite(LED,LEDstate);

}
