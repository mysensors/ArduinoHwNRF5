# ArduinoHwNRF5

Arduino hardware definitions for Mysensors nRF5 boards

CI statuses
-----------
Current build status of master branch with respect to the master and development branch of the MySensors library: [![Build Status](https://ci.mysensors.org/job/MySensors/job/ArduinoHwNRF5/job/master/badge/icon)](https://ci.mysensors.org/job/MySensors/job/ArduinoHwNRF5/job/master/)

Current build status of master branch with respect to the master and development branch of the MySensors library using the nightly build of the Arduino IDE: [![Build Status](https://ci.mysensors.org/job/MySensors-nightly-IDE/job/ArduinoHwNRF5/job/master/badge/icon)](https://ci.mysensors.org/job/MySensors-nightly-IDE/job/ArduinoHwNRF5/job/master/)

## MyNRF5Board

This repository allows managing the nRF5 pin mapping as part of your code.
You can use the method for any nRF51822 or nRF52832 board or module.

Most components, like UART, SPI, Wire Bus, of the nRF5 series chips don't
have a fixed pin mapping. There are some pins with restrictions like analog
inputs, NFC or pins near the radio module. Please refer the latest
documentation about pin restrictions at http://infocenter.nordicsemi.com 

To use the custom pin mapping you have to do following steps:

  1. Install "arduino-nrf5" like described at
     https://github.com/sandeepmistry/arduino-nRF5/
  2. Install the "My Sensors nRF5 Boards" with the board manager like
     explained at https://github.com/mysensors/ArduinoBoards
  3. Copy the files "MyNRF5Board.cpp" and "MyNRF5Board.h" from
     "MyNRF5Board" example into your sketch.
  4. Modify pin mappings in "MyNRF5Board.cpp" and "MyNRF5Board.h" to fit
     your requirements.
  5. Select "MyNRF5Board nrf52832" or "MyNRF5Board nrf52822" as your board.
     Choose the correct parameters and programmer in the Tools menu.

### MyNRF5Board.h

This file allows you to change the pins of internal hardware, like the
serial port, SPI bus or Wire bus.

All pins referenced here are mapped via the "g_ADigitalPinMap" Array
defined in "MyNRF5Board.cpp" to pins of the MCU.

As an example, if you have at the third position in "g_ADigitalPinMap" the
12, then all ports referenced in Arduino with 2 are mapped to P0.12. If you
don't change the "g_ADigitalPinMap" Array, the Arduino pins 0..31 are
translated to P0.00..P0..31.

### MyNRF5Board.cpp

This file allows you to change the relation between pins referenced in
the Arduino IDE (0..31) and pins of the nRF5 MCU (P0.00..P0.31).

If you can live with addressing the GPIO pins by using the Arduino pins
0..31 instead of a custom mapping, don't change this file. If you have
a lot of Arduino code with fixed pin numbers and you need to map these
pins to specific pins of the nRF5 MCU; you need to change this file.

If you fill the "g_ADigitalPinMap" Array with numbers between 0..31,
the Arduino pins 0..31 are assigned to pins P0.00..P0.31 of the MCU.

As an example, if you need to change the pin mapping for Arduino pin 5
to P0.12 of the MCU, you have to write the 12 into the sixth position
in the  "g_ADigitalPinMap" Array.

The pin mapping effects commands like "pinMode()", "digitalWrite()",
"analogRead()" and "analogWrite()".

If you change the pin mapping, you have to modify the pins in
"MyNRF5Board.h". Especially the analog pin mapping must be replaced with
your pin numbers by replacing PIN_AIN0..7 with a number of your mapping
array. You can use the constants PIN_AIN0..7 in the "g_ADigitalPinMap"
Array if you want to reference analog ports MCU independent. You cannot
use the pins P0.00 and P0.01 for GPIO, when the 32kHz crystal is connected.
