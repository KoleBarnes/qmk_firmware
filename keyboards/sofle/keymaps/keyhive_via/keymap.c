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

// TODO add num pad layer

#include QMK_KEYBOARD_H
#include <stdio.h>

#ifdef LEADER_ENABLE
  bool did_leader_succeed;
  int leader_state = 0;
  uint16_t leader_timer = 0;
#endif

#ifdef WPM_ENABLE
  char wpm_char[10];
#endif

enum layers {
  _QWERTY,
  // _COLEMAK,
  _GAME,
  _NUMPAD,
  _LOWER,
  _RAISE,
};

enum custom_keycodes {
	  VDR = SAFE_RANGE, // Virtual Desktop Right
	  VDL, // Virtual Desktop Left
    TV, // Task View
};

#include "oled.c"
#include "encoder.c"

// Default keymap. This can be changed in Via. Use oled.c and encoder.c to change behavior that Via cannot change.

void suspend_power_down_user(void) { // turn off when computer is sleeping.
  #ifdef OLED_DRIVER_ENABLE
    oled_off();
  #endif
  #ifdef RGBLIGHT_ENABLE
    rgblight_disable();
  #endif
}

void suspend_wakeup_init_user(void) {  // turn on when computer is awake.
  #ifdef OLED_DRIVER_ENABLE
    oled_on();
  #endif
  #ifdef RGBLIGHT_ENABLE
    rgblight_enable();
  #endif
}

#ifdef LEADER_ENABLE
  LEADER_EXTERNS();
#endif

void matrix_init_user(void) {
}

void matrix_scan_user(void) {

  #ifdef LEADER_ENABLE
    LEADER_DICTIONARY() {
      did_leader_succeed = leading = false;

      SEQ_ONE_KEY(KC_F) {
        // Anything you can do in a macro.
        SEND_STRING("QMK is awesome.");
        did_leader_succeed = true;
      }
      SEQ_TWO_KEYS(KC_C, KC_S) {
        SEND_STRING("Signed-off-by: KoleBarnes <kbarnes261@gmail.com>");
        did_leader_succeed = true;
      }
      SEQ_THREE_KEYS(KC_D, KC_D, KC_G) {
        SEND_STRING("https://start.duckduckgo.com\n");
        did_leader_succeed = true;
      }
      
      leader_end();
    }

    if (leader_state != 0 && timer_elapsed(leader_timer) > 5000) {
        leader_state = 0;
    }
  #endif

}

#ifdef LEADER_ENABLE
  void leader_start(void) {
    // sequence started
    leader_state = 1;
  }

  void leader_end(void) {
    if (did_leader_succeed) {
      leader_state = 2;
    } else {
      leader_state = 3;
    }
    leader_timer = timer_read();
  }
#endif

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
    default:
      return true; // Process all other keycodes normally
  };
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
  * QWERTY
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Del  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | `    |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
  * |------+------+------+------+------+------| MUTE  |    |       |------+------+------+------+------+------|
  * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RSHIFT|
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *            |  NUM | LALT |LSUPER|LCTRL | / LOWER /       \RAISE \  |LSHIFT| LALT | MENU | LEAD |
  *            |  PAD |      |      |      |/ SPACE /         \ BSPC \ |ENTER |      |      |      |
  *             `----------------------------------'           '------''---------------------------'
  */
  [_QWERTY] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,     KC_5,                                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINUS,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,                                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_DEL,
    KC_GRV,   KC_A,   KC_S,    KC_D,    KC_F,     KC_G,                                                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,     KC_B,            KC_MUTE,                 XXXXXXX,           KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
               TG(_NUMPAD), KC_LALT, KC_LGUI, KC_LCTRL, LT(_LOWER, KC_SPC),     LT(_RAISE, KC_BSPC), LSFT_T(KC_ENT), KC_RALT,  KC_APP, KC_LEAD
  ),
  /*
  * COLEMAK
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
  * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
  * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
  *             `----------------------------------'           '------''---------------------------'
  */
  // [_COLEMAK] = LAYOUT(
  //   _______,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  _______,
  //   _______,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                          KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  _______,
  //   _______,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                          KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  _______,
  //   _______,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, _______,     _______,    KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  _______,
  //                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  // ),
  /*
  * Game
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * | ESC  |   `  |   1  |   2  |   3  |   4  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      | Tab  |   Q  |   W  |   E  |   R  |                    |   Y  |   U  |   I  |   O  |   P  | Del  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |   A  |   S  |   D  |   F  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
  * |------+------+------+------+------+------| TRNS  |    |       |------+------+------+------+------+------|
  * |      |LShift|   Z  |   X  |   C  |   V  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | TRNS |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *            |      |      |      |      | / SPACE /       \ TRNS \  | TRNS | TRNS | TRNS | TRNS |
  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
  *             `----------------------------------'           '------''---------------------------'
  */
  [_GAME] = LAYOUT(
    KC_ESC,   KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINUS,
    XXXXXXX,   KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_DEL,
    XXXXXXX,  XXXXXXX,   KC_A,    KC_S,    KC_D,    KC_F,                          KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
    XXXXXXX,  KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V, _______,     XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  _______,
                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_SPC,     _______, _______, _______, _______, _______
  ),
  /*
  * NUM PAD
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |                    |      |   7  |   8  |   9  |      |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |-------.    ,-------|      |   4  |   5  |   6  |      |      |
  * |------+------+------+------+------+------|______ |    |       |------+------+------+------+------+------|
  * |      |      |      |      |      |      |-------|    |-------|      |   1  |   2  |   3  |      |      |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *            |______|______|______|______| /______ /       \______\  |______|  0   |______|______|
  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
  *             `----------------------------------'           '------''---------------------------'
  */
  [_NUMPAD] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______, _______,     _______, _______,    KC_0, _______, _______
  ),
  /* LOWER
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |______|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |______|      |      |      |      |      |-------.    ,-------|      |   =  |   -  |   +  |      |   |  |
  * |------+------+------+------+------+------|_______|    |_______|------+------+------+------+------+------|
  * |______|      |      |      |   {  |   }  |-------|    |-------|   [  |   ]  |      |      |   \  |______|
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *            |______|______|______|______| /_______/       \______\  |______|______|______|______|
  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
  *             `----------------------------------'           '------''---------------------------'
  */
  [_LOWER] = LAYOUT(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
    XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX,  KC_EQL, KC_MINS, KC_PLUS, XXXXXXX, KC_PIPE,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, _______,     _______, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_BSLS, _______,
                      _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  ),
  /* RAISE
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |      |      |      |      |RGBTOG|RGBVAI|                    |  TG1 |      |      |      |      |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |                    | PGUP | Home |  Up  | End  |      |______|
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |      | Caps | Num  | Scrl |-------.    ,-------| PGDN | Left | Down |Right |      |      |
  * |------+------+------+------+------+------|_______|    |_______|------+------+------+------+------+------|
  * |______|      |      |      |      |      |-------|    |-------|      |  VDL |      |  VDR |      |______|
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *            |______|______|______|______| /_______/       \______\  |______|______|      |      |
  *            |      |      |      |      |/       /         \      \ |      |      |      |      |
  *             `----------------------------------'           '------''---------------------------'
  */
  [_RAISE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_VAI,                     TG(_GAME), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_CLCK, KC_NLCK, KC_SLCK,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, XXXXXXX,     VDL,      TV,     VDR, XXXXXXX, _______,
                      _______, _______, _______, _______, _______,     _______, _______, _______, XXXXXXX, XXXXXXX
  )
};
