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

//Sets up what the OLED screens display.

// static void render_background(void) {
//     static const char PROGMEM raw_background[] = {
//         0,  0,  0,  0, 64, 64, 64,240,248,248,255, 56,255,248,248, 63,248,248,255, 56,255,248,248,240, 64, 64, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0, 73, 73, 73,255,255,255,255,224,223,191,191,  0,191,191,223,224,255,255,255,255, 73, 73, 73,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  7, 15, 15,127, 15,127, 15, 15,126, 15, 15,127, 15,127, 15, 15,  7,  1,  1,  1,  0,  0,  0,  0,  0,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//     };
//     oled_write_raw_P(raw_background, sizeof(raw_background));
// }


static void render_logo(void) {
    static const char PROGMEM qmk[] = {
        0,  0,  0,  0, 64, 64, 64,240,248,248,255, 56,255,248,248, 63,248,248,255, 56,255,248,248,240, 64, 64, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0, 73, 73, 73,255,255,255,255,224,223,191,191,  0,191,191,223,224,255,255,255,255, 73, 73, 73,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  7, 15, 15,127, 15,127, 15, 15,126, 15, 15,127, 15,127, 15, 15,  7,  1,  1,  1,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(qmk, sizeof(qmk));
}

// static void render_tux(void) {
//     static const char PROGMEM tux[] = {
//         153,154,10,
//         185,186,0
//     };

//     oled_write_P(tux, false);
// }

static void print_status(void) {
    oled_set_cursor(0,0);
    // render_background();
    render_logo();

    oled_set_cursor(0,4);
    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        // case _COLEMAK_DHM:
        //     oled_write_ln_P(PSTR("ClMk"), false);
        //     break;
        case _GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Num"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
            break;
    }


    if (is_keyboard_master()) {
        oled_set_cursor(0,13);

        #ifdef LEADER_ENABLE
            if (leader_sequence_active()) {
                oled_write_P(PSTR("LEAD"), false);
            } else {
                switch (leader_state) {
                    case _SUCD:
                        oled_write_ln_P(PSTR("SUCD"), false);
                        break;
                    case _FAIL:
                        oled_write_ln_P(PSTR("FAIL"), false);
                        break;
                    default:
                        oled_write_ln_P(PSTR(" "), false);
                        break;
                }
            }

            if (leader_state != _IDLE && timer_elapsed(leader_timer) > 5000) {
                leader_state = _IDLE;
            }
        #endif
     } // else {
    //     oled_set_cursor(0,12);
    //     render_tux();
    // }

    led_t led_usb_state = host_keyboard_led_state();
    oled_set_cursor(0,15);
    oled_write_P(led_usb_state.caps_lock ? PSTR("C") : PSTR(" "), false);
    oled_set_cursor(2,15);
    oled_write_P(led_usb_state.num_lock ? PSTR("N") : PSTR(" "), false);
    oled_set_cursor(4,15);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("S") : PSTR(" "), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    print_status();
    // if (is_keyboard_master()) {
    //     print_status();
    // } else {
    //     oled_set_cursor(0,0);
    // }
    return false;
}
