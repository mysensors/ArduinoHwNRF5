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

#include "variant.h"

#ifndef MY_ARDUINO_CORE_NRF5
const uint32_t g_ADigitalPinMap[] = {
#if PINS_COUNT>(0u)
  g_APinDescription[0].ulPin
#endif
#if PINS_COUNT>(1u)
  ,g_APinDescription[1].ulPin
#endif
#if PINS_COUNT>(2u)
  ,g_APinDescription[2].ulPin
#endif
#if PINS_COUNT>(3u)
  ,g_APinDescription[3].ulPin
#endif
#if PINS_COUNT>(4u)
  ,g_APinDescription[4].ulPin
#endif
#if PINS_COUNT>(5u)
  ,g_APinDescription[5].ulPin
#endif
#if PINS_COUNT>(6u)
  ,g_APinDescription[6].ulPin
#endif
#if PINS_COUNT>(7u)
  ,g_APinDescription[7].ulPin
#endif
#if PINS_COUNT>(8u)
  ,g_APinDescription[8].ulPin
#endif
#if PINS_COUNT>(9u)
  ,g_APinDescription[9].ulPin
#endif
#if PINS_COUNT>(10u)
  ,g_APinDescription[10].ulPin
#endif
#if PINS_COUNT>(11u)
  ,g_APinDescription[11].ulPin
#endif
#if PINS_COUNT>(12u)
  ,g_APinDescription[12].ulPin
#endif
#if PINS_COUNT>(13u)
  ,g_APinDescription[13].ulPin
#endif
#if PINS_COUNT>(14u)
  ,g_APinDescription[14].ulPin
#endif
#if PINS_COUNT>(15u)
  ,g_APinDescription[15].ulPin
#endif
#if PINS_COUNT>(16u)
  ,g_APinDescription[16].ulPin
#endif
#if PINS_COUNT>(17u)
  ,g_APinDescription[17].ulPin
#endif
#if PINS_COUNT>(18u)
  ,g_APinDescription[18].ulPin
#endif
#if PINS_COUNT>(19u)
  ,g_APinDescription[19].ulPin
#endif
#if PINS_COUNT>(20u)
  ,g_APinDescription[20].ulPin
#endif
#if PINS_COUNT>(21u)
  ,g_APinDescription[21].ulPin
#endif
#if PINS_COUNT>(22u)
  ,g_APinDescription[22].ulPin
#endif
#if PINS_COUNT>(23u)
  ,g_APinDescription[23].ulPin
#endif
#if PINS_COUNT>(24u)
  ,g_APinDescription[24].ulPin
#endif
#if PINS_COUNT>(25u)
  ,g_APinDescription[25].ulPin
#endif
#if PINS_COUNT>(26u)
  ,g_APinDescription[26].ulPin
#endif
#if PINS_COUNT>(27u)
  ,g_APinDescription[27].ulPin
#endif
#if PINS_COUNT>(28u)
  ,g_APinDescription[28].ulPin
#endif
#if PINS_COUNT>(29u)
  ,g_APinDescription[29].ulPin
#endif
#if PINS_COUNT>(30u)
  ,g_APinDescription[30].ulPin
#endif
#if PINS_COUNT>(31u)
  ,g_APinDescription[31].ulPin
#endif
};
#endif

#if defined(MY_ARDUINO_CORE_NRF5) && defined(PIN_SERIAL_RX) && defined(PIN_SERIAL_TX)
Uart Serial(PIN_SERIAL_RX, PIN_SERIAL_TX);
#endif
