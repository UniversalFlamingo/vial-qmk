
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
  if (!uf_process_rgb_keycodes(keycode, record)) {
    return false;
  }

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

    case QK_TRI_LAYER_LOWER:
      if (record->event.pressed) {
        uf_numlock_on();
      }
      else if (!uf_is_numlock_on()) {
        uf_numlock_off();
      }
  }

  return true;
}
