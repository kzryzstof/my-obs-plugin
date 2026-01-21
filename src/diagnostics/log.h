#pragma once

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const char *PLUGIN_NAME;
extern const char *PLUGIN_VERSION;

/* Provided by OBS at link time */
extern void blogva(int log_level, const char *format, va_list args);

void obs_log(int log_level, const char *format, ...);

#ifdef __cplusplus
}
#endif
