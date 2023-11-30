
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
#include "process_tri_layer.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include "vial_ensure_keycode.h"

void matrix_scan_user(void) {
#ifdef MOUSEJIGGLER_ENABLE
  uf_mousejiggler_task();
#endif
}

void uf_handle_tri_layer_lower(keyrecord_t *record) {
  if (record->event.pressed) {
    uf_numlock_on();
  } else /* if (!uf_is_numlock_on()) */ {
    uf_numlock_off();
  }
}

void uf_magic_backspace(uint16_t trigger_keycode, uint16_t on_tap_keycode, keyrecord_t *record) {
  uint8_t mods = get_mods() | get_weak_mods();
  uint8_t shifted = mods & MOD_MASK_SHIFT;

  if (record->event.pressed) {
    return;
  }

  if (trigger_keycode != KC_NO) {
    unregister_code(trigger_keycode);
  }

  if (shifted == MOD_MASK_SHIFT) {
    // l_shift + r_shift + tap sends delete with shift enabled (i.e. -- delete line)
    tap_code(KC_DELETE);
  } else if (shifted) {
    // one shift key + tap sends delete without shift enabled (i.e. -- regular delete)
    del_mods(MOD_MASK_SHIFT);
    tap_code(KC_DELETE);
  } else {
    // tap sends keycode
    tap_code(on_tap_keycode);
  }
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

    case KC_BSPC:
      uf_magic_backspace(keycode, keycode, record);
      return false;

    case KC_SPACE:
      uf_magic_backspace(keycode, keycode, record);
      return false;

    case UF_LOWR:
      unregister_code(keycode);
      if (record->tap.count) {
        // On tap
        uf_magic_backspace(KC_NO, KC_BSPC, record);
      } else {
        // on hold
        process_tri_layer(QK_TRI_LAYER_LOWER, record);
        uf_handle_tri_layer_lower(record);
      }
      return false;

    case UF_UPPR:
      unregister_code(keycode);
      if (record->tap.count) {
        if (record->event.pressed) {
          tap_code(KC_ENTER);
        }
      } else {
        process_tri_layer(QK_TRI_LAYER_UPPER, record);
      }
      return false;

    // case QK_TRI_LAYER_LOWER:
    //   uf_handle_tri_layer_lower(record);
  }

  return true;
}
