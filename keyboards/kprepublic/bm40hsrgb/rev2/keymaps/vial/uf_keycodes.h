#include QMK_KEYBOARD_H

#include "config.h"

#ifdef VIAL_ENABLE
  // See vial-gui/src/main/python/keycodes/keycodes_v6.py
  // Map custom keycodes to vial's USER00 ...
#  define   KB_SAFE_RANGE   QK_KB_0
#else
#  define   KB_SAFE_RANGE   SAFE_RANGE
#endif

enum custom_keycodes {
#ifdef VIAL_ENABLE
  // See vial-gui/src/main/python/keycodes/keycodes_v6.py
  // Map custom keycodes to vial's USER00 ...
  B_MJM_TG = KB_SAFE_RANGE,  // toggle mouse-jiggle mode
#else
  B_MJM_TG = SAFE_RANGE,  // toggle mouse-jiggle mode
#endif
  // numlock TO(1) & toggle rgb
  B_LLOWR,
  B_LUPPR,

//   B_RGBL_TG,           // rgblight_toggle_noeeprom   -- LEDs below the PCB (i.e. - underlight)
//   B_RGBM_TG,           // rgb_matrix_toggle_noeeprom -- per-key LEDs

  // underlight equivalents of the matrix keycodes.
  B_RGBL_TOG,
  B_RGBL_MOD,  // MODE_FORWARD,
  B_RGBL_RMOD, // MODE_REVERSE,
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
