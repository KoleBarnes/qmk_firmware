//Sets up leader key.

bool leader_success;
static uint16_t leader_timer = 0;

enum custom_leader_state {
    _IDLE,
    _SUCD,
    _FAIL
};

enum custom_leader_state leader_state = _IDLE;


void leader_end_user(void) {
    leader_state = _FAIL;

    if (leader_sequence_one_key(KC_F)) {
      SEND_STRING("QMK is awesome.");
      leader_state = _SUCD;
    }
    else if (leader_sequence_one_key(KC_T)) {
      // When I press KC_LEAD and then T, this sends CTRL + SHIFT + T
      SEND_STRING(SS_LCTL(SS_LSFT("t")));
      leader_state = _SUCD;
    }
    else if (leader_sequence_two_keys(KC_G, KC_S)) {
      SEND_STRING("Signed-off-by: KoleBarnes <kbarnes261@gmail.com>");
      leader_state = _SUCD;
    }
    else if (leader_sequence_three_keys(KC_D, KC_D, KC_G))  {
      SEND_STRING("https://start.duckduckgo.com\n");
      leader_state = _SUCD;
    }

    leader_timer = timer_read();
}
