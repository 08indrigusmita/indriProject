#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int val = 0;
//inisialiasai pin sensor ultrasonik 1
const int trigPinUltra1 = 12; //D6 
const int echoPinUltra1 = 13; //D7
 
//inisialisasi pin sensor ultrasonik 2
const int trigPinUltra2 = 2;
const int echoPinUltra2 = 14;

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
const char *ssid =  "indrispot";     //Nama SSID Wifi
const char *pass =  "71154043";             //Password Wifi
WiFiClient client;
//http client
const char *host = "http://indriproject.haxors.or.id/mainApp/sendData.php";
//inisialisasi lcd 
LiquidCrystal_I2C lcd(0x27, 16, 2);

SoftwareSerial mySerial(0, 15); // RX, TX
void setup() {
  //inisialisasi lcd
  lcd.begin();
  lcd.backlight();
  //pertama kali dijalankan ketika program berjalan
  Serial.begin (9600);
  delay(500); 
  pinMode(trigPinUltra1, OUTPUT);
  pinMode(echoPinUltra1, INPUT);
  pinMode(trigPinUltra2, OUTPUT);
  pinMode(echoPinUltra2, INPUT);
  servo.attach(16);
  servo.write(0);
//    mp3_set_volume (25);
//  //Memulai inisialisasi program
  Serial.println("Mulai");
  printLcd("Smart Trash","Dev By Indri");
  Serial.println("Selamat datang di Smart Trash. By Indri Gusmita");
  Serial.println(" ============================ ");
  Serial.println("Melakukan koneksi ke wifi : ");
  delay(2000);
   printLcd("Menghubungkan","ke wifi ...");
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
   printLcd("Koneksi","berhasil :) ");
  delay(1000);
  printLcd("Cek koneksi", "ke server ..");
  delay(1000);
  cekStatusDevice();
  delay(3000);
}

void cekStatusDevice(){
  HTTPClient http;
  String postData;
  postData = "status=on";
  http.begin("http://indri-project.haxors.or.id/mainApp/cekKoneksi.php");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int httpCode = http.POST(postData);   //Send the request
  String respon = http.getString();    //Get the response payload
  Serial.println(respon);
  printLcd("Status device : ",respon);
  if(respon == "smart"){
    cekDataVolume();
  }else{
    
    printLcd("Menunggu smart","mode");
    delay(2000);
    cekStatusDevice();
  }
  delay(500);
  http.end();  //Close connection
}

void cekDataVolume(){
  delay(500);
  
  digitalWrite(trigPinUltra2, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinUltra2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinUltra2, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durasiUltra2 = pulseIn(echoPinUltra2, HIGH);
  // Nilai pusat
  jarakUltra2 = (durasiUltra2 / 2) / 29.1;
  
  if(jarakUltra2 >= 30){
    jarakUltra2 = 30;
  }else{
    if(jarakUltra2 <= 0){
      jarakUltra2 = 1;
    }
  }
  int finvVol = 0;
  switch(jarakUltra2){
    case 30:
    finvVol = 1;
    break;
    case 29:
    finvVol = 2;
    break;
    case 28:
    finvVol = 3;
    break;
    case 27:
    finvVol = 4;
    break;
    case 26:
    finvVol = 5;
    break;
    case 25:
    finvVol = 6;
    break;
    case 24:
    finvVol = 7;
    break;
    case 23:
    finvVol = 8;
    break;
    case 22:
    finvVol = 9;
    break;
    case 21:
    finvVol = 10;
    break;
    case 20:
    finvVol = 11;
    break;
    case 19:
    finvVol = 12;
    break;
    case 18:
    finvVol = 13;
    break;
    case 17:
    finvVol = 14;
    break;
    case 16:
    finvVol = 15;
    break;
    case 15:
    finvVol = 16;
    break;
    case 14:
    finvVol = 17;
    break;
    case 13:
    finvVol = 18;
    break;
    case 12:
    finvVol = 19;
    break;
    case 11:
    finvVol = 20;
    break;
    case 10:
    finvVol = 21;
    break;
    case 9:
    finvVol = 22;
    break;
    case 8:
    finvVol = 23;
    break;
    case 7:
    finvVol = 24;
    break;
    case 6:
    finvVol = 25;
    break;
    case 5:
    finvVol = 26;
    break;
    case 4:
    finvVol = 27;
    break;
    case 3:
    finvVol = 28;
    break;
    case 2:
    finvVol = 29;
    break;
    case 1:
    finvVol = 30;
    break;       
  }
  
 finvVol = finvVol - 2 ;
 if(finvVol >= 25){
  printLcd("Volume sekarang : ", String(finvVol));
  delay(2000);
  printLcd("Tempat sampah","penuh broo..");
  HTTPClient http;
  String postData;
  String volCap = String(finvVol);
  postData = "status="+String(finvVol);
  http.begin("http://indri-project.haxors.or.id/mainApp/gantiStatus.php");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int httpCode = http.POST(postData);   //Send the request
  String respon = http.getString();    //Get the response payload
  printLcd("Ke mode","manual ...");
  Serial.println(respon);
  http.end();
  delay(1500);
  cekStatusDevice();

 }else{
  printLcd("Volume sekarang : ", String(finvVol));

  //update data ke server
  HTTPClient http;
  String postData;
  String volCap = String(finvVol);
  postData = "volume=" + volCap;
  http.begin("http://indri-project.haxors.or.id/mainApp/sendData.php");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int httpCode = http.POST(postData);   //Send the request
  String respon = http.getString();    //Get the response payload
  Serial.println(respon);
  http.end();
  delay(2500);
 }
  
  
}

void printLcd(String teks, String teks2){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(teks);
  lcd.setCursor(0,1);
  lcd.print(teks2);
}


  int bil = 0;
void ultraDepan()
{
 printLcd("Stand by","..........");
 delay(500);
 
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
Serial.print("Halangan : ");
Serial.println(jarakUltra1);

if(jarakUltra1 > 50)
{
//  gerakTutup();
}else{
  Serial.println("Tutup terbuka ...");
  printLcd("Masukkan","sampah kamu ..");
  gerakBuka();
  delay(5000);
  gerakTutup();
   printLcd("Terima ","kasih..");
   delay(1000);
   cekDataVolume();
   delay(500);
   lcd.clear();
//  mp3_play(5);

}

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
  jarakUltra2 = (durasiUltra2 * 0.034) / 2;
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
  
  //Rule based
  const char* status = "";

String statusTempatSampah = "";
  if(volume >= kosongMin && volume <= kosongMax)
  {
    status = "kosong";
  }else if(volume >= sedikitMin && volume <= sedikitMax)
  {
    status = "sedikit";
  }else if(volume >= setengahMin && volume <= setengahMax)
  {
    status = "setengah";
  }else if(volume >= hampirMin && volume <= hampirMax)
  {
    status = "hampir_penuh";
  }else if(volume >= penuhMin && volume <= penuhMax)
  {
    status = "penuh";
  }
  if (status=="penuh"){
    statusTempatSampah = "penuh";
  }
  else {
    statusTempatSampah = "tidak";
  }
  
  Serial.println(jarakUltra2);
  sendVolume(jarakUltra2);
//  Serial.print(" => ");
//  Serial.println(status);
  delay(1000);
}

void sendVolume(int volum)
{
  HTTPClient http;
  String postData;
  String volCap = String(volum);
  postData = "volume=" + volCap;
  http.begin("http://indri-project.haxors.or.id/mainApp/sendData.php");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int httpCode = http.POST(postData);   //Send the request
  String respon = http.getString();    //Get the response payload
  Serial.println(respon);
  
  http.end();  //Close connection
  delay(2000);
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
