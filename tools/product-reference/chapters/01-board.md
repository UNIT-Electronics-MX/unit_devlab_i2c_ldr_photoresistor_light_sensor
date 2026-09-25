## **1 The Board**

The design supports two host paths. An I2C-capable controller can attach
through any of the three I2C connectors, while a host or test instrument with
an analog input can sample the dedicated RAW Signal Header directly. The
GT36537 photoresistor (LDR) is wired as a voltage divider; its midpoint is
read by the onboard microcontroller and made available through the I2C
interface, and remains separately available as an unprocessed analog signal
on the RAW Signal Header.

Detailed mechanical, pinout, and schematic assets for this GT36537 revision
are still pending publication. The values in this chapter reflect the current
confirmed design; items not yet released are marked accordingly.

### **1.1 Accessories** {.section-page}

The module is supplied with a Qwiic-compatible cable for connection to the I2C interface.

| Accessory | Purpose | Selection notes |
|---|---|---|
| JST/Qwiic-compatible cable | Connects `GND`, `VCC`, `SDA`, and `SCL` | Connector pitch and orientation for this GT36537 revision are pending publication; verify against the populated connector before use |

### **1.2 Recommended Test Equipment**

The following equipment may be used for integration, testing, and validation. These items are not included with the module.

| Equipment | Purpose | Selection notes |
|---|---|---|
| I2C-capable host | Scans and communicates with the module | Use 7-bit addressing over the DevLab Device Protocol (DDP) |
| Analog test lead or carrier | Provides access to `VCC`, `GND`, and `SIGNAL` on the RAW Signal Header | `SIGNAL` must connect to a voltage-compatible ADC input |
| Logic analyzer | Checks I2C communication activity | Use input thresholds compatible with the powered board |
| Reference lux meter | Supports optical calibration and validation | Required for quantitative illuminance validation |

### **1.3 Board Identification**

| Item | Value |
|---|---|
| Product | DevLab I2C GT36537 LDR Ambient Light Sensor |
| Brand / company | UNIT Electronics |
| Board ecosystem | DevLab |
| Product type | I2C-compatible ambient-light module with direct raw-signal access |
| Optical component | GT36537 photoresistor (LDR), wired as a voltage divider |
| Interface controller | 32-bit Arm Cortex-M0+ microcontroller; exact fitted part pending confirmation |
| Manufacturer Part Number (MPN) | Pending |
| Current board artwork | Pending |
| Product Reference | Pending — this chapter reflects the GT36537 revision in progress |

Board, pinout, schematic, and documentation revisions are controlled
independently.

### **1.4 Board Components and Features**

| Component / Feature | Function | Implementation / Notes |
|---|---|---|
| GT36537 photoresistor (LDR) | Changes resistance with incident visible light | Wired as a voltage divider; primary ambient-light sensing element |
| Onboard microcontroller | Reads the divider signal through its ADC and manages I2C communication | 32-bit Arm Cortex-M0+; exact fitted part pending confirmation |
| I2C connectors | Provide module power and I2C bus access | Three connectors, all wired to the same bus |
| RAW Signal Header | Provides direct access to `VCC`, `GND`, and the unprocessed sensor `SIGNAL` | Independent of the I2C interface; intended for analog measurement, testing, and characterization |
| Power indicator | Indicates that the board is powered | Onboard power LED |
| User / status indicator | Provides firmware-controlled status indication | Onboard status LED |
| Test points | Support debug and validation | Dedicated test points; assignment pending detailed publication |

### **1.5 Board Layout and Reference Designators** {.section-page}

Board-layout artwork, component placement, and reference designators for this
GT36537 revision are still pending publication. The topology, top-view, and
bottom-view images previously published for this repository belong to the
prior TEMT6000 (UE0098) hardware revision and must not be used as a layout
reference for the GT36537 module. This section will be completed once the
corresponding hardware assets are released.

Refer to Chapter 4 for user connections once the released schematic and
pinout are available.

### **1.6 Board Views** {.section-page}

Top- and bottom-view images for this GT36537 revision are pending
publication. A product photo and board-view images will be added once the
corresponding hardware assets are available.

### **1.7 Handling** {.section-page}

Use normal ESD precautions. Keep the sensor surface clean and optically
unobstructed. Remove power before changing connectors.
