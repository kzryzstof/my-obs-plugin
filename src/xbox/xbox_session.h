#pragma once

#include "common/types.h"

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Checks whether the session is currently associated with the given game.
 *
 * Typically used to detect when the user has started playing a different title.
 *
 * @param session Session to inspect.
 * @param game Game to compare against.
 *
 * @return True if the session's current game matches @p game, false otherwise.
 */
bool xbox_session_is_game_played(xbox_session_t *session, const game_t *game);

/**
 * @brief Updates the session to use a new current game.
 *
 * Implementations typically free/replace the previous @c session->game and reset
 * cached session state derived from that game (e.g., achievements list and
 * gamerscore).
 *
 * @param session Session to update.
 * @param game New game to set for this session.
 */
void xbox_session_change_game(xbox_session_t *session, game_t *game);

/**
 * @brief Applies an unlock/progress update to the session.
 *
 * Updates the session state (achievement list, unlocked achievements, gamerscore
 * deltas, etc.) based on the provided progress event.
 *
 * @param session Session to update.
 * @param progress Progress information for the achievement being unlocked.
 */
void xbox_session_unlock_achievement(const xbox_session_t *session, const achievement_progress_t *progress);

#ifdef __cplusplus
}
#endif
