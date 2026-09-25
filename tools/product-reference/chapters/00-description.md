## **Description**

The DevLab I2C GT36537 LDR Ambient Light Sensor is an ambient-light sensor module developed by UNIT Electronics as part of the DevLab ecosystem. It combines a GT36537 photoresistor (LDR), wired as a voltage divider, with an onboard microcontroller-based interface controller, providing both I2C communication and direct access to the sensor's raw analog signal.

The board provides three I2C connectors sharing the same bus, a dedicated RAW Signal Header for direct access to the unprocessed sensor output, and power/status indicators. The onboard microcontroller reads the GT36537 divider signal through its analog-to-digital converter (ADC) and makes the resulting measurements available through the I2C interface.

### **Applications**

- I2C-connected ambient-light acquisition
- Direct analog light measurement during development, testing, and characterization
- Automatic display and indicator brightness control
- Smart lighting and home/industrial automation
- Day/night and relative-light detection
- Environmental and IoT light-level data logging
- Educational I2C and photoresistor experiments
- Integration into I2C sensor networks

### **DevLab Format Compatibility**

As part of the DevLab ecosystem, the GT36537 module follows a compact form factor intended for rapid prototyping and integration with other DevLab modules. The board provides three I2C connectors carrying `GND`, `VCC`, `SDA`, and `SCL`, all wired to the same bus, giving multiple physical access points to the I2C interface and supporting different module integration and mounting configurations.

Connector pitch, mechanical drawings, and supply-voltage limits for this GT36537 revision are still pending publication; verify the current hardware documentation before connecting the module to a host.

### **Hardware Features**

- GT36537 ambient-light photoresistor, wired as a voltage divider
- Onboard microcontroller handling I2C communication and ADC acquisition
- 7-bit I2C slave operation using the DevLab Device Protocol (DDP)
- Three I2C connection positions carrying `GND`, `VCC`, `SDA`, and `SCL`, all connected to the same bus
- Dedicated RAW Signal Header exposing the unprocessed GT36537 divider output, independent of the I2C interface
- Power and user/status indicators
- Dedicated test points for debug

The controller implements DevLab Device Protocol (DDP) v1.0. The GT36537 profile is identified by Device ID `0x0106`, and the factory I2C address is `0x26`.

Detailed electrical ratings, mechanical dimensions, and pinout diagrams for this GT36537 revision are still pending and will be published once the corresponding hardware assets are available.
