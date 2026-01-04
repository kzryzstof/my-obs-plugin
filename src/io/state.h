#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void io_load(void);

const char* get_xsts_token(void);

void set_xsts_token(const char*);

#ifdef __cplusplus
}
#endif
