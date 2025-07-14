#include <Arduino.h>

#include "../include/config.h"

uint8_t buttonPin = D7;

uint8_t clkPin = D5;
uint8_t dioPin = D6;

uint8_t debounceTime = 200;
uint16_t delayReadSensor = 1000; //
uint16_t delaySetDataId = 10000;

char* serverUri = "http://192.168.31.82"; //
char* port = "5000"; //
