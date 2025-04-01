# Práctica 1.2 - Parpadeo con mensajes en el puerto serie

## 1. Descripción
En esta práctica, se extiende el programa de parpadeo del LED de la práctica anterior para incluir la comunicación a través del puerto serie. Se enviará un mensaje indicando el estado del LED ("ON" cuando está encendido y "OFF" cuando está apagado) cada vez que cambie su estado.

## 2. Objetivos
- Configurar un pin del ESP32-S3 como salida digital.
- Inicializar y utilizar el puerto serie para depuración.
- Enviar mensajes de estado ("ON" y "OFF") cada vez que el LED cambie de estado.
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
   monitor_speed = 115200
   ```
3. Conectar el ESP32-S3 al ordenador mediante USB.
4. Configurar el puerto adecuado en PlatformIO.

### 4.2 Programación del Microcontrolador
El código implementado en `main.cpp` se basa en la estructura estándar de Arduino:
```cpp
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
```
**Explicación del código:**
- Se define el **pin 2** como el pin del LED.
- Se establece el modo del pin como salida en `setup()`.
- Se inicializa el puerto serie con `Serial.begin(115200);`.
- En `loop()`, se enciende el LED y se envía "ON" por el puerto serie.
- Luego, tras una pausa de 1000 ms, se apaga el LED y se envía "OFF" por el puerto serie.

### 4.3 Subida del Código al ESP32-S3
1. Conectar la placa ESP32-S3 y asegurarse de que está en modo de programación.
2. Compilar y cargar el código usando PlatformIO (`Upload`).
3. Abrir el monitor serie (`Monitor`) para verificar los mensajes "ON" y "OFF".

### 4.4 Publicación en GitHub
1. Inicializar un repositorio en GitHub si no existe.
2. Subir los archivos `main.cpp` y `platformio.ini`.
3. Confirmar que el código está disponible en el repositorio personal.

## 5. Resultados
- Al cargar el código en el ESP32-S3, el LED comienza a **parpadear con un periodo de 2 segundos** (1 segundo encendido, 1 segundo apagado).
- Se observa en el monitor serie que se imprimen los mensajes "ON" y "OFF" en cada ciclo.
- La ejecución del programa es estable y se verifica correctamente mediante la salida serie.

## 6. Conclusiones
- Se comprendió cómo utilizar la comunicación serie en el ESP32-S3.
- Se verificó la funcionalidad de `Serial.println()` para depuración.
- Se estableció un flujo de trabajo con PlatformIO para programar y depurar el microcontrolador.
- Se aprendió a gestionar un repositorio en GitHub para compartir el código.

## 7. Referencias
- Documentación oficial de PlatformIO: [https://docs.platformio.org](https://docs.platformio.org)
- Documentación de la comunicación serie en Arduino: [https://www.arduino.cc/reference/en/language/functions/communication/serial/](https://www.arduino.cc/reference/en/language/functions/communication/serial/)


