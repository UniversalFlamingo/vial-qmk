#include QMK_KEYBOARD_H

// clang-format off

#include "config.h"
#include "uf_key_overrides.h"
#include "uf_keycodes.h"
#include "uf_keymap.h"

// clang-format on

#include "keymap_us.h"
#include "quantum_keycodes.h"

#ifdef UF_KEY_OVERRIDE_ENABLE

#  define L_QWERTY (1 << _QWERTY)
#  define L_LOWER (1 << _LOWER)
#  define L_RAISE (1 << _RAISE)
#  define L_ALL ~0

#  if defined(VIAL_ENABLE) && defined(VIAL_KEY_OVERRIDE_ENABLE)
#    define uf_options_default (ko_options_default | vial_ko_enabled)
#  else
#    define uf_options_default ko_options_default
#  endif

#  define KO(var, trigger_mods, trigger_key, replacement_key, layers) \
    const key_override_t var##_key_override = ko_make_with_layers_negmods_and_options(trigger_mods, trigger_key, replacement_key, layers, 0, uf_options_default)

// Only use this for vanilla KC_* and UF_* that are defined as vanilla KC_*
// In general, map vanilla KC_* that will be overridden to UF_* defines so
// that they are easier to see in the keymap.
// Use UF_* enums and process_record_user for non-vanilla things.

KO(lprn, MOD_MASK_SHIFT, UF_LPRN, KC_RPRN, L_QWERTY);  // Shift ( is )
KO(lbrc, MOD_MASK_SHIFT, UF_LBRC, KC_RBRC, L_QWERTY);  // Shift [ is ]
KO(lcbr, MOD_MASK_SHIFT, UF_LCBR, KC_RCBR, L_QWERTY);  // Shift { is }

KO(psls, MOD_MASK_SHIFT, UF_PMNS, KC_PIPE, L_LOWER);  // Shift numpad - is |
KO(past, MOD_MASK_SHIFT, UF_PAST, KC_DQUO, L_LOWER);  // Shift numpad * is "

KO(lpcb, MOD_MASK_SHIFT, UF_LPRN, KC_LCBR, L_RAISE);  // Shift ( is {
KO(rpcb, MOD_MASK_SHIFT, UF_RPRN, KC_RCBR, L_RAISE);  // Shift ) is }

#  if defined(VIAL_ENABLE) && defined(VIAL_KEY_OVERRIDE_ENABLE)
#    define KEY_OVERRIDES uf_key_overrides
#  else
#    define KEY_OVERRIDES key_overrides
#  endif

const key_override_t** KEY_OVERRIDES = (const key_override_t*[]){

    // L_QWERTY

    &lprn_key_override,
    &lbrc_key_override,
    &lcbr_key_override,

    // L_LOWER (numpad)

    &psls_key_override,
    &past_key_override,

    // L_RAISE

    &lpcb_key_override,
    &rpcb_key_override,

    // all

    // &bspc_key_override,
    // &fspc_key_override,

    NULL,
};

#endif  // UF_KEY_OVERRIDE_ENABLE
