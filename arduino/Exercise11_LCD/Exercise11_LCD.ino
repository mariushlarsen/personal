#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define ANALOGPIN A0
int sensorValue;

void setup() {
  // put your setup code here, to run once:
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  pinMode(ANALOGPIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  display.clearDisplay();

  sensorValue = avgMeasurement(analogRead(ANALOGPIN));
  
  if(sensorValue < 700){
    DisplayContent(sensorValue);
  } else {
    DisplayWarning();
  }

  delay(100);
}


void DisplayContent(int input){
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(30,6);
  display.print("Brightness: ");
  display.setCursor(50,20);
  display.println(input);
  display.display();
}

void DisplayWarning(){
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(5,10);
  display.println("TOO BRIGHT");
  display.display();
  
}

int avgMeasurement(int measurement){
  int i;
  int totalMeasure;
  int avgMeasurement;

  for(i = 0; i < 10; i++){
    totalMeasure = totalMeasure + measurement;
    }

  avgMeasurement = totalMeasure/10;
  return avgMeasurement;
}