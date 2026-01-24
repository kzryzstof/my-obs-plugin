#include "gamerscore.h"

#include <obs-module.h>

/**
 * @brief Creates a deep copy of a gamerscore object.
 *
 * Duplicates the gamerscore container and deep-copies its linked list of
 * unlocked achievements.
 *
 * @param gamerscore Source gamerscore to copy (may be NULL).
 *
 * @return Newly allocated copy of @p gamerscore, or NULL if @p gamerscore is
 *         NULL. The caller owns the returned object and must free it with
 *         @ref free_gamerscore.
 */
gamerscore_t *copy_gamerscore(const gamerscore_t *gamerscore) {

    if (!gamerscore) {
        return NULL;
    }

    gamerscore_t *copy = bzalloc(sizeof(gamerscore_t));

    copy->base_value            = gamerscore->base_value;
    copy->unlocked_achievements = copy_unlocked_achievement(gamerscore->unlocked_achievements);

    return copy;
}

/**
 * @brief Frees a gamerscore object and sets the caller's pointer to NULL.
 *
 * Frees nested allocations (the unlocked achievements list) and then frees the
 * gamerscore container.
 *
 * Safe to call with NULL or with @c *gamerscore == NULL.
 *
 * @param[in,out] gamerscore Address of the @c gamerscore_t pointer to free.
 */
void free_gamerscore(gamerscore_t **gamerscore) {

    if (!gamerscore || !*gamerscore) {
        return;
    }

    gamerscore_t *current = *gamerscore;
    free_unlocked_achievement(&current->unlocked_achievements);

    bfree(current);
    *gamerscore = NULL;
}

/**
 * @brief Computes the total gamerscore.
 *
 * Returns the base gamerscore plus the sum of values from all unlocked
 * achievements.
 *
 * @param gamerscore Gamerscore container (may be NULL).
 *
 * @return Total gamerscore. Returns 0 if @p gamerscore is NULL.
 */
int gamerscore_compute(const gamerscore_t *gamerscore) {

    if (!gamerscore) {
        return 0;
    }

    int total_value = gamerscore->base_value;

    const unlocked_achievement_t *current = gamerscore->unlocked_achievements;

    while (current) {
        total_value += current->value;
        current = current->next;
    }

    return total_value;
}
