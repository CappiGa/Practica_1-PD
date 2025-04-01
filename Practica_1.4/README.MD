# Práctica 1.4 - Parpadeo usando millis()

## 1. Descripción
En esta práctica, se implementa el control de un LED sin utilizar la función `delay()`, sino con la función `millis()`, lo que permite un control más eficiente del tiempo. Además, se medirá la máxima frecuencia de encendido/apagado que permite el microcontrolador ESP32-S3 utilizando un osciloscopio.

## 2. Objetivos
- Reemplazar `delay()` por `millis()` para permitir la ejecución de otras tareas en paralelo.
- Evaluar el impacto del uso de registros GPIO frente a las funciones de Arduino en la velocidad de conmutación del LED.
- Medir la frecuencia de encendido/apagado en distintos escenarios mediante un osciloscopio.
- Comparar el impacto del envío de datos por el puerto serie en la velocidad de conmutación.
- Subir el código al repositorio de GitHub personal.

## 3. Materiales
- **ESP32-S3** (placa de desarrollo).
- **LED** (puede ser el integrado en la placa o uno externo).
- **Protoboard** y cables.
- **Osciloscopio** para medir la frecuencia de conmutación.

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
El código implementado en `main.cpp` se basa en el uso de `millis()` para evitar bloqueos:
```cpp
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
```
**Explicación del código:**
- Se define el **pin 2** como el pin del LED.
- Se usa `millis()` en lugar de `delay()` para gestionar el tiempo sin bloquear la ejecución.
- Se manipulan directamente los registros GPIO del ESP32 (`GPIO.out_w1tc` y `GPIO.out_w1ts`) para cambiar el estado del LED.
- Se elimina el uso de `Serial.println()` para no afectar la frecuencia máxima de conmutación.

### 4.3 Medición de la Frecuencia con el Osciloscopio
Se realizarán mediciones en cuatro casos:
1. **Con envío por el puerto serie y funciones de Arduino** (`digitalWrite()`).
2. **Con envío por el puerto serie y acceso directo a registros GPIO**.
3. **Sin envío por el puerto serie y funciones de Arduino** (`digitalWrite()`).
4. **Sin envío por el puerto serie y acceso directo a registros GPIO**.

Pasos:
1. Conectar el osciloscopio al pin del LED.
2. Cargar cada versión del código y medir la frecuencia de parpadeo.
3. Comparar los resultados y analizar el impacto del puerto serie y del método de acceso al GPIO.

### 4.4 Subida del Código al ESP32-S3
1. Conectar la placa ESP32-S3 y asegurarse de que está en modo de programación.
2. Compilar y cargar el código usando PlatformIO (`Upload`).
3. Abrir el monitor serie (`Monitor`) si es necesario.

### 4.5 Publicación en GitHub
1. Inicializar un repositorio en GitHub si no existe.
2. Subir los archivos `main.cpp` y `platformio.ini`.
3. Confirmar que el código está disponible en el repositorio personal.

## 5. Resultados
- Se observó en el osciloscopio que la frecuencia de parpadeo varía según el método utilizado.
- El uso de registros GPIO permite una conmutación más rápida que `digitalWrite()`.
- El envío de datos por el puerto serie reduce significativamente la frecuencia máxima alcanzable.
- Se lograron frecuencias de conmutación superiores sin el uso del puerto serie.

## 6. Conclusiones
- El uso de `millis()` en lugar de `delay()` permite ejecutar otras tareas sin bloquear el microcontrolador.
- La manipulación directa de registros GPIO es mucho más eficiente en términos de velocidad de conmutación.
- La comunicación serie introduce una latencia significativa en la velocidad de parpadeo.
- Se comprendió el impacto del software en la velocidad de respuesta del hardware.

## 7. Referencias
- Documentación oficial de PlatformIO: [https://docs.platformio.org](https://docs.platformio.org)
- Documentación sobre registros GPIO del ESP32: [https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/api-reference/peripherals/gpio.html](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/api-reference/peripherals/gpio.html)
