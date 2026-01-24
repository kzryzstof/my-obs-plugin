#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Linked-list node describing an unlocked achievement and its value.
 *
 * This type is used as a singly-linked list via @c next.
 *
 * Ownership:
 * - Instances returned by @ref copy_unlocked_achievement are owned by the caller
 *   and must be freed with @ref free_unlocked_achievement.
 * - @c id is deep-copied by @ref copy_unlocked_achievement and freed by
 *   @ref free_unlocked_achievement.
 */
typedef struct unlocked_achievement {
    /** Achievement id. */
    const char                  *id;
    /** Gamerscore value contributed by this unlocked achievement. */
    int                          value;
    /** Next node in the list, or NULL. */
    struct unlocked_achievement *next;
} unlocked_achievement_t;

/**
 * @brief Deep-copies a linked list of unlocked achievements.
 *
 * @param unlocked_achievement Head of the source list (may be NULL).
 *
 * @return Head of the newly allocated list, or NULL if @p unlocked_achievement
 *         is NULL. The caller owns the returned list and must free it with
 *         @ref free_unlocked_achievement.
 */
unlocked_achievement_t *copy_unlocked_achievement(const unlocked_achievement_t *unlocked_achievement);

/**
 * @brief Frees a linked list of unlocked achievements and sets the caller's pointer to NULL.
 *
 * Safe to call with NULL or with @c *unlocked_achievement == NULL.
 *
 * @param[in,out] unlocked_achievement Address of the head pointer to free.
 */
void free_unlocked_achievement(unlocked_achievement_t **unlocked_achievement);

#ifdef __cplusplus
}
#endif
