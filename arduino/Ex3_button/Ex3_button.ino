const byte LED = 13;
const byte BUTTON = 12;

void setup() {
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(BUTTON) == false){
    digitalWrite(LED,HIGH);
  } else {
    digitalWrite(LED,LOW);
  }


}
