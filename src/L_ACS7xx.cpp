#include <L_ACS7xx.h>

/**
 * @brief Construct a new ACS7xx::ACS7xx object
 * 
 * @param modelACS: Modelo del ACS
 * @param bits: Resolución en bits de la entrada analógica
 */
ACS7xx::ACS7xx(uint8_t modelACS)
{
    _modelACS = modelACS;
}

/**
 * @brief 
 * Iniciamos con el punto cero
 */
void ACS7xx::begin(float VCC, uint8_t bits)
{
    _VCC = VCC;
    _bits = pow(2, bits);
    _PCC = _puntoCeroConsumo[_modelACS] * _VCC;
}

/**
 * @brief Calcular el consumo del sensor
 * 
 * @param voltiosPin: Recibe el voltaje del pin
 * @return float: Devulelve el consumo medido por el sensor
 */
float ACS7xx::consumoSensor(float voltiosPin)
{
    float temporal;
    temporal = (voltiosPin - _PCC) / _sensitivity[_modelACS];
    if (abs(temporal) < 0.1)
        temporal = 0.0;
    return temporal;
}

/**
 * @brief Calcular el consumo del sensor
 * 
 * @param valorPin: Recibe el valor del pin
 * @return float: Devuelve el consumo medido por el sensor
 */
float ACS7xx::consumoSensor(uint16_t valorPin)
{
    float voltiosPin;
    voltiosPin = (float)valorPin * _VCC / _bits;
    return consumoSensor(voltiosPin);
}
