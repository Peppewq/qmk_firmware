#include QMK_KEYBOARD_H
#include "keymap_spanish.h"
#include "sendstring_spanish.h"

#define _BASE 0
#define _ADV 1

/*
Keys:
ALGR(ES_LABK) \
ES_SLSH       /
ES_NTIL       Ñ
ES_LABK       ºª

*/



// TODO Manca la @

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     ES_SLSH,   ES_Q,    ES_W,   ES_E,    ES_R,   ES_T,                          ES_Y,    ES_U,    ES_I,    ES_O,   ES_P,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    ES_A,    ES_S,    ES_D,    ES_F,    ES_G,                         ES_H,    ES_J,    ES_K,   ES_L,  ES_NTIL,  ES_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   ES_Z,    ES_X,    ES_C,    ES_V,    ES_B,                         ES_N,    ES_M, ES_COMM,  ES_DOT, ES_MINS,  KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LALT, KC_LGUI,   KC_SPC,   MO(1),   KC_ENT
                                      //`--------------------------'  `--------------------------'

  ),

    [_ADV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,------------------------------------------------------------.
     ES_LABK, ES_EXLM, ES_DQUO, ES_HASH , ES_DLR,  ES_PERC,                    ES_AMPR,  ALGR(ES_LABK), ES_LPRN,  ES_RPRN, ES_EQL,  ES_QUES,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------------+---------+--------+--------+--------|
     ES_MORD,  ES_1,    ES_2,     ES_3,   ES_4,    ES_5,                        ES_PIPE,  KC_UP,   ES_LBRC, ES_RBRC, ES_LCBR, ES_RCBR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, ES_6,    ES_7,    ES_8,    ES_9,    ES_0,                        KC_LEFT, KC_DOWN,  KC_RGHT,  ES_GRV, ES_QUOT, ES_ACUT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______,  _______,  _______,   XXXXXXX, KC_ENT
                                      //`--------------------------'  `--------------------------'
  )
};


/*
==================================
        COMBO Keys
==================================
*/
const uint16_t PROGMEM combo_esc[] = {ES_Q, ES_W, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_esc, KC_ESC)
};
// ==========================================================================================
// ==========================================================================================

/*
==================================
        Keys OVERRIDE
==================================
*/

// When shift + backspace are pressed ==> DEL
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// When shift + slash are pressed ==> backslash
//const key_override_t backslash_key_override = ko_make_basic(MOD_MASK_SHIFT, ES_SLSH, ALGR(ES_LABK));

const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
//    &backslash_key_override,
    NULL // Null terminate the array of overrides!
};

// ==========================================================================================
// ==========================================================================================

/*
==================================
        CUSTOM keys
==================================
*/
