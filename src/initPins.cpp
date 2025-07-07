#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#include "../include/initPins.h"

Adafruit_BME280 bme;

extern uint32_t delayReadSensor;

void initPins()
{
    Serial.begin(115200);

    bool status;
    status = bme.begin(0x76);
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }

    delayReadSensor = 1000;
}
