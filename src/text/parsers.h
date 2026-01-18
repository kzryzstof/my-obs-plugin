#pragma once
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

bool is_presence_message(const char *json_string);

bool is_achievement_message(const char *json_string);

#ifdef __cplusplus
}
#endif
