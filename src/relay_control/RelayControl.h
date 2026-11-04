#ifndef RELAY_CONTROL_H
#define RELAY_CONTROL_H

#include <Arduino.h>

const int relay_pin = 8;
const int led_pin = 9;
const int led_status_pin = 13;

void relay_control_init();
void relay_set(bool on);
bool relay_get_state();

#endif