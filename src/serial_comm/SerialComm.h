#ifndef SERIAL_COMM_H
#define SERIAL_COMM_H

#include <Arduino.h>

const long serial_baud_rate = 9600;
const int serial_buffer_max_size = 256;

void serial_comm_init();
bool serial_comm_has_command();
String serial_comm_get_command();

void serial_comm_print(const char* message);
void serial_comm_print(String message);
void serial_comm_println(const char* message);
void serial_comm_println(String message);

void serial_comm_report_status(bool relay_on);

#endif