#include "../include/initPins.h"
#include "../include/readData.h"

uint32_t delayReadSensor;

void setup() 
{
  initPins();
}

void loop() 
{
  uint8_t temperature = readTemperature();
  uint8_t humidity = readHumidity();
  uint8_t pressure = readPressure();
  uint8_t altitude = readAltitude();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.print("Altitude: ");
  Serial.print(altitude);
  Serial.println(" m");

  delay(delayReadSensor);
}
