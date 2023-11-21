#include QMK_KEYBOARD_H
#include "config.h"
#include "uf_keycodes.h"
#include "uf_mousejiggler.h"
#include "uf_numlock.h"
#include "uf_process_rgb_keycodes.h"

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

    case B_LLOWR:
      if (record->event.pressed) {
        uf_numlock_toggle();
      }
      return false;
   }

   return uf_process_rgb_keycodes(keycode, record);
}
