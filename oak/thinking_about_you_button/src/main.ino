// #define WHOAMI "alpha"
#define WHOAMI "beta"

#define BUTTON_PIN 5
#define LED_PIN 7

void eventHandler(const char *event, const char *data) {
    // Blink #1
    // for (int i = 0; i < 10; i++) {
    //     digitalWrite(LED_PIN, HIGH);
    //     delay(250);
    //     digitalWrite(LED_PIN, LOW);
    //     delay(1000);
    // }

    // Throb #1 - meh
    // float in, out;
    // for (int i = 0; i < 5; i++) {
    //     for (in = 0; in < 6.283; in = in + 0.001) {
    //         out = sin(in) * 511.5 + 511.5;
    //         analogWrite(LED_PIN, out);
    //         delay(1);
    //     }
    // }
    // analogWrite(LED_PIN, 0);
    // -----------------------------------------

    // Throb #2
    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 1024; k++) {
            analogWrite(LED_PIN, k);
            delay(1);
        }

        for (int j = 1022; j >= 0; j--) {
            analogWrite(LED_PIN, j);
            delay(1);
        }
    }
}

void setup() {
    // LED
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    // button
    pinMode(BUTTON_PIN, INPUT);

    if (WHOAMI == "alpha") {
        Particle.subscribe("beta", eventHandler);
    } else if (WHOAMI == "beta") {
        Particle.subscribe("alpha", eventHandler);
    }
}

void loop() {
    if (digitalRead(BUTTON_PIN) == HIGH) {
        Particle.publish(WHOAMI);
        digitalWrite(LED_PIN, HIGH);
        delay(5000);
    } else {
        digitalWrite(LED_PIN, LOW);
    }
}
