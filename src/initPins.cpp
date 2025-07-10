#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#include "../include/initPins.h"

#include "../include/dataId.h"
#include "../include/config.h"

extern DataId dataId;
extern uint32_t lastSetDataIdTime;

Adafruit_BME280 bme;
volatile uint32_t lastDebounceTime = 0;

void IRAM_ATTR handleClick()
{
    uint32_t nowTime = millis();
    if ((nowTime - lastDebounceTime) > debounceTime)
    {
        lastDebounceTime = nowTime;
        lastSetDataIdTime = nowTime;
        dataId = static_cast<DataId>((dataId + 1) % 3);
    }
}

void initButton()
{
    pinMode(buttonPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(buttonPin), handleClick, RISING);
}

void initBME280()
{
    bool status;
    status = bme.begin(0x76);
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }
}

void initPins()
{
    Serial.begin(115200);
    initButton();
    initBME280();
}
