#include <Arduino.h>

#include "../include/printData.h"

#include "../include/dataId.h"
#include "../include/BME280Data.h"

extern BME280Data oldBmeData;

void printData(DataId dataId) {
    switch (dataId)
    {
    case TEMPERATURE:
        Serial.println(oldBmeData.temperature);
        break;
    case HUMIDITY:
        Serial.println(oldBmeData.humidity);
        break;
    case PRESSURE:
        Serial.println(oldBmeData.pressure);
        break;
    default:
        Serial.print("Exception in printData: Unknown DataId: ");
        Serial.println(dataId);
        break;
    }
}
