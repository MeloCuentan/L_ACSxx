#include <L_ACS7xx.h>

const float VCC = 5.0;
const uint8_t analogResolution = 10;
const uint8_t canalADS = 0;

uint16_t valorRawPin;
float voltiosADS;
float consumo;

ACS7xx sensor1(ACS712_05);

void setup() {
  Serial.begin(115200);
  Serial.println("Inicio del sistema");
  
  sensor1.begin(VCC); // Hay que pasar el voltaje medido de alimentación
  // sensor1.begin(VCC, analogResolution); // Opción añadiendo la resolución en bits
}

void loop() {
  valorRawPin = analogRead(canalADS);
  // Método pasando el valor del pin
  //consumo = sensor1.consumoSensor(valorRawPin);
  
  // Método pasando el voltaje del pin
  voltiosADS = (float)valorRawPin * VCC / 1024;
  consumo = sensor1.consumoSensor(voltiosADS);

  Serial.print("AIN0: ");
  Serial.print(valorRawPin, 1);
  Serial.print("  ");
  Serial.print(voltiosADS, 1);
  Serial.println("V");
  Serial.print("consumo : ");
  Serial.println(consumo);

  delay(1000);
}
