#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
//konfigurasi wifi
const char* ssid = "IndriSpot";
const char* password = "46M^09f0";
WiFiClient client;
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("Connecting...");
  }
}
void sistemUtama()
{
  // Check WiFi Status
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;  //Object of class HTTPClient
    http.begin("http://indriproject.haxors.or.id/infoDevice.php");
    int httpCode = http.GET();
    //Check the returning code                                                                  
    if (httpCode > 0) {
      // Get the request response payload
      String payload = http.getString();
      // TODO: Parsing
      const size_t bufferSize = JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(8) + 370;
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());
      const char* name = root["username"];
      Serial.println(name);
    }
    http.end();   //Close connection
  }
  // Delay
}
void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Konek");
  }else{
    Serial.println("Tidak konek");
  }
delay(3000);
}
