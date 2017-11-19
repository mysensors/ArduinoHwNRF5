/*
 * This example sketch shows how you can manage the nRF5 pin mapping as part of your code.
 * You can use the method for any nRF51822 or nRF52832 board or module.
 * 
 * Most components, like UART, SPI, Wire Bus, of the nRF5 series chips don't
 * have a fixed pin mapping. There are some pins with restrictions like analog
 * inputs, NFC or pins near the radio module. Please refer the latest
 * documentation about pin restrictions at http://infocenter.nordicsemi.com 
 * 
 * To use the custom pin mapping you have to do following steps:
 * 
 * 1. Install "arduino-nrf5" like described at
 *    https://github.com/sandeepmistry/arduino-nRF5/
 * 2. Install the "My Sensors nRF5 Boards" with the board manager like
 *    explained at https://github.com/mysensors/ArduinoBoards
 * 3. Copy the files "MyBoardNRF5.cpp" and "MyBoardNRF5.h" from
 *    "MyBoardNRF5" example into your sketch.
 * 4. Modify pin mappings in "MyBoardNRF5.cpp" and "MyBoardNRF5.h" to fit
 *    your requirements.
 * 5. Select "MyBoardNRF5 nrf52832" or "MyBoardNRF5 nrf52822" as your board.
 *    Choose the correct parameters and programmer in the Tools menu.
 */

void setup() {
}

void loop() {
}
