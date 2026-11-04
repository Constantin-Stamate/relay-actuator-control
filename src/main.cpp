#include <Arduino.h>

#include "relay_control/RelayControl.h"
#include "lcd_display/LcdDisplay.h"
#include "serial_comm/SerialComm.h"

const unsigned long status_report_interval_ms = 10000;
unsigned long last_status_report = 0;

void process_command(String cmd);

void setup() {
    serial_comm_init();
    relay_control_init();
    lcd_display_init();

    serial_comm_println("Initializing Relay Actuator Control...");
    lcd_display_update(relay_get_state());
    serial_comm_report_status(relay_get_state());
}

void loop() {
    if (Serial.available() > 0) {
        String cmd = Serial.readStringUntil('\n');
        cmd.trim();

        if (cmd.length() > 0) {
            process_command(cmd);
        }
    }

    unsigned long now = millis();

    if (now - last_status_report >= status_report_interval_ms) {
        last_status_report = now;

        lcd_display_update(relay_get_state());
        serial_comm_report_status(relay_get_state());
    }
}

void process_command(String cmd) {
    cmd.trim();
    cmd.toUpperCase();

    if (cmd == "ON") {
        relay_set(true);
        lcd_display_update(true);

        serial_comm_println(
            "{\"result\":\"OK\",\"action\":\"RELAY ON\",\"light\":\"ON\"}"
        );

        serial_comm_report_status(true);

    } else if (cmd == "OFF") {
        relay_set(false);
        lcd_display_update(false);

        serial_comm_println(
            "{\"result\":\"OK\",\"action\":\"RELAY OFF\",\"light\":\"OFF\"}"
        );

        serial_comm_report_status(false);

    } else if (cmd == "STATUS") {
        lcd_display_update(relay_get_state());
        serial_comm_report_status(relay_get_state());

    } else {
        serial_comm_print("{\"error\":\"UNKNOWN COMMAND\",\"cmd\":\"");
        serial_comm_print(cmd);
        serial_comm_println(
            "\",\"valid_commands\":[\"ON\",\"OFF\",\"STATUS\"]}"
        );
    }
}