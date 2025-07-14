#ifndef CONFIG_H
#define CONFIG_H

extern uint8_t buttonPin;

extern uint8_t clkPin;
extern uint8_t dioPin;

extern uint8_t debounceTime;
extern uint16_t delayReadSensor;
extern uint16_t delaySetDataId;

extern char* serverUri;
extern char* port;

#endif // CONFIG_H
