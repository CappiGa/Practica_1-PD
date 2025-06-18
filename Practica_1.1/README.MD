# Práctica 1.1 - Parpadeo básico del LED

## 1. Descripción
En esta práctica, se implementa un programa básico en ESP32-S3 para hacer parpadear un LED de manera periódica. Se utilizará la salida serie para depuración y se explorará la funcionalidad de control de pines de salida del microcontrolador.

## 2. Objetivos
- Configurar un pin del ESP32-S3 como salida.
- Generar un parpadeo periódico de un LED con un tiempo de encendido y apagado de 500 ms.

## 3. Materiales
- **ESP32-S3**
- **Led**
- **Cable tipo c**

![Image](https://github.com/user-attachments/assets/19769dc3-83b1-4c3a-9392-3f512ddd5112)

## 4. Desarrollo

### 4.1 Preparación del Entorno
1. Configurar el archivo `platformio.ini` con el siguiente contenido:
   ```ini
   [env:esp32-s3-devkitm-1]
   platform = espressif32
   board = esp32-s3-devkitm-1
   framework = arduino
   ```
2. Conectar el ESP32-S3 al ordenador mediante USB.

### 4.2 Programación del Microcontrolador
El código implementado en `main.cpp` se basa en la estructura estándar de Arduino:
```cpp
#include <Arduino.h>
#define LED_BUILTIN 2  // Definir el pin 2 como el pin del LED
#define DELAY 500      // Definir el tiempo de espera en milisegundos

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);  // Encender LED
    delay(DELAY);                      // Esperar 500 ms
    digitalWrite(LED_BUILTIN, LOW);   // Apagar LED
    delay(DELAY);                      // Esperar 500 ms
}
```
**Explicación del código:**
- Se define el **pin 2** como el pin del LED.
- Se establece el modo del pin como salida en `setup()`.
- En `loop()`, se enciende y apaga el LED con intervalos de 500 ms.

### 4.3 Subida del Código al ESP32-S3
1. Conectar la placa ESP32-S3 y asegurarse de que está en modo de programación.
2. Compilar y cargar el código usando PlatformIO (`Upload`).
3. Abrir el monitor serie (`Monitor`) para verificar el funcionamiento.

## 5. Resultados
- Al cargar el código en el ESP32-S3, el LED comienza a **parpadear con un periodo de 1 segundo** (500 ms encendido, 500 ms apagado).
- La ejecución del programa es estable y se verifica correctamente mediante la salida serie.

![Image](https://github.com/CappiGa/Practica_1-PD/issues/2#issue-3157554914)


