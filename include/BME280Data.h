#ifndef BME280DATA_H
#define BME280DATA_H

struct BME280Data {
    float temperature;
    float humidity;
    float pressure;

    bool operator!=(const BME280Data& other) const {
        return (temperature != other.temperature) ||
               (humidity != other.humidity) ||
               (pressure != other.pressure);
    }
};

#endif // BME280DATA_H
