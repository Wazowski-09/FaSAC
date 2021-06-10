

#define BLYNK_PRINT Serial

#include <SPI.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "SHTC3.h"

WidgetLED led(V32);

BlynkTimer timer;

#define BLYNK_GREEN     "#23C48E"
#define BLYNK_BLUE      "#04C0F8"
#define BLYNK_YELLOW    "#ED9D00"
#define BLYNK_RED       "#D3435C"
#define BLYNK_DARK_BLUE "#5F7CD8"

#define relay1 32
#define relay2 33
#define relay3 25
#define relay4 26
#define relay5 27
#define relay6 14
#define relay7 12
#define relay8 13

SHTC3 s(Wire);

int relay1Status = 0;
int relay2Status = 0;
int relay3Status = 0;
int relay4Status = 0;
int relay5Status = 0;
int relay6Status = 0;
int relay7Status = 0;
int relay8Status = 0;

int timerStatus = 0;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "NVl3WfWqIuQ2sVxLaisFrIj46f0eVK28";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Steakholder_2.4G";
char pass[] = "Steakholder4-2";

BLYNK_CONNECTED() {

  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4);
  Blynk.syncVirtual(V5);
  Blynk.syncVirtual(V6);
  Blynk.syncVirtual(V7);
  Blynk.syncVirtual(V8);
  Blynk.syncVirtual(V11);
  Blynk.syncVirtual(V12);
  Blynk.syncVirtual(V13);
  Blynk.syncVirtual(V14);
  Blynk.syncVirtual(V15);
  Blynk.syncVirtual(V16);
  Blynk.syncVirtual(V17);
  Blynk.syncVirtual(V18);
  Blynk.syncVirtual(V21);
  Blynk.syncVirtual(V22);
  Blynk.syncVirtual(V31);
}

BLYNK_WRITE(V1) {
  relay1Status = param.asInt();
  digitalWrite(relay1, relay1Status);
}
BLYNK_WRITE(V2) {
  relay2Status = param.asInt();
  digitalWrite(relay2, relay2Status);
}

BLYNK_WRITE(V3) {
  relay3Status = param.asInt();
  digitalWrite(relay3, relay3Status);
}

BLYNK_WRITE(V4) {
  relay4Status = param.asInt();
  digitalWrite(relay4, relay4Status);
}

BLYNK_WRITE(V5) {
  relay5Status = param.asInt();
  digitalWrite(relay5, relay5Status);
}

BLYNK_WRITE(V6) {
  relay6Status = param.asInt();
  digitalWrite(relay6, relay6Status);
}

BLYNK_WRITE(V7) {
  relay7Status = param.asInt();
  digitalWrite(relay7, relay7Status);
}

BLYNK_WRITE(V8) {
  relay8Status = param.asInt();
  digitalWrite(relay8, relay8Status);
}

BLYNK_WRITE(V31){
  timerStatus = param.asInt();
  if(timerStatus == 1){
    led.setColor(BLYNK_RED);
    led.on();
  }
  else{
    led.setColor(BLYNK_GREEN);
    led.on();
  }
  
  }
  
BLYNK_WRITE(V11)
{
  if(timerStatus == 1){
  relay1Status = param.asInt();
  digitalWrite(relay1, relay1Status);
  Blynk.virtualWrite(V1, relay1Status);
  }
}
BLYNK_WRITE(V12)
{
  if(timerStatus == 1){
  relay2Status = param.asInt();
  digitalWrite(relay2, relay2Status);
  Blynk.virtualWrite(V2, relay2Status);
  }
}
BLYNK_WRITE(V13)
{
  if(timerStatus == 1){
  relay3Status = param.asInt();
  digitalWrite(relay3, relay3Status);
  Blynk.virtualWrite(V3, relay3Status);
  }
}
BLYNK_WRITE(V14)
{
  if(timerStatus == 1){
  relay4Status = param.asInt();
  digitalWrite(relay4, relay4Status);
  Blynk.virtualWrite(V4, relay4Status);
  }
}
BLYNK_WRITE(V15)
{
  if(timerStatus == 1){
  relay5Status = param.asInt();
  digitalWrite(relay5, relay5Status);
  Blynk.virtualWrite(V5, relay5Status);
  }
}
BLYNK_WRITE(V16)
{
  if(timerStatus == 1){
  relay6Status = param.asInt();
  digitalWrite(relay6, relay6Status);
  Blynk.virtualWrite(V6, relay6Status);
  }
}
BLYNK_WRITE(V17)
{
  if(timerStatus == 1){
  relay7Status = param.asInt();
  digitalWrite(relay7, relay7Status);
  Blynk.virtualWrite(V7, relay7Status);
  }
}
BLYNK_WRITE(V18)
{
  if(timerStatus == 1){
  relay8Status = param.asInt();
  digitalWrite(relay8, relay8Status);
  Blynk.virtualWrite(V8, relay8Status);
  }
}



void sendSensor()
{
  float h = s.readHumidity();
  float t = s.readTempC(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) == 0 && isnan(t) == 0) {
    Serial.println("Failed to read from SHTC3 sensor!");
  }
  Blynk.virtualWrite(V21, h);
  Blynk.virtualWrite(V22, t);
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relay3,OUTPUT);
  pinMode(relay4,OUTPUT);
  pinMode(relay5,OUTPUT);
  pinMode(relay6,OUTPUT);
  pinMode(relay7,OUTPUT);
  pinMode(relay8,OUTPUT);
  
  Blynk.begin(auth, ssid, pass,"blynk.honey.co.th",8080);

  Wire.begin();
  timer.setInterval(1000L, sendSensor);
  }

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
  timer.run();
  s.begin(true);
  s.sample();
}
