#include <Arduino.h>
#define LED_BUILTIN 2  // Definir el pin 2 como el pin del LED
#define DELAY 500      // Definir el tiempo de espera en milisegundos

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
digitalWrite(LED_BUILTIN, HIGH);
delay(DELAY);
digitalWrite(LED_BUILTIN, LOW);
delay(DELAY);
}