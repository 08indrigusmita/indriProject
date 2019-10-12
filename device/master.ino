#include <DFPlayer_Mini_Mp3.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

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

void cekGerakan()
{
  delay(3000);
  long state = digitalRead(sensorPir);
  delay(400);
    if(state == LOW) {
      Serial.println("Tidak ada gerak");
      cekGerakan();
    }else{
      Serial.println("Ada gerakan");
    Serial.println("Tutup di tutup ..");
    gerakTutup();
    delay(1500);
    ultraDepan();
    }
    
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
  //domain
  int rangeVolume [] = {30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  
  volume = rangeVolume[jarakFin];
  //fungsi keanggotaan
    int kosongMin, kosongMax, sedikitMin, sedikitMax, setengahMin, setengahMax, hampirMin, hampirMax, penuhMin, penuhMax;
  
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
  
  

  //kirim status
  const char* status = "";
//  if(
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
  
  Serial.println(volume);
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
  
cekVolume();
//gerakBuka();
//delay(3000);
//gerakTutup();
//delay(3000);
//ultraDepan();
//cekGerakan();


//mp3_set_volume (25);
//mp3_play(1);
//delay(1550);
}
