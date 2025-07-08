#include <ESP8266WiFi.h>

#include "../include/initWiFi.h"

char* ssid = "Test";
char* password = "123123123";

void initWiFi()
{
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED)
    {
        delay(2000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}
