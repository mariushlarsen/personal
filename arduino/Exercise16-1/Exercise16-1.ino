int var = 1;
int *pointer = &var;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  Serial.println(var);

  *pointer = 2;

  Serial.println(var);
}

void loop() {
  // put your main code here, to run repeatedly:

}
