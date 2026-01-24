#include "xbox_identity.h"

#include "memory.h"

/**
 * @brief Creates a deep copy of an Xbox identity.
 *
 * Allocates a new @c xbox_identity_t and duplicates all string fields. The token
 * is also deep-copied.
 *
 * @param identity Source identity to copy (may be NULL).
 *
 * @return Newly allocated copy of @p identity, or NULL if @p identity is NULL.
 *         The caller owns the returned object and must free it with
 *         @ref free_identity.
 */
xbox_identity_t *copy_xbox_identity(const xbox_identity_t *identity) {

    if (!identity) {
        return NULL;
    }

    xbox_identity_t *copy = bzalloc(sizeof(xbox_identity_t));
    copy->gamertag        = bstrdup(identity->gamertag);
    copy->xid             = bstrdup(identity->xid);
    copy->uhs             = bstrdup(identity->uhs);
    copy->token           = copy_token(identity->token);

    return copy;
}

/**
 * @brief Frees an Xbox identity and sets the caller's pointer to NULL.
 *
 * Frees all internal allocations (strings and token) and then frees the
 * @c xbox_identity_t object itself.
 *
 * Safe to call with NULL or with @c *identity == NULL.
 *
 * @param[in,out] identity Address of the @c xbox_identity_t pointer to free.
 */
void free_identity(xbox_identity_t **identity) {

    if (!identity || !*identity) {
        return;
    }

    xbox_identity_t *current = *identity;

    free_memory((void **)&current->gamertag);
    free_memory((void **)&current->xid);
    free_memory((void **)&current->uhs);
    free_token((token_t **)&current->token);

    bfree(current);
    *identity = NULL;
}
