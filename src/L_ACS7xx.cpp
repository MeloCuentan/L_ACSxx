#include "L_ACS7xx.h"

/**
 * @brief Seleccion del modelo
 * @param modelACS: Modelo del ACS
 */
ACS7xx::ACS7xx(uint8_t modelACS) {
  _modelACS = modelACS;
}

/**
 * @brief Inicializar valores 
 * @param VCC: Voltaje de funcionamiento del microcontrolador o máximo del ADC
 * @param bits: Resolución de la lectura analógica
 */
void ACS7xx::begin(float VCC, uint8_t bits) {
  _VCC = VCC;
  _resolucion = pow(2, bits);
  _PCC = _puntoCeroConsumo[_modelACS] * _VCC;
}

/**
 * @brief Calcular el consumo del sensor con voltios como parámetro
 * 
 * @param voltiosPin: Recibe el voltaje del pin
 * @return float: Devulelve el consumo medido por el sensor
 */
float ACS7xx::consumoSensor(float voltiosPin) {
  float temporal;
  temporal = (voltiosPin - _PCC) / _sensitivity[_modelACS];
  if (abs(temporal) < 0.1)
    temporal = 0.0;
  return temporal;
}

/**
 * @brief Calcular el consumo del sensor con valor como parámetro
 * 
 * @param valorPin: Recibe el valor del pin
 * @param referenciaVoltios: Valor máximo en voltios donde se ha tomado esa medida (por defecto)
 * @return float: Devuelve el consumo medido por el sensor
 */
float ACS7xx::consumoSensor(uint16_t valorPin, float referenciaVoltios) {
  float voltiosPinTemp = ((float)valorPin * referenciaVoltios) / (float)_resolucion * 2;
  float consumoMedido = consumoSensor(voltiosPinTemp);
  return consumoMedido;
}
