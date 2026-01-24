#pragma once

#include <stdbool.h>
#include <stdint.h> // for int64_t/int32_t
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Parses an ISO-8601 UTC timestamp into Unix seconds.
 *
 * Converts an ISO-8601 timestamp (UTC) into a Unix timestamp (seconds since the
 * Unix epoch, 1970-01-01T00:00:00Z). If the input contains fractional seconds,
 * the fractional part is returned separately.
 *
 * @param iso8601 Input timestamp string (e.g. `2024-01-01T12:34:56Z` or
 *        `2024-01-01T12:34:56.123Z`).
 * @param[out] out_unix_seconds Output Unix timestamp in seconds.
 * @param[out] out_fraction_ns Output fractional part in nanoseconds (0..999,999,999).
 *
 * @return True on successful parse, false otherwise.
 */
bool time_iso8601_utc_to_unix(const char *iso8601, int64_t *out_unix_seconds, int32_t *out_fraction_ns);

/**
 * @brief Returns the current time as seconds since the Unix epoch.
 *
 * This is a small wrapper around the platform time source used by the project.
 * Primarily used to improve testability (can be stubbed in unit tests).
 *
 * @return Current Unix timestamp in seconds.
 */
time_t now();

#ifdef __cplusplus
}
#endif
