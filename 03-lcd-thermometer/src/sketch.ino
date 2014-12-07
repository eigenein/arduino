#include <math.h>

#include <LiquidCrystal.h>

#define A_MAX 1024.0
#define T_MIN 273.15
#define THERMISTOR_B 4300.0
#define V_IN 5.0

LiquidCrystal lcd(4, 5, 10, 11, 12, 13);

float decimal(const float value) {
    return value - (int)value;
}

void setup() {
    lcd.begin(16, 2);
    Serial.begin(9600);
}

void loop() {
    const float voltage = V_IN * analogRead(A0) / A_MAX;
    const float thermistorR = voltage / (V_IN - voltage);
    const float temperatureC = 1.0 / (1.0 / THERMISTOR_B * log(thermistorR) + 1.0 / (25.0 + T_MIN)) - T_MIN;

    Serial.print("V = ");
    Serial.print(voltage);
    Serial.print(" T = ");
    Serial.println(temperatureC);

    char temperatureString[16];
    sprintf(temperatureString, "T: %d.%02d", (int)temperatureC, (int)(decimal(temperatureC) * 100));

    lcd.setCursor(0, 1);
    lcd.print(temperatureString);

    delay(500);
}
