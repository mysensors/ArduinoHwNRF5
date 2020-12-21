// Modification of arduino/hardware/nrf52/cores/arduino/WVariant.h to support arduino-nrf5 variant.

#ifndef _VARIANTS_ARDUINO_
#define _VARIANTS_ARDUINO_

#include <stdint.h>
#include <nrf.h>

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

//number of channel: 8
typedef enum _EAnalogChannel
{
	No_ADC_Channel=-1,
#ifdef NRF51
	ADC_A0=ADC_CONFIG_PSEL_AnalogInput0,
	ADC_A1=ADC_CONFIG_PSEL_AnalogInput1,
	ADC_A2=ADC_CONFIG_PSEL_AnalogInput2,
	ADC_A3=ADC_CONFIG_PSEL_AnalogInput3,
	ADC_A4=ADC_CONFIG_PSEL_AnalogInput4,
	ADC_A5=ADC_CONFIG_PSEL_AnalogInput5,
	ADC_A6=ADC_CONFIG_PSEL_AnalogInput6,
	ADC_A7=ADC_CONFIG_PSEL_AnalogInput7
#else
	ADC_A0=SAADC_CH_PSELP_PSELP_AnalogInput0,
	ADC_A1=SAADC_CH_PSELP_PSELP_AnalogInput1,
	ADC_A2=SAADC_CH_PSELP_PSELP_AnalogInput2,
	ADC_A3=SAADC_CH_PSELP_PSELP_AnalogInput3,
	ADC_A4=SAADC_CH_PSELP_PSELP_AnalogInput4,
	ADC_A5=SAADC_CH_PSELP_PSELP_AnalogInput5,
	ADC_A6=SAADC_CH_PSELP_PSELP_AnalogInput6,
	ADC_A7=SAADC_CH_PSELP_PSELP_AnalogInput7
#endif
} EAnalogChannel ;

typedef enum _ETCChannel
{
	NOT_ON_TIMER=-1,
} ETCChannel ;

// Definitions for PWM channels
// MSB = PWM module (0 - NRF_PWM0, 1 - NRF_PWM1, 2 - NRF_PWM2)
// LSB = PWM channel (0 to 3)
// ex: 0x10 = PWM1 channel 0
typedef enum _EPWMChannel
{
	NOT_ON_PWM=-1,
	PWM0=0x00,	
	PWM1=0x01,
	PWM2=0x02,
	PWM3=0x03,
	PWM4=0x10,
	PWM5=0x11,
	PWM6=0x12,
	PWM7=0x13,
	PWM8=0x20,
	PWM9=0x21,
	PWM10=0x22,
	PWM11=0x23
} EPWMChannel ;


typedef enum _EPortType
{
	NOT_A_PORT=-1,
	PORT0=0
} EPortType ;


typedef enum _EPioType
{
  PIO_NOT_A_PIN=-1,  /* Not under control of a peripheral. */
  PIO_ANALOG,        /* The pin is controlled by the associated signal of peripheral B. */
  PIO_DIGITAL,       /* The pin is controlled by PORT. */
  PIO_INPUT,         /* The pin is controlled by PORT and is an input. */
  PIO_INPUT_PULLUP,  /* The pin is controlled by PORT and is an input with internal pull-up resistor enabled. */
  PIO_OUTPUT,        /* The pin is controlled by PORT and is an output. */

  } EPioType ;

/**
 * Pin Attributes to be OR-ed
 */
#define PIN_ATTR_NONE          (0UL<<0)
#define PIN_ATTR_COMBO         (1UL<<0)
#define PIN_ATTR_ANALOG        (1UL<<1)
#define PIN_ATTR_DIGITAL       (1UL<<2)
#define PIN_ATTR_PWM           (1UL<<3)
#define PIN_ATTR_TIMER         (1UL<<4)
#define PIN_ATTR_EXTINT        (1UL<<5)

/* Types used for the table below */
typedef struct _PinDescription
{
  EPortType ulPort ;
  uint32_t ulPin ;
  EPioType ulPinType ;
  uint32_t ulPinAttribute ;
  EAnalogChannel ulADCChannelNumber ;
  EPWMChannel ulPWMChannel ;
  ETCChannel ulTCChannel ;
//  EExt_Interrupts ulExtInt ;
} PinDescription ;

/* Pins table to be instantiated into variant.cpp */
extern const PinDescription g_APinDescription[] ;

// reference voltages for LPCOMP
#ifdef NRF51
#define REF_VDD_1_8 LPCOMP_REFSEL_REFSEL_SupplyOneEighthPrescaling
#define REF_VDD_1_4 LPCOMP_REFSEL_REFSEL_SupplyTwoEighthsPrescaling
#define REF_VDD_3_8 LPCOMP_REFSEL_REFSEL_SupplyThreeEighthsPrescaling
#define REF_VDD_1_2 LPCOMP_REFSEL_REFSEL_SupplyFourEighthsPrescaling
#define REF_VDD_5_8 LPCOMP_REFSEL_REFSEL_SupplyFiveEighthsPrescaling
#define REF_VDD_3_4 LPCOMP_REFSEL_REFSEL_SupplySixEighthsPrescaling
#define REF_VDD_7_8 LPCOMP_REFSEL_REFSEL_SupplySevenEighthsPrescaling
#else
#define REF_VDD_1_8 LPCOMP_REFSEL_REFSEL_Ref1_8Vdd
#define REF_VDD_1_4 LPCOMP_REFSEL_REFSEL_Ref2_8Vdd
#define REF_VDD_3_8 LPCOMP_REFSEL_REFSEL_Ref3_8Vdd
#define REF_VDD_1_2 LPCOMP_REFSEL_REFSEL_Ref4_8Vdd
#define REF_VDD_5_8 LPCOMP_REFSEL_REFSEL_Ref5_8Vdd
#define REF_VDD_3_4 LPCOMP_REFSEL_REFSEL_Ref6_8Vdd
#define REF_VDD_7_8 LPCOMP_REFSEL_REFSEL_Ref7_8Vdd
#define REF_VDD_1_16 LPCOMP_REFSEL_REFSEL_Ref1_16Vdd
#define REF_VDD_3_16 LPCOMP_REFSEL_REFSEL_Ref1_16Vdd
#define REF_VDD_5_16 LPCOMP_REFSEL_REFSEL_Ref1_16Vdd
#define REF_VDD_7_16 LPCOMP_REFSEL_REFSEL_Ref1_16Vdd
#define REF_VDD_9_16 LPCOMP_REFSEL_REFSEL_Ref1_16Vdd
#define REF_VDD_11_16 LPCOMP_REFSEL_REFSEL_Ref1_16Vdd
#define REF_VDD_13_16 LPCOMP_REFSEL_REFSEL_Ref1_16Vdd
#define REF_VDD_15_16 LPCOMP_REFSEL_REFSEL_Ref1_16Vdd
#endif
#define AREF LPCOMP_REFSEL_REFSEL_ARef | (LPCOMP_EXTREFSEL_EXTREFSEL_AnalogReference0 << 16)

#if defined(LPCOMP_PRESENT)
typedef enum{
	UP = LPCOMP_ANADETECT_ANADETECT_Up,
	DOWN = LPCOMP_ANADETECT_ANADETECT_Down,
	CROSS = LPCOMP_ANADETECT_ANADETECT_Cross
}detect_mode;
#endif


#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // _VARIANTS_ARDUINO_
