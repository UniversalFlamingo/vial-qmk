
#include QMK_KEYBOARD_H

#include <stdbool.h>
#include <stdint.h>

// clang-format off

#include "config.h"
#include "uf_keycodes.h"
#include "uf_mousejiggler.h"
#include "uf_numlock.h"
#include "uf_process_rgb_keycodes.h"

// clang-format on

#include "action.h"
#include "action_util.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include "vial_ensure_keycode.h"

void matrix_scan_user(void) {
#ifdef MOUSEJIGGLER_ENABLE
  uf_mousejiggler_task();
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t shifted = get_mods() & MOD_MASK_SHIFT;
  switch (keycode) {
    case UF_MJM_TG:
      if (record->event.pressed) {
        uf_mousejiggler_toggle();
      }
      return false;

    case UF_NLTOG:
      if (record->event.pressed) {
        uf_numlock_toggle();
      }
      return false;

    case UF_BRC:
      if (record->event.pressed) {
        tap_code(shifted ? KC_RBRC : KC_LBRC);
      }
      return false;

    case UF_CBR:
      if (record->event.pressed) {
        tap_code16(shifted ? KC_RCBR : KC_LCBR);
      }
      return false;

    case UF_PRN:
      if (record->event.pressed) {
        tap_code16(shifted ? KC_RPRN : KC_LPRN);
      }
      return false;

    case UF_DBS:
      if (record->event.pressed) {
        tap_code(shifted ? KC_DELETE : KC_BACKSPACE);
      }

      return false;

    case QK_TRI_LAYER_LOWER:
      if (!record->event.pressed && uf_is_numlock_on()) {
        return false;
      }
  }

  return uf_process_rgb_keycodes(keycode, record);
}
