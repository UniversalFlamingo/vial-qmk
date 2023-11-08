/*
 * This is modeled after quantum/caps_word.{c,h}
 */

#pragma once

#include <stdbool.h>

#ifndef MOUSEJIGGLER_TIMEOUT
#    define MOUSEJIGGLER_TIMEOUT 30000 // Default timeout of 60 seconds.
#endif
#ifndef MOUSEJIGGLER_MULTIPLIER
#    define MOUSEJIGGLER_MULTIPLIER 10 // Total default timeout of 5 minutes.
#endif

/** @brief Matrix scan task for MouseJiggler feature */
void mousejiggler_task(void);

#if MOUSEJIGGLER_TIMEOUT > 0
/** @brief Resets timer for MouseJiggler idle timeout. */
void mousejiggler_reset_idle_timer(void);
#endif

/** @brief Activates MouseJiggler. */
void mousejiggler_on(void);

/** @brief Deactivates MouseJiggler. */
void mousejiggler_off(void);

/** @brief Toggles MouseJiggler. */
void mousejiggler_toggle(void);

/** @brief Gets whether currently active. */
bool is_mousejiggler_on(void);
