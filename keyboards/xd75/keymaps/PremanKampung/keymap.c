/* Copyright 2017 Wunder
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
#include "xd75.h"

// Layer shorthand
#define _QW 0
#define _L1 1
#define _L2 2
#define _L3 3
#define _L4 4

// dynamic macro
#define MM_0 DYN_MACRO_PLAY1
#define MM_1 DYN_MACRO_PLAY2
#define RC_0 DYN_REC_START1 
#define RC_1 DYN_REC_START2

enum keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    PLOVER,
    LOWER,
    RAISE,
    BACKLIT,
    EXT_PLV,
    DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if ( !process_record_dynamic_macro( keycode, record ) ) {
    return false;
  }

  return true;
};

#define RGBLIGHT_LIGHT_VAL 255
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYOUT
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */  

[_QW] = { /* QWERTY */
	{ KC_GESC,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_EQL,		KC_PSLS,	KC_PAST,	KC_BSPC }, 
	{ KC_TAB,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	KC_P7,		KC_P8,		KC_P9,		KC_PPLS }, 
	{ KC_CAPS,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	KC_H,	KC_J,	KC_K,	KC_L,	KC_QUOT,KC_P4,		KC_P5,		KC_P6,		KC_ENT }, 
	{ OSM(MOD_LSFT),	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_N,	KC_M,	RSFT_T(KC_COMM),KC_UP,	KC_SLSH,	KC_P1,		KC_P2, 		KC_P3,	KC_PENT }, 
	{ KC_LCTL,	KC_LGUI,KC_LALT,MO(_L1),LT(_L4,KC_SPACE),	KC_SPC, KC_SPC, (LT(_L2,KC_SPACE)), KC_LEFT,	KC_DOWN,	KC_RGHT,	LT(_L2,  KC_P0), KC_PDOT, KC_MINS, KC_DEL }, 
},

 
 [_L1] = { /* FUNCTION */
	{ DYN_REC_STOP, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, RC_0, RC_1 }, 
	{ KC_TAB, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, RGB_SAI, RGB_SAD, RGB_M_SN, _______ }, 
	{ KC_ASTG, KC_VOLD, KC_MSTP, KC_VOLU, KC_MUTE, _______, _______, _______, _______, _______, _______, RGB_M_B, RGB_M_R, RGB_M_SW, _______ }, 
	{ KC_RSFT, _______, _______, (KC_CALC), _______, _______, _______, _______, RGB_RMOD, RGB_TOG, RGB_MOD, _______, MM_0, MM_1, _______ }, 
	{ KC_RCTL, _______, KC_RALT, KC_TRNS, _______, _______, _______, MO(_L3), RGB_VAD, RGB_HUI, RGB_VAI, _______, _______, _______, _______ }, 
},


  [_L2] = { /* FUNCTION */
	{ KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_LBRC, KC_RBRC, _______, KC_PSCR, KC_SLCK, KC_DEL }, 
	{ KC_TAB, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP, KC_PGUP, _______ }, 
	{ KC_NLCK, _______, _______, _______, _______, _______, KC_HOME, _______, _______, _______, KC_SCLN, KC_LEFT, _______, KC_RGHT, KC_ENT }, 
	{ KC_RSFT, _______, _______, _______, _______, _______, KC_END, _______, KC_DOT, KC_HOME, KC_BSLS, KC_END, KC_DOWN, KC_PGDN, KC_PENT }, 
	{ KC_RCTL, _______, KC_RALT, _______, KC_SPC, KC_SPC, _______, KC_TRNS, KC_PGUP, KC_END, KC_PGDN, KC_TRNS, _______, _______, _______ }, 
},


 [_L3] = { /* FUNCTION */
	{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }, 
	{ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PWR, _______, _______, _______, _______ }, 
	{ _______, _______, KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }, 
	{ _______, _______, RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }, 
	{ _______, _______, _______, _______, _______, _______, _______, KC_TRNS, _______, _______, _______, _______, _______, _______, _______ }, 
}, 


 [_L4] = { /* FUNCTION */
	{ KC_ESC, KC_WWW_BACK, _______, KC_WFWD, KC_F4, KC_F5, KC_F6, _______, _______, _______, _______, _______, _______, _______, _______ }, 
	{ LCTL(KC_TAB), LCTL(KC_PGUP), KC_HOME, (LCTL(KC_PGDOWN)), (KC_WREF), _______, _______, _______, KC_INS, _______, _______, _______, _______, _______, _______ }, 
	{ _______, KC_PGUP, KC_END, KC_PGDN, (S(LCTL(KC_F))), _______, KC_HOME, _______, _______, _______, _______, _______, _______, _______, _______ }, 
	{ KC_LSFT, _______, _______, (KC_CALC), _______, _______, KC_END, _______, _______, _______, _______, _______, _______, _______, _______ }, 
	{ KC_LCTL, _______, _______, _______, KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }, 
	}
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};



void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        rgblight_mode_noeeprom(18);
    } else {
        rgblight_mode_noeeprom(14);
    }
}
