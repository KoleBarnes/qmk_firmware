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

// Tap Dance declarations
enum {
    TD_AltS_AltU,
    TD_F5_BYE,
    TD_F6_BYE,
    TD_F7_BYE,
    TD_F8_BYE,
    TD_F9_RESET,
};

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

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for LALT S, twice for LALT U
    [TD_AltS_AltU] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_S), LALT(KC_U)),
    [TD_F5_BYE] = ACTION_TAP_DANCE_DOUBLE(KC_F5, BYEMACRO),
    [TD_F6_BYE] = ACTION_TAP_DANCE_DOUBLE(KC_F6, BYEMACRO),
    [TD_F7_BYE] = ACTION_TAP_DANCE_DOUBLE(KC_F7, BYEMACRO),
    [TD_F8_BYE] = ACTION_TAP_DANCE_DOUBLE(KC_F8, BYEMACRO),
    [TD_F9_RESET] = ACTION_TAP_DANCE_DOUBLE(KC_F9, LALT(KC_R)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_5x4(
        TD(TD_F9_RESET), LALT(KC_W),    KC_F12, TD(TD_AltS_AltU),
                  KC_P7,      KC_P8,     KC_P9,    TD(TD_F5_BYE),
                  KC_P4,      KC_P5,     KC_P6,    TD(TD_F6_BYE),
                  KC_P1,      KC_P2,     KC_P3,    TD(TD_F7_BYE),
                  KC_P0,     KC_TAB,   XXXXXXX,    TD(TD_F8_BYE)
    )
};