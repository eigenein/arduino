#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 5, 10, 11, 12, 13);

void setup() {
    lcd.begin(16, 2);
}

void loop() {
    static const char spin[] = "\x80\x81\x82\x83";

    const unsigned long time = millis() / 1000;

    const int hours = time / 3600;
    const int minutes = (time / 60) % 60;
    const int seconds = time % 60;

    char time_string[16];
    sprintf(time_string, "%c %02d:%02d:%02d", spin[time % 4], hours, minutes, seconds);

    lcd.setCursor(0, 1);
    lcd.print(time_string);

    delay(100);
}
