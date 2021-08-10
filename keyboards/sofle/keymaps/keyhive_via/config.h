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

#define EE_HANDS

#define RETRO_TAPPING

#ifdef LEADER_ENABLE
  #undef LEADER_TIMEOUT
  #define LEADER_TIMEOUT 500
  #define LEADER_NO_TIMEOUT
  #define LEADER_PER_KEY_TIMING
#endif

#ifdef WPM_ENABLE
  #define WPM_ALLOW_COUNT_REGRESSION
#endif

//OLED
#ifdef OLED_DRIVER_ENABLE
  #define OLED_BRIGHTNESS 80
  #define OLED_TIMEOUT 25000
  #define OLED_FADE_OUT
  #define OLED_FADE_OUT_INTERVAL 15
#endif

//Add RGB underglow
#ifdef RGBLIGHT_ENABLE
  #define RGB_DI_PIN D3 //The pin connected to the data pin of the LEDs
  #define RGBLED_NUM 74 //The number of LEDs connected
  #define RGBLED_SPLIT {37,37} //For split keyboards, the number of LEDs connected on each half directly wired to RGB_DI_PIN
  #define RGBLIGHT_ANIMATIONS //Enable all additional animation modes.
  #define RGBLIGHT_DEFAULT_HUE 127
  #define RGBLIGHT_DEFAULT_SAT 255
  #define RGBLIGHT_LIMIT_VAL 60 //The maximum brightness level #192
  #define RGBLIGHT_SLEEP
#endif
