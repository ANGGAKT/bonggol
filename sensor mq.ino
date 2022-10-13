int sensorValue;
int buzzerPin = ""; // sesuaikan pin yang akan digunakan
int greenLED = ""; // sesuaikan pin yang akan digunakan
int redLED = ""; // sesuaikan pin yang akan digunakan
int sensorPin = ""; // sesuaikan pin yang akan digunakan

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

  if (sensorValue > "") { // silahkan isi nilai keinginan batas deteksi sensor
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


