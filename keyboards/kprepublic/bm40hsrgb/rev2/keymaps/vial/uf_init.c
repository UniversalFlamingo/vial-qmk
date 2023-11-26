
// clang-format off

#include "config.h"

// clang-format on

#include "color.h"
#include "rgb_matrix.h"
#include "rgblight.h"

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
}
