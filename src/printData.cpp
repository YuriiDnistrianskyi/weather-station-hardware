#include <TM1637Display.h>
#include <Arduino.h>

#include "../include/printData.h"

#include "../include/dataId.h"
#include "../include/BME280Data.h"

extern BME280Data oldBmeData;
extern TM1637Display display;

void printData(DataId dataId) {
    switch (dataId)
    {
        case TEMPERATURE: {
            int t = int(oldBmeData.temperature * 100);
            display.showNumberDecEx(t, 0b01000000);
            break;
        }
        case HUMIDITY: {
            int h = int(oldBmeData.humidity * 100);
            display.showNumberDecEx(h, 0b01000000);
            break;
        }
        case PRESSURE: {
            int p = int(oldBmeData.pressure);
            display.showNumberDec(p);
            break;
        }
        default: {
            Serial.print("Exception in printData: Unknown DataId: ");
            Serial.println(dataId);
            break;
        }
    }
}
