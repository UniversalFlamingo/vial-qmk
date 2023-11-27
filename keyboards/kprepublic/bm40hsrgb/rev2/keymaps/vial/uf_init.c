
// clang-format off

#include "config.h"

// clang-format on

#include "color.h"
#include "rgb_matrix.h"
#include "rgblight.h"

#ifdef VIAL_ENABLE
#  include "vial.h"
#  ifdef VIAL_KEY_OVERRIDE_ENABLE
extern const key_override_t **uf_key_overrides;
#  endif
#endif

void keyboard_post_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
  rgb_matrix_enable_noeeprom();
  rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
  rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
#endif

#ifdef RGBLIGHT_ENABLE
  rgblight_enable_noeeprom();  // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_YELLOW);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
#endif

#if defined(VIAL_ENABLE) && defined(VIAL_KEY_OVERRIDE_ENABLE)
  for (size_t i = 0; uf_key_overrides[i] && i < VIAL_KEY_OVERRIDE_ENTRIES; ++i) {
    key_overrides[i] = uf_key_overrides[i];
  }
#endif
}
