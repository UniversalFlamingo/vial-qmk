/* Copyright 2020 tominabox1
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
#include "keycodes.h"
#include "keymap_us.h"
#include QMK_KEYBOARD_H

#include <stdint.h>

#include "uf_keycodes.h"
#include "uf_keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------------.
 * |   Q   |   W   |   E   |   R   |   T   |  ( )  | | = + |   Y   |   U   |   I   |   O   |   P   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   A   |   S   |   D   |   F   |   G   |  [ ]  | " - _ |   H   |   J   |   K   |   L   |  ; :  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   Z  s|   X   |   C   |   V   |   B   |  { }  | ' ` ~ |   N   |   M   |  , <  |  . >  |  / ? s|
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | GESC ^| TAB  o|      c|  -v   |DEL  BS|               |  ENT  |  -^   |      c|    | o|  ' " ^|
 * `-----------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
    KC_Q,            KC_W,           KC_E,    KC_R,    KC_T,   UF_PRN,  KC_EQL,  KC_Y,   KC_U,    KC_I,    KC_O,            KC_P,
    KC_A,            KC_S,           KC_D,    KC_F,    KC_G,   UF_BRC,  KC_MINS, KC_H,   KC_J,    KC_K,    KC_L,            KC_SCLN,
    LSFT_T(KC_Z),    KC_X,           KC_C,    KC_V,    KC_B,   UF_CBR,  KC_GRV,  KC_N,   KC_M,    KC_COMM, KC_DOT,          RSFT_T(KC_SLSH),
    LCTL_T(KC_ESC),  LOPT_T(KC_TAB), KC_LCMD, TL_LOWR, UF_DBS,     KC_SPC,       KC_ENT, TL_UPPR, KC_RCMD, ROPT_T(KC_PIPE), RCTL_T(KC_QUOT)
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_UP  , _______, _______, _______, KC_PGUP, _______, _______,   KC_7,     KC_8,         KC_9,           KC_PSLS,
    KC_LEFT, _______, KC_RGHT, _______, KC_HOME, _______, KC_END , _______,   KC_4,     KC_5,         KC_6,           KC_PAST,
    _______, KC_DOWN, _______, _______, _______, KC_PGDN, _______, _______,   KC_1,     KC_2,         KC_3,           KC_PMNS,
    _______, _______, _______, _______, _______, ________________,  KC_PENT, _______, RCMD_T(KC_0), ROPT_T(KC_DOT), RCTL_T(KC_PPLS)
),

/* Raise
 * ,-----------------------------------------------------------------------------------------------.
 * |  - _  |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   |  \ |  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  = +  |  1 !  |  2 @  |  3 #  |  4 $  |  5 %  |  6 ^  |  7 &  |  8 *  |  9 (  |  0 )  |  ' "  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |               |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12_1x2uC(
    KC_MINS, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
    KC_EQL , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_QUOT,
    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    _______, _______, _______, _______, _______, ________________, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | RGB  |RGBMOD| HUE+ | SAT+ |BRGTH+|      | UND  |UNDMOD| HUE+ | SAT+ |BRGTH+|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |RGBMOD| HUE- | SAT- |BRGTH-|      |      |UNDMOD| HUE- | SAT- |BRGTH-|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS | NUMB |  MJ  | INS  |      |             |      |      |      |      | RESET|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12_1x2uC(
    _______,  RGB_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, _______, B_RGBL_TOG, B_RGBL_MOD,  B_RGBL_HUI, B_RGBL_SAI, B_RGBL_VAI,
    _______,  _______, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,    B_RGBL_RMOD, B_RGBL_HUD, B_RGBL_SAD, B_RGBL_VAD,
    _______,  _______, _______,  RGB_M_P, RGB_M_B, RGB_M_T, _______, _______,    _______,     B_RGBL_M_P, B_RGBL_M_B, _______,
    KC_CAPS,  B_NLTOG, B_MJM_TG, KC_INS , _______, _______,          _______,    _______,     _______,    _______,    QK_BOOT
)

};
