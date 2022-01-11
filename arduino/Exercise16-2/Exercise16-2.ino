int a[5] = {9,2,42,5,8};
int *pointer = &a[0];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("Value of pointer is "); 
  Serial.println(*pointer);
  Serial.print("Address of pointer is "); 
  Serial.println((long)pointer);

  pointer++;;
  delay(3000);

}
