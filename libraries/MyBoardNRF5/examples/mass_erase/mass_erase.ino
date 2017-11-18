/*
 * This Sketch removes any contents of the nRF5 MCU.
 * If you don't have an programming adapter, the board can be become useless!
 */
#include <nrf.h>
void setup() {
  // Enable erasing flash
  NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Een << NVMC_CONFIG_WEN_Pos;
  while (NRF_NVMC->READY == NVMC_READY_READY_Busy) {
  };
  // Erase Flash and UICR
  NRF_NVMC->ERASEALL = 1;
}
void loop () {
}
