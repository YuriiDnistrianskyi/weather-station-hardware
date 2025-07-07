#include <Adafruit_BME280.h>

#include "../include/readData.h"

extern Adafruit_BME280 bme;

float readTemperature() {
    float temperature = bme.readTemperature(); // float
    return temperature;
}

float readHumidity() {
    float humidity = bme.readHumidity();
    return humidity;
}

float readPressure() {
    float pressure = bme.readPressure() / 100.0F; // float to uint16_t
    return pressure;
}

float readAltitude() {
    float altitude = bme.readAltitude(1013.25);
    return altitude;
}
