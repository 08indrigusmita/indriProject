const int trigPin = D6;  //D4
const int echoPin = D5;  //D3
byte led = 16;
int enA = D2;
int in1   = D3;
int in2   = D4;
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
 pinMode(led, OUTPUT);
 digitalWrite(led, LOW);
 pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
}

void loop() {

digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(enA, HIGH); // n is set to 150

}
