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

#define RGBLIGHT_LIGHT_VAL 255

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYOUT WIP
 * .------------------------------------------------------------------------------------------------------------------------------------------------------.
 * |KC_GESC	|KC_1	 |KC_2	  |KC_3	   |KC_4	|	KC_5	 	|	KC_6		|KC_7	 |	KC_8	|KC_9	 |KC_0	  |KC_EQL  |KC_PSLS |KC_PAST |KC_BSPC |
 * |--------+--------+--------+--------+--------+---------------+---------------+--------+----------+--------+--------+--------+--------+--------+--------|
 * |   *5	|KC_Q    |KC_W	  |KC_E    |KC_R	|	KC_T 		|	KC_Y		|KC_U	 |	KC_I	|KC_O	 |KC_P	  |KC_P7   |KC_P8	|KC_P9	 |KC_PPLS |
 * |--------+--------+--------+--------+--------+---------------+---------------+--------+----------+--------+--------+--------+--------+--------+--------|
 * |KC_CAPS	|KC_A    |KC_S	  |KC_D	   |KC_F	|	KC_G		|	KC_H	 	|KC_J	 |	KC_K	|KC_L	 |KC_QUOT |KC_P4   |KC_P5	|KC_P6	 |KC_ENT  |
 * |--------+--------+--------+--------+--------+---------------+---------------+--------+----------+--------+--------+--------+--------+--------+--------|
 * |MOD_LSFT|KC_Z    |KC_X	  |KC_C	   |KC_V	|	KC_B	 	|	KC_N		|KC_M	 |  *3		|KC_UP	 |KC_SLSH |KC_P1   |KC_P2	|KC_P3	 |KC_PENT |
 * |--------+--------+--------+--------+--------+---------------+---------------+--------+----------+--------+--------+--------+--------+--------+--------|
 * |KC_LCTL	|KC_LGUI |KC_LALT |MO(_L1) |  *1    |RSFT_T(KC_SPC)	|LSFT_T(KC_SPC)	|  *2	 |	KC_LEFT	|KC_DOWN |KC_RGHT |  *4    |KC_PDOT |KC_MINS |KC_DEL  |
 * '------------------------------------------------------------------------------------------------------------------------------------------------------'
 */  

// *1 = LT(_L4,KC_SPC) 
// *2 = (LT(_L2,KC_SPC))
// *3 = RSFT_T(KC_COMM)
// *4 = LT(_L2,  KC_P0)
// *5 = LGUI_T(KC_TAB)

[_QW] = { /* QWERTY */
	{ KC_GESC		,	KC_1	,	KC_2	,	KC_3	,	KC_4		,	KC_5		,	KC_6		,	KC_7		,	KC_8		,	KC_9	,	KC_0	,	KC_EQL		,	KC_PSLS	,	KC_PAST	,	KC_BSPC	}, 
	{ GUI_T(KC_TAB)	,	KC_Q	,	KC_W	,	KC_E	,	KC_R		,	KC_T		,	KC_Y		,	KC_U		,	KC_I		,	KC_O	,	KC_P	,	KC_P7		,	KC_P8	,	KC_P9	,	KC_PPLS	}, 
	{ KC_CAPS		,	KC_A	,	KC_S	,	KC_D	,	KC_F		,	KC_G		,	KC_H		,	KC_J		,	KC_K		,	KC_L	,	KC_QUOT	,	KC_P4		,	KC_P5	,	KC_P6	,	KC_ENT	}, 
	{ OSM(MOD_LSFT)	,	KC_Z	,	KC_X	,	KC_C	,	KC_V		,	KC_B		,	KC_N		,	KC_M		,RSFT_T(KC_COMM),	KC_UP	,	KC_SLSH	,	KC_P1		,	KC_P2	,	KC_P3	,	KC_PENT	}, 
	{ KC_LCTL		,	KC_LGUI	,	KC_LALT	,	MO(_L1)	,LT(_L4,KC_SPC)	,RSFT_T(KC_SPC)	,LSFT_T(KC_SPC)	,LT(_L2,KC_SPC)	,	KC_LEFT		,	KC_DOWN	,	KC_RGHT	,LT(_L2,KC_P0)	,	KC_PDOT	,	KC_MINS	,	KC_DEL	}, 
},

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
 
 [_L1] = { /* FUNCTION */
	{ DYN_REC_STOP	, KC_F1		, KC_F2		, KC_F3		, KC_F4		, KC_F5	 , KC_F6	, KC_F7		, KC_F8		, KC_F9		, KC_F10	, KC_F11	, KC_F12	, RC_0		, RC_1		}, 
	{ KC_TAB		, KC_MPRV	, KC_MPLY	, KC_MNXT	, _______	, _______, _______	, _______	, _______	, _______	, _______	, RGB_SAI	, RGB_SAD	, RGB_M_SN	, _______	}, 
	{ KC_ASTG		, KC_VOLD	, KC_MSTP	, KC_VOLU	, KC_MUTE	, _______, _______	, _______	, _______	, _______	, _______	, RGB_M_B	, RGB_M_R	, RGB_M_SW	, _______	}, 
	{ KC_RSFT		, _______	, _______	, KC_CALC	, _______	, _______, _______	, _______	, RGB_RMOD	, RGB_TOG	, RGB_MOD	, _______	, MM_0		, MM_1		, _______	}, 
	{ KC_RCTL		, _______	, KC_RALT	, KC_TRNS	, _______	, _______, _______	, MO(_L3)	, RGB_VAD	, RGB_HUI	, RGB_VAI	, _______	, _______	, _______	, _______	}, 
},


  [_L2] = { /* FUNCTION */
	{ KC_ESC	,	KC_1 ,	KC_2	,	KC_3	,	KC_4	,	KC_5	,	KC_6	,	KC_7	,	KC_8	, KC_LBRC	, KC_RBRC, _______	,	KC_PSCR	, KC_SLCK, KC_DEL	}, 
	{ KC_TAB	, _______, _______	, _______	, _______	, _______	, _______	, _______	, _______	, _______	, _______, KC_HOME	,	KC_UP	, KC_PGUP, _______	}, 
	{ KC_NLCK	, _______, _______	, _______	, _______	, _______	, KC_HOME	, _______	, _______	, _______	, KC_SCLN, KC_LEFT	,	_______	, KC_RGHT, KC_ENT	}, 
	{ KC_RSFT	, _______, _______	, _______	, _______	, _______	, KC_END	, _______	, KC_DOT	, KC_HOME	, KC_BSLS, KC_END	,	KC_DOWN	, KC_PGDN, KC_PENT	}, 
	{ KC_RCTL	, _______, KC_RALT	, _______	, KC_SPC	, KC_SPC	, _______	, KC_TRNS	, KC_PGUP	, KC_END	, KC_PGDN, KC_TRNS	,	_______	, _______, _______	}, 
},


 [_L3] = { /* FUNCTION */
	{ XXXXXXX, XXXXXXX, XXXXXXX	, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, 
	{ XXXXXXX, XXXXXXX, XXXXXXX	, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PWR	, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, 
	{ XXXXXXX, XXXXXXX, KC_SLEP	, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, 
	{ XXXXXXX, XXXXXXX, RESET	, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, 
	{ XXXXXXX, XXXXXXX, XXXXXXX	, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX }, 
}, 


 [_L4] = { /* FUNCTION */
	{	KC_ESC		, KC_WWW_BACK	, _______	,	KC_WFWD		,	KC_F4		,	KC_F5,	KC_F6	, _______, _______	, _______, _______, _______, _______, _______, _______ }, 
	{ LCTL(KC_TAB)	, LCTL(KC_PGUP)	, KC_HOME	,LCTL(KC_PGDOWN),	KC_WREF		, _______, _______	, _______, KC_INS	, _______, _______, _______, _______, _______, _______ }, 
	{	_______		, KC_PGUP		, KC_END	,	KC_PGDN		,S(LCTL(KC_F))	, _______,	KC_HOME	, _______, _______	, _______, _______, _______, _______, _______, _______ }, 
	{	KC_LSFT		,	_______		, _______	,	KC_CALC		,	_______		, _______,	KC_END	, _______, _______	, _______, _______, _______, _______, _______, _______ }, 
	{	KC_LCTL		,	_______		, _______	,	_______		,	KC_TRNS		, _______, _______	, _______, _______	, _______, _______, _______, _______, _______, _______ }, 
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if ( !process_record_dynamic_macro( keycode, record ) ) {
    return false;
  }

  return true;
};

//CAPSLOCK stuff

// RGB switch mode when changing layer
// RGB Modes
// 1 = Static
// 2-5 = Breathing
// 6-8 = Rainbow
// 9-14 = Swirl
// 15-20 = Snake
// 21-24 = Nightrider
// 25 = Christmas
// 26-30 = Static Gradient


void led_set_user(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        rgblight_mode(18);
		rgblight_sethsv(355, 255, 255);
  } else { 
    if (biton32(layer_state) == _QW) {
        rgblight_mode(13);
		rgblight_sethsv(255, 50, 255);
    }
  }
}

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 10}; // Set the last one to 10ms for some speedy swirls

uint8_t prev = _QW;
uint32_t desired = 18;
uint16_t hue = 355;
uint16_t sat = 255;
uint16_t val = 255;

void get_hsv(void) {
    hue = rgblight_get_hue();
    sat = rgblight_get_sat();
    val = rgblight_get_val();
}

void reset_hsv(void) {
    rgblight_sethsv(hue, sat, val);
}

void matrix_init_user() {
    rgblight_mode(desired);
    rgblight_enable();
    reset_hsv();
}


uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  if (prev!=_L4) {
      switch (layer) {
        case _QW:
			rgblight_mode(18);
			rgblight_sethsv(355, 255, 255);
          if (host_keyboard_leds()  & (1<<USB_LED_CAPS_LOCK) ) {
			rgblight_mode(13);
			rgblight_sethsv(255, 50, 255);
          }
          break;

        case _L1:
          rgblight_mode(21);
          rgblight_sethsv(150, 255, 255);
          break;

        case _L2:
          rgblight_mode(21); 
          rgblight_sethsv( 280, 255, 255);
          break;

        case _L3:
          rgblight_mode(5);     
          rgblight_sethsv( 16, 255, 255);
          break;
 
		case _L4:
          rgblight_mode(21);     
          rgblight_sethsv( 200, 255, 255);
          break;

      }
  } else {
      desired = rgblight_get_mode();
      get_hsv();
  }
  prev = layer;
  return state;
}