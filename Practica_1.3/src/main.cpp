#include <Arduino.h>
#include "soc/gpio_reg.h"  // Librería para acceso a los registros GPIO

#define LED_PIN 2  // Pin del LED
#define DELAY 1000  // Retardo en milisegundos

void setup() {
   // Configurar el pin como salida usando el registro de dirección GPIO
   uint32_t *gpio_enable = (uint32_t *)GPIO_ENABLE_REG;
   *gpio_enable |= (1 << LED_PIN); // Habilitar el pin como salida

   Serial.begin(115200); // Inicializar el puerto serie
}

void loop() {
   uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG;

   // Encender el LED
   *gpio_out |= (1 << LED_PIN);
   Serial.println("ON");
   delay(DELAY);

   // Apagar el LED
   *gpio_out &= ~(1 << LED_PIN);
   Serial.println("OFF");
   delay(DELAY);
} 