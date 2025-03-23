// Include libraries
#include <SoftwareSerial.h>

// Define pins for ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

// Define SoftwareSerial object for Bluetooth communication
SoftwareSerial BTSerial(2, 3);  // RX, TX pins on Arduino (connect these to TX, RX of HC-05 respectively)

void setup() {
  // Initialize serial communication with computer
  Serial.begin(9600);

  // Initialize serial communication with Bluetooth module
  BTSerial.begin(9600);

  // Set trigPin as OUTPUT and echoPin as INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Variables to store distance calculation
  long duration, distance_cm;

  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond high pulse on trigPin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters (cm)
  distance_cm = duration * 0.034 / 2;

  // Print distance to serial monitor
  // Serial.print("Distance: ");
  Serial.print(distance_cm);
  // Serial.println(" cm");

  // Send distance data to Bluetooth module
  // BTSerial.print("Distance: ");
   BTSerial.print(distance_cm);
  // BTSerial.println(" cm");

  // Delay before next reading
  delay(2000);  // adjust delay time as needed
}