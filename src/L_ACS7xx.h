#ifndef L_ACS7XX_H
#define L_ACS7XX_H

#include <Arduino.h>

#define ACS712_ELC05 0x00   // -5A -> 5A
#define ACS712_ELC20 0x01   // -20A -> 20A
#define ACS712_ELC30 0x02   // -30A -> 30A
#define ACS758LCB_050B 0x03 // -50A -> 50A
#define ACS758LCB_050U 0x04 // 50A
#define ACS758LCB_100B 0x05 // -100A -> 100A
#define ACS758LCB_100U 0x06 // 100A
#define ACS758KCB_150B 0x07 // -150A -> 150A
#define ACS758KCB_150U 0x08 // 150A
#define ACS758ECB_200B 0x09 // -200A -> 200A
#define ACS758ECB_200U 0x0A // 200A

class ACS7xx
{
public:
  ACS7xx(uint8_t modelACS);
  void begin(float VCC, uint8_t bits = 10);
  float consumoSensor(float voltiosPin);
  float consumoSensor(uint16_t valorPin);

private:
  uint8_t _modelACS;
  uint8_t _bits;
  float _VCC = 5.0;
  const float _sensitivity[11] = {
      0.185, // ACS712 ELC-05  -> hsata 5A
      0.100, // ACS712 ELC-20  -> hasta 20A
      0.066, // ACS712 ELC-30  -> hasta 30A
      0.040, // ACS758LCB-050B -> -50A a 50A
      0.060, // ACS758LCB-050U -> hasta 50A
      0.020, // ACS758LCB-100B -> -100A a 100A
      0.040, // ACS758LCB-100U -> hasta 100A
      0.013, // ACS758KCB-150B -> -150A a 150A
      0.016, // ACS758KCB-150U -> hasta 150A
      0.010, // ACS758ECB-200B -> -200A a 200A
      0.020, // ACS758ECB-200U -> hasta 200A
  };
  const float _puntoCeroConsumo[11] = {
      0.5,  // ACS712-ELC05
      0.5,  // ACS712-ELC20
      0.5,  // ACS712-ELC30
      0.5,  // ACS758LCB-050B
      0.12, // ACS758LCB-050U
      0.5,  // ACS758LCB-100B
      0.12, // ACS758LCB-100U
      0.5,  // ACS758KCB-150B
      0.12, // ACS758KCB-150U
      0.5,  // ACS758ECB-200B
      0.12, // ACS758ECB-200U
  };
  float _PCC;
};

#endif