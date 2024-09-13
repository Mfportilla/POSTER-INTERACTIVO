
#include <Esplora.h>   // Librería para usar las funcionalidades de la Arduino Esplora
#include <TFT.h>       // Librería para controlar la pantalla TFT
#include <SPI.h>       // Librería para la comunicación SPI (necesaria para la pantalla TFT)

// Definimos el tamaño de la pantalla TFT (320x240 para Esplora)
#define CS   7  // Pin Chip Select
#define DC   0  // Pin Data/Command
#define RESET 1 // Pin Reset

void setup() {
  // Inicializamos la pantalla TFT
  EsploraTFT.begin(); // Inicializa la pantalla con los pines correctos
  EsploraTFT.background(0, 0, 0);  // Establece el fondo en negro
  EsploraTFT.stroke(255, 255, 255);  // Color blanco para los textos y formas
  EsploraTFT.text("Inicializando...", 10, 10);  // Muestra un texto inicial en pantalla
}

void loop() {
  // Aquí iría el resto de la lógica del proyecto, como la detección del sensor de sonido
}
#include <Esplora.h>
#include <TFT.h>      // Biblioteca para manejar la pantalla TFT
#include <SPI.h>      // Biblioteca para la comunicación SPI

// Definimos los pines para la pantalla TFT (no es necesario configurar los pines específicos en la Esplora)
#define CS   7  // Pin Chip Select
#define DC   0  // Pin Data/Command
#define RESET 1 // Pin Reset

// Pin donde está conectado el sensor de sonido (en el puerto TinkerKit A0)
const int soundPin = A0;

// Umbral de detección de ruido (puedes ajustar este valor según sea necesario)
const int soundThreshold = 600;

void setup() {
  // Inicializar la pantalla
  EsploraTFT.begin();
  EsploraTFT.background(0, 0, 0);  // Fondo negro
  EsploraTFT.stroke(255, 255, 255); // Color blanco para el texto

  // Mostrar mensaje inicial
  EsploraTFT.text("Esperando sonido fuerte...", 10, 10);

  // Inicializar el puerto serial para depuración (opcional)
  Serial.begin(9600);
}

void loop() {
  // Leer el valor del sensor de sonido
  int soundValue = analogRead(soundPin);

  // Imprimir el valor del sensor en el monitor serial (opcional, para depuración)
  Serial.println(soundValue);

  // Comparar el valor del sensor con el umbral
  if (soundValue > soundThreshold) {
    // Si el sonido es fuerte, mostrar un mensaje en la pantalla
    EsploraTFT.background(255, 0, 0);  // Cambiar el fondo a rojo
    EsploraTFT.stroke(255, 255, 255);  // Texto blanco
    EsploraTFT.text("¡Sonido detectado!", 10, 10);  // Mostrar mensaje

    // Mantener el mensaje visible por un tiempo
    delay(1000);  // 1 segundo de espera

    // Restaurar el mensaje original
    EsploraTFT.background(0, 0, 0);  // Fondo negro
    EsploraTFT.stroke(255, 255, 255); // Texto blanco
    EsploraTFT.text("Esperando sonido fuerte...", 10, 10);
  }

  // Pequeña pausa entre lecturas
  delay(100);
}
// Pines para la pantalla TFT
#define CS   7  // Pin Chip Select
#define DC   0  // Pin Data/Command
#define RESET 1 // Pin Reset

// Pin para la tarjeta SD
#define SD_CS 8  // Pin Chip Select para la tarjeta SD

void setup() {
  // Inicializar la pantalla TFT
  EsploraTFT.begin();
  EsploraTFT.background(0, 0, 0);  // Fondo negro
  EsploraTFT.stroke(255, 255, 255); // Color blanco para el texto

  // Inicializar la tarjeta SD
  if (!SD.begin(SD_CS)) {
    EsploraTFT.text("No se pudo acceder a la SD", 10, 10);
    while (1);  // Si falla la SD, detener el programa
  }

  // Mostrar mensaje de inicio
  EsploraTFT.text("Cargando imagen...", 10, 10);

  // Cargar y mostrar la imagen BMP
  EsploraTFT.image(SD.open("imagen.bmp"), 0, 0);  // Cargar la imagen desde la SD y mostrarla
}

void loop() {
  // No se necesita hacer nada en el loop, ya que solo estamos mostrando la imagen
}
