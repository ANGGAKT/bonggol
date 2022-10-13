int sensorValue;
int buzzerPin = 10;
int greenLED = 9;
int redLED = 8;
int sensorPin = 14;

void setup() {
  Serial.begin(9600); // sets the serial port to 9600
  pinMode(buzzerPin, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(sensorPin, INPUT);

}

void loop() {
  sensorValue = analogRead(sensorPin);       // read analog input pin A5
  Serial.print("AirQuality Value: ");
  Serial.println(sensorValue, DEC);               // prints the value read

  if (sensorValue > 300) {
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(redLED, HIGH);
    Serial.println("Alert!!!");
    delay(5000); // wait 2000ms
  }

  else {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzerPin, LOW);
    Serial.println("Normal");
    delay(1000); // wait 500ms
  }
  delay(1000);                                   // wait 100ms for next reading
}


