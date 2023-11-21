#ifdef ENABLE_RGB_MATRIX_NUMLOCK
#  define RGB_MATRIX_EFFECT_NUMLOCK

   RGB_MATRIX_EFFECT(NUMLOCK)

#  ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

    bool NUMLOCK(effect_params_t* params) {
        if (!params->init) {
            return false;
        }

        const uint8_t max_cols = MATRIX_COLS - 4;
        const uint8_t intensity = rgb_matrix_config.hsv.v / 2;

        for (uint8_t col = 0; col < max_cols; col++) {
            for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
                g_rgb_frame_buffer[row][col] = intensity;
            }
        }

        return false;
    }

#  endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif    // ENABLE_RGB_MATRIX_NUMLOCK
