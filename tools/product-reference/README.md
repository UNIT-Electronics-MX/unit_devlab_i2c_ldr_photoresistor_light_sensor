# UE0164 Product Reference source

This source documents the DevLab I2C LDR Photoresistor Light Sensor (MPN **UE0164**). The chapter order comes from `book.yml`; the generated HTML and PDF use the DevLab contents menu. Product-specific pinouts, board views, topology, dimensions, and CAD files are under `hardware/`. A UE0164 electrical schematic remains pending.

The digital profile is based on the GT36537 firmware and repository examples: factory 7-bit I2C address `0x26`, DDP Device ID `0x0106`, and a 12-bit raw sensor reading. The raw reading is relative and is not a calibrated lux value. Complete electrical ratings require a released product-specific source.

## Build

From the repository root:

```bash
./tools/product-reference/build.sh
```

Pass an output directory as the first argument for local review. The build writes Markdown, DOCX, HTML, and PDF files named `unit_product_reference_v_1_1_0_ue0164_i2c_ldr_photoresistor_light_sensor.*`.

The CI workflow publishes generated files under `docs/hardware/`.
