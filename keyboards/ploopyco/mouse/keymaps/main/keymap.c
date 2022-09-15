/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
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
#include QMK_KEYBOARD_H

// safe range starts at `PLOOPY_SAFE_RANGE` instead.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* LAYOUT(BLL, BL, BM, BR, BRR, BF, BB, BDPI) */
    /* Base */
    /*             Copy | Left Click | Middle Click | Right Click | LT(2, Paste)   */
    /*            --------------------------------------------------------  */
    /*  Forword   |                  |     DPI      |                       */
    /*   Back     |                                                         */
    [0] = LAYOUT(
        C(KC_C), KC_BTN1, KC_BTN3, KC_BTN2, MO(2), KC_BTN4, KC_BTN5, DPI_CONFIG),
    /* Game */
    /*               O  | Left Click | Middle Click | Right Click | LT(2, KC_N)*/
    /*            --------------------------------------------------------  */
    /*   Shift    |                  |     DPI      |                       */
    /*   CRTL     |                                                         */
    [1] = LAYOUT(
        KC_O, _______, _______, _______, LT(2, KC_I), KC_LCTL, KC_LSFT, _______),
    /* Raise */
    /*               TG(1) | Left Click | Middle Click | Right Click |    ?    */
    /*               --------------------------------------------------------  */
    /*  Vol Up       |                  |     DPI      |                       */
    /*  Vol Down     |                                                         */
    [2] = LAYOUT(
        C(KC_V), _______, _______, _______, _______, KC_VOLD, KC_VOLU, TG(1))
};
