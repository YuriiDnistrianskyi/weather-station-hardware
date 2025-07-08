#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#include "../include/serverFunctions.h"

#include "../include/config.h"

String macAddress = WiFi.macAddress();

void sendDataToServer(float temperature, float humidity, float pressure)
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("WiFi not connected. Cannot send data.");
        return;
    }

    WiFiClient client;
    HTTPClient http;

    String uri = String(serverUri) + ":" + String(port) + "/info";
    
    http.begin(client, uri);
    http.addHeader("Content-Type", "application/json");

    StaticJsonDocument<200> doc;
    doc["mac_address"] = macAddress;
    doc["t"] = temperature;
    doc["h"] = humidity;
    doc["p"] = pressure;

    String jsonData;
    serializeJson(doc, jsonData);
    
    int httpResponseCode = http.POST(jsonData);

    if (httpResponseCode > 0)
    {
        String response = http.getString();
        Serial.print("HTTP Response code: ");
        Serial.println(response);
    }
    else
    {
        Serial.print("Error sending POST: ");
        Serial.println(http.errorToString(httpResponseCode).c_str());
    }

    http.end();
}
