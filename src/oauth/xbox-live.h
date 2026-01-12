#pragma once

#include <stdbool.h>

#include "common/types.h"

#ifdef __cplusplus
extern "C" {
#endif

bool xbox_live_get_authenticate(const device_t *device);

#ifdef __cplusplus
}
#endif
