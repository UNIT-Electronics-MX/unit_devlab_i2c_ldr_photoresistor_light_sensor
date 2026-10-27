## **2 Ratings**

This chapter summarizes the electrical operating conditions and interface
characteristics relevant to integrating the DevLab I2C GT36537 LDR Ambient Light Sensor. It covers the
module supply, I2C operation, analog sensor path, and controller capabilities. Use these ratings to select a compatible
power source and host interface and to identify the electrical characteristics
that require application-specific verification.

### **2.1 Recommended Operating Conditions** {.section-page}

| Symbol | Description | Min. | Typ. | Max. | Unit |
|---|---|---:|---:|---:|---|
| `VCC` | Module supply voltage | — | 3.3 or 5 | — | V |
| `VI2C` | I2C logic-high and pull-up voltage | — | `VCC` | — | V |
| `fSCL` | I2C clock frequency | 100 | — | 400 | kHz |
| `VSIG` | Direct analog `SIGNAL` voltage range | — | Not specified | — | V |
| `ICC` | Module supply current | — | Not specified | — | mA |
| `TA` | Module ambient operating temperature | Not specified | — | Not specified | °C |

The `VCC` values are the supported nominal operating points; they are not
complete-module absolute maximum ratings. The validated continuous supply
range around each nominal point is not specified.

Use a current-limited source during initial bring-up. The I2C pull-ups follow
the module supply, so the host must tolerate the actual bus voltage. When the
module operates at 5 V with a 3.3 V host, bidirectional level translation may
be required.

The direct `SIGNAL` range requires analog-stage verification and measurement.
Module current consumption must include the controller, indicators, pull-ups,
and sensor load. The complete-module ambient-temperature range has not been
qualified. I2C pull-up resistance, bus capacitance, and complete-module
absolute maximum ratings are also not specified.

### **2.2 Digital Interface and Firmware Characteristics**

| Parameter | Value | Description |
|---|---:|---|
| I2C addressing | 7-bit slave | Valid configurable addresses are `0x08..0x77` |
| Factory I2C address | `0x26` (7-bit) | Pass `0x26` directly to the host I2C library; `0x4C` is the 8-bit write address, not the device address |
| Device protocol | DDP v1.0 | Command transaction followed by an exact-length read transaction |
| Logical Device ID | `0x0106` | GT36537 identity; independent of the I2C address |
| Firmware / hardware | 1.0 / 1.0 | Current observable controller profile |
| Capability bitmap | `0x000001B9` | I2C configuration, analog input, sensor data, relay, watchdog, and persistent configuration |
| Raw digital sample | `0` to `4095` | 12-bit ADC code returned as an unsigned 16-bit little-endian value |
| ADC update interval | Approximately 20 ms | Background acquisition; an I2C read returns the latest published sample |
| Command processing delay | 2 to 5 ms | Use 5 ms conservatively before reading |
| Pending setter timeout | 250 ms | Parameter must arrive before expiry |

These values describe the currently documented digital behavior. Detailed DDP
commands and transaction sequences are provided in Chapter 3.

### **2.3 Onboard Interface Controller**

The onboard controller acquires the analog output of the GT36537 LDR divider and provides
the processed sensor data through the module's I2C interface. The controller is
not exposed as a general-purpose microcontroller and is not intended for
user programming.

| Feature | Module implementation |
|---|---|
| Internal controller | 32-bit Arm Cortex-M0+ |
| Sensor acquisition | 12-bit ADC |
| User digital interface | I2C |
| I2C addressing | 7-bit addressing |
| Supported I2C clock | 100 kHz and 400 kHz |
| Direct sensor access | Analog `SIGNAL` contact |
| Programming and debugging | Reserved for factory use |

### **2.4 Module-Level Characteristics**

The following characteristics are established for the current module
implementation and are described in the preceding sections.

| Characteristic | Current module specification |
|---|---|
| Nominal supply voltage | 3.3 V or 5 V |
| Digital interface | I2C, 7-bit slave |
| Factory I2C address | `0x26` |
| Configurable I2C address range | `0x08` to `0x77` |
| I2C clock frequency | 100 kHz to 400 kHz |
| Sensor acquisition | 12-bit ADC |
| Raw digital output | 0 to 4095 |
| ADC update interval | Approximately 20 ms |
| Command processing delay | 2 to 5 ms |
| Direct analog access | `SIGNAL` contact on the RAW Signal Header |

Additional characteristics such as complete-module absolute maximum ratings,
supply-current limits, guaranteed analog-output accuracy, calibrated lux
accuracy, board-level operating-temperature range, and environmental
qualification are not specified unless explicitly stated elsewhere in this
Product Reference.

Component-level ratings shall not be interpreted as guaranteed ratings of the
complete module.

### **2.5 Electrical Precautions**

1. Use a current-limited 3.3 V or 5 V supply during engineering bring-up.
2. Verify connector orientation and establish a common ground before applying power.
3. Do not exceed the controller upper operating-voltage limit of 5.5 V.
4. When operating the module at 5 V, verify host compatibility with the actual voltage present on `SDA`, `SCL`, and `SIGNAL`. Use appropriate level translation when required.
5. During normal operation, use the I2C connection points only for I2C communication. The same physical signals are shared with the controller's factory programming and debugging functions; SWD is not provided as a separate user interface.
6. Do not attempt firmware replacement or external debugging through the I2C connection points. Programming, debugging, and reset functions are reserved for manufacturer use and factory diagnostics.
7. Remove power before cutting, soldering, or reworking the I2C disable bridge or optional connector positions.
8. Verify the current released schematic, component specifications, and interface documentation before production integration.
