Creada y probada con un Arduino NANO, ESP8266 y ESP32

Para mediciones más precisas, utiliza un ADC externo (como el ADS1115), y en este caso se pueden utilizar los siguientes métodos;

  consumoSensor(float voltiosPin);
  consumoSensor(uint16_t valorPin, float referenciaVoltios);

En el segundo caso, hay que enviar el valor de lectura del pin y el voltaje de ganancia del ADS

