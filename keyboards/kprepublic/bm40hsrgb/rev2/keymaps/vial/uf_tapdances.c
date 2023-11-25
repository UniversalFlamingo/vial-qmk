
#include <stddef.h>
#include <stdint.h>

// clang-format off

#include "uf_tapdances.h"

// clang-format on

#include "action.h"
#include "action_tapping.h"
#include "dynamic_keymap.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "process_tap_dance.h"
#include "quantum_keycodes.h"

#ifdef VIAL_ENABLE
#  define UF_TAP_DANCE_ACTIONS uf_tap_dance_actions
#else  //  VIAL_ENABLE
#  define UF_TAP_DANCE_ACTIONS tap_dance_actions
#endif  //  VIAL_ENABLE

tap_dance_action_t UF_TAP_DANCE_ACTIONS[UF_TAP_DANCE_ENTRIES] = {
    [UF_TD_EQUAL] = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_PIPE),
    [UF_TD_MINUS] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_DOUBLE_QUOTE),
    [UF_TD_GRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_QUOTE),
};

#ifdef VIAL_ENABLE
#  include "vial.h"
vial_tap_dance_entry_t uf_vial_tap_dances[UF_TAP_DANCE_ENTRIES] = {
    [UF_TD_EQUAL] = {KC_EQUAL, KC_PIPE, KC_NO, KC_NO, TAPPING_TERM},
    [UF_TD_MINUS] = {KC_MINUS, KC_DOUBLE_QUOTE, KC_NO, KC_NO, TAPPING_TERM},
    [UF_TD_GRAVE] = {KC_GRAVE, KC_QUOTE, KC_NO, KC_NO, TAPPING_TERM},
};
void uf_tap_dance_init(void) {
  int offset = VIAL_TAP_DANCE_ENTRIES - UF_TAP_DANCE_ENTRIES;
  for (int i = 0; i < UF_TAP_DANCE_ENTRIES; ++i) {
    dynamic_keymap_set_tap_dance(i + offset, &uf_vial_tap_dances[i]);
  }
}
#endif
