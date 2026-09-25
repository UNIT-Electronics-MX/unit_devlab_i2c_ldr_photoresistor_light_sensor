# UNIT DevLab GT36537 LDR light sensor — examples

Choose the interface first. The `i2c/` examples talk to the module's onboard
microcontroller over the DevLab Device Protocol (DDP); the `adc/` example
reads the module's separate direct `SIG` contact instead. They are kept in
different trees so wiring and host-pin assumptions are not mixed.

## Layout

```text
examples/
├── i2c/
│   └── cpp_examples/
│       ├── serialLightRead/           normal raw reading + percentage
│       ├── serialLightReadInverted/   same reading, inverted scale
│       ├── serialLightRawPlot/        raw stream only, for a serial plotter
│       └── i2c_scanner/               bus troubleshooting only
└── adc/
    └── cpp_examples/
        └── light_sensor/              direct SIG reading
```

## I2C — recommended interface

Start with `serialLightRead` for normal operation. Use `i2c_scanner` only when
the module is not discovered on the bus.

| Example | Purpose |
|---|---|
| [`i2c/cpp_examples/serialLightRead`](i2c/cpp_examples/serialLightRead/serialLightRead.ino) | Verifies the GT36537 DDP device (ID `0x0106`) and prints its raw ADC0 reading and relative percentage. |
| [`i2c/cpp_examples/serialLightReadInverted`](i2c/cpp_examples/serialLightReadInverted/serialLightReadInverted.ino) | Same read, but flips the scale (`inverted = 4095 - raw`) so higher values always mean more light. |
| [`i2c/cpp_examples/serialLightRawPlot`](i2c/cpp_examples/serialLightRawPlot/serialLightRawPlot.ino) | Streams the raw ADC0 count as one integer per line, ready for the Arduino Serial Plotter or a script. |
| [`i2c/cpp_examples/i2c_scanner`](i2c/cpp_examples/i2c_scanner/i2c_scanner.ino) | Scans all 7-bit addresses and reports which ones respond; does not identify the device or its protocol. |

The `serialLightRead*`/`serialLightRawPlot` examples require the
[`DevLab_GT365xx`](https://github.com/UNIT-Electronics-MX/unit_devlab_gt36537_library)
library and expect the sensor at factory address `0x26`. `i2c_scanner` only
needs the generic `DevLab_I2C_Orchestrator` library and does not depend on the
GT36537 library.

All four sketches select their I2C bus and pins the same way:

| Board family | Bus | SDA | SCL |
|---|---|---|---|
| ESP32 | `Wire` | GPIO6 | GPIO7 |
| RP2040 / RP2350 | `Wire1` | GPIO12 | GPIO13 |
| AVR (Uno/Nano/Mega/Leonardo, ...) | `Wire` | board default (`SDA`) | board default (`SCL`) |

These are host pins, not the module's internal controller pins.

## ADC — direct SIG only

Use this path only when the host is wired to the module's direct `SIG`
contact instead of using the I2C/DDP interface.

| Example | Purpose |
|---|---|
| [`adc/cpp_examples/light_sensor`](adc/cpp_examples/light_sensor/light_sensor.ino) | Averages 16 analog samples on `SIG` and reports the ADC code and voltage. |

Set `SENSOR_PIN` and `ADC_FULL_SCALE_V` for the selected board. The example
reports ADC code and voltage, not lux, because the analog transfer function
still requires release and validation.

## Electrical note

The module supports nominal 3.3 V or 5 V operation. At 5 V, the host must
tolerate the actual I2C pull-up level or use a bidirectional level shifter.
`SDA/SCL` share their physical controller pins with the factory-only
`SWDIO/SWCLK` functions; the examples in this repository use I2C only.

See [`../protocol/README.md`](../protocol/README.md) for command timing,
response formats, capabilities, and address-change behavior.
