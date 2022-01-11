#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

const byte LED1 = 4;
const byte LED2 = 5;
const byte LED3 = 6;
const byte LED4 = 7;
const byte LED5 = 8;

const byte BUTTON = 9;

int timeCount = 0;
int LEDcount = 0;
int missCount = 0;
int hitCount = 0;

int blinkInterval = 60;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  for (int i = 4; i <= 8; i++){
    pinMode(i, OUTPUT);
  }

  pinMode(BUTTON, INPUT_PULLUP);
  DisplayHitsAndMisses();

}

void loop() {
  // put your main code here, to run repeatedly:


  if(hitCount == 10){
    Serial.println("YOU WIN!");
    DisplayWin();
    FancyLightShow();
    FancyLightShow();
    hitCount = 0;
    missCount = 0;
    blinkInterval = 60;
    
    Serial.println("");
    Serial.println("-----------------");
    Serial.println("--GAME RESTARTS--");
    Serial.println("-----------------");    
    Serial.println("");
    
    DisplayHitsAndMisses();
  }

  if(timeCount % blinkInterval == 0){ 
    //Two times a second, change lit LED
    
    if(hitCount < 8){
      LEDcount++;
      if(LEDcount > 5){
        LEDcount = 1;
        }
      LightLED();
      } else {
      LEDcount = random(1,6);
      LightLED();
      }
  }

  if(timeCount % 2 == 0){
    //Every 20ms, check if button is pressed

    
    
    if(digitalRead(BUTTON) == LOW){
      if(LEDcount == 1 || LEDcount == 2 || LEDcount == 4 || LEDcount == 5){
        TurnAllLEDsOff();
        Serial.print("MISS! You hit LED no ");
        Serial.println(LEDcount);
        DisplayMiss();
        missCount++;
        delay(1000);
      } else if (LEDcount == 3){
        
        Serial.print("HIT! You hit LED no ");
        Serial.println(LEDcount);
        DisplayHit();
        hitCount++;
        FancyLightShow();
        blinkInterval = blinkInterval - 5;
      }     

      DisplayHitsAndMisses();      

    }  
  }

  if(timeCount % 500 == 0){
    Serial.print("Hits: ");
    Serial.print(hitCount);
    Serial.print(" | Misses: ");    
    Serial.println(missCount);
  }

  timeCount++;
  delay(10); //wait 10ms
}

void LightLED(){

  if(LEDcount == 1){
    TurnAllLEDsOff();
    digitalWrite(LED1, HIGH);
  } else if (LEDcount == 2){
    TurnAllLEDsOff();
    digitalWrite(LED2, HIGH);  
  } else if (LEDcount == 3){
    TurnAllLEDsOff();
    digitalWrite(LED3, HIGH);
  } else if (LEDcount == 4){
    TurnAllLEDsOff();
    digitalWrite(LED4, HIGH);
  } else if (LEDcount == 5){
    TurnAllLEDsOff();
    digitalWrite(LED5, HIGH);
  }   

}

void TurnAllLEDsOff(){
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
}

void FancyLightShow(){
  TurnAllLEDsOff();
  
  TurnLEDsOn(1,0,0,0,1);
  delay(100);
  TurnLEDsOn(0,1,0,1,0);
  delay(100);
  TurnLEDsOn(1,0,1,0,1);
  delay(100);  
  TurnLEDsOn(0,1,0,1,0);
  delay(100);  
  TurnLEDsOn(1,0,1,0,1);
  delay(100); 
  TurnLEDsOn(0,1,0,1,0);
  delay(100);  
  TurnLEDsOn(1,0,1,0,1);
  delay(100); 
  TurnLEDsOn(0,1,0,1,0);
  delay(100);  
  TurnLEDsOn(1,0,1,0,1);
  delay(100); 
}

void TurnLEDsOn(byte one, byte two, byte three, byte four, byte five){
  TurnAllLEDsOff();
  digitalWrite(LED1, one);
  digitalWrite(LED2, two);
  digitalWrite(LED3, three);
  digitalWrite(LED4, four);
  digitalWrite(LED5, five);
}

void DisplayHitsAndMisses(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(7,12);
  display.print("Hits: ");
  display.print(hitCount);
  display.print(" | Misses: ");
  display.print(missCount);
  display.display();  
}

void DisplayHit(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(45,10);
  display.print("HIT!");
  display.display();
}

void DisplayMiss(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(37,5);
  display.print("MISS!");
  display.setTextSize(1);
  display.setCursor(17,25); 
  display.print("You hit LED no ");
  display.print(LEDcount);
  display.display();
}

void DisplayWin(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(13,10);
  display.print("YOU WIN!");
  display.display();
}