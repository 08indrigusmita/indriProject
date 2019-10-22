#include <DFPlayer_Mini_Mp3.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

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
long angkaAcak;
//inisialisasi konfigurasi wifi
const char *ssid =  "NadhaMedia";     //Nama SSID Wifi
const char *pass =  "rikacantik";             //Password Wifi
WiFiClient client;
//http client
const char *host = "http://indriproject.haxors.or.id/mainApp/sendData.php";
void setup() {
//pertama kali dijalankan ketika program berjalan
Serial.begin (9600);
  delay(500); 
  pinMode(sensorPir, INPUT);
  pinMode(trigPinUltra1, OUTPUT);
  pinMode(echoPinUltra1, INPUT);
  pinMode(trigPinUltra2, OUTPUT);
  pinMode(echoPinUltra2, INPUT);
  servo.attach(D0);
  servo.write(0);
//  //Memulai inisialisasi program
  Serial.println("Inisialisasi .... ");
  Serial.println("Selamat datang di Smart Trash. By Indri Gusmita");
  Serial.println(" ============================ ");
  Serial.println("Melakukan koneksi ke wifi : ");
  Serial.println(ssid); 
//
  WiFi.begin(ssid, pass); 
  while (WiFi.status() != WL_CONNECTED) 
     {
      delay(500);
      Serial.print(".");
     }
  Serial.println("");
  Serial.println("Koneksi berhasil. Sistem memeriksa koneksi ke server.");
  //audio untuk pembuka 1
  delay(500);
  //fungsi mengambil status ke tabel koneksi
   HTTPClient http;
  String volumeData, station, postData;
  postData = "status=on";
  http.begin("https://indri-project.haxors.or.id/mainApp/cekKoneksi.php");              //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
  int httpCode = http.POST(postData);   //Send the request
  String payload = http.getString();    //Get the response payload
  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
  http.end();  //Close connection
  delay(5000);
  Serial.println("Pengecekan selesai. Tempat sampah siap digunakan. "); 
  delay(3000);
}
  int bil = 0;

void cekGerakan()
{

  delay(100);
  long state = digitalRead(sensorPir);
  if(state == LOW){
    Serial.println("No");
  }else{
    Serial.println("Ada");
    delay(200);
    cekGerakan();
  }
  
//  delay(2000);
//  long state = digitalRead(sensorPir);
//  delay(400);
//    if(state == LOW) {
//      Serial.println("Tidak ada gerak");
//      delay(500);
//      bil++;
//      if(bil >= 7){
//        gerakTutup();
//    delay(1000);
//    ultraDepan();
//      }else{
//        bil = 0;
//        delay(200);
//        cekGerakan();
//      }
//    }else{
//      Serial.println("Ada gerakan");
//    Serial.println("Tutup di tutup ..");
//    gerakTutup();
//    delay(2500);
//    ultraDepan();
//    }
    
//    gerakTutup();
//      delay(1500);
//      ultraDepan();
}

void ultraDepan()
{
 
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
int nilaiPusat = 100;

if(jarakUltra1 > 50)
{
//  gerakTutup();
}else{
  Serial.println("Tutup terbuka ...");
  gerakBuka();
  delay(1000);
 cekGerakan();
}

Serial.print("Halangan : ");
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
  // Nilai pusat
  jarakUltra2 = (durasiUltra2  / 2) / 29.1;
  int jarakFin = jarakUltra2 - 5 + 7;
  //domain range
  int rangeVolume [] = {30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  //total dari keseluruhan range
  int totRange = 465;
  
  volume = rangeVolume[jarakFin];
  //fungsi mencari derajat keanggotaan
    int kosongMin, kosongMax, sedikitMin, sedikitMax, setengahMin, setengahMax, hampirMin, hampirMax, penuhMin, penuhMax;
    int kosMa, sedMa, setMa, hamMa,penMa;
    kosMa = 0;
    sedMa = 6;
    setMa = 12;
    hamMa = 18;
    penMa = 24;
  //fuzzifikasi
   
    //derajat keanggotaan 
    //kosong
    for(int kosMi = 0; kosMi <= totRange; kosMi++ ){
     if(kosMi < kosMa && kosMa == kosMi + 6){
       kosMa = kosMa + 6;
     }
    }
    //sedikit
    for(int sedMi = 0; sedMi <= totRange; sedMi++ ){
     if(sedMi < sedMa && sedMa == sedMi + 6){
       sedMa = sedMa + 6;
     }
    }
    //setengah
    for(int setMi = 0; setMi <= totRange; setMi++ ){
     if(setMi < setMa && setMa == setMi + 6){
       setMa = setMa + 6;
     }
    }
    //hampir
    for(int hamMi = 0; hamMi <= totRange; hamMi++ ){
     if(hamMi < hamMa && hamMa == hamMi + 6){
       hamMa = hamMa + 6;
     }
    }
    //penuh
    for(int penMi = 0; penMi <= totRange; penMi++ ){
     if(penMi < penMa && penMa == penMi + 6){
       penMa = penMa + 6;
     }
    }
   kosongMin = 0;
  kosongMax = 6;
  sedikitMin = 6;
  sedikitMax =  12;
  setengahMin = 12;
  setengahMax = 18;
  hampirMin = 18;
  hampirMax = 24;
  penuhMin = 24;
  penuhMax = 30;
  
  //Rule fuzzy
  const char* status = "";


  if(volume >= kosongMin && volume <= kosongMax)
  {
    status = "Penuh";
  }else if(volume >= sedikitMin && volume <= sedikitMax)
  {
    status = "Hampir penuh";
  }else if(volume >= setengahMin && volume <= setengahMax)
  {
    status = "Setengah";
  }else if(volume >= hampirMin && volume <= hampirMax)
  {
    status = "Sedikit";
  }else if(volume >= penuhMin && volume <= penuhMax)
  {
    status = "Kosong";
  }
  
  Serial.println(jarakFin);
//  Serial.print(" => ");
//  Serial.println(status);
  delay(1000);
}

void kirimData(){
  HTTPClient http;
String volumeData, station, postData;
angkaAcak = random(20, 100);
volumeData = String(angkaAcak);
postData = "volume=" + volumeData;
http.begin("http://indriproject.haxors.or.id/mainApp/sendData.php");              //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
  int httpCode = http.POST(postData);   //Send the request
  String payload = http.getString();    //Get the response payload
  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
  http.end();  //Close connection
  delay(5000);  //Post Data at every 5 seconds
}

void loop() {
  
//cekVolume();
//gerakBuka();
//delay(3000);
//gerakTutup();
//delay(3000);
ultraDepan();
//cekGerakan();


//mp3_set_volume (25);
//mp3_play(1);
//delay(1550);
}
