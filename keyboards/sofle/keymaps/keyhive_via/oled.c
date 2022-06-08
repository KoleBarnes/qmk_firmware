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

#ifdef OLED_ENABLE

static void print_status_narrow(void) {
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

    oled_write_P(PSTR("\n"), false);

    led_t led_usb_state = host_keyboard_led_state();
    oled_set_cursor(0,15);
    oled_write_P(led_usb_state.caps_lock ? PSTR("C") : PSTR(" "), false);
    oled_set_cursor(2,15);
    oled_write_P(led_usb_state.num_lock ? PSTR("N") : PSTR(" "), false);
    oled_set_cursor(4,15);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("S") : PSTR(" "), false);
    oled_set_cursor(0,0);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        oled_set_cursor(0,0);
    }
}

#endif
