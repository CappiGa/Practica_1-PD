# Práctica 1.3 - Control del LED mediante registros GPIO

## 1. Descripción
En esta práctica, se implementa el control de un LED utilizando el acceso directo a los registros GPIO del ESP32-S3. En lugar de usar las funciones estándar de Arduino (`digitalWrite()`), se operará directamente sobre los registros del microcontrolador para modificar el estado del LED.

## 2. Objetivos
- Configurar un pin del ESP32-S3 como salida digital utilizando registros GPIO.
- Manipular directamente los registros de salida del ESP32-S3 para encender y apagar un LED.
- Utilizar operaciones a nivel de bits para modificar el estado del pin de salida.
- Enviar mensajes de estado ("ON" y "OFF") al puerto serie.

## 3. Materiales
- **ESP32-S3**.
- **LED**.
- **Protoboard**.

## 4. Desarrollo

### 4.1 Preparación del Entorno
1. Instalar **PlatformIO** en VS Code (si no está instalado).
2. Configurar el archivo `platformio.ini` con el siguiente contenido:
   ```ini
   [env:esp32-s3-devkitm-1]
   platform = espressif32
   board = esp32-s3-devkitm-1
   framework = arduino
   monitor_speed = 115200
   ```
3. Conectar el ESP32-S3 al ordenador mediante USB.
4. Configurar el puerto adecuado en PlatformIO.

### 4.2 Programación del Microcontrolador
El código implementado en `main.cpp` se basa en el acceso directo a los registros GPIO:
```cpp
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
```
**Explicación del código:**
- Se define el **pin 2** como el pin del LED.
- Se habilita el pin como salida modificando el registro `GPIO_ENABLE_REG`.
- Se inicializa el puerto serie con `Serial.begin(115200);`.
- En `loop()`, se usa `GPIO_OUT_REG` para encender (`|=`) y apagar (`&= ~`) el LED mediante manipulación de bits.
- Se imprimen los mensajes "ON" y "OFF" en el monitor serie.

### 4.3 Subida del Código al ESP32-S3
1. Conectar la placa ESP32-S3 y asegurarse de que está en modo de programación.
2. Compilar y cargar el código usando PlatformIO (`Upload`).
3. Abrir el monitor serie (`Monitor`) para verificar los mensajes "ON" y "OFF".

## 5. Resultados
- Al cargar el código en el ESP32-S3, el LED comienza a **parpadear con un periodo de 2 segundos** (1 segundo encendido, 1 segundo apagado).
- Se observa en el monitor serie que se imprimen los mensajes "ON" y "OFF" en cada ciclo.
- La ejecución del programa es estable y se verifica correctamente mediante la salida serie.
- 
