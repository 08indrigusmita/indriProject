int Status = 12;  // Digital pin D6

int sensor = 13;  // Digital pin D7


void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);   // declare sensor as input
  pinMode(Status, OUTPUT);  // declare LED as output
   pinMode(BUILTIN_LED, OUTPUT);
}

void loop() {

  long state = digitalRead(sensor);
    if(state == HIGH) {
      digitalWrite (Status, HIGH);
      Serial.println("Motion detected!");
      digitalWrite(BUILTIN_LED, HIGH);
      delay(1000);
    }
    else {
      digitalWrite (Status, LOW);
      Serial.println("Motion absent!");
      digitalWrite(BUILTIN_LED, LOW);
      delay(1000);
      }
}
