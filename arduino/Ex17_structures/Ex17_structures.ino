#include <string.h>

struct Animal {
  int ID;
  char name[20];
  float weight;
  boolean alive;
  char placeOfCapture[20];
};

Animal woodpecker = {
  1,                //ID
  "Woodpecker",    //Name
  0.3,              //Weight
  false,            //Alive
  "Forest"          //Place of Capture

};

Animal elephant = {
  2,                //
  "Elephant",       //Name
  1000,            //Weight
  true,            //Alive
  "Savannah"        //Place of Capture
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  printAnimal(woodpecker);
  printAnimal(elephant);
  
  //SwapName(&woodpecker, &elephant);
  compareAnimals(&woodpecker, &elephant);

  
  printAnimal(woodpecker);
  printAnimal(elephant);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void printAnimal(struct Animal typeOfAnimal) {

  Serial.print("ID: ");
  Serial.println(typeOfAnimal.ID);
  Serial.print("Type of animal is: ");
  Serial.println(typeOfAnimal.name);
  Serial.print("Weight of Animal is: ");
  Serial.print(typeOfAnimal.weight);
  Serial.println(" kg");
  Serial.print("Is it alive?: ");
  if(typeOfAnimal.alive){
    Serial.println("Yes");
  } else {
    Serial.println("No");
  }
  Serial.print(" Place of capture: ");
  Serial.println(typeOfAnimal.placeOfCapture);

  Serial.println(" ");
}

void SwapName(struct Animal *ptrMemberA, struct Animal *ptrMemberB){ 
  char temp[20];
  
  strcpy(temp, ptrMemberA->name);
  strcpy(ptrMemberA->name, ptrMemberB->name);
  strcpy(ptrMemberB->name, temp);

}

void compareAnimals(struct Animal *ptrMemberA, struct Animal *ptrMemberB){

  if(ptrMemberA->weight > ptrMemberB->weight){
    
    Serial.print(ptrMemberA->name);
    Serial.println(" is bigger.");

    if(ptrMemberA->ID > ptrMemberB->ID){
      int temp;

      temp = ptrMemberA->ID;
      ptrMemberA->ID = ptrMemberB->ID;
      ptrMemberB->ID = temp;

      Serial.println("IDs swapped.");
      Serial.println("");
    }

  } else {
    Serial.print(ptrMemberB->name);
    Serial.println(" is bigger.");

    if(ptrMemberB->ID > ptrMemberA->ID){
      int temp;

      temp = ptrMemberA->ID;
      ptrMemberA->ID = ptrMemberB->ID;
      ptrMemberB->ID = temp;

      Serial.println("IDs swapped");
      Serial.println("");
    }
  }



}

