#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#include "../include/initPins.h"

#include "../include/config.h"

Adafruit_BME280 bme;
uint32_t lastDebounceTime = 0;

void handleClick()
{
    uint32_t nowTime = millis();
    if ((nowTime - lastDebounceTime) > debounceTime)
    {
        lastDebounceTime = nowTime;
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
