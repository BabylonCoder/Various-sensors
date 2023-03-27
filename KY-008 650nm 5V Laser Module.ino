int laserPin = 2; // digital pin 2

void setup() {
  pinMode(laserPin, OUTPUT);
}

void loop() {
  digitalWrite(laserPin, HIGH); // turn on the laser
  delay(1000); // wait for 1 second
  digitalWrite(laserPin, LOW); // turn off the laser
  delay(1000); // wait for 1 second
}
