/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.

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

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/** Master clock frequency */
#ifdef NRF52
#define VARIANT_MCK       (64000000ul)
#else
#define VARIANT_MCK       (16000000ul)
#endif

/*
 * Analog pins
 */
#ifdef NRF51
#define PIN_AIN0               (26)
#define PIN_AIN1               (27)
#define PIN_AIN2               (1)
#define PIN_AIN3               (2)
#define PIN_AIN4               (3)
#define PIN_AIN5               (4)
#define PIN_AIN6               (5)
#define PIN_AIN7               (6)
#else
#define PIN_AIN0               (2)
#define PIN_AIN1               (3)
#define PIN_AIN2               (4)
#define PIN_AIN3               (5)
#define PIN_AIN4               (28)
#define PIN_AIN5               (29)
#define PIN_AIN6               (30)
#define PIN_AIN7               (31)
#endif

#ifdef NRF52
#define ADC_RESOLUTION    14
#else
#define ADC_RESOLUTION    10
#endif

#ifdef __cplusplus
}
#endif // __cplusplus

#include <sketch/MyNRF5Board.h>
#endif
