
/*
This is the c configuration file for the keymap

Copyright 2019 Temur Beissov <nettema@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
*/
#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

/* USB Device descriptor parameter */

#undef MANUFACTURER
#define MANUFACTURER    nettema
#undef PRODUCT
#define PRODUCT         AtreusBLERgbUnderglow

/* key matrix size */
// #define MATRIX_ROWS 4
// #define MATRIX_COLS 11

// Change this to how you wired your keyboard
// COLS: Left to right, ROWS: Top to bottom
#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#define MATRIX_ROW_PINS { D3, D2, D1, D0 }
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B5, B4, E6, D7, C6, D4 }
// #undef DIODE_DIRECTION
// #define DIODE_DIRECTION ROW2COL


/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
#define NO_PRINT


/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION


/* RGB Underglow settings */
#define RGB_DI_PIN F4
#define RGBLED_NUM 20
#define RGBLIGHT_ANIMATIONS

/* Bluetooth settings */
// #define AdafruitBleResetPin B0
// #define AdafruitBleCSPin B7
// #define AdafruitBleIRQPin C7

/* Bootmagic settins */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#endif
