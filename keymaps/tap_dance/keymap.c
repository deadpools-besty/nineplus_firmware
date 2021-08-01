#include QMK_KEYBOARD_H

// Tap Dance Declarations
enum tap_dances {
  ENT_5 = 0,
  ZERO_7,
};

// Macro Declarations
enum custom_keycodes {
  DBL_0 = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-----------------------.
 * |  7/0  |   8   |  9/FN |
 * |-------+-------+-------|
 * |   4   | 5/ENT |   6   | Dbl Tap 5 for Enter
 * |-------+-------+-------|
 * |   1   |   2   |   3   | 7/0 = Dbl Tap 7 for 0  -  9/FN = Hold 9 for FN
 * `-----------------------'
 */
[0] = LAYOUT( \
  TD(ZERO_7),       KC_8,      LT(1, KC_9),       \
  KC_4,       TD(ENT_5), KC_6,       \
  KC_1, KC_2, KC_3 \
),

/* LAYER 1
 * ,-----------------------.
 * | RCTRL |  V_UP |       |
 * |-------+-------+-------|
 * |  PREV |  PLAY |  NEXT |
 * |-------+-------+-------|
 * |  00   | V_DOWN|  MUTE | 00 will act as bootmagic key
 * `-----------------------'
 */
[1] = LAYOUT( \
  KC_RCTRL, KC_AUDIO_VOL_UP, KC_TRNS, \
  KC_MEDIA_PREV_TRACK,  KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, \
  DBL_0,   KC_AUDIO_VOL_DOWN,  KC__MUTE  \
)

};

qk_tap_dance_action_t tap_dance_actions[] = {
  [ENT_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_ENT),
  [ZERO_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_0)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DBL_0:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        tap_code(KC_P0);
        tap_code(KC_P0);
      }
      break;

  }
  return true;
};


void matrix_init_user(void) {
}
