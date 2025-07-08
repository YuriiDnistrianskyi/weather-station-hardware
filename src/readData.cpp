#include <Adafruit_BME280.h>

#include "../include/readData.h"

extern Adafruit_BME280 bme;

float readTemperature() {
    float temperature = bme.readTemperature();
    return temperature;
}

float readHumidity() {
    float humidity = bme.readHumidity();
    return humidity;
}

float readPressure() {
    float pressure = bme.readPressure() / 100.0F;
    return pressure;
}
