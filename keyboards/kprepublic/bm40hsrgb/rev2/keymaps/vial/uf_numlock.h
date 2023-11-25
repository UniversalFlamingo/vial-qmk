/*
 * This is modeled after quantum/caps_word.{c,h}
 */

#pragma once

#include <stdbool.h>

#include "config.h"

/** @brief Activates numlock. */
void uf_numlock_on(void);

/** @brief Deactivates numlock. */
void uf_numlock_off(void);

/** @brief Toggles numlock. */
void uf_numlock_toggle(void);

/** @brief Gets whether currently active. */
bool uf_is_numlock_on(void);
