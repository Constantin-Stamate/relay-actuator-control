#include "SerialComm.h"

static String serial_buffer = "";
static bool command_ready = true;

bool serial_comm_has_command() {
    while (Serial.available() > 0) {
        char received_char = (char)Serial.read();

        if (received_char == '\r') {
            continue;
        }

        if (received_char == '\n') {
            if (serial_buffer.length() > 0) {
                command_ready = true;
                return true;
            }
        } else {
            serial_buffer += received_char;

            if (serial_buffer.length() > serial_buffer_max_size) {
                serial_buffer = serial_buffer.substring(
                    serial_buffer.length() - serial_buffer_max_size
                );
            }
        }
    }

    return false;
}

String serial_comm_get_command() {
    if (!command_ready) {
        return "";
    }

    String command = serial_buffer;
    serial_buffer = "";
    command_ready = false;

    return command;
}

void serial_comm_init() {
    Serial.begin(serial_baud_rate);
    serial_buffer = "";
    command_ready = false;
}

void serial_comm_print(const char* message) {
    Serial.print(message);
}

void serial_comm_print(String message) {
    Serial.print(message);
}

void serial_comm_println(const char* message) {
    Serial.println(message);
}

void serial_comm_println(String message) {
    Serial.println(message);
}

void serial_comm_report_status(bool relay_on) {
    String json = "{";
    json += "\"relay\":\"";
    json += relay_on ? "ON" : "OFF";
    json += "\",\"light\":\"";
    json += relay_on ? "ON" : "OFF";
    json += "\",\"timestamp\":";
    json += String(millis());
    json += "}";

    Serial.println(json);
}