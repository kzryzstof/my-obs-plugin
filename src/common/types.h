#pragma once

#include <openssl/evp.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Device {
    /* unique identifier for the device */
    const char     *uuid;
    /* proof of ownership key pair */
    const EVP_PKEY *keys;
} Device;

#ifdef __cplusplus
}
#endif
