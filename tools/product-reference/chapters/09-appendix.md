## **9 Appendix**

### **9.1 Current Schematic** {.section-page}

The schematic documents the controller-based board, including the reference
controller, LDR analog stage, I2C interfaces, status indicators, test points,
and optional connectors.

**Figure 9.1 — Electrical schematic.**

The LDR divider signal is routed to the controller ADC input and the external
`VCC`/`GND`/`SIGNAL` header. The reading is not a calibrated or guaranteed
conversion to lux.

The I2C `SDA` and `SCL` signals are available at three physical connection
positions: one connector populated by default and two optional horizontal
positions. These signals are shared with the controller's factory programming
and debugging interface; there is no separate user-accessible SWD connector.

### **9.2 Document Control** {.section-page}

| Field | Value |
|---|---|
| Product | DevLab I2C GT36537 LDR Ambient Light Sensor |
| Product hierarchy | UNIT Electronics → DevLab board ecosystem → Atom family |
| Manufacturer Part Number (MPN) | UE0164 |
| Current board artwork | -- |
| Current pinout, topology, and dimensions | -- |
| Available schematic | -- |
| Product Reference | Version 1.0.0 |
| Publication date | 2026-08-31 |
| Interfaces | Three I2C connection positions on one bus; `VCC`/`GND`/`SIGNAL` header; reserved expansion pads; shared factory programming/debug signals |

### **9.3 Technical Data Not Specified in This Revision**

- Complete-module absolute-maximum ratings and current consumption
- I2C pull-up values and validated bus-loading limits
- Direct `SIGNAL` output range, loading characteristics, and ADC guidance
- Mechanical tolerances, board thickness, component heights, and finished mass
- Module-level optical, electrical, environmental, and EMC characterization
