#include "LcdDisplay.h"

static LiquidCrystal lcd(
    lcd_rs_pin,
    lcd_en_pin,
    lcd_d4_pin,
    lcd_d5_pin,
    lcd_d6_pin,
    lcd_d7_pin
);

void lcd_display_init() {
    lcd.begin(lcd_columns, lcd_rows);
    lcd.setCursor(0, 0);
    lcd.setCursor(0, 1);
    lcd.print("Waiting command...");
    delay(1000);
}

void lcd_display_update(bool relay_on) {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("RELAY: ");
    lcd.print(relay_on ? "ON " : "OFF");

    lcd.setCursor(0, 1);
    lcd.print("Light: ");
    lcd.print(relay_on ? "ON " : "OFF");
}

void lcd_display_message(const char* line1, const char* line2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(line1);
    lcd.setCursor(0, 1);
    lcd.print(line2);
}