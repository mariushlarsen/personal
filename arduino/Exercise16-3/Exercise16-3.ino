int a = 1;
int b = 2;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  Serial.print("a: ");
  Serial.print(a);
  Serial.print(" | b: ");
  Serial.println(b);
  
  swap(&a, &b);
  
  Serial.print("a: ");
  Serial.print(a);
  Serial.print(" | b: ");
  Serial.println(b);
  
  Serial.println("");
}

void loop() {
  // put your main code here, to run repeatedly
  
}


void swap(int *pointer_a, int *pointer_b){
  
  int c;

  c = *pointer_a;
  *pointer_a = *pointer_b;
  *pointer_b = c;

  Serial.println(" ");
  Serial.println("Swap it up!");
  Serial.println(" ");
}