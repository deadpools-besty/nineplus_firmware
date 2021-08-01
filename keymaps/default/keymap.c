#include QMK_KEYBOARD_H

#define _MAIN 0
#define _l1 1
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { //button closest to usb is first
  [_MAIN] = LAYOUT(
     KC_KP_7, KC_KP_8, KC_KP_9,
	 KC_KP_4, KC_KP_5, KC_KP_6,
	 KC_KP_1, KC_KP_2, KC_KP_3 )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_1);
        } else {
            tap_code(KC_2);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_3);
        } else {
            tap_code(KC_4);
        }
    }
	else if (index == 2) {
        if (clockwise) {
            tap_code(KC_5);
        } else {
            tap_code(KC_6);
        }
    }
	else if (index == 3) {
        if (clockwise) {
            tap_code(KC_7);
        } else {
            tap_code(KC_8);
        }
    }
	else if (index == 4) {
        if (clockwise) {
            tap_code(KC_9);
        } else {
            tap_code(KC_0);
        }
    }
	else if (index == 5) {
        if (clockwise) {
            tap_code(KC_W);
        } else {
            tap_code(KC_X);
        }
    }
	else if (index == 6) {
        if (clockwise) {
            tap_code(KC_Y);
        } else {
            tap_code(KC_Z);
        }
    }
}