byte mac[6]; // the MAC address of your Wifi shield
int LED = D7;

void setup()
{
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
    WiFi.macAddress(mac);
}

void loop () {
    Serial.print("MAC: ");
    Serial.print(mac[5],HEX);
    Serial.print(":");
    Serial.print(mac[4],HEX);
    Serial.print(":");
    Serial.print(mac[3],HEX);
    Serial.print(":");
    Serial.print(mac[2],HEX);
    Serial.print(":");
    Serial.print(mac[1],HEX);
    Serial.print(":");
    Serial.println(mac[0],HEX);
    //blink an LED - this is just here as a validation that it's working...
    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED, LOW);
    delay(1000);
}
