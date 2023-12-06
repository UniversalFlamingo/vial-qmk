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

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *
 * +-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
 * |      Q    |      W    |      E    |      R    |     T     | ~    )    |     +     |      Y    |hme  U     |up   I     |pup   O    | |   P   | |
 * |     q     |     w     |     e     |     r     |    t      |     (     |    =      |     y     |    u      |    i      |     o     |    p      |
 * |esc     esc| &       ! | *       @ | (       # | )       $ | `       % |fmt      ^ |         & | 7       * | 8      (  | 9       ) | -       \ |
 * |   cmd-`   |    rgb    |   mode+   |   hue +   |   sat +   |  bright+  |           | underglow |   mode+   |   hue +   |   sat +   |  bright+  |
 * +-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
 * |      A    |      S    |      D    |      F    |     G     |>>>   ]    |      _    |      H    | la   J    |     K     | ra   L    |  "   :   "|
 * |     a     |     s     |     d     |     f     |    g      |     [     |     -     |     h     |     j     |    k      |     l     |     ;     |
 * |tab     tab| $  opt  1 | %       2 | ^  cmd  3 |         4 |<<<      5 |         6 |         7 | 4  cmd  8 | 5       9 | 6  opt  0 | *       ' |
 * |  cmd-tab  |           |   mode-   |   hue -   |   sat -   |  bright-  |           |           |   mode-   |   hue -   |   sat -   |  bright-  |
 * +-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
 * |      Z    |      X    |      C    |     V     |     B     |>>t   }    |     "     |      N    |end   M    |dwn   <    |pdn   >    |      ?    |
 * |     z     |     x     |     c     |    v      |    b      |     {     |    '      |     n     |     m     |     ,     |     .     |     /     |
 * |    sft  F1| !       F2| @       F3| #       F4|         F5|<<t      F6|         F7|fold     F8| 1       F9| 2       Fa| 3       Fb| /  sft  Fc|
 * |  caplock  |  numlock  |    ins    |           |           |           |           |           |           |           |   kpawk   |  scrncap  |
 * +-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
 * |           |           |           |           |   del     |          del          |  backtab  |           |           |           |           |
 * |    esc    |    hme    |    pdn    |    end    |   bsp     |         space         |    tab    |    lft    |    dwn    |    rgt    |    ent    |
 * |    ctl    |    opt    |        pup|    cmd    |  lower    |                       |   raise   |ent cmd    | 0      up | .  opt    | +  ctl    |
 * |           |           |           |           |           |                       |           |           |           |           |   reset   |
 * +-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+
 *
 * +-----------+                              +--------------------------------+---------------------------------+---------------------------------+
 * | LS   S RS |                              | <<< = undent = Cmd-[           | >>> = indent = Cmd-]            | kpawk = keep awake / mouse jig. |
 * |    tap    |                              | <<t = previous tab = Cmd-{     | >>t = next tab = Cmd-}          | fold = Cmd-k Cmd-<n>            |
 * | L   H   R |                              | tap = tap on layer 0           | hold = on key hold              | S = shift on layer 0            |
 * |    adj    |                              | L = Lower, LS = Lower + Shift  | R = Raise, RS = Raise + Shift   | adj = Adjust (Lower + Raise)    |
 * +-----------+                              +--------------------------------+---------------------------------+---------------------------------+
 *
 */

[_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
    KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    UF_LPRN, KC_EQL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    UF_A,    UF_S,    KC_D,    UF_F,   KC_G,    UF_LBRC, KC_MINS, KC_H,    UF_J,    KC_K,    UF_L,    UF_SCLN,
    UF_Z,    KC_X,    KC_C,    KC_V,   KC_B,    UF_LCBR, KC_QUOT, KC_N,    KC_M,    KC_COMM, KC_DOT,  UF_SLSH,
    UF_ESC,  UF_HOME, UF_PGDN, UF_END, UF_LOWR, UF_SPC,               UF_UPPR, UF_LEFT, UF_DOWN, UF_RIGHT, UF_ENT
),
[_LOWER] = LAYOUT_ortho_4x12_1x2uC(
    KC_ESC , KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_QUOT, UF_FMT , KC_NO  , KC_P7,   KC_P8, KC_P9,   UF_PMNS, // - and |
    KC_TAB , KC_DLR , KC_PERC, KC_CIRC, KC_NO  , UF_UNDT, KC_NO  , UF_PAST, KC_P4,   KC_P5, KC_P6,   UF_PAST, // * and "
    KC_LSFT, KC_EXLM, KC_AT  , KC_HASH, KC_NO  , UF_PTAB, KC_NO  , UF_FOLD, KC_P1,   KC_P2, KC_P3,   UF_PSLS, // /
    _______, _______, _______, _______, _______, _______,              _______, UF_PENT, UF_P0, UF_PDOT, UF_PPLS  // +
),
[_RAISE] = LAYOUT_ortho_4x12_1x2uC(
    KC_ESC , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, UF_LPCB, UF_RPCB, KC_BSLS,
    KC_TAB , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_QUOT,
    UF_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , UF_F12 ,
    _______, _______, KC_PGUP, _______, _______, _______,              _______, _______, KC_UP  , _______, _______
),
[_ADJUST] = LAYOUT_ortho_4x12_1x2uC(
    UF_NAPP, RGB_TOG,  RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_P, B_RGBL_TOG, B_RGBL_MOD,  B_RGBL_HUI, B_RGBL_SAI, B_RGBL_VAI,
    UF_NWIN, _______,  RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_M_B, _______,    B_RGBL_RMOD, B_RGBL_HUD, B_RGBL_SAD, B_RGBL_VAD,
    KC_CAPS,   UF_NLTOG, KC_INS,   _______, _______, _______, _______, _______,    _______,     _______,    UF_MJM_TG,  UF_SCAP,
    _______,   _______,  _______,  _______, _______, _______,              _______,    _______,     _______,    _______,    QK_BOOT
)

};

// clang-format on
