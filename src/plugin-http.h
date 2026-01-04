#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Tiny HTTP helpers (libcurl + OBS memory helpers).
 *
 * All returned strings are allocated with bzalloc/bstrdup and must be freed with bfree().
 */

char *plugin_http_post_form(const char *url, const char *postfields, long *out_http_code);

char *plugin_http_post_json(
	const char *url,
	const char *json_body,
	const char *extra_header,
	long *out_http_code);

char *plugin_http_urlencode(const char *in);

/*
 * Minimal JSON string value getter used by auth flows.
 * NOTE: This is not a full JSON parser; it expects a flat key:"value" pattern.
 */
char *plugin_json_get_string_value(const char *json, const char *key);

#ifdef __cplusplus
}
#endif

