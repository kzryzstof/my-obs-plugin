#pragma once

#include <stdbool.h>
#include <stdint.h> // for int64_t
#include <common/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Fetches the current authenticated user's gamerscore.
 *
 * This performs an authenticated request to the Xbox profile settings endpoint
 * and extracts the "Gamerscore" value.
 *
 * @param[out] out_gamerscore Output location for the gamerscore.
 *
 * @return True on success (and @p out_gamerscore is written), false otherwise.
 */
bool xbox_fetch_gamerscore(int64_t *out_gamerscore);

/**
 * @brief Retrieves the game currently being played by the authenticated user.
 *
 * @return Newly allocated @c game_t on success, or NULL if no active game is
 *         detected or on error. The caller owns the returned object and must
 *         free it with @ref free_game.
 */
game_t *xbox_get_current_game(void);

/**
 * @brief Retrieves the list of achievements for a game.
 *
 * @param game Game for which achievements should be fetched (may be NULL).
 *
 * @return Head of a newly allocated linked list of achievements, or NULL on
 *         error. The caller owns the returned list and must free it with
 *         @ref free_achievement.
 */
achievement_t *xbox_get_game_achievements(const game_t *game);

/**
 * @brief Fetches a cover image URL for a given game.
 *
 * @param game Game to fetch the cover for (may be NULL).
 *
 * @return Newly allocated URL string, or NULL if not available or on error.
 *         The caller owns the returned string and must free it.
 */
char *xbox_get_game_cover(const game_t *game);

#ifdef __cplusplus
}
#endif
