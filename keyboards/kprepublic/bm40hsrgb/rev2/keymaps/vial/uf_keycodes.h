#include QMK_KEYBOARD_H

#include "config.h"
#include "keycodes.h"

#ifdef VIAL_ENABLE
// See vial-gui/src/main/python/keycodes/keycodes_v6.py
// Map custom keycodes to vial's USER00 ...
#  define KB_SAFE_RANGE QK_KB_0
#else
#  define KB_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  B_MJM_TG = KB_SAFE_RANGE,  // toggle mouse-jiggle mode

  B_LLOWR,  // Lock Lower Layer
  B_LUPPR,  // Lock Upper Layer

  B_NLTOG,  // Toggle numlock (on lower layer)

  UF_PRN,  // KC_LPRN and KC_RPRN
  UF_BRC,  // KC_LBRC and KC_RBRC
  UF_CBR,  // KC_LCBR and KC_RCBR

  UF_EQL,   // KC_EQL,  | on double-tap
  UF_MINS,  // KC_MINS, " on double-tap
  UF_GRV,   // KC_GRV,  ' on double-tap

  UF_DBS,   // KC_BSPC and KC_DEL

  //   B_RGBL_TG,           // rgblight_toggle_noeeprom   -- LEDs below the PCB (i.e. - underlight)
  //   B_RGBM_TG,           // rgb_matrix_toggle_noeeprom -- per-key LEDs

  // underlight equivalents of the matrix keycodes.
  B_RGBL_TOG,
  B_RGBL_MOD,   // MODE_FORWARD,
  B_RGBL_RMOD,  // MODE_REVERSE,
  B_RGBL_HUI,
  B_RGBL_HUD,
  B_RGBL_SAI,
  B_RGBL_SAD,
  B_RGBL_VAI,
  B_RGBL_VAD,
  B_RGBL_SPI,
  B_RGBL_SPD,
  B_RGBL_M_P,  // MODE_PLAIN
  B_RGBL_M_B,  // MODE_BREATHE
  // B_RGBL_M_T,  // MODE_RGBTEST
};
