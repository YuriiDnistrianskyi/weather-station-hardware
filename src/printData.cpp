#include <Arduino.h>

#include "../include/printData.h"

#include "../include/dataId.h"

extern float lastTemperature;
extern float lastHumidity;
extern float lastPressure; 

void printData(DataId dataId) {
    switch (dataId)
    {
    case TEMPERATURE:
        Serial.println(lastTemperature);
        break;
    case HUMIDITY:
        Serial.println(lastHumidity);
        break;
    case PRESSURE:
        Serial.println(lastPressure);
        break;
    default:
        Serial.print("Exception in printData: Unknown DataId: ");
        Serial.println(dataId);
        break;
    }
}
