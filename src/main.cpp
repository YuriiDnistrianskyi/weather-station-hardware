#include "../include/initPins.h"
#include "../include/initWiFi.h"
#include "../include/readData.h"
#include "../include/printData.h"
#include "../include/dataId.h"
#include "../include/BME280Data.h"

#include "../include/serverFunctions.h"

#include "../include/config.h"

DataId dataId = TEMPERATURE; 

BME280Data oldBmeData; // = {0.0f, 0.0f, 0.0f};

uint32_t lastReadSensorTime = 0;
uint32_t lastSetDataIdTime = 0;

void setup() 
{
  initPins();
  initWiFi();
}

void loop() 
{
  uint32_t nowTimeForReadSensor = millis();
  if ((nowTimeForReadSensor - lastReadSensorTime) > delayReadSensor)
  {
    lastReadSensorTime = nowTimeForReadSensor;
    BME280Data bmeData = readBME280();

    if (bmeData != oldBmeData)
    {
      oldBmeData = bmeData;

      printData(dataId);
      // sendDataToServer(oldBmeData);

      uint32_t nowTimeForSetDataId = millis();
      if ((nowTimeForSetDataId - lastSetDataIdTime) > delaySetDataId) 
      {
        dataId = TEMPERATURE;
      }
    }
  }
}
