/* Copyright 2021 Danny Nguyen <danny@keeb.io>

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

#include "encoder.h"
#include QMK_KEYBOARD_H

#define EC_UNDO LCTL(KC_Z)
#define EC_REDO LCTL(KC_Y)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_MUTE, KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NO, KC_BSPC,
    KC_HOME,          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_END,           MO(1), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_PGUP,          KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_NO,
    KC_PGDN,          KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_NO,  KC_SPC,      KC_SPC,  KC_SPC,  KC_RALT, KC_RGUI, KC_RCTL, KC_MENU
  ),
  [1] = LAYOUT(
    KC_MUTE, QK_BOOT, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, KC_DEL,
    BL_STEP,          _______, _______, KC_UP,   _______, _______, _______,     _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______,
    RGB_MOD,          _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,     _______, KC_4,    KC_5,    KC_6,    _______, _______,          _______,
    KC_VOLU,          _______, _______, _______, _______, _______, _______,     _______, KC_1,    KC_2,    KC_3,    _______, _______, _______,
    KC_VOLD,          _______, _______, _______, _______, _______, _______,     _______, KC_0,    _______, _______, _______, _______
  ),
  [2] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,          _______,
    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______
  ),
  [3] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,          _______,
    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(EC_UNDO, EC_REDO) },
    //[1] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
    [2] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [3] = { ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
};
#endif
