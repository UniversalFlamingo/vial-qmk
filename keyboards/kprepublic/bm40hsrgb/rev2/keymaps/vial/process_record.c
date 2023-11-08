#include QMK_KEYBOARD_H
#include "config.h"
#include "custom_keycodes.h"
#include "mousejiggler.h"

bool process_rgb_keycodes(const uint16_t keycode, const keyrecord_t *record);

void matrix_scan_user(void) {
#ifdef MOUSEJIGGLER_ENABLE
    mousejiggler_task();
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case B_MJM_TG:
      if (record->event.pressed) {
        mousejiggler_toggle();
      }
      return false;
   }

   return process_rgb_keycodes(keycode, record);
}
