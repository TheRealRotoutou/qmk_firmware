/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_french.h"

enum layers {
  _BASE,
  _LOWER,
  _RAISE,
  _NUMBER,
  _SIGNS
};

// Macros for circumflex
enum custom_keycodes {
    FR_ECIR = SAFE_RANGE,
    FR_UCIR,
    FR_ACIR,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case FR_ECIR:
        if (record->event.pressed) {
            register_code16(FR_CIRC);
            register_code16(FR_E);
        } else {
            unregister_code16(FR_CIRC);
            unregister_code16(FR_E);
        }
        return false;

    case FR_UCIR:
        if (record->event.pressed) {
            register_code16(FR_CIRC);
            register_code16(FR_U);
        } else {
            unregister_code16(FR_CIRC);
            unregister_code16(FR_U);
        }
        return false;

    case FR_ACIR:
        if (record->event.pressed) {
            register_code16(FR_CIRC);
            register_code16(FR_A);
        } else {
            unregister_code16(FR_CIRC);
            unregister_code16(FR_A);
        }
        return false;

    default:
        return true;
    }
}

// Combos for french accents
const uint16_t PROGMEM FR_EACU_combo[] = {FR_Z, FR_E, COMBO_END};
const uint16_t PROGMEM FR_EGRV_combo[] = {FR_E, FR_R, COMBO_END};
const uint16_t PROGMEM FR_ECIR_combo[] = {FR_E, FR_T, COMBO_END};
const uint16_t PROGMEM FR_UGRV_combo[] = {FR_U, FR_I, COMBO_END};
const uint16_t PROGMEM FR_UCIR_combo[] = {FR_U, FR_O, COMBO_END};
const uint16_t PROGMEM FR_AGRV_combo[] = {FR_A, FR_Z, COMBO_END};
const uint16_t PROGMEM FR_ACIR_combo[] = {FR_A, FR_E, COMBO_END};
const uint16_t PROGMEM FR_CCED_combo[] = {FR_X, FR_C, COMBO_END};
combo_t key_combos[] = {
    COMBO(FR_EGRV_combo, FR_EGRV),
    COMBO(FR_EACU_combo, FR_EACU),
    COMBO(FR_ECIR_combo, FR_ECIR),
    COMBO(FR_UGRV_combo, FR_UGRV),
    COMBO(FR_UCIR_combo, FR_UCIR),
    COMBO(FR_AGRV_combo, FR_AGRV),
    COMBO(FR_ACIR_combo, FR_ACIR),
    COMBO(FR_CCED_combo, FR_CCED)
};

// cut/copy/paste that works both on linux and windows.
#define LWCOPY LCTL(KC_INS)    // Ctrl+Ins
#define LWCUT LSFT(KC_DEL)     // Maj+Suppr
#define LWPASTE LSFT(KC_INS)   // Maj+Ins 

// Base layer - Middle of the key - black
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------.                          ,-----------------------------------------------------------------------.
          KC_TAB,       FR_A,       FR_Z,       FR_E,       FR_R,       FR_T,                                  FR_Y,       FR_U,       FR_I,       FR_O,       FR_P,    KC_BSPC,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                          |-----------+-----------+-----------+-----------+-----------+-----------|
         KC_LSFT,       FR_Q,       FR_S,       FR_D, LT(3,FR_F),       FR_G,                                  FR_H, LT(4,FR_J),       FR_K,       FR_L,       FR_M,     KC_DEL,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                          |-----------+-----------+-----------+-----------+-----------+-----------|
         KC_LCTL,       FR_W,       FR_X,       FR_C,       FR_V,       FR_B,                                  FR_N,    FR_COMM,     FR_DOT,    FR_COLN,    FR_QUES,     KC_ESC,
  //|-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                         KC_LALT,      MO(1),     KC_SPC,        KC_ENT,      MO(2),     KC_RALT
                                                      //`-------------------------------'  `-----------------------------------'
  ),

// Lower layer - Lower left in the key - blue
    [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------.                          ,-----------------------------------------------------------------------.
         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                               FR_UNDS,     FR_EQL,    FR_EXLM,    FR_SECT,    FR_TILD,      FR_AT,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                          |-----------+-----------+-----------+-----------+-----------+-----------|
         XXXXXXX,    XXXXXXX,    XXXXXXX,      LWCUT,     KC_DEL,    XXXXXXX,                               KC_LEFT,    KC_DOWN,      KC_UP,    KC_RGHT,    KC_HOME,     KC_INS,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                          |-----------+-----------+-----------+-----------+-----------+-----------|
         XXXXXXX,    XXXXXXX,    XXXXXXX,     LWCOPY,    LWPASTE,    XXXXXXX,                               XXXXXXX,    KC_PGDN,    KC_PGUP,    XXXXXXX,     KC_END,    XXXXXXX,
  //|-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                         _______,    _______,    _______,        _______,   _______,     KC_RWIN
                                                      //`-------------------------------'  `-----------------------------------'
  ),

// Raise layer - Lower right  in the key - green
    [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------.                          ,-----------------------------------------------------------------------.
         XXXXXXX,    XXXXXXX,     FR_GRV,    FR_QUOT,    FR_CIRC,    FR_DIAE,                               XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                          |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                               XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                          |-----------+-----------+-----------+-----------+-----------+-----------|
           KC_F7,      KC_F8,      KC_F9,     KC_F10,     KC_F11,     KC_F12,                               XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  //|-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                         KC_LWIN,    _______,    _______,       _______,    _______,     _______
                                                      //`-------------------------------'  `-----------------------------------'
  ),

// Number layer - Upper left in the key - red
    [_NUMBER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------.                          ,-----------------------------------------------------------------------.
         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                  FR_7,       FR_8,       FR_9,    FR_SLSH,    FR_MINS,    FR_EURO,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                          |-----------+-----------+-----------+-----------+-----------+-----------|
         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                  FR_4,       FR_5,       FR_6,    FR_ASTR,    FR_PLUS,     FR_DLR,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                          |-----------+-----------+-----------+-----------+-----------+-----------|
         XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                  FR_1,       FR_2,       FR_3,    FR_HASH,    FR_PERC,     FR_DEG,
  //|-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                         _______,    _______,    _______,       _______,       FR_0,      FR_DOT
                                                      //`-------------------------------'  `-----------------------------------'
  ),

// Signs layer - Upper right in the key - orange
    [_SIGNS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------.                          ,-----------------------------------------------------------------------.
         FR_SUP2,    FR_SCLN,    FR_DQUO,    FR_QUOT,    FR_LPRN,    FR_RPRN,                               XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                          |-----------+-----------+-----------+-----------+-----------+-----------|
         FR_MICR,    FR_AMPR,    FR_LABK,    FR_RABK,    FR_LBRC,    FR_RBRC,                               XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  //|-----------+-----------+-----------+-----------+-----------+-----------|                          |-----------+-----------+-----------+-----------+-----------+-----------|
         FR_CURR,    FR_PIPE,    FR_BSLS,    FR_SLSH,    FR_LCBR,    FR_RCBR,                               XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  //|-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                         _______,    _______,    _______,       _______,    _______,     _______
                                                      //`-------------------------------'  `-----------------------------------'
 )
};
