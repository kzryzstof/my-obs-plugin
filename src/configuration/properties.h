#pragma once

#include <obs-module.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Returns the obs_source_info descriptor for this source type.
 *
 * Note: The returned pointer is to static storage and must not be freed.
 */
const struct obs_source_info *get_plugin_properties(void);

#ifdef __cplusplus
}
#endif

