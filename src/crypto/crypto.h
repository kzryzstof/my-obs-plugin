#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* OpenSSL key generation helpers. */
#include <openssl/evp.h>

/* Generate an EC P-256 keypair. Caller must EVP_PKEY_free(). */
EVP_PKEY *crypto_generate_p256_keypair(void);

char* crypto_key_to_string(
	EVP_PKEY *pkey
);

#ifdef __cplusplus
}
#endif
