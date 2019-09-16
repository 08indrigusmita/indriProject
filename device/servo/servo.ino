#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <Servo.h>
//ultrasonik 1
#define triggerPin  D1
#define echoPin     D2
//ultrasonik 2
#define triggerPin2 D4
#define echoPin2    D5
//servo
int sensorPir = 12;  // Digital pin D6
Servo servo;
//konfigurasi wifi
const char* ssid = "IndriSpot";
const char* password = "46M^09f0";

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(triggerPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(sensorPir, INPUT);
servo.attach(D3);
servo.write(0);
// WiFi.begin(ssid, password);
//delay(2000);
}

void pirKita()
{
  long state = digitalRead(sensorPir);
    if(state == HIGH) {
     
      Serial.println("Motion detected!");
      delay(500);
    }
    else {
      
      Serial.println("Motion absent!");
      delay(500);
      }
}
void gerakServo()
{
//put your main code here, to run repeatedly:
servo.write(90);
delay(2000);
servo.write(180);
delay(2000);
}

void gerakBuka()
{
  servo.write(180);
  delay(2000);
}

void gerakTutup()
{
  servo.write(90);
delay(2000);
}

void loop() {
long duration, jarak;
long duration2, jarak2;

//digitalWrite(triggerPin2, LOW);
//delayMicroseconds(2);
//digitalWrite(triggerPin2, HIGH);
//delayMicroseconds(10); 
//digitalWrite(triggerPin2, LOW);
//duration2 = pulseIn(echoPin2, HIGH);
//jarak2 = (duration2 / 2) / 29.1;
//Serial.println(jarak2);
//delay(1000);

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  jarak = (duration/2) / 29.1;

//  if(jarak >= 100)
//  {
//  
//    Serial.println("Tidak ada halangan");
//    servo.write(90);
//  delay(2000);
//  }else{
//    gerakTutup();
//    Serial.println("Ada halangan");
//   servo.write(0);
//delay(2000);
//  }
////  
  gerakTutup();
  gerakBuka();
  delay(1500);
//  gerakTutup();
//  gerakBuka();
//pirKita();
}
