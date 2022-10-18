// Конденсатор - аппаратное устранение дребезга

#define BTN_PIN 2   // 2 or 3 (поддерживают аппаратные прерывания)
#define LED_PIN 13

bool state = LOW;

void setup()
{
    Serial.begin(9600);

    pinMode(BTN_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);

    int number = digitalPinToInterrupt(BTN_PIN);
    attachInterrupt(number, blink, RISING);
}

void loop()
{
    Serial.println(state);

    digitalWrite(LED_PIN, state);
}

void blink()
{
    state = !state;
}