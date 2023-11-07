#include QMK_KEYBOARD_H

bool my_process_rgb(const uint16_t keycode, const keyrecord_t *record);
bool my_mouse_jiggler(const uint16_t keycode, const keyrecord_t *record);
void my_mouse_jiggler_matrix_scan();

void matrix_scan_user(void) {
    my_mouse_jiggler_matrix_scan();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if(!my_mouse_jiggler(keycode, record)) { return false; }
    if(!my_process_rgb(keycode, record)) { return false; }

    return true; // Perform default handling
}

