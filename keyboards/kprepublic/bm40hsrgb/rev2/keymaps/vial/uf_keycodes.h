
#pragma once

// clang-format off

#include "config.h"
#include "uf_tapdances.h"

// clang-format on

#include "keycodes.h"

#ifdef VIAL_ENABLE
// See vial-gui/src/main/python/keycodes/keycodes_v6.py
// Map custom keycodes to vial's USER00 ...
#  define KB_SAFE_RANGE QK_KB_0
#else
#  define KB_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  UF_MJM_TG = KB_SAFE_RANGE,  // toggle mouse-jiggle mode

  UF_LLOWR,  // Lock Lower Layer
  UF_LUPPR,  // Lock Upper Layer

  UF_NLTOG,  // Toggle numlock (on lower layer)

  // B_RGBL_TG,           // rgblight_toggle_noeeprom   -- LEDs below the PCB (i.e. - underlight)
  // B_RGBM_TG,           // rgb_matrix_toggle_noeeprom -- per-key LEDs

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

// vscode  shortcuts
#define UF_FMT S(A(KC_F))     // Shift-Alt-F -- Format code
#define UF_NET S(G(KC_RBRC))  // Shift-Gui-] (Shift-Cmd-]) -- Next editor/browser/iTerm tab
#define UF_PET S(G(KC_LBRC))  // Shift-Gui-] ^--- previous
#define UF_NAPP G(KC_TAB)     // Gui-Tab (Cmd-Tab) -- Next App
#define UF_NWIN G(KC_GRV)     // Gui-` (Cmd-`) -- Next Window of App
