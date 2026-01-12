#pragma once

#include "common/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void io_load(void);

device_t *state_get_device(void);

const char *get_xid(void);
const char *get_xsts_token(void);

void     state_set_user_token(const token_t *user_token);
token_t *state_get_user_token(void);

void     state_set_device_token(const token_t *device_token);
token_t *state_get_device_token(void);

void     state_set_sisu_token(const token_t *sisu_token);
token_t *state_get_sisu_token(void);

void state_clear(void);

void state_set_tokens(const char *xid, const char *token);

#ifdef __cplusplus
}
#endif
