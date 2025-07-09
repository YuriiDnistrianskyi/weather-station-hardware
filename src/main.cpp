#include "../include/initPins.h"
#include "../include/initWiFi.h"
#include "../include/readData.h"

#include "../include/serverFunctions.h"

#include "../include/config.h"

float lastTemperature = 0.0;
float lastHumidity = 0.0;
float lastPressure = 0.0;

void setup() 
{
  initPins();
  initWiFi();
}

void loop() 
{
  float temperature = readTemperature();
  float humidity = readHumidity();
  float pressure = readPressure();

  if (temperature != lastTemperature || humidity != lastHumidity || pressure != lastPressure) {
    lastTemperature = temperature;
    lastHumidity = humidity;
    lastPressure = pressure;
    sendDataToServer(temperature, humidity, pressure);
    
    // Serial.print("Temperature: ");
    // Serial.print(temperature);
    // Serial.println(" °C");

    // Serial.print("Humidity: ");
    // Serial.print(humidity);
    // Serial.println(" %");

    // Serial.print("Pressure: ");
    // Serial.print(pressure);
    // Serial.println(" hPa");
  }  

  delay(delayReadSensor);
}
