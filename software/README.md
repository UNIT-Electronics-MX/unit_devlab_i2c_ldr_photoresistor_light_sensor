# Using the DevLab UE0164 GT36537 LDR module

The module provides two ways to read ambient light: a 12-bit raw measurement
over I2C through its onboard controller, and the direct analog `SIG` contact.
The reading is relative; neither interface supplies calibrated lux.

## I2C connection

Use the [released UE0164 pinout](../hardware/resources/unit_pinout_v_1_0_ue0164_i2c_ldr_photoresistor_light_sensor_en.png)
to connect `VCC`, `GND`, `SDA`, and `SCL`. One 4-pin, 1 mm I2C connector is
populated; the board drawing also shows two optional connector positions.
Check the actual bus pull-up voltage against the host's I2C pin rating before
applying power. The examples use 7-bit address `0x26` and Device ID `0x0106`.

Start with [serialLightRead](examples/i2c/cpp_examples/serialLightRead/serialLightRead.ino),
which verifies the device and prints its raw reading and relative percentage.
The [scanner](examples/i2c/cpp_examples/i2c_scanner/i2c_scanner.ino) helps
find an address, but an I2C acknowledgement alone does not identify the module.
The I2C measurement sketches require the
[DevLab_GT365xx library](https://github.com/UNIT-Electronics-MX/unit_devlab_gt36537_library).

| Host board | Bus | SDA | SCL |
|---|---|---|---|
| ESP32 | `Wire` | GPIO6 | GPIO7 |
| RP2040 / RP2350 | `Wire1` | GPIO12 | GPIO13 |
| AVR | `Wire` | Board's `SDA` pin | Board's `SCL` pin |

These are example host pins; select the actual pins for your board. See the
[examples guide](examples/README.md) for the other Arduino sketches and
the [protocol profile](protocol/README.md) for command and response details.

## Direct analog connection

With power removed, connect the module's `VCC` and `GND` contacts and its
direct `SIG` contact to a high-impedance host ADC. Set the host's ADC pin,
resolution, and reference voltage in the
[analog example](examples/adc/cpp_examples/light_sensor/light_sensor.ino).
Check the `SIG` voltage range before connecting a lower-voltage ADC. The
product-specific electrical schematic and a calibrated lux transfer function
have not yet been released.
