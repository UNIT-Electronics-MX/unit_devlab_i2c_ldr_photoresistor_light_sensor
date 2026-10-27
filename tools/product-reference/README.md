# Product Reference build

The UNIT ATOM GT36537 Product Reference source is maintained in Markdown under
`chapters/`. Document metadata and chapter order are defined in `book.yml`.
Version 1.0.0 documents the DevLab I2C GT36537 LDR Ambient Light Sensor
(MPN UE0164), hardware revision V0.3.1, and is based on DevLab Device Protocol
v1.0 and the repository examples under `software/examples/i2c/cpp_examples/`.
The module is read through the `DevLab_GT365xx` Arduino library, which
integrates DevLab Interface for I2C bus management.

The Product Reference documents the observable GT36537 profile: factory 7-bit
address `0x26`, DDP Device ID `0x0106`, DDP v1.0, and the 12-bit raw reading of
the LDR divider (`0` to `4095`) acquired on controller pin `PA2` (ADC_IN2).
Hardware assets for this revision (board artwork, pinout, dimensions,
schematic) and complete-module electrical limits are still pending and are
tracked as open items in Chapters 1, 2, 6, and 9.

## Local validation build

Requirements:

- Pandoc
- WeasyPrint, Google Chrome, or Chromium

Run from the repository root and direct validation output outside the
repository:

```bash
./tools/product-reference/build.sh /tmp/atom-gt36537-product-reference
```

The build produces the Markdown, DOCX, HTML, and PDF versions of the Product
Reference. Their base file name is set by `OUTPUT_BASENAME` in `build.sh`.

GitHub Actions publishes the PDF and DOCX under `docs/hardware/`. Do not edit
generated documents or `docs/` manually.

The Markdown chapters are the source of truth. Module values and mappings must
come from controlled technical references. The module provides three I2C
connection positions wired to the same bus, plus a separate RAW Signal Header
for direct analog access to the unprocessed LDR divider output. Do not infer
complete-module limits from a component rating alone.

Known source inconsistencies and unspecified board-level values are listed in
Chapter 9.
