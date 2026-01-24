#pragma once

#ifdef _WIN32
#include <rpc.h>
#else
#include <uuid/uuid.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Generates a random UUID (version 4) as a string.
 *
 * Writes a NUL-terminated UUID string in the canonical format:
 * `xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx`
 *
 * Buffer requirements:
 * - @p random_uuid must point to a writable buffer of at least 37 bytes
 *   (36 characters + terminating NUL).
 *
 * @param[out] random_uuid Output buffer that receives the UUID string.
 */
void uuid_get_random(char random_uuid[37]);

#ifdef __cplusplus
}
#endif
