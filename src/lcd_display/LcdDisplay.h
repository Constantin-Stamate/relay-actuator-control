#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal.h>

const int lcd_rs_pin = 12;
const int lcd_en_pin = 11;
const int lcd_d4_pin = 5;
const int lcd_d5_pin = 4;
const int lcd_d6_pin = 3;
const int lcd_d7_pin = 2;

const int lcd_columns = 16;
const int lcd_rows = 2;

void lcd_display_init();
void lcd_display_update(bool relay_on);
void lcd_display_message(const char* line1, const char* line2);

#endif