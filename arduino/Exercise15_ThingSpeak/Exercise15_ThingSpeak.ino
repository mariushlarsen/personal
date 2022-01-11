
// Load Wi-Fi library
#include <WiFi.h>
#include <ThingSpeak.h>

// Replace with your network credentials
const char* ssid = "Noller";
const char* pass = "sweetmango405";
WiFiClient server;

unsigned long channelID = 1629443;
const char * APIKey = "4ZJW37LGYPAFED69";
const char* serverName = "api.thingspeak.com";
const int postDelay = 5 * 1000;

int sensorValue;
int X = 1;
float dataNum;
long rssi = WiFi.RSSI();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  WiFi.begin(ssid, pass);
  pinMode(26, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  dataNum = 42.0;
  sensorValue = analogRead(26);
  ThingSpeak.begin(server);
  server.connect(serverName, 80);
  ThingSpeak.setField(X, sensorValue);

  ThingSpeak.writeFields(channelID, APIKey); //post everything to TS
  server.stop();

  
  Serial.println(sensorValue);
  delay(postDelay);
}
