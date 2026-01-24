#include "unlocked_achievement.h"
#include "memory.h"
#include <obs-module.h>

/**
 * @brief Deep-copies a linked list of unlocked achievements.
 *
 * Allocates a new list where each node is duplicated and the @c id string is
 * copied. The returned list is independent from the input list.
 *
 * @param unlocked_achievement Head of the source @c unlocked_achievement_t linked
 *        list (may be NULL).
 *
 * @return Head of the newly allocated list, or NULL if @p unlocked_achievement is
 *         NULL. The caller owns the returned list and must free it with
 *         @ref free_unlocked_achievement.
 */
unlocked_achievement_t *copy_unlocked_achievement(const unlocked_achievement_t *unlocked_achievement) {

    if (!unlocked_achievement) {
        return NULL;
    }

    unlocked_achievement_t *root_copy     = NULL;
    unlocked_achievement_t *previous_copy = NULL;

    const unlocked_achievement_t *current = unlocked_achievement;

    while (current) {
        const unlocked_achievement_t *next = current->next;

        unlocked_achievement_t *copy = bzalloc(sizeof(unlocked_achievement_t));

        copy->id    = bstrdup(current->id);
        copy->value = current->value;

        if (previous_copy) {
            previous_copy->next = copy;
        }

        previous_copy = copy;
        current       = next;

        if (!root_copy) {
            root_copy = copy;
        }
    }

    return root_copy;
}

/**
 * @brief Frees a linked list of unlocked achievements and sets the caller's pointer to NULL.
 *
 * Frees each node's internal allocations (currently @c id) and then the node
 * itself.
 *
 * Safe to call with NULL or with @c *unlocked_achievement == NULL.
 *
 * @param[in,out] unlocked_achievement Address of the head pointer to free.
 */
void free_unlocked_achievement(unlocked_achievement_t **unlocked_achievement) {

    if (!unlocked_achievement || !*unlocked_achievement) {
        return;
    }

    unlocked_achievement_t *current = *unlocked_achievement;

    while (current) {

        unlocked_achievement_t *next = current->next;

        free_memory((void **)&current->id);
        free_memory((void **)&current);

        current = next;
    }

    *unlocked_achievement = NULL;
}
