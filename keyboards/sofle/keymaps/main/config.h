 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define RETRO_TAPPING
#define TAPPING_TERM 175

//OLED
#ifdef OLED_ENABLE
  #undef OLED_BRIGHTNESS
  #undef OLED_TIMEOUT
  #define OLED_BRIGHTNESS 80
  #define OLED_TIMEOUT 20000
#endif

// More lighting options in quantum/rgblight/rgblight.h
#ifdef RGBLIGHT_ENABLE
  #undef RGBLIGHT_DEFAULT_MODE
  #undef RGBLIGHT_DEFAULT_HUE
  #undef RGBLIGHT_DEFAULT_SAT
  #undef RGBLIGHT_DEFAULT_ON
  #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
  #define RGBLIGHT_DEFAULT_HUE 180
  #define RGBLIGHT_DEFAULT_SAT 255
  #define RGBLIGHT_DEFAULT_ON false
#endif

// Disabled to save space
#define NO_ACTION_ONESHOT  // 332
#define NO_ACTION_MACRO    // 0
#define NO_ACTION_FUNCTION // 0
#define DISABLE_LEADER     // 0
