# DevLab: I2C GT36537 LDR Ambient Light Sensor

The **DevLab I2C GT36537 LDR Ambient Light Sensor** is a small ambient light sensor module that contains the **GT36537 photoresistor (LDR)** and an onboard **microcontroller**. This version has an **I2C interface** that allows the sensor signal to be captured, processed and accessed digitally from an I2C host using the DevLab Device Protocol (DDP), unlike a typical LDR module which only offers an analog output.

The module also includes a dedicated header for direct access to the **raw sensor signal**, allowing the GT36537 divider output to be used directly for analog measurements, testing, characterization or custom signal processing. The board has three I2C connections, which makes it easy to integrate with other DevLab modules and I2C based systems.


<div align="center">

*(Product photo pending — the GT36537 hardware asset has not been provided yet)*

</div>


<div align="center">

### Quick Setup

<img src="https://img.shields.io/badge/Product%20Wiki-pending-lightgrey?style=for-the-badge" alt="Product Wiki (pending)">
<img src="https://img.shields.io/badge/Datasheet-pending-lightgrey?style=for-the-badge" alt="Datasheet (pending)">
[<img src="https://img.shields.io/badge/Buy%20Now-orange?style=for-the-badge" alt="Buy Now">](https://uelectronics.com/)
[<img src="https://img.shields.io/badge/Getting%20Started-purple?style=for-the-badge" alt="Getting Started">](https://github.com/UNIT-Electronics-MX/unit_devlab_i2c_ldr_photoresistor_light_sensor/tree/main/software)

</div>


## Overview

| Feature | Description |
|---|---|
| Sensor | GT36537 Ambient Light Sensor |
| Sensor Type | Ambient light photoresistor (LDR) |
| Onboard MCU | 32-bit Arm Cortex-M0+ microcontroller |
| Main Interface | I2C (DevLab Device Protocol, DDP 1.0) |
| Raw Signal Access | Direct sensor signal available through dedicated header |
| I2C Connectivity | 3 I2C connectors |
| Status Indicators | Power and user/status LEDs |
| Debug / Test | Dedicated test points |
| Module Function | Ambient light acquisition and I2C sensor interface |


## How It Works

The **GT36537** photoresistor (LDR) changes resistance according to the incident ambient light level. Wired as a voltage divider, its midpoint is read by the onboard **microcontroller** through a 12-bit ADC input, updated roughly every 20 ms.

The microcontroller makes the resulting reading available through the **I2C interface** using the DevLab Device Protocol (DDP): the module answers as DDP Device ID `0x0106` at the factory I2C address `0x26`.

The board also exposes the sensor signal through the **RAW Signal Header**, allowing direct access to the unprocessed GT36537 divider output independently of the I2C interface.

This architecture provides two ways to work with the sensor:

- **I2C interface:** Easy digital integration with microcontrollers and other I2C systems.
- **RAW signal:** Direct access to the sensor output for analog measurements, testing, or custom processing.


## Use Cases

- Ambient light monitoring.
- Automatic display brightness adjustment.
- Smart lighting systems.
- Home and industrial automation.
- IoT environmental monitoring.
- Light-level data logging.
- Educational and prototyping applications.
- Sensor characterization using the RAW signal output.
- Integration into I2C sensor networks.


## Resources

> Schematic, pinout and dimension diagrams for the GT36537 revision of this
> board are pending. The `docs/hardware/` and `hardware/` files currently in
> this repository still belong to the previous TEMT6000 revision and should
> **not** be used as a reference for this board — they will be replaced once
> the GT36537 hardware assets are available.

- Firmware: [`unit_firmware_i2c_gt36537_py32`](https://github.com/UNIT-Electronics-Labs/unit_firmware_i2c_gt36537_py32)
- Arduino library: [`unit_devlab_gt36537_library`](https://github.com/UNIT-Electronics-MX/unit_devlab_gt36537_library) (`DevLab_GT365xx`)
- Protocol: [`DevLabDDP`](https://github.com/UNIT-Electronics-MX/unit_devlab_ddp_library)
- [Software examples in this repository](software)


## License

All hardware and documentation in this project are licensed under the **MIT License**.

Please refer to [`LICENSE.md`](LICENSE.md) for full terms.


<div align="center">

  <sub>Developed by UNIT Electronics</sub>

</div>
