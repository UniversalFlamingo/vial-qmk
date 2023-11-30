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

#include QMK_KEYBOARD_H

// https://docs.qmk.fm/#/feature_layouts?id=tips-for-making-layouts-keyboard-agnostic

#include <stddef.h>
#include <stdint.h>

// clang-format off

#include "config.h"
#include "uf_keycodes.h"
#include "uf_keymap.h"

// clang-format on

#include "default_keyboard.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "process_key_override.h"
#include "quantum_keycodes.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------------.
 * |   Q   |   W   |   E   |   R   |   T   |  ( )  |  = +  |   Y   |   U   |   I   |   O   |   P   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   A   |   S   |   D   |   F   |   G   |  [ ]  |  - _  |   H   |   J   |   K   |   L   |  ; :  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   Z  s|   X   |   C   |   V   |   B   |  { }  |  ` ~  |   N   |   M   |  , <  |  . >  |  / ? s|
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | HOME ^| PGDN o| PGUP  |  END c|BSDEL-v|               | ENT -^| LEFT c| DOWN  |  UP  o| RGHT ^|
 * `-----------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
    KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_LPRN, KC_EQL,  KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_LBRC, KC_MINS, KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,
    UF_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_LCBR, KC_GRV,  KC_N,    KC_M,    KC_COMM, KC_DOT, UF_SLSH,
    UF_HOME, UF_PGDN, UF_PGUP, UF_END, UF_LOWR, KC_SPC,               UF_UPPR, UF_LEFT, UF_DOWN, UF_UP,  UF_RIGHT
),
/* Lower
 * ,-----------------------------------------------------------------------------------------------.
 * |  ESC  |   &   |   *   |   (   |   )   |  ' "  |  FMT  |       |  7 &  |  8 *  |  9 (  |  / |  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  TAB  |   $   |   %   |   ^   |       |PrevTab|NextTab|       |  4 $  |  5 %  |  6 ^  |  * "  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |      s|   !   |   @   |   #   |       |       |       |       |  1 !  |  2 @  |  3 #  |   -  s|
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |               |       |NPENT c|   0   |   .  o|   +  ^|
 * `-----------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12_1x2uC(
    KC_ESC , KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_QUOT, UF_FMT , KC_NO  , KC_P7,   KC_P8, KC_P9,   KC_PSLS,
    KC_TAB , KC_DLR , KC_PERC, KC_CIRC, KC_NO  , UF_PET , UF_NET , KC_NO  , KC_P4,   KC_P5, KC_P6,   KC_PAST,
    KC_LSFT, KC_EXLM, KC_AT  , KC_HASH, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_P1,   KC_P2, KC_P3,   UF_PMNS,
    _______, _______, _______, _______, _______, _______,              _______, UF_PENT, KC_P0, UF_PDOT, UF_PPLS
),
/* Raise
 * ,-----------------------------------------------------------------------------------------------.
 * |  ESC  |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   |  \ |  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  TAB  |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |  ' "  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  F1  s|  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12 s|
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |               |       | LEFT  | DOWN  |  UP   | RGHT  |
 * `-----------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12_1x2uC(
    KC_ESC , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
    KC_TAB , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_QUOT,
    UF_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , UF_F12 ,
    _______, _______, _______, _______, _______, _______,              _______, KC_LEFT, KC_DOWN ,KC_UP  , KC_RIGHT
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * | CAPS | RGB  |RGBMOD| HUE+ | SAT+ |BRGTH+|      | UND  |UNDMOD| HUE+ | SAT+ |BRGTH+|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | NUMB |      |RGBMOD| HUE- | SAT- |BRGTH-|      |      |UNDMOD| HUE- | SAT- |BRGTH-|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  MJ  |      |      |      |      |      |      |      |      |      |      | SCAP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | INS  |      |      |      |      |             |      |      |      |      | RESET|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12_1x2uC(
    KC_CAPS,   RGB_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, _______, B_RGBL_TOG,  B_RGBL_MOD,   B_RGBL_HUI,  B_RGBL_SAI,  B_RGBL_VAI,
    UF_NLTOG,  _______, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,     B_RGBL_RMOD,  B_RGBL_HUD,  B_RGBL_SAD,  B_RGBL_VAD,
    UF_MJM_TG, _______, _______,  RGB_M_P, RGB_M_B, RGB_M_T, _______, _______,     _______,      B_RGBL_M_P,  B_RGBL_M_B,  UF_SCAP,
    KC_INS,    _______, _______,  _______, _______, _______,          _______,     _______,      _______,    _______,      QK_BOOT
)

};

// clang-format on
