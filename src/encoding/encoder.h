#pragma once

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

char *encode_base64(const uint8_t *data, size_t len);

#ifdef __cplusplus
}
#endif
