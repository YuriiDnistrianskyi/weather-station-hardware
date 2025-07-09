#include <Arduino.h>

#include "../include/config.h"

uint8_t buttonPin = D4;

uint8_t debounceTime = 200;

char* serverUri = "http://192.168.31.82"; //
char* port = "5000"; //
