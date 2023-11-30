#include QMK_KEYBOARD_H

// clang-format off

#include "config.h"
#include "uf_key_overrides.h"
#include "uf_keymap.h"

// clang-format on

#include "keymap_us.h"
#include "quantum_keycodes.h"

#ifdef UF_KEY_OVERRIDE_ENABLE

#  define L_QWERTY (1 << _QWERTY)
#  define L_LOWER (1 << _LOWER)
#  define L_ALL ~0

#  if defined(VIAL_ENABLE) && defined(VIAL_KEY_OVERRIDE_ENABLE)
#    define uf_options_default (ko_options_default | vial_ko_enabled)
#  else
#    define uf_options_default ko_options_default
#  endif

#  define KO(var, trigger_mods, trigger_key, replacement_key, layers) \
    const key_override_t var##_key_override = ko_make_with_layers_negmods_and_options(trigger_mods, trigger_key, replacement_key, layers, 0, uf_options_default)

KO(lprn, MOD_MASK_SHIFT, KC_LPRN, KC_RPRN, L_QWERTY);  // Shift ( is )
KO(lbrc, MOD_MASK_SHIFT, KC_LBRC, KC_RBRC, L_QWERTY);  // Shift [ is ]
KO(lcbr, MOD_MASK_SHIFT, KC_LCBR, KC_RCBR, L_QWERTY);  // Shift { is }

KO(psls, MOD_MASK_SHIFT, KC_PSLS, KC_PIPE, L_LOWER);  // Shift numpad / is |
KO(past, MOD_MASK_SHIFT, KC_PAST, KC_DQUO, L_LOWER);  // Shift numpad * is "
KO(ppls, MOD_MASK_SHIFT, KC_PPLS, KC_END, L_LOWER);   // Shift numpad + is End
KO(pdot, MOD_MASK_SHIFT, KC_PDOT, KC_PGUP, L_LOWER);  // Shift numpad . is PgUp
KO(pzer, MOD_MASK_SHIFT, KC_P0, KC_PGDN, L_LOWER);    // Shift numpad 0 is PgDn

// KO(bspc, MOD_MASK_SHIFT, KC_BSPC, KC_DEL, L_ALL);   // Shift BackSpace is Delete
// KO(fspc, MOD_MASK_SHIFT, KC_SPACE, KC_DEL, L_ALL);  // Shift (Forward)Space is Delete

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
    &ppls_key_override,
    &pdot_key_override,
    &pzer_key_override,

    // all

    // &bspc_key_override,
    // &fspc_key_override,

    NULL,
};

#endif  // UF_KEY_OVERRIDE_ENABLE
