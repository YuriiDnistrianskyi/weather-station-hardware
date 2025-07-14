#include <TM1637Display.h>
#include <Arduino.h>

#include "../include/printData.h"

#include "../include/dataId.h"
#include "../include/BME280Data.h"

extern TM1637Display display;

void printData(DataId dataId, BME280Data bmeData) {
    switch (dataId)
    {
        case TEMPERATURE: {
            int t = int(bmeData.temperature * 100);
            display.showNumberDecEx(t, 0b01000000);
            break;
        }
        case HUMIDITY: {
            int h = int(bmeData.humidity * 100);
            display.showNumberDecEx(h, 0b01000000);
            break;
        }
        case PRESSURE: {
            int p = int(bmeData.pressure);
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
