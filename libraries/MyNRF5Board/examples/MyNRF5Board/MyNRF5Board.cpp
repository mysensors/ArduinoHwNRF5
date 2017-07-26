/*
  If you don't use an nRF5 board, you can ignore this file.
  
  This file was part of the "My Sensors nRF5 Boards" board repository
  available at https://github.com/mysensors/ArduinoBoards If you have
  questions, please refer the documentation at
  https://github.com/mysensors/ArduinoHwNRF5 first.
  
  This file is compatible with ArduinoHwNRF5 > 0.1.0

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

  
  ###########################################################################

  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry. All right reserved.
  Copyright (c) 2017 Sensnology AB. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/



#ifdef MYNRF5BOARD
#include <variant.h>

const uint32_t g_ADigitalPinMap[] = {
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
  12,
  13,
  14,
  15,
  16,
  17,
  18,
  19,
  20,
  21,
  22,
  23,
  24,
  25,
  26,
  27,
  28,
  29,
  30,
  31
};
#endif
