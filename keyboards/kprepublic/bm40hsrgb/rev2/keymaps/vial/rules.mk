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
QMK_SETTINGS = no
MUSIC_ENABLE = no

SRC += my_process_record.c my_process_rgb.c mousejiggler.c

SECURE_ENABLE = no
