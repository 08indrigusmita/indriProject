#include <Servo.h>

//inisialisasi pin sensor pir
int sensorPir = D6;
int pirState = LOW;
int val = 0;
//inisialiasai pin sensor ultrasonik 1
const int trigPinUltra1 = D1; 
const int echoPinUltra1 = D2; 
//inisialisasi pin sensor ultrasonik 2
const int trigPinUltra2 = D4;
const int echoPinUltra2 = D5;
//inisialisasi servo
Servo servo;
//inisialisasi variabel lokal
long durasiUltra1;
int jarakUltra1;
long durasiUltra2;
int jarakUltra2;
int volume;

void setup() {
  //pertama kali dijalankan ketika program berjalan
  Serial.begin(9600);
  pinMode(sensorPir, INPUT);
  pinMode(trigPinUltra1, OUTPUT);
  pinMode(echoPinUltra1, INPUT);
  pinMode(trigPinUltra2, OUTPUT);
  pinMode(echoPinUltra2, INPUT);
  servo.attach(D0);
  servo.write(0);
  delay(2000);
}

void cekGerakan()
{
  delay(1000);
  long state = digitalRead(sensorPir);
  
    if(state == HIGH) {
      gerakTutup();
      delay(1500);
      ultraDepan();
    }else{
      delay(500);
      cekGerakan();
    }
}

void ultraDepan()
{
  //perintah yang akan di ulang
  
// Clears the trigPin
digitalWrite(trigPinUltra1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinUltra1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinUltra1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durasiUltra1 = pulseIn(echoPinUltra1, HIGH);
// Calculating the distance
jarakUltra1 = durasiUltra1 * 0.034 / 2;
// Prints the distance on the Serial Monitor
if(jarakUltra1 > 50)
{
//  gerakTutup();
}else{
  gerakBuka();
  delay(1000);
 cekGerakan();
}
Serial.print("Distance: ");
Serial.println(jarakUltra1);
delay(1000);

}

void gerakTutup()
{
  servo.write(0);
  delay(1000);
}

void gerakBuka()
{
  servo.write(120);
  delay(1000);
}

void cekVolume()
{
  digitalWrite(trigPinUltra2, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinUltra2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinUltra2, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durasiUltra2 = pulseIn(echoPinUltra2, HIGH);
// Calculating the distance
jarakUltra2 = (durasiUltra2 * 0.034 / 2) + 3;
volume = jarakUltra2 - 30;

Serial.println(volume);
delay(1000);
  
}

void loop() {
//cekVolume();
ultraDepan();
//cekGerakan();

}
