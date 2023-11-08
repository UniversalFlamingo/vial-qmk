/*
 * This is modeled after quantum/caps_word.{c,h}
 */

#include QMK_KEYBOARD_H

#include <stdint.h>
#include "timer.h"
#include "action.h"
#include "action_util.h"

#include "config.h"
#include "custom_keycodes.h"
#include "mousejiggler.h"

/** @brief True when MouseJiggler is active. */
static bool mousejiggler_active = false;

#if MOUSEJIGGLER_TIMEOUT > 0
#    if MOUSEJIGGLER_TIMEOUT < 100 || MOUSEJIGGLER_TIMEOUT > 30000
#        error "MOUSEJIGGLER_TIMEOUT must be between 100 and 60000 ms"
#    endif
#    if MOUSEJIGGLER_MULTIPLIER < 1 || MOUSEJIGGLER_MULTIPLIER > 60
#        error "MOUSEJIGGLER_MULTIPLIER must be between 1 and 60"
#    endif

/** @brief Deadline for idle timeout. */
static uint16_t idle_timer = 0;
static uint8_t multiplier = 0;

static void mousejiggler_send_keepalive(void) {

    // Turn on underglow LEDs.
    rgblight_enable_noeeprom();

    tap_code(KC_CAPS);
    tap_code(KC_NUM);
    _delay_ms(TAP_HOLD_CAPS_DELAY);
    tap_code(KC_CAPS);
    tap_code(KC_NUM);

}

void mousejiggler_task(void) {
    if(mousejiggler_active && timer_expired(timer_read(), idle_timer)) {
      if(!multiplier) { mousejiggler_send_keepalive(); }
      mousejiggler_reset_idle_timer();
    }
}

#else
void mousejiggler_task(void) {}
#endif // MOUSEJIGGLER_TIMEOUT > 0

void mousejiggler_reset_idle_timer(void) {
    if(multiplier) {
      multiplier -= 1;
    } else {
      multiplier = MOUSEJIGGLER_MULTIPLIER - 1;
    }
    idle_timer = (timer_read() + MOUSEJIGGLER_TIMEOUT) | 1;
}

void mousejiggler_on(void) {
#if MOUSEJIGGLER_TIMEOUT > 0
    rgblight_enable_noeeprom();
    if(!mousejiggler_active) {
        multiplier = MOUSEJIGGLER_MULTIPLIER - 1;
        mousejiggler_reset_idle_timer();
    }
#endif // MOUSEJIGGLER_TIMEOUT > 0
    mousejiggler_active = true;
}

void mousejiggler_off(void) {
#if MOUSEJIGGLER_TIMEOUT > 0
    rgblight_disable_noeeprom();
#endif // MOUSEJIGGLER_TIMEOUT > 0
    mousejiggler_active = false;
}

void mousejiggler_toggle(void) {
    if(mousejiggler_active) {
        mousejiggler_off();
    } else {
        mousejiggler_on();
    }
}

bool is_mousejiggler_on(void) {
    return mousejiggler_active;
}
