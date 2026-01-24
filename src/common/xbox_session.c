#include "common/xbox_session.h"

#include <obs-module.h>

/**
 * @brief Creates a deep copy of an Xbox session.
 *
 * Performs a deep copy of the session container and its nested objects:
 * game, gamerscore, and achievements.
 *
 * @param session Source session to copy (may be NULL).
 *
 * @return Newly allocated copy of @p session, or NULL if @p session is NULL.
 *         The caller owns the returned object and must free it with
 *         @ref free_xbox_session.
 */
xbox_session_t *copy_xbox_session(const xbox_session_t *session) {

    if (!session) {
        return NULL;
    }

    xbox_session_t *copy = bzalloc(sizeof(xbox_session_t));
    copy->game           = copy_game(session->game);
    copy->gamerscore     = copy_gamerscore(session->gamerscore);
    copy->achievements   = copy_achievement(session->achievements);

    return copy;
}

/**
 * @brief Frees an Xbox session and sets the caller's pointer to NULL.
 *
 * Frees nested allocations (game, gamerscore, achievements) and then frees the
 * session container.
 *
 * Safe to call with NULL or with @c *session == NULL.
 *
 * @param[in,out] session Address of the @c xbox_session_t pointer to free.
 */
void free_xbox_session(xbox_session_t **session) {

    if (!session || !*session) {
        return;
    }

    xbox_session_t *current = *session;

    free_game(&current->game);
    free_gamerscore(&current->gamerscore);
    free_achievement(&current->achievements);

    bfree(current);
    *session = NULL;
}

/**
 * @brief Computes the total gamerscore for a session.
 *
 * Delegates to @ref gamerscore_compute using the session's gamerscore data.
 *
 * @param session Session to compute gamerscore for (may be NULL).
 *
 * @return Total gamerscore for the session. Returns 0 if @p session is NULL.
 */
int xbox_session_compute_gamerscore(const xbox_session_t *session) {

    if (!session) {
        return 0;
    }

    return gamerscore_compute(session->gamerscore);
}
