
#define LED_PIN 13

int incoming;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    if (Serial.available() != 0) {
        incoming = Serial.read();
        if (incoming == 'H') {
            digitalWrite(LED_PIN, HIGH);
        } else if (incoming == 'L') {
            digitalWrite(LED_PIN, LOW);
        }
    }
}
