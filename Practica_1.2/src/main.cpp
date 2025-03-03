#include <Arduino.h>
#define LED_BUILTIN 2
#define DELAY 1000

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(115200); // Inicializar el puerto serie
}

void loop() {
digitalWrite(LED_BUILTIN, HIGH);
Serial.println("ON"); // Enviar mensaje por el puerto serie
delay(DELAY);

digitalWrite(LED_BUILTIN, LOW);
Serial.println("OFF"); // Enviar mensaje por el puerto serie
delay(DELAY);
}
