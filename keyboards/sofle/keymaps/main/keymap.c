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

#include QMK_KEYBOARD_H

// Base layer is the number of layers CYCLE selects from.
// #define BASE_LAYERS 2

enum custom_layers {
    _QWERTY,
//   _COLEMAK_DHM, // TG(_COLEMAK_DHM)
    _GAME,
    _NUMPAD,
    _LOWER,
    _RAISE
};

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here (4 bytes)
    // CYCLE,                    // cycle through first BASE_LAYERS (62 bytes)
    LVDH,                     // Linux Virtual Desktop Home
    LVDL,                     // Linux Virtual Desktop Right
	LVDR,                     // Linux Virtual Desktop Left
    LVDE,                     // Linux Virtual Desktop End
    WVDL,                     // Windows Virtual Desktop Right
	WVDR,                     // Windows Virtual Desktop Left
    TV,                       // Task View
    PWRD,                     // Previous Word
    NWRD                      // Next Word
};

#include "oled.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * .-----------------------------------------.                                .-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |----------.    E    .-----------|   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|  VolUp   |  < N >  |  Pg Up    |------+------+------+------+------+------|
 * | #/Tab|   Q  |   W  |   E  |   R  |   T  |----------|    C    |-----------|   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------|  Mute    |  < O >  |           |------+------+------+------+------+------|
 * | APP  |   A  |   S  |   D  |   F  |   G  |----------|    D    |-----------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  VolDn   |  < E >  |  Pg Dn    |------+------+------+------+------+------|
 * |SpcCad|   Z  |   X  |   C  |   V  |   B  |----------|    R    |-----------|   N  |   M  |   ,  |   .  |   /  |SpcCad|
 * '-----------------------------------------|  /       /         \       \   |-----------------------------------------'
 *               |      | LALT |LSUPER|LCTRL | / LOWER /           \ RAISE \  |RSHIFT| RCLT | RALT |      |
 *               |      |      |      |      |/ SPACE /             \ BSPC  \ |ENTER |      |      |      |
 *               '-----------------------------------'               '------------------------------------'
 */
[_QWERTY] = LAYOUT(
  KC_ESC            , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                              KC_6          , KC_7   , KC_8   , KC_9  , KC_0   , KC_MINUS,
  LT(_NUMPAD,KC_TAB), KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                              KC_Y          , KC_U   , KC_I   , KC_O  , KC_P   ,   KC_DEL,
  KC_APP            , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                              KC_H          , KC_J   , KC_K   , KC_L  , KC_SCLN,  KC_QUOT,
  SC_LSPO           , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_MUTE           ,     XXXXXXX            , KC_N          , KC_M   , KC_COMM, KC_DOT, KC_SLSH,  SC_RSPC,
                               XXXXXXX, KC_LALT, KC_LGUI, KC_LCTL, LT(_LOWER, KC_SPC),     LT(_RAISE, KC_BSPC), RSFT_T(KC_ENT), KC_RCTL, KC_RALT, XXXXXXX
),


/* COLEMAK_DHM
 * .-----------------------------------------.                                .-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |----------.    E    .-----------|   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|  VolUp   |  < N >  |  Pg Up    |------+------+------+------+------+------|
 * | #/Tab|   Q  |   W  |   F  |   P  |   B  |----------|    C    |-----------|   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+------|  Mute    |  < O >  |           |------+------+------+------+------+------|
 * | APP  |   A  |   R  |   S  |   T  |   G  |----------|    D    |-----------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  VolDn   |  < E >  |  Pg Dn    |------+------+------+------+------+------|
 * |SpcCad|   Z  |   X  |   C  |   D  |   V  |----------|    R    |-----------|   K  |   H  |   ,  |   .  |   /  |SpcCad|
 * '-----------------------------------------|  /       /         \       \   |-----------------------------------------'
 *               |      | LALT |LSUPER|LCTRL | / LOWER /           \ RAISE \  |RSHIFT| RCLT | RALT |      |
 *               |      |      |      |      |/ SPACE /             \ BSPC  \ |ENTER |      |      |      |
 *               '-----------------------------------'               '------------------------------------'
 */
// [_COLEMAK_DHM] = LAYOUT(
//   KC_ESC            , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                              KC_6          , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINUS,
//   LT(_NUMPAD,KC_TAB), KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                                              KC_J          , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_DEL  ,
//   KC_APP            , KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                                              KC_M          , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT ,
//   SC_LSPO           , KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , KC_MUTE           ,                 XXXXXXX, KC_K          , KC_H   , KC_COMM, KC_DOT , KC_SLSH, SC_RSPC ,
//                                XXXXXXX, KC_LALT, KC_LGUI, KC_LCTL, LT(_LOWER, KC_SPC),     LT(_RAISE, KC_BSPC), RSFT_T(KC_ENT), KC_RCTL, KC_RALT, XXXXXXX
// ),


/* Game
 * .-----------------------------------------.                                .-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |----------.    E    .-----------|   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|  ______  |  < N >  |  ______   |------+------+------+------+------+------|
 * |   `  | Tab  |   Q  |   W  |   R  |   T  |----------|    C    |-----------|   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------|  ______  |  < O >  |  ______   |------+------+------+------+------+------|
 * |   G  |      |   A  |   S  |   F  |   G  |----------|    D    |-----------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  ______  |  < E >  |  ______   |------+------+------+------+------+------|
 * |      |      |   Z  |   X  |   V  |   B  |----------|    R    |-----------|   N  |   M  |   ,  |   .  |   /  |______|
 * '-----------------------------------------|  /       /         \       \   |-----------------------------------------'
 *               |      |      |      |      | / SPACE /           \ ______\  |______|______|______|______|
 *               |      |      |      |      |/       /             \       \ |      |      |      |      |
 *               '-----------------------------------'               '------------------------------------'
*/
[_GAME] = LAYOUT(
  KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINUS,
  KC_GRV , KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   ,                       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,   KC_DEL,
  KC_G   , KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   ,                       KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN,  KC_QUOT,
  XXXXXXX, KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , _______,     XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,  _______,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_SPC,     _______, _______, _______, _______, _______
),


 /* NUMPAD
 * .-----------------------------------------.                                .-----------------------------------------.
 * |______|      |      |      |      |      |----------.    E    .-----------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  ______  |  < N >  |  ______   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |----------|    C    |-----------|   ^  |   7  |   8  |   9  |   *  |______|
 * |------+------+------+------+------+------|  ______  |  < O >  |  ______   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |----------|    D    |-----------|   -  |   4  |   5  |   6  |   =  |   |  |
 * |------+------+------+------+------+------|  ______  |  < E >  |  ______   |------+------+------+------+------+------|
 * |______|      |      |      |      |      |----------|    R    |-----------|   +  |   1  |   2  |   3  |   \  |______|
 * '-----------------------------------------|  /       /         \       \   |-----------------------------------------'
 *               |______|______|______|______| /______ /           \ ______\  |______|   0  |   .  |______|
 *               |      |      |      |      |/       /             \       \ |      |      |      |      |
 *               '-----------------------------------'               '------------------------------------'
 */
[_NUMPAD] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_CIRC, KC_P7  ,  KC_P8 ,   KC_P9, KC_ASTR, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_MINS, KC_P4  ,  KC_P5 ,   KC_P6, KC_EQL , KC_PIPE,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, KC_PLUS, KC_P1  ,  KC_P2 ,   KC_P3, KC_SLSH, _______,
                    _______, _______, _______, _______, _______,     _______, _______, KC_P0  , KC_PDOT, _______
),


/* LOWER
 * .-----------------------------------------.                                .-----------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |----------.    E    .-----------|  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|  ______  |  < N >  |  ______   |------+------+------+------+------+------|
 * |______|   1  |   2  |   3  |   4  |   5  |----------|    C    |-----------|   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|  ______  |  < O >  |  ______   |------+------+------+------+------+------|
 * |______|   !  |   @  |   #  |   $  |   %  |----------|    D    |-----------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  ______  |  < E >  |  ______   |------+------+------+------+------+------|
 * |______|   =  |   -  |   +  |   {  |   }  |----------|    R    |-----------|   [  |   ]  |   ;  |   :  |  \|  |______|
 * '-----------------------------------------|  /       /         \       \   |-----------------------------------------'
 *               | BOOT |______|______|______| /______ /           \ ______\  |______|______|______|______|
 *               |      |      |      |      |/       /             \       \ |      |      |      |      |
 *               '-----------------------------------'               '------------------------------------'
 */
[_LOWER] = LAYOUT(
   KC_GRV, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                       KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
  _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_F12 ,
  _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______, KC_EQL , KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,     _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                    QK_BOOT, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),


/* RAISE Windows
 * .-----------------------------------------.                                .-----------------------------------------.
 * | XMAS |PLAIN |RGBSAI|RGBHUI|RGBVAI|RGBTOG|----------.    E    .-----------|  TG1 | CYCLE|      |      |      |      |
 * |------+------+------+------+------+------|  ______  |  < N >  |  ______   |------+------+------+------+------+------|
 * |      |      |      | Caps | Num  | Scrl |----------|    C    |-----------| PGUP | PWRD |  Up  | NWRD | Home |______|
 * |------+------+------+------+------+------|  ______  |  < O >  |  ______   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |----------|    D    |-----------| PGDN | Left | Down |Right | End  |      |
 * |------+------+------+------+------+------|  ______  |  < E >  |  ______   |------+------+------+------+------+------|
 * |______|      |      |      |      |      |----------|    R    |-----------|Insert| WVDL |  TV  | WVDR |      |______|
 * '-----------------------------------------|  /       /         \       \   |-----------------------------------------'
 *               |______|______|______|______| /______ /           \ ______\  |______|______|______|______|
 *               |      |      |      |      |/       /             \       \ |      |      |      |      |
 *               '-----------------------------------'               '------------------------------------'
 */
// [_RAISE] = LAYOUT(
//   RGB_MODE_XMAS, RGB_MODE_PLAIN, RGB_SAI, RGB_HUI, RGB_VAI, RGB_TOG,                       TG(_GAME), CYCLE  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX      , XXXXXXX       , XXXXXXX, KC_CLCK, KC_NLCK, KC_SLCK,                       KC_PGUP  , PWRD   , KC_UP  , NWRD   , KC_HOME, _______,
//   XXXXXXX      , XXXXXXX       , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_PGDN  , KC_LEFT, KC_DOWN, KC_RGHT, KC_END , XXXXXXX,
//   _______      , XXXXXXX       , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, KC_INS   , WVDL   , TV     , WVDR   , XXXXXXX, _______,
//                                  _______, _______, _______, _______, _______,     _______, _______  , _______, _______, _______
// )


/* RAISE Linux
 * .-----------------------------------------.                                .-----------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |----------.    E    .-----------|  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|  ______  |  < N >  |  ______   |------+------+------+------+------+------|
 * |      |      |      | Caps | Num  | Scrl |----------|    C    |-----------| PGUP | Home | PWRD | NWRD | End  | F12  |
 * |------+------+------+------+------+------|  ______  |  < O >  |  ______   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |----------|    D    |-----------| PGDN | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|  ______  |  < E >  |  ______   |------+------+------+------+------+------|
 * |______|      |      |      |      |      |----------|    R    |-----------|Insert| LVDH | LVDL | LVDR | LVDE |______|
 * '-----------------------------------------|  /       /         \       \   |-----------------------------------------'
 *               |RGBSAI|RGBHUI|RGBVAI|RGBTOG| /______ /           \ ______\  |  TG1 |______|______| BOOT |
 *               |      |      |      |      |/       /             \       \ |      |      |      |      |
 *               '-----------------------------------'               '------------------------------------'
 */
[_RAISE] = LAYOUT(
   KC_GRV, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                       KC_F6    , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, KC_NUM , KC_SCRL,                       KC_PGUP  , KC_HOME, PWRD   , NWRD   , KC_END , KC_F12 ,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_PGDN  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, KC_INS   , LVDH   , LVDL   , LVDR   , LVDE   , _______,
                    RGB_SAI, RGB_HUI, RGB_VAI, RGB_TOG, _______,     _______, TG(_GAME), _______, _______, QK_BOOT
)
};

// turn off when computer is sleeping.
void suspend_power_down_user(void) {
  #ifdef OLED_ENABLE
    oled_off();
  #endif
}

// turn on when computer is awake.
void suspend_wakeup_init_user(void) {
  #ifdef OLED_ENABLE
    oled_on();
  #endif
}

// Custom keycode handling.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // handling this once instead of in each keycode uses less program memory.
    if ((keycode >= SAFE_RANGE) && !(record->event.pressed)) {
        return false;
    }

    switch (keycode) { // For keycode overrides
        // case CYCLE:
        //     set_single_persistent_default_layer((1+get_highest_layer(default_layer_state)) % BASE_LAYERS);
        //     break;
        case LVDH: // Windows Virtual Desktop Home
		    if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_HOME);
                unregister_code(KC_HOME);
                unregister_code(KC_LGUI);
		    }
		    break;
		case LVDL: // Windows Virtual Desktop Left
		    if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_PGUP);
                unregister_code(KC_PGUP);
                unregister_code(KC_LGUI);
		    }
		    break;
        case LVDR: // Windows Virtual Desktop Right
		    if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_PGDN);
                unregister_code(KC_PGDN);
                unregister_code(KC_LGUI);
		    }
		    break;
        case LVDE: // Windows Virtual Desktop End
		    if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_END);
                unregister_code(KC_END);
                unregister_code(KC_LGUI);
		    }
		    break;
		case WVDL: // Windows Virtual Desktop Left
		    if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_LEFT);
                unregister_code(KC_LEFT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
		    }
		    break;
		case WVDR: // Windows Virtual Desktop Right
		    if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LCTL);
                register_code(KC_RIGHT);
                unregister_code(KC_RIGHT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
		    }
		    break;
        case TV: // Task View
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_TAB);
                unregister_code(KC_TAB);
                unregister_code(KC_LGUI);
                }
            break;
        case PWRD: // Previous Word
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LEFT);
                unregister_code(KC_LEFT);
                unregister_code(KC_LCTL);
                }
            break;
        case NWRD: // Next Word
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_RGHT);
                unregister_code(KC_RGHT);
                unregister_code(KC_LCTL);
                }
            break;
    }

    // this uses less memory than returning in each case.
    return keycode < SAFE_RANGE;
};

#ifdef ENCODER_MAP_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
        [_QWERTY]       =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
        // [_COLEMAK_DHM] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
        [_GAME]         =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
        [_NUMPAD]       =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
        [_LOWER]        =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
        [_RAISE]        =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  }
    };
#endif
