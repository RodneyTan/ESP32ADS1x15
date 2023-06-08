// ESP32ADS1x15 read ADS1x15 ADC channel 0 and channel 1,
// then print its ADC value on serial monitor every 10 seconds.
// It is based on RobTillaart ADS1x15 Library https://github.com/RobTillaart/ADS1X15

#include "ADS1X15.h"
ADS1115 ADS(0x48); // default address, ADDR connected to GND
int16_t ADC0, ADC1;

void setup() {
  // Setup Serial Port
  Serial.begin(115200);
  // Start ADS
  ADS.begin();
  ADS.setGain(16);  // Gain 0, Full Scale Range 6.411V, 187.5uV per bit
                    // Gain 1, Full Scale Range 4.096V, 125uV per bit
                    // Gain 2, Full Scale Range 2.048V, 62.5uV per bit
                    // Gain 4, Full Scale Range 1.024V, 31.25uV per bit
                    // Gain 8, Full Scale Range 0.512V, 15.625uV per bit
                    // Gain 16, Full Scale Range 0.256V, 7.8125uV per bit
}

void loop() {
  
  if (ADS.isReady()) {
    ADC0 = ADS.readADC(0);
    ADC1 = ADS.readADC(1);

    Serial.print("\nADC Channel 0 = ");
    Serial.println(ADC0);
    Serial.print("ADC Channel 1 = ");
    Serial.println(ADC1);
    delay(10000);
  }
  
}