#include "RelayControl.h"

static bool relay_state = false;

void relay_control_init() {
    pinMode(relay_pin, OUTPUT);
    pinMode(led_pin, OUTPUT);
    pinMode(led_status_pin, OUTPUT);

    relay_set(false);
}

void relay_set(bool on) {
    relay_state = on;

    digitalWrite(relay_pin, on ? LOW : HIGH);
    digitalWrite(led_pin, on ? HIGH : LOW);
    digitalWrite(led_status_pin, on ? HIGH : LOW);
}

bool relay_get_state() {
    return relay_state;
}