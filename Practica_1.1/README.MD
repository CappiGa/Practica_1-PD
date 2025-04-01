# Práctica 1.1 - Parpadeo básico del LED

## 1. Descripción
En esta práctica, se implementa un programa básico en ESP32-S3 para hacer parpadear un LED de manera periódica. Se utilizará la salida serie para depuración y se explorará la funcionalidad de control de pines de salida del microcontrolador.

## 2. Objetivos
- Configurar un pin del ESP32-S3 como salida digital.
- Generar un parpadeo periódico de un LED con un tiempo de encendido y apagado de 500 ms.
- Utilizar `platformio.ini` para gestionar el entorno de desarrollo.
- Subir el código al repositorio de GitHub personal.

## 3. Materiales
- **ESP32-S3** (placa de desarrollo).
- **LED** (puede ser el integrado en la placa o uno externo).
- **Protoboard** y cables (en caso de usar un LED externo).

## 4. Desarrollo

### 4.1 Preparación del Entorno
1. Instalar **PlatformIO** en VS Code (si no está instalado).
2. Configurar el archivo `platformio.ini` con el siguiente contenido:
   ```ini
   [env:esp32-s3-devkitm-1]
   platform = espressif32
   board = esp32-s3-devkitm-1
   framework = arduino
   ```
3. Conectar el ESP32-S3 al ordenador mediante USB.
4. Configurar el puerto adecuado en PlatformIO.

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

### 4.4 Publicación en GitHub
1. Inicializar un repositorio en GitHub si no existe.
2. Subir los archivos `main.cpp` y `platformio.ini`.
3. Confirmar que el código está disponible en el repositorio personal.

## 5. Resultados
- Al cargar el código en el ESP32-S3, el LED comienza a **parpadear con un periodo de 1 segundo** (500 ms encendido, 500 ms apagado).
- La ejecución del programa es estable y se verifica correctamente mediante la salida serie.
- Se ha logrado programar y subir el código sin errores.

## 6. Conclusiones
- Se comprendió cómo configurar un pin del ESP32-S3 como salida digital.
- Se verificó el uso del `delay()` para generar pausas en la ejecución.
- Se estableció un flujo de trabajo con PlatformIO para programar el microcontrolador.
- Se aprendió a gestionar un repositorio en GitHub para compartir el código.

## 7. Referencias
- Código de referencia: [GitHub - Blink](https://github.com/schacon/blink)
- Documentación oficial de PlatformIO: [https://docs.platformio.org](https://docs.platformio.org)

