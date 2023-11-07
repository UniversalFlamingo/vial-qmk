#include QMK_KEYBOARD_H

#include "config.h"
#include "custom_keycodes.h"

static bool mouse_jiggle_mode = false;
static uint16_t mouse_jiggle_timer = 0;

// See https://github.com/qmk/qmk_firmware/blob/master/docs/feature_pointing_device.md#custom-driver
/*
 * Create a fake pointing device. This uses less space than MOUSEKEY_ENABLE.
 * Add to rules.mk:
 *  POINTING_DEVICE_ENABLE = yes
 *  POINTING_DEVICE_DRIVER = custom
 */
void           pointing_device_driver_init(void) {}
report_mouse_t pointing_device_driver_get_report(report_mouse_t mouse_report) { return mouse_report; }
uint16_t       pointing_device_driver_get_cpi(void) { return MOUSE_JIGGLER_CPI; }
void           pointing_device_driver_set_cpi(uint16_t cpi) {}

void my_mouse_jiggler_matrix_scan(void) {

  if(!mouse_jiggle_mode) { return; }
  if(!mouse_jiggle_timer) { return; }

  // See https://getreuer.info/posts/keyboards/triggers/#when-idle-for-x-milliseconds
  uint16_t timer = timer_read();
  if (!timer_expired(timer, mouse_jiggle_timer)) { return; }

  // If execution reaches here, the keyboard has gone idle. Increment the timer.
  mouse_jiggle_timer = (mouse_jiggle_timer + MOUSE_JIGGLE_TIMEOUT_MS) | 1;

  // Turn on underglow LEDs.
  rgblight_enable_noeeprom();

  // See https://github.com/DIYCharles/MouseJiggler/
  tap_code(KC_MS_UP);
  tap_code(KC_MS_DOWN);
  tap_code(KC_MS_LEFT);
  tap_code(KC_MS_RIGHT);
  tap_code(KC_MS_WH_UP);
  tap_code(KC_MS_WH_DOWN);
}

bool my_mouse_jiggler(const uint16_t keycode, const keyrecord_t *record) {

  if(B_MJM_TG != keycode) { return true; }

  if (record->event.pressed) {
    mouse_jiggle_mode = !mouse_jiggle_mode;
    if(mouse_jiggle_mode) {
        rgblight_enable_noeeprom();
    }
    else {
        rgblight_disable_noeeprom();
    }
  }

  // On every key event, set mouse_jiggle_timer to expire after MOUSE_JIGGLE_TIMEOUT_MS.
  // We use mouse_jiggle_timer == 0 to indicate that the timer is inactive, so
  // the value is bitwise or'd with 1 to ensure it is nonzero.
  // See https://github.com/DIYCharles/MouseJiggler/
  if(mouse_jiggle_mode) {
    mouse_jiggle_timer = (record->event.time + MOUSE_JIGGLE_TIMEOUT_MS) | 1;
  }

  return false; // Skip default handling

}
