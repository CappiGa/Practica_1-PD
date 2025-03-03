#include <Arduino.h>

#define LED_PIN 2  // Definir el pin del LED
#define INTERVALO 1 // Intervalo en milisegundos

unsigned long tiempoAnterior = 0;
bool estadoLED = false;

void setup() {
    pinMode(LED_PIN, OUTPUT);  // Configurar el pin como salida
}

void loop() {
    unsigned long tiempoActual = millis();

    // Verificar si ha pasado el intervalo
    if (tiempoActual - tiempoAnterior >= INTERVALO) {
        tiempoAnterior = tiempoActual;  // Actualizar el tiempo de referencia

        // Alternar el estado del LED accediendo a los registros del ESP32
        if (estadoLED) {
            GPIO.out_w1tc = (1 << LED_PIN);  // Apagar el LED
        } else {
            GPIO.out_w1ts = (1 << LED_PIN);  // Encender el LED
        }
        estadoLED = !estadoLED; // Cambiar el estado del LED
    }
}