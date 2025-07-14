#include <Adafruit_BME280.h>

#include "../include/readData.h"
#include "../include/BME280Data.h"

extern Adafruit_BME280 bme;

BME280Data readBME280() 
{
    BME280Data data;
    data.temperature = bme.readTemperature();
    data.humidity = bme.readHumidity();
    data.pressure = bme.readPressure() / 100.0F;
    return data;
}
