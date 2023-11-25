
#pragma once

#define UF_TAP_DANCE_ENTRIES 3

enum {
  UF_TD_EQUAL,
  UF_TD_MINUS,
  UF_TD_GRAVE,
};

#ifdef VIAL_ENABLE
void uf_tap_dance_init(void);
#endif
