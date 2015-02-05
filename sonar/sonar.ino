
#define LED_PIN 8
#define ECHO_PIN 12
#define TRIGGER_PIN 13

// 25 °C
#define SOUND_SPEED 346

void setup()
{
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    
    unsigned long mmDistance = pulseIn(ECHO_PIN, HIGH) * SOUND_SPEED / 1000 / 2;
    Serial.println(mmDistance);
    digitalWrite(LED_PIN, mmDistance <= 1000 ? HIGH : LOW);
    
    delay(100);
}
