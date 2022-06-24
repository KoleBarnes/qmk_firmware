 /* Copyright 2020 Josef Adamcik
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

enum layers {
  _QWERTY,
//   _COLEMAK_DHM, // TG(_COLEMAK_DHM)
  _GAME,
  _NUMPAD,
  _LOWER,
  _RAISE
};

enum custom_keycodes {
	VDR = SAFE_RANGE, // Virtual Desktop Right
	VDL, // Virtual Desktop Left
    TV, // Task View
    PWRD, // Previous Word
    NWRD // Next Word
};

#include "oled.c"
#include "encoder.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* QWERTY
  * .-----------------------------------------.                          .-----------------------------------------.
  * | ESC  |   1  |   2  |   3  |   4  |   5  |                          |   6  |   7  |   8  |   9  |   0  |  -   |
  * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
  * | #/Tab|   Q  |   W  |   E  |   R  |   T  |                          |   Y  |   U  |   I  |   O  |   P  | Del  |
  * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
  * | APP  |   A  |   S  |   D  |   F  |   G  |-------.          .-------|   H  |   J  |   K  |   L  |   ;  |  '   |
  * |------+------+------+------+------+------| MUTE  |          |       |------+------+------+------+------+------|
  * |SpcCad|   Z  |   X  |   C  |   V  |   B  |-------|___    ___|-------|   N  |   M  |   ,  |   .  |   /  |SpcCad|
  * \-----------------------------------------|  /       /    \      \   |-----------------------------------------/
  *               |      | LALT |LSUPER|LCTRL | / LOWER /      \RAISE \  |RSHIFT| RCLT | RALT |      |
  *               |      |      |      |      |/ SPACE /        \ BSPC \ |ENTER |      |      |      |
  *               \-----------------------------------/          \-----------------------------------/
  */
  [_QWERTY] = LAYOUT(
               KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,     KC_5,                                                         KC_6,     KC_7,     KC_8,    KC_9,    KC_0, KC_MINUS,
   LT(_NUMPAD,KC_TAB),   KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,                                                         KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,   KC_DEL,
               KC_APP,   KC_A,   KC_S,    KC_D,    KC_F,     KC_G,                                                         KC_H,     KC_J,     KC_K,    KC_L, KC_SCLN,  KC_QUOT,
              KC_LSPO,   KC_Z,   KC_X,    KC_C,    KC_V,     KC_B,    KC_MUTE,                 XXXXXXX,           KC_N,     KC_M,  KC_COMM,  KC_DOT, KC_SLSH,  KC_RSPC,
                      XXXXXXX, KC_LALT, KC_LGUI, KC_LCTRL, LT(_LOWER, KC_SPC),     LT(_RAISE, KC_BSPC), RSFT_T(KC_ENT), KC_RCTRL,  KC_RALT, XXXXXXX
  ),
 /* COLEMAK_DHM
  * .-----------------------------------------.                          .-----------------------------------------.
  * |______|______|______|______|______|______|                          |______|______|______|______|______|______|
  * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
  * |______|   Q  |   W  |   F  |   P  |   G  |                          |   J  |   L  |   U  |   Y  |   ;  |______|
  * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
  * |______|   A  |   R  |   S  |   T  |   D  |-------.          .-------|   H  |   N  |   E  |   I  |   O  |______|
  * |------+------+------+------+------+------|______ |          |       |------+------+------+------+------+------|
  * |______|   Z  |   X  |   C  |   V  |   B  |-------|___    ___|-------|   K  |   M  |   ,  |   .  |   /  |______|
  * \-----------------------------------------|  /       /    \      \   |-----------------------------------------/
  *               |______|______|______|______| /______ /      \______\  |______|______|______|______|
  *               |      |      |      |      |/       /        \      \ |      |      |      |      |
  *               \-----------------------------------/          \-----------------------------------/
  */
//   [_COLEMAK_DHM] = LAYOUT(
//     _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
//     _______,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                          KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, _______,
//     _______,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                          KC_M,    KC_N,    KC_E,    KC_I,    KC_O, _______,
//     _______,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, _______,     _______,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, _______,
//                       _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
//   ),
 /* Game
  *  .-----------------------------------------.                           .-----------------------------------------.
  *  | ESC  |   `  |   1  |   2  |   3  |   4  |                           |   6  |   7  |   8  |   9  |   0  |  -   |
  *  |------+------+------+------+------+------|                           |------+------+------+------+------+------|
  *  |      | Tab  |   Q  |   W  |   E  |   R  |                           |   Y  |   U  |   I  |   O  |   P  | Del  |
  *  |------+------+------+------+------+------|                           |------+------+------+------+------+------|
  *  |      |      |   A  |   S  |   D  |   F  |-------.           .-------|   H  |   J  |   K  |   L  |   ;  |  '   |
  *  |------+------+------+------+------+------|_______|           |       |------+------+------+------+------+------|
  *  |      |      |   Z  |   X  |   C  |   V  |-------|___     ___|-------|   N  |   M  |   ,  |   .  |   /  |______|
  *  \-----------------------------------------|  /       /     \      \   |-----------------------------------------/
  *                |      |      |      |      | / SPACE /       \______\  |______|______|______|______|
  *                |      |      |      |      |/       /         \      \ |      |      |      |      |
  *                \-----------------------------------/           \-----------------------------------/
  */
  [_GAME] = LAYOUT(
     KC_ESC,  KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINUS,
    XXXXXXX,  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_DEL,
    XXXXXXX, XXXXXXX,   KC_A,    KC_S,    KC_D,    KC_F,                          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
    XXXXXXX, XXXXXXX,   KC_Z,    KC_X,    KC_C,    KC_V, _______,     XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  _______,
                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_SPC,     _______, _______, _______, _______, _______
  ),
 /* NUMPAD
  * .-----------------------------------------.                          .-----------------------------------------.
  * |______|      |      |      |      |      |                          |      |      |      |      |      |      |
  * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
  * |      |      |      |      |      |      |                          |   ^  |   7  |   8  |   9  |   *  |______|
  * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
  * |      |      |      |      |      |      |-------.          .-------|   -  |   4  |   5  |   6  |   =  |   |  |
  * |------+------+------+------+------+------|_______|          |_______|------+------+------+------+------+------|
  * |______|      |      |      |      |      |-------|___    ___|-------|   +  |   1  |   2  |   3  |   \  |______|
  * \-----------------------------------------|  /       /    \      \   |-----------------------------------------/
  *               |______|______|______|______| /______ /      \______\  |______|   0  |   .  |______|
  *               |      |      |      |      |/       /        \      \ |      |      |      |      |
  *               \-----------------------------------/          \-----------------------------------/
  */
  [_NUMPAD] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_EQL,  KC_PIPE,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,    _______, KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_SLSH, _______,
                   _______, _______, _______, _______, _______,    _______, _______, KC_P0, KC_PDOT, _______
  ),
 /* LOWER
  * .-----------------------------------------.                          .-----------------------------------------.
  * |______|  F1  |  F2  |  F3  |  F4  |  F5  |                          |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
  * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
  * |      |   1  |   2  |   3  |   4  |   5  |                          |   6  |   7  |   8  |   9  |   0  | F12  |
  * |------+------+------+------+------+------|                          |------+------+------+------+------+------|
  * |______|      |   -  |   +  |   =  |   [  |-------.          .-------|   ]  |      |      |      |      |      |
  * |------+------+------+------+------+------|_______|          |_______|------+------+------+------+------+------|
  * |______|      |      |      |      |   {  |-------|___    ___|-------|   }  |      |      |      |  \|  |______|
  * \-----------------------------------------|  /       /    \      \   |-----------------------------------------/
  *               |______|______|______|______| /_______/      \______\  |______|______|______|______|
  *               |      |      |      |      |/       /        \      \ |      |      |      |      |
  *               \-----------------------------------/          \-----------------------------------/
  */
  [_LOWER] = LAYOUT(
     KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,    KC_F7,    KC_F8,   KC_F9,  KC_F10,  KC_F11,
    XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,     KC_7,     KC_8,    KC_9,    KC_0,  KC_F12,
    _______, XXXXXXX, KC_MINS, KC_PLUS,  KC_EQL, KC_LBRC,                       KC_RBRC,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, _______,     _______, KC_RCBR,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_BSLS, _______,
                      _______, _______, _______, _______, _______,     _______, _______,  _______,  _______, _______
  ),
 /* RAISE
  *  .-----------------------------------------.                           .-----------------------------------------.
  *  | XMAS |PLAIN |RGBSAI|RGBHUI|RGBVAI|RGBTOG|                           |  TG1 |      |      |      |      |      |
  *  |------+------+------+------+------+------|                           |------+------+------+------+------+------|
  *  |      |      |      | Caps | Num  | Scrl |                           | PGUP | PWRD |  Up  | NWRD | Home |______|
  *  |------+------+------+------+------+------|                           |------+------+------+------+------+------|
  *  |      |      |      |      |      |      |-------.           .-------| PGDN | Left | Down |Right | End  |      |
  *  |------+------+------+------+------+------|_______|           |_______|------+------+------+------+------+------|
  *  |______|      |      |      |      |      |-------|___     ___|-------|Insert|  VDL |  TV  |  VDR |      |______|
  *  \-----------------------------------------|  /       /     \      \   |-----------------------------------------/
  *                |______|______|______|______| /_______/       \______\  |______|______|      |      |
  *                |      |      |      |      |/       /         \      \ |      |      |      |      |
  *                \-----------------------------------/           \-----------------------------------/
  */
  [_RAISE] = LAYOUT(
    RGB_MODE_XMAS, RGB_MODE_PLAIN, RGB_SAI, RGB_HUI, RGB_VAI, RGB_TOG,                     TG(_GAME), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
          XXXXXXX,        XXXXXXX, XXXXXXX, KC_CLCK, KC_NLCK, KC_SLCK,                       KC_PGUP,    PWRD,   KC_UP,    NWRD, KC_HOME, _______,
          XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END, XXXXXXX,
          _______,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______,  KC_INS,     VDL,      TV,     VDR, XXXXXXX, _______,
                                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

void suspend_power_down_user(void) { // turn off when computer is sleeping.
  #ifdef OLED_ENABLE
    oled_off();
  #endif
}

void suspend_wakeup_init_user(void) {  // turn on when computer is awake.
  #ifdef OLED_ENABLE
    oled_on();
  #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) { // For keycode overrides
		case VDR: // Virtual Desktop Right
		    if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTRL);
                register_code(KC_RIGHT);
                unregister_code(KC_RIGHT);
                unregister_code(KC_LCTRL);
                unregister_code(KC_LGUI);
		    }
		    return true;
		case VDL: // Virtual Desktop Left
		    if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTRL);
                register_code(KC_LEFT);
                unregister_code(KC_LEFT);
                unregister_code(KC_LCTRL);
                unregister_code(KC_LGUI);
		    }
		    return true;
        case TV: // Task View
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_TAB);
                unregister_code(KC_TAB);
                unregister_code(KC_LGUI);
                }
            return true;
        case PWRD: // Previous Word
            if (record->event.pressed) {
                register_code(KC_LCTRL);
                register_code(KC_LEFT);
                unregister_code(KC_LEFT);
                unregister_code(KC_LCTRL);
                }
            return true;
        case NWRD: // Next Word
            if (record->event.pressed) {
                register_code(KC_LCTRL);
                register_code(KC_RGHT);
                unregister_code(KC_RGHT);
                unregister_code(KC_LCTRL);
                }
            return true;
    default:
      return true; // Process all other keycodes normally
    };
}
