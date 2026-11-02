#include <Arduino.h>

// Connect this pin to the UE0164 module's direct SIG contact.
const uint8_t SENSOR_PIN = A0;

#if defined(ARDUINO_ARCH_AVR)
const uint8_t ADC_BITS = 10;
#else
const uint8_t ADC_BITS = 12;
#endif

// Set this to the ADC's actual full-scale voltage.
const float ADC_FULL_SCALE_V = 3.3f;
const uint16_t SAMPLE_COUNT = 16;
const uint32_t ADC_MAX = (1UL << ADC_BITS) - 1UL;

void setup() {
  Serial.begin(115200);

#if defined(ARDUINO_ARCH_ESP32) || defined(ARDUINO_ARCH_RP2040)
  analogReadResolution(ADC_BITS);
#endif

  pinMode(SENSOR_PIN, INPUT);
  Serial.println("DevLab UE0164 GT36537 direct analog SIG");
  Serial.println("Analog transfer and lux calibration are not yet specified.");
}

void loop() {
  uint32_t sum = 0;
  for (uint16_t i = 0; i < SAMPLE_COUNT; ++i) {
    sum += analogRead(SENSOR_PIN);
    delay(2);
  }

  const float raw = static_cast<float>(sum) / SAMPLE_COUNT;
  const float voltage = raw * ADC_FULL_SCALE_V / ADC_MAX;

  Serial.print("Raw: ");
  Serial.print(raw, 1);
  Serial.print("  Voltage: ");
  Serial.print(voltage, 3);
  Serial.println(" V");

  delay(500);
}

