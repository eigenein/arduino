#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 5, 10, 11, 12, 13);

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2);
}

void loop() {
    static unsigned long time_offset = 0;
    static const char spin[] = "\x80\x81\x82\x83";

    const unsigned long relative_time = millis() / 1000;

    // Time correction via serial port.
    if (Serial.available() != 0) {
        char current_time_string[16];
        if (Serial.readBytesUntil('\n', current_time_string, sizeof(current_time_string)) != 0) {
            unsigned long current_time;
            if (sscanf(current_time_string, "%ld", &current_time) == 1) {
                time_offset = current_time - relative_time;
            }
        }
    }

    const unsigned long time = relative_time + time_offset;

    const int hours = (time / 3600) % 24;
    const int minutes = (time / 60) % 60;
    const int seconds = time % 60;

    char time_string[16];
    sprintf(time_string, "%c %02d:%02d:%02d", spin[time % 4], hours, minutes, seconds);

    lcd.setCursor(0, 1);
    lcd.print(time_string);

    delay(100);
}
