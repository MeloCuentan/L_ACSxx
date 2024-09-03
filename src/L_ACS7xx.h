#ifndef L_ACS7XX_H
#define L_ACS7XX_H

#include <Arduino.h>

#define ACS712_05 0x00   // -5A -> 5A
#define ACS712_20 0x01   // -20A -> 20A
#define ACS712_30 0x02   // -30A -> 30A
#define ACS758_050B 0x03 // -50A -> 50A
#define ACS758_050U 0x04 // 50A
#define ACS758_100B 0x05 // -100A -> 100A
#define ACS758_100U 0x06 // 100A
#define ACS758_150B 0x07 // -150A -> 150A
#define ACS758_150U 0x08 // 150A
#define ACS758_200B 0x09 // -200A -> 200A
#define ACS758_200U 0x0A // 200A

class ACS7xx
{
public:
  ACS7xx(uint8_t modelACS);
  void begin(float VCC, uint8_t bits = 10);
  float consumoSensor(float voltiosPin, float referenciaVoltios = 5.0);
  float consumoSensor(uint16_t valorPin, float referenciaVoltios = 5.0);

private:
  uint8_t _modelACS;
  uint32_t _resolucion;
  float _VCC = 5.0;
  float _PCC;
  const float _sensitivity[11] = {
      0.185, // ACS712 - 05
      0.100, // ACS712 - 20
      0.066, // ACS712 - 30
      0.040, // ACS758 - 050B
      0.060, // ACS758 - 050U
      0.020, // ACS758 - 100B
      0.040, // ACS758 - 100U
      0.013, // ACS758 - 150B
      0.016, // ACS758 - 150U
      0.010, // ACS758 - 200B
      0.020  // ACS758 - 200U
  };
  const float _puntoCeroConsumo[11] = {
      0.5,  // ACS712 -05
      0.5,  // ACS712 -20
      0.5,  // ACS712 -30
      0.5,  // ACS758 - 050B
      0.12, // ACS758 - 050U
      0.5,  // ACS758 - 100B
      0.12, // ACS758 - 100U
      0.5,  // ACS758 - 150B
      0.12, // ACS758 - 150U
      0.5,  // ACS758 - 200B
      0.12  // ACS758 - 200U
  };
};

#endif
