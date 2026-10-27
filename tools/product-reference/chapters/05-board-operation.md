## **5 Board Operation**

This chapter shows how to verify one DevLab I2C GT36537 LDR Ambient Light
Sensor and read its raw ambient-light value with Arduino. The examples use the
`DevLab_GT365xx` library and support ESP32, RP2040/RP2350, and AVR hosts.

### **5.1 Required Hardware and Software** {.section-page}

- DevLab I2C GT36537 module
- ESP32, RP2040/RP2350, or AVR development board acting as I2C host
- I2C connection for `VCC`, `GND`, `SDA`, and `SCL`
- USB cable for programming and Serial Monitor access
- Arduino IDE with the selected board package installed
- `DevLab_GT365xx` Arduino library

### **5.2 Library Installation**

1. Open **Tools > Manage Libraries** in Arduino IDE.
2. Search for `DevLab_GT365xx`.
3. Select the current release and click **Install**.

The library implements DDP v1.0 and uses DevLab Interface for I2C bus
management, integrated in the library itself. The sketch only includes
`DevLab_GT365xx.h`; no separate bus-handling or bus-recovery library is
needed. A screenshot of the library in Arduino Library Manager is pending.

### **5.3 I2C Connection and Example Settings** {.page-break}

Connect the module with power removed. Align the connector with the
orientation printed on the board and verify `VCC`, `GND`, `SDA`, and `SCL`
before applying power. A connection diagram for this GT36537 revision is
pending publication.

| Module | ESP32 | RP2040 / RP2350 | AVR | Function |
|---|---:|---:|---|---|
| `VCC` | 3.3 V or 5 V | 3.3 V or 5 V | 3.3 V or 5 V | Module supply |
| `GND` | `GND` | `GND` | `GND` | Common reference |
| `SDA` | GPIO6 | GPIO12 | Fixed board `SDA` pin | I2C data |
| `SCL` | GPIO7 | GPIO13 | Fixed board `SCL` pin | I2C clock |

On RP2040 and RP2350 the examples use the `Wire1` bus. AVR boards have fixed
I2C pins (Uno/Nano: A4/A5, Mega: 20/21, Leonardo: 2/3) taken from the board
variant. The pin numbers above match the repository examples; change `SDA_PIN`
and `SCL_PIN` when the selected host board uses different I2C pins.

Important: The I2C pull-up voltage follows the module supply (VCC). When operating the module at 5 V, verify that the host I2C pins are 5 V tolerant. If the host operates at 3.3 V and is not 5 V tolerant, use appropriate bidirectional level translation between the module and the host.

The example uses the following settings:

| Constant | Default | Purpose |
|---|---:|---|
| `SDA_PIN` | GPIO6 (ESP32); GPIO12 (RP2040/RP2350) | Host SDA pin |
| `SCL_PIN` | GPIO7 (ESP32); GPIO13 (RP2040/RP2350) | Host SCL pin |
| `I2C_FREQ` | 400000 Hz | I2C clock |
| `SENSOR_ADDRESS` | `0x26` | Factory 7-bit module address |
| `READ_INTERVAL_MS` | 250 ms | Time between printed readings |

If the module address was changed previously, update `SENSOR_ADDRESS` before
uploading the sketch.

### **5.4 Single-Sensor Arduino Example** {.page-break}

Open `serialLightRead.ino` from the library examples, or create it with the
following sketch:

```{.cpp .compact-code}
/**
 * @file serialLightRead.ino
 * @brief Verifies a GT36537 DDP device (ID 0x0106) on the I2C bus and prints
 *        its raw ADC0 reading and relative percentage over Serial.
 */

#include <Arduino.h>
#include <Wire.h>
#include <DevLab_GT365xx.h>

#if defined(ARDUINO_ARCH_RP2040) || defined(ARDUINO_ARCH_RP2350)
  #define I2C_BUS Wire1
  constexpr int SDA_PIN = 12;
  constexpr int SCL_PIN = 13;
#elif defined(ARDUINO_ARCH_ESP32)
  #define I2C_BUS Wire
  constexpr int SDA_PIN = 6;
  constexpr int SCL_PIN = 7;
#elif defined(ARDUINO_ARCH_AVR)
  #define I2C_BUS Wire
  constexpr int SDA_PIN = SDA;
  constexpr int SCL_PIN = SCL;
#else
#error "Use an ESP32, RP2040, RP2350, or AVR master"
#endif

constexpr uint32_t I2C_FREQ = 400000UL;
constexpr uint8_t SENSOR_ADDRESS = 0x26U;
constexpr uint32_t READ_INTERVAL_MS = 250U;

DevLab_GT365xx sensor(I2C_BUS, SENSOR_ADDRESS, I2C_FREQ);

void setup() {
  Serial.begin(9600);

  sensor.beginRecovered(SDA_PIN, SCL_PIN);
  if (!sensor.busReady()) {
    Serial.println("ERROR: I2C bus is blocked");
    return;
  }

  if (!sensor.isConnected()) {
    Serial.println("ERROR: expected GT36537 DDP device ID 0x0106 at 0x26");
    return;
  }

  sensor.printInfo();
  Serial.println("GT36537 ready: PA2 ADC0 reads the LDR divider");
}

void loop() {
  static uint32_t lastRead = 0U;
  if (millis() - lastRead < READ_INTERVAL_MS) {
    return;
  }
  lastRead = millis();

  uint16_t raw = 0U;
  if (sensor.readRaw(raw)) {
    float percent = (raw * 100.0f) / 4095.0f;
    Serial.printf("adc0=%u percent=%.1f\n", raw, percent);
  } else {
    Serial.println("ERROR: light read failed");
  }
}
```

The complete example also supports AVR hosts, where `Serial.printf()` is not
available and the output is printed with `Serial.print()` instead.

Two companion examples are provided:

| Example | Purpose |
|---|---|
| `serialLightReadInverted` | Reports `4095 - raw` with `readInvertRaw()` and `readInvertPercentage()` so that the value rises with more light |
| `serialLightRawPlot` | Streams one raw integer per line at 115200 baud for the Arduino Serial Plotter or `python/serial_plotter.py` |

### **5.5 Upload and Serial Output** {.section-page}

1. Select the connected host board in Arduino IDE.
2. Select its serial port.
3. Compile and upload `serialLightRead.ino`.
4. Open Serial Monitor at **9600 baud** (115200 baud for `serialLightRawPlot`).
5. Illuminate and cover the LDR to confirm that the printed value changes.

At startup, the sketch recovers and initializes the I2C bus, verifies that
address `0x26` contains a DDP GT36537 with Device ID `0x0106`, and prints the
reported device information. It then prints `adc0` and `percent` every 250 ms.

```text
<DDP device information>
GT36537 ready: PA2 ADC0 reads the LDR divider
adc0=<value from 0 to 4095> percent=<0.0 to 100.0>
adc0=<value from 0 to 4095> percent=<0.0 to 100.0>
```

The readings are raw ADC values. They indicate relative light level and must
not be interpreted directly as lux. Whether the value rises or falls with more
light depends on which end of the voltage divider carries the LDR; use
`serialLightReadInverted` if a value that rises with light is preferred.

### **5.6 Troubleshooting** {.section-page}

| Serial output or symptom | Check |
|---|---|
| `ERROR: I2C bus is blocked` | Wiring, connector orientation, shared ground, pull-up voltage, and unintended SDA/SCL drive |
| `ERROR: expected GT36537 DDP device ID 0x0106 at 0x26` | Address setting, I2C pins, module power, and possible address collision |
| `ERROR: light read failed` after successful identification | Cable continuity, bus clock, supply stability, and I2C connections |
| Constant `0` or `4095` | Sensor obstruction, excessive illumination, supply, and module orientation |
| Value falls when light increases | Expected for some divider orientations; use `serialLightReadInverted` |
| Values change but lux is inaccurate | Calibrate the complete optical installation against a reference light meter |

The complete Arduino examples and the `DevLab_GT365xx` library are listed in
Chapter 8.
