## **4 Connectors & Pinouts**

The released V1.0 pinout for the UE0164 LDR Photoresistor Light Sensor shows
the top and bottom board views. Check the view and connector orientation
before wiring.

### **4.1 Released Pinout** {.section-page}

![UE0164 LDR Photoresistor Light Sensor pinout, top and bottom views.](../../../hardware/resources/unit_pinout_v_1_0_ue0164_i2c_ldr_photoresistor_light_sensor_en.png){width=5.8in}

**Figure 4.1 — UE0164 pinout, English version.** The Spanish version is linked
in Section 8.

### **4.2 Connection Groups** {.page-break}

| Group | Labels in the released drawing | Purpose |
|---|---|---|
| Qwiic I2C connector | `GND`, `VCC`, `SDA`, `SCL` | Power and I2C bus connections |
| Direct contacts | `VCC`, `GND`, `SIG` | Power and direct signal access |
| Service pads | `TX`, `RX`, `RST` | Pads identified in the drawing; consult the hardware design before use |

The drawing marks optional 4-pin, 1 mm JST connector positions and two solder
links. Its notes say that opening the `I2C` link disables the I2C `SIG` signal
and opening the `SNS` link disables the LDR filter. The pinout does not
establish electrical limits or connector part numbers.
