#include <OneWire.h>

// DS18B20 temperature sensor data pin
#define ONE_WIRE_BUS 3

OneWire oneWire(ONE_WIRE_BUS); // initialize OneWire library
byte addr[8]; // variable to store the device address
float temperature; // variable to store the temperature value

void setup() {
  Serial.begin(9600); // initialize serial communication
  if (!oneWire.search(addr)) { // search for the device address
    Serial.println("No device found."); // if no device is found, print an error message
  }
}

void loop() {
  oneWire.reset(); // reset the OneWire bus
  oneWire.select(addr); // select the device using the device address
  oneWire.write(0x44); // start temperature conversion
  delay(1000); // wait for conversion to finish
  oneWire.reset(); // reset the OneWire bus
  oneWire.select(addr); // select the device using the device address
  oneWire.write(0xBE); // read the temperature data
  byte data[9]; // buffer to store the temperature data
  for (int i = 0; i < 9; i++) {
    data[i] = oneWire.read(); // read the temperature data byte by byte
  }
  int rawTemp = (data[1] << 8) | data[0]; // combine the temperature data bytes
  if (rawTemp > 32767) { // check if the temperature is negative
    rawTemp = 0 - ((65535 - rawTemp) + 1); // convert the temperature to a negative value
  }
  temperature = (float)rawTemp / 16.0; // convert the raw temperature value to Celsius
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  delay(1000); // wait for 1 second
}
