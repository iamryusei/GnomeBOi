/**
 * [SUMMARY]
 *  This header defines menmonic identifiers for ATMega328P's I/O pins configurations.
 *  It may be possible for different GnomeBOI devices to make use of different pin
 *  configuration for different underlying hardware. Pin configurations can be selected
 *  trough preprocessor macros
 * 
 * [ADDITIONAL INFO]
 *  This header is meant for internal accessibility and usage.
 *  
 *	!! YOU SHOULD NOT INCLUDE THIS HEADER IN YOUR EXTERNAL CODE !!
 *
 */

#ifndef __GNOMEBOI_FIRMWARE_INTERNAL_CONFIG_H_
#define __GNOMEBOI_FIRMWARE_INTERNAL_CONFIG_H_

	// DISPLAY SPI PINs
	constexpr unsigned short  PINOUT_DISPLAY_SPI_SCK = 13;
	constexpr unsigned short  PINOUT_DISPLAY_SPI_MOSI = 11;
	constexpr unsigned short  PINOUT_DISPLAY_SPI_CS = 10;
	constexpr unsigned short  PINOUT_DISPLAY_SPI_RST = 9;
	constexpr unsigned short  PINOUT_DISPLAY_SPI_DC = 8;

	// DIRECTIONAL BUTTONS PINs
	#define PINOUT_ARROW_UP     A0
	#define PINOUT_ARROW_LEFT   A1
	#define PINOUT_ARROW_RIGHT  A2
	#define PINOUT_ARROW_DOWN   A3

	// BUTTONS PINs
	#define PINOUT_BUTTON_A        4
	#define PINOUT_BUTTON_B        5
	#define PINOUT_BUTTON_START    6
	#define PINOUT_BUTTON_RESERVED 7

#endif