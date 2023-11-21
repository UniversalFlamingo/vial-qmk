#include QMK_KEYBOARD_H

// clang-format off

#include "config.h"
#include "uf_keycodes.h"
#include "uf_mousejiggler.h"
#include "uf_numlock.h"
#include "uf_process_rgb_keycodes.h"

// clang-format on

#include <stdint.h>

#include "action.h"

void matrix_scan_user(void) {
#ifdef MOUSEJIGGLER_ENABLE
  uf_mousejiggler_task();
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case B_MJM_TG:
      if (record->event.pressed) {
        uf_mousejiggler_toggle();
      }
      return false;

    case B_NLTOG:
      if (record->event.pressed) {
        uf_numlock_toggle();
      }
      return false;

    case QK_TRI_LAYER_LOWER:
      if (!record->event.pressed) {
        uf_numlock_off();
      }
  }

  return uf_process_rgb_keycodes(keycode, record);
}
