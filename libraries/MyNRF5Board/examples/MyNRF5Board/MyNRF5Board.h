/*
  If you don't use an nRF5 board, you can ignore this file.

  This file was part of the "My Sensors nRF5 Boards" board repository
  available at https://github.com/mysensors/ArduinoBoards If you have
  questions, please refer the documentation at
  https://github.com/mysensors/ArduinoHwNRF5 first.

  This file is compatible with ArduinoHwNRF5 > 0.1.0

  This file allows you to change the pins of internal hardware, like the
  serial port, SPI bus or Wire bus.

  All pins referenced here are mapped via the "g_ADigitalPinMap" Array
  defined in "MyNRF5Board.cpp" to pins of the MCU.
  
  As an example, if you have at the third position in "g_ADigitalPinMap" the
  12, then all ports referenced in Arduino with 2 are mapped to P0.12. If you
  don't change the "g_ADigitalPinMap" Array, the Arduino pins 0..31 are
  translated to P0.00..P0..31.
   
  ###########################################################################
 
  This file is compatible with ArduinoHwNRF5 > 0.1.0
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

#ifndef _MYNRF5BOARD_H_
#define _MYNRF5BOARD_H_

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

// Number of pins defined in PinDescription array
#define PINS_COUNT           (32u)
#define NUM_DIGITAL_PINS     (32u)
#define NUM_ANALOG_INPUTS    (8u)
#define NUM_ANALOG_OUTPUTS   (8u)

/* 
 *  LEDs
 *  
 *  This is optional
 *  
 *  With My Sensors, you can use
 *  hwPinMode() instead of pinMode()
 *  hwPinMode() allows to use advanced modes like OUTPUT_H0H1 to drive LEDs.
 *  https://github.com/mysensors/MySensors/blob/development/drivers/NRF5/nrf5_wiring_constants.h
 *
 */
#define PIN_LED1                (13)
//  #define PIN_LED2                (9)
//  #define PIN_LED3                (10)
//  #define PIN_LED4                (11)
//  #define PIN_LED5                (12)
//  #define PIN_LED6                (14)
//  #define PIN_LED7                (15)
//  #define PIN_LED8                (16)
#define LED_BUILTIN          PIN_LED1

/* 
 *  Buttons
 *  
 *  This is optional
 */
// #define PIN_BUTTON1             (3)
// #define PIN_BUTTON2             (4)
// #define PIN_BUTTON3             (5)
// #define PIN_BUTTON4             (6)
// #define PIN_BUTTON5             (7)
// #define PIN_BUTTON6             (8)
// #define PIN_BUTTON7             (9)
// #define PIN_BUTTON8             (10)

/* 
 * Analog ports
 *  
 * If you change g_ADigitalPinMap, replace PIN_AIN0 with
 * port numbers mapped by the g_ADigitalPinMap Array.
 * You can add PIN_AIN0 to the g_ADigitalPinMap Array if
 * you want provide analog ports MCU independed, you can add
 * PIN_AIN0..PIN_AIN7 to your custom g_ADigitalPinMap Array
 * defined in MyNRF5Board.cpp
 */
static const uint8_t A0  = PIN_AIN0;
static const uint8_t A1  = PIN_AIN1;
static const uint8_t A2  = PIN_AIN2;
static const uint8_t A3  = PIN_AIN3;
static const uint8_t A4  = PIN_AIN4;
static const uint8_t A5  = PIN_AIN5;
static const uint8_t A6  = PIN_AIN6;
static const uint8_t A7  = PIN_AIN7;

/*
 * Serial interfaces
 * 
 * RX and TX are required.
 * If you have no serial port, use unused pins
 * CTS and RTS are optional.
 */
#define PIN_SERIAL_RX       (2)
#define PIN_SERIAL_TX       (3)
// #define PIN_SERIAL_CTS      (4)
// #define PIN_SERIAL_RTS      (5)

/*
 * SPI Interfaces
 * 
 * This is optional
 * 
 * If SPI is defined MISO, MOSI, SCK are required
 * SS is optional and can be used in your sketch.
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO         (22)
#define PIN_SPI_MOSI         (23)
#define PIN_SPI_SCK          (24)
#define PIN_SPI_SS           (21)

static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

/*
 * Wire Interfaces
 *
 * This is optional
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (20u)
#define PIN_WIRE_SCL         (21u)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#ifdef __cplusplus
}
#endif

#endif

