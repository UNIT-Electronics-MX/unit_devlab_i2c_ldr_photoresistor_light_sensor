# DevLab UE0164 GT36537 DDP device profile

The onboard controller exposes the GT36537 LDR through DevLab Device Protocol
(DDP) v1.0 over I2C. The values below match the
[GT36537 controller firmware](https://github.com/UNIT-Electronics-Labs/unit_firmware_i2c_gt36537_py32).
They describe the digital interface; the direct `SIG` contact is analog.

| Field | Value |
|---|---|
| Manufacturer part number | `UE0164` |
| Factory 7-bit I2C address | `0x26` |
| DDP Device ID | `0x0106` (little-endian bytes `[0x06, 0x01]`) |
| DDP version | 1.0 |
| Firmware / hardware version | 1.0 / 1.0 in the current firmware profile |
| Capabilities | `0x00000199`: I2C configuration, analog input, sensor data, watchdog, persistent configuration |
| Configurable I2C address range | `0x08..0x77` |
| Raw light reading | 12-bit ADC code `0..4095` as little-endian `uint16` |
| Background update | Approximately every 20 ms |
| Averaging | 1, 4, 8, 16, or 24 samples |

The capability bitmap does **not** advertise `RELAY` or general-purpose
digital I/O. The firmware nevertheless accepts legacy `RELAY_*` commands for
the built-in indicator; those commands are compatibility behavior rather than
a relay on this module.

## Reading the sensor

DDP is a command protocol, not a register map. Send one command byte, issue
STOP, wait 2–5 ms, then read exactly the documented response length. Multi-byte
values use little-endian order.

```text
host -> [address + write, command] -> STOP
wait 5 ms
host -> [address + read, response bytes] -> NACK + STOP
```

| Command | Code | Response or effect |
|---|---:|---|
| `GET_DEVICE_ID` | `0x00` | `[0x06, 0x01]` |
| `GET_FIRMWARE_VERSION` | `0x01` | Current firmware version |
| `GET_HARDWARE_VERSION` | `0x02` | Current hardware version |
| `GET_CAPABILITIES` | `0x03` | `[0x99, 0x01, 0x00, 0x00]` |
| `GET_PROTOCOL` | `0x04` | `[0x01, 0x00]` for DDP v1.0 |
| `GET_I2C_ADDR` | `0x20` | Current 7-bit address |
| `SET_I2C_ADDR` | `0x21` | Staged address change, saved to Flash |
| `RESET_FACTORY` | `0x23` | Restore factory configuration; reset required |
| `READ_ADC0` | `0x60` | Latest raw sample `[LSB, MSB]` |
| `SET_ADC_AVERAGING` | `0x62` | Staged averaging change, saved to Flash |
| `GET_ADC_AVERAGING` | `0x63` | Active averaging window |
| `GT36537_RAW` | `0x80` | Same latest raw sample `[LSB, MSB]` |

`READ_ADC0` and `GT36537_RAW` return the same published ADC sample. A read
does not start a new conversion. The ADC code is a relative light reading,
not a calibrated lux value. The direction of change with light depends on
the LDR divider orientation.

For setters, send the command, read its one-byte acknowledgement, send the
parameter in a separate write within 250 ms, then read the final acknowledgement.
Read the current setting before changing it: address and averaging settings
persist in Flash. Use the [DevLab_GT365xx library](https://github.com/UNIT-Electronics-MX/unit_devlab_gt36537_library)
for the normal Arduino measurement path.

The product-specific electrical schematic and complete-module electrical
limits are pending. Use the [released pinout](../../hardware/resources/unit_pinout_v_1_0_ue0164_i2c_ldr_photoresistor_light_sensor_en.png)
for connection orientation.
