# Busybody Shield 3000

This is a device is a gift that I made which will keep Teams and busybodies happy while you take brief or long breaks.

## BOM

- Arduino Leonardo or Arduino Micro
- a red LED (I used a bezel mounted one)
- a SPST toggle switch

## Arduino Firmware

This project uses [Arduino-Makefile](https://github.com/sudar/Arduino-Makefile) to build, flash and test the Arduinos.

On Linux, install Arduino-Makefile then run `make upload` to flash your Arduino.

## Circuit

![](./circuit/Fritzing%20Sketch_schem.jpg)

- Arduino D13 - LED Act - R330 - GND
- Arduino D12 - Toggle Switch - GND
- Arduino D11 - LED Pwr - R330 - GND

## Enclosure

Load `enclosure/design.scad` in [OpenSCAD](https://openscad.org/).

This is my first attempt using YAPP_Box, the PCB standoffs aren't quite right and I want to revise and reprint the enclosure bottom half at a later time.

## Libraries, Sources & Licenses

The following libraries are used in the Arduino firmware and packaged with this repository:

| Name  | Source / Commit | License |
| ----- | --------------- | ------- |
| Mouse by [Arduino Libraries](<https://github.com/arduino-libraries>) | [9df2f76](https://github.com/arduino-libraries/Mouse/commit/9df2f765cb70aaa0cf00cd56e168185ee65f8f74) | GPL 2.1 |

The following libraries are used in the enclosure and packaged with this repository:

| Name     | Source / Commit                                                                                | License     |
| -------- | ---------------------------------------------------------------------------------------------- | ----------- |
| Arduino Measurements from Arduino Leonardo with USB Host Shield case by [Michael Ansel](https://www.printables.com/@michaelansel_967747) | [Printables](https://www.printables.com/model/536019-arduino-leonardo-with-usb-host-shield-case) | Creative Commons (4.0 International License) Attribution-ShareAlike |
| YAPP_Box by [Willem Aandewiel](https://github.com/mrWheel) | [08f71b7](https://github.com/mrWheel/YAPP_Box/commit/08f71b719a4ec3a436eab022c6c0f2b3bca2eef2) | MIT License |
