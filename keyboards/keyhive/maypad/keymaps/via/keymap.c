/* Copyright 2019 codybender
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

enum custom_keycodes {
    BYEMACRO = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case BYEMACRO:
        if (record->event.pressed) {
            // when MACRO is pressed
            SEND_STRING("BYE");
        } else {
            // when MACRO is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x4(
        LALT(KC_S), XXXXXXX,   KC_F9, KC_F12,
             KC_F5,    KC_7,    KC_8,   KC_9,
             KC_F6,    KC_4,    KC_5,   KC_6,
             KC_F7,    KC_1,    KC_2,   KC_3,
             KC_F8, XXXXXXX, XXXXXXX,  LT(1, KC_0)
    ),
    [1] = LAYOUT_ortho_5x4(
        LALT(KC_U), LALT(KC_L), LALT(KC_R), LALT(KC_W),
          BYEMACRO,    XXXXXXX,    XXXXXXX,    XXXXXXX,
          BYEMACRO,     KC_TAB,  KC_BSPACE,   KC_ENTER,
          BYEMACRO,    XXXXXXX,    XXXXXXX,    XXXXXXX,
          BYEMACRO,    XXXXXXX,    XXXXXXX,    XXXXXXX
    )
};