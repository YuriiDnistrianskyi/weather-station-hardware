#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#include "../include/initServer.h"

#include "../include/config.h"

void initServer()
{
    
}

void sendDataToServer(float temperature, float humidity, float pressure)
{
    if (WiFi.status() != WL_CONNECTED)
    {
        return;
    }

    WiFiClient client;
    HTTPClient http;

    String uri = String(serverUri) + ":" + String(port) + "/info";
    Serial.print("Connecting to server: ");
    Serial.println(uri);
    
    http.begin(client, uri);

    http.addHeader("Content-Type", "application/json");

    String jsonData = "{ \"weather_station_id\": " + String(1) + // mac_address
                      ", \"date\" : \"2024-02-02\" " + // delete
                      ", \"temperature\": " + String(temperature) +
                      ", \"humidity\": " + String(humidity) +
                      ", \"CO2\": " + String(pressure) + "}";
    
    int httpResponseCode = http.POST(jsonData);

    if (httpResponseCode > 0)
    {
        String response = http.getString();
        Serial.print("HTTP Response code: ");
        Serial.print(httpResponseCode + " ");
        Serial.println(response);
    }
    else
    {
        Serial.print("Error sending POST: ");
        Serial.println(http.errorToString(httpResponseCode).c_str());
    }

    http.end();
}
