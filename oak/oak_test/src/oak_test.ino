// #include <BlynkSimpleEsp8266.h>
// #include <ESP8266WiFi.h>

// char auth[] = "3aa131eb45734fae9ed29a4e59e3eaf1";

void setup() {
    pinMode(6, OUTPUT);
    // Blynk.config(auth);
}

void loop() {
    // Blynk.run();

    digitalWrite(6, LOW);
    delay(1000);
    digitalWrite(6, HIGH);
    delay(1000);
}
