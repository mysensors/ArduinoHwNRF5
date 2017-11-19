/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.
  Copyright (c) 2016 Arduino Srl.  All right reserved.

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

#ifndef _VARIANT_MYNRF5BOARD_
#define _VARIANT_MYNRF5BOARD_

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef MY_ARDUINO_CORE_NRF5
#ifdef __cplusplus
 #include "Uart.h"
#endif // __cplusplus
#endif

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus


#ifdef MY_ARDUINO_CORE_NRF5
/**
 * Libc porting layers
 */
#if defined (  __GNUC__  )
#    include <syscalls.h> /** RedHat Newlib minimal stub */
#endif
#endif

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Master clock frequency */
#ifdef NRF52
#define VARIANT_MCK       (64000000ul)
#else
#define VARIANT_MCK       (16000000ul)
#endif

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

#ifndef PIN_ATTR_NONE
#include "WVariant_arduino.h"
#endif

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/
#ifdef MY_ARDUINO_CORE_NRF5
#define digitalPinToPort(P)        ( NRF_P0 )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
#define digitalPinToTimer(P)       ( )
#define portOutputRegister(port)   ( &(port->OUT) )
#define portInputRegister(port)    ( &(port->IN)  )
#define portModeRegister(port)     ( &(port->DIR) )
#define analogInPinToBit(P)        ( g_APinDescription[P].ulPin )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM )
#define digitalPinToInterrupt(P)   ( P )
#endif

/*
 * Analog pins
 */
#ifdef NRF51
#define PIN_A0               (26)
#define PIN_A1               (27)
#define PIN_A2               (1)
#define PIN_A3               (2)
#define PIN_A4               (3)
#define PIN_A5               (4)
#define PIN_A6               (5)
#define PIN_A7               (6)
#else
#define PIN_A0               (2)
#define PIN_A1               (3)
#define PIN_A2               (4)
#define PIN_A3               (5)
#define PIN_A4               (28)
#define PIN_A5               (29)
#define PIN_A6               (30)
#define PIN_A7               (31)
#endif

#ifdef NRF52
#define PIN_RESOLUTION    14
#else
#define PIN_RESOLUTION    10
#endif

#ifdef __cplusplus
}
#endif // __cplusplus

#include <sketch/MyBoardNRF5.h>

#ifdef MY_ARDUINO_CORE_NRF5
/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/
#ifdef __cplusplus

extern Uart Serial;

#endif

#define SERIAL_PORT_MONITOR         Serial
#endif

#endif
