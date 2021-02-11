#define BLYNK_PRINT Serial

#include <SPI.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

BlynkTimer timer;

#define relay1 19
#define relay2 18
#define relay3 5
#define relay4 17
#define relay5 16
#define relay6 4
#define relay7 2
#define relay8 15

int relay1Status = 0;
int relay2Status = 0;
int relay3Status = 0;
int relay4Status = 0;
int relay5Status = 0;
int relay6Status = 0;
int relay7Status = 0;
int relay8Status = 0;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "NVl3WfWqIuQ2sVxLaisFrIj46f0eVK28";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "A";
char pass[] = "tablet2520";

BLYNK_CONNECTED() {

  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4);
  Blynk.syncVirtual(V5);
  Blynk.syncVirtual(V6);
  Blynk.syncVirtual(V7);
  Blynk.syncVirtual(V8);
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

BLYNK_WRITE(V11)
{
  relay1Status = param.asInt();
  digitalWrite(relay1, relay1Status);
  Blynk.virtualWrite(V1, relay1Status);
}
BLYNK_WRITE(V12)
{
  relay2Status = param.asInt();
  digitalWrite(relay2, relay2Status);
  Blynk.virtualWrite(V2, relay2Status);
}
BLYNK_WRITE(V13)
{
  relay3Status = param.asInt();
  digitalWrite(relay3, relay3Status);
  Blynk.virtualWrite(V3, relay3Status);
}
BLYNK_WRITE(V14)
{
  relay4Status = param.asInt();
  digitalWrite(relay4, relay4Status);
  Blynk.virtualWrite(V4, relay4Status);
}
BLYNK_WRITE(V15)
{
  relay5Status = param.asInt();
  digitalWrite(relay5, relay5Status);
  Blynk.virtualWrite(V5, relay5Status);
}
BLYNK_WRITE(V16)
{
  relay6Status = param.asInt();
  digitalWrite(relay6, relay6Status);
  Blynk.virtualWrite(V6, relay6Status);
}
BLYNK_WRITE(V17)
{
  relay7Status = param.asInt();
  digitalWrite(relay7, relay7Status);
  Blynk.virtualWrite(V7, relay7Status);
}
BLYNK_WRITE(V18)
{
  relay8Status = param.asInt();
  digitalWrite(relay8, relay8Status);
  Blynk.virtualWrite(V8, relay8Status);
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
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  //timer.setInterval(500L, checkPhysicalButton);  
  }

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
  timer.run();
}
