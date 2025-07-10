#include "../include/initPins.h"
#include "../include/initWiFi.h"
#include "../include/readData.h"
#include "../include/printData.h"
#include "../include/dataId.h"

#include "../include/serverFunctions.h"

#include "../include/config.h"

DataId dataId = TEMPERATURE; 

float lastTemperature = 0.0;
float lastHumidity = 0.0;
float lastPressure = 0.0;

uint32_t lastSetDataIdTime = 0;

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

    printData(dataId);
    // sendDataToServer(temperature, humidity, pressure);

    uint32_t nowTimeForSetDataId = millis();
    if ((nowTimeForSetDataId - lastSetDataIdTime) > delaySetDataId) 
    {
      dataId = TEMPERATURE;
    }
  }
  
  delay(delayReadSensor);
}
