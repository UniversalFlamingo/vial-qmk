/*
 * This is modeled after quantum/caps_word.{c,h}
 */

#include QMK_KEYBOARD_H

#include "rgb_matrix/rgb_matrix.h"
#include "action_layer.h"

#include "uf_numlock.h"
#include "uf_keymap.h"

/** @brief True when numlock is active. */
static bool uf_numlock_active = false;

static uint8_t uf_numlock_animation = RGB_MATRIX_CUSTOM_STAR_LIGHT;
static uint8_t uf_previous_animation = 0;

void uf_numlock_task(void) {
}

void uf_numlock_on(void) {
    if(!uf_numlock_active) {
        uf_previous_animation = rgb_matrix_get_mode();
        rgb_matrix_mode_noeeprom(uf_numlock_animation);
    }
    layer_on(get_tri_layer_lower_layer());
    uf_numlock_active = true;
}

void uf_numlock_off(void) {
    if(uf_numlock_active) {
        rgb_matrix_mode_noeeprom(uf_previous_animation);
    }
    layer_off(get_tri_layer_lower_layer());
    uf_numlock_active = false;
}

void uf_numlock_toggle(void) {
    if(uf_numlock_active) {
        uf_numlock_off();
    } else {
        uf_numlock_on();

    }
}

bool uf_is_numlock_on(void) {
    return uf_numlock_active;
}
