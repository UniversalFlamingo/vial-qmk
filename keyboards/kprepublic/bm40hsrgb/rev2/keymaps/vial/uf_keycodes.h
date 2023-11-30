
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

// clang-format off

// Raise / Lower
// These are intercepted in uf_process_record.
#define UF_LOWR    LT(0,KC_DOWN)  // Send Backspace on tap, Delete on shift-tap, TL_LOWR on hold
#define UF_UPPR    LT(0,KC_UP)    // Send Enter on tap, TL_UPPR on hold

// _QWERTY

#define UF_Z        LSFT_T(KC_Z)
#define UF_SLSH     RSFT_T(KC_SLSH)

#define UF_HOME     LCTL_T(KC_HOME)
#define UF_PGDN     LOPT_T(KC_PGDN)
#define UF_PGUP     KC_PGUP
#define UF_END      LCMD_T(KC_END)

#define UF_LEFT     RCMD_T(KC_LEFT)
#define UF_DOWN     KC_DOWN
#define UF_UP       ROPT_T(KC_UP)
#define UF_RIGHT    RCTL_T(KC_RIGHT)

// _LOWER

#define UF_PMNS     RSFT_T(KC_PMNS)

#define UF_PENT     RCMD_T(KC_PENT)
#define UF_P0       KC_P0
#define UF_PDOT     ROPT_T(KC_PDOT)
#define UF_PPLS     RCTL_T(KC_PPLS)

// _RAISE

#define UF_F1       LSFT_T(KC_F1)
#define UF_F12      RSFT_T(KC_F12)

// vscode & macos shortcuts

#define UF_FMT     S(A(KC_F))     // Shift-Alt-F -- Format code
#define UF_PET     S(G(KC_LBRC))  // Shift-Cmd-[ -- Previous editor/browser/iTerm tab
#define UF_NET     S(G(KC_RBRC))  // Shift-Cmd-] -- Next editor/browser/iTerm tab
#define UF_SCAP    S(G(KC_4))     // Shift-Cmd-4 -- Capture a portion of the screen

// UF_NAPP doesn't work as desired because the OS expects CMD to be held across one or more TABs.
// Tapping CMD+TAB effectively toggles between the two most current apps.
// #define UF_NAPP    LCMD(KC_TAB)   // Cmd-Tab     -- Next App
// #define UF_NWIN    LCMD(KC_GRV)   // Cmd-`       -- Next Window of App

// clang-format on
