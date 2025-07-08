#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

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
    Serial.print("Connecting to server: ");
    Serial.println(uri);
    
    http.begin(client, uri);

    http.addHeader("Content-Type", "application/json");

    String jsonData = "{ \"mac_address\": " + macAddress +
                      ", \"t\": " + String(temperature) +         // Temperature
                      ", \"h\": " + String(humidity) +            // Humidity
                      ", \"p\": " + String(pressure) + "}";       // Pressure
    
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
