LTO_ENABLE = yes

# Below-PCB solid color lights.
RGBLIGHT_ENABLE = yes
# Per-key RGB lights.
RGB_MATRIX_ENABLE = yes

VIA_ENABLE = yes
VIAL_ENABLE = yes

# Required by the mousejiggler mod.
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = custom

TAP_DANCE_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

# I can do what I need with mod-tap or tap-dance.
# e.g. -- RSFT_T(KC_ENTER)
SPACE_CADET_ENABLE = no

COMBO_ENABLE = no
DYNAMIC_MACRO_ENABLE = no
ENCODER_ENABLE = no
MAGIC_ENABLE = no
MOUSEKEYS_ENABLE = no
MUSIC_ENABLE = no
POINTING_DEVICE_ENABLE = no
QMK_SETTINGS = no
SECURE_ENABLE = no

SRC += process_record.c process_rgb_keycodes.c mousejiggler.c
