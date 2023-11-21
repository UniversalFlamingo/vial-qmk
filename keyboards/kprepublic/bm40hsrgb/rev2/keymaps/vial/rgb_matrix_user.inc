#ifdef ENABLE_RGB_MATRIX_STAR_LIGHT
#   define RGB_MATRIX_EFFECT_STAR_LIGHT
RGB_MATRIX_EFFECT(STAR_LIGHT)
#   ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool STAR_LIGHT(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, rgb.r * 2, rgb.g * 2, rgb.b * 2);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#   endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif    // ENABLE_RGB_MATRIX_STAR_LIGHT
