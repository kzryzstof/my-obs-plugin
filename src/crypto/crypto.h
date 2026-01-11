#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <openssl/evp.h>
#include <stdint.h>

EVP_PKEY *crypto_generate_key(void);

void crypto_print_key(EVP_PKEY *pkey);

char     *crypto_to_string(EVP_PKEY *pkey);
EVP_PKEY *crypto_from_string(const char *key_json);

uint8_t *crypto_sign(EVP_PKEY *private_key, const char *url, const char *authorization_token, const char *payload,
                     size_t *out_len);

#ifdef __cplusplus
}
#endif
