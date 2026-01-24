#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Registers the "Xbox Account" OBS source.
 *
 * This connects the source implementation with OBS so it becomes available in
 * the "Sources" list. It should be called once during plugin/module startup.
 */
void xbox_account_source_register(void);

#ifdef __cplusplus
}
#endif
