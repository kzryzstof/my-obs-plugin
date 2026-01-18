#include "parsers.h"

#include <obs-module.h>

#include <cJSON.h>
#include <cJSON_Utils.h>
#include <string.h>
#include <common/types.h>
#include <diagnostics/log.h>

//  --------------------------------------------------------------------------------------------------------------------
//  Private functions
//  --------------------------------------------------------------------------------------------------------------------

static bool contains_node(const char *json_string, const char *node_key) {

    cJSON *json_message  = NULL;
    cJSON *node          = NULL;
    bool   contains_node = false;

    if (!json_string || strlen(json_string) == 0) {
        goto cleanup;
    }

    json_message = cJSON_Parse(json_string);

    if (!json_message) {
        goto cleanup;
    }

    node = cJSONUtils_GetPointer(json_message, node_key);

    contains_node = node != NULL;

cleanup:
    FREE_JSON(json_message);

    return contains_node;
}

//  --------------------------------------------------------------------------------------------------------------------
//  Public functions
//  --------------------------------------------------------------------------------------------------------------------

bool is_achievement_message(const char *json_string) {

    return contains_node(json_string, "/serviceConfigId");
}

bool is_presence_message(const char *json_string) {

    return contains_node(json_string, "/presenceDetails");
}

game_t *parse_game(const char *json_string) {

    cJSON  *json_root = NULL;
    game_t *game      = NULL;

    if (!json_string || strlen(json_string) == 0) {
        return NULL;
    }

    json_root = cJSON_Parse(json_string);

    if (!json_root) {
        return NULL;
    }

    char current_game_title[128] = "";
    char current_game_id[128]    = "";

    for (int detail_index = 0; detail_index < 3; detail_index++) {

        /* Finds out if there is anything at this index */
        char is_game_key[512] = "";
        snprintf(is_game_key, sizeof(is_game_key), "/presenceDetails/%d/isGame", detail_index);

        cJSON *is_game_value = cJSONUtils_GetPointer(json_root, is_game_key);

        if (!is_game_value) {
            /* There is nothing more */
            obs_log(LOG_DEBUG, "No more game at %d", detail_index);
            break;
        }

        if (is_game_value->type == cJSON_False) {
            /* This is not a game: most likely the xbox home */
            obs_log(LOG_DEBUG, "No game at %d. Is game = %s", detail_index, is_game_value->valuestring);
            continue;
        }

        obs_log(LOG_DEBUG, "Game at %d. Is game = %s", detail_index, is_game_value->valuestring);

        /* Retrieve the game title and its ID */
        char game_title_key[512];
        snprintf(game_title_key, sizeof(game_title_key), "/presenceDetails/%d/presenceText", detail_index);

        cJSON *game_title_value = cJSONUtils_GetPointer(json_root, game_title_key);

        obs_log(LOG_DEBUG, "Game title: %s %s", game_title_value->string, game_title_value->valuestring);

        char game_id_key[512];
        snprintf(game_id_key, sizeof(game_id_key), "/presenceDetails/%d/titleId", detail_index);

        cJSON *game_id_value = cJSONUtils_GetPointer(json_root, game_id_key);

        obs_log(LOG_DEBUG, "Game ID: %s %s", game_id_value->string, game_id_value->valuestring);

        snprintf(current_game_title, sizeof(current_game_title), "%s", game_title_value->valuestring);
        snprintf(current_game_id, sizeof(current_game_id), "%s", game_id_value->valuestring);
    }

    if (strlen(current_game_id) == 0) {
        obs_log(LOG_DEBUG, "No game found");
        goto cleanup;
    }

    obs_log(LOG_DEBUG, "Game is %s (%s)", current_game_title, current_game_id);

    game        = bzalloc(sizeof(game_t));
    game->id    = strdup(current_game_id);
    game->title = strdup(current_game_title);

cleanup:
    FREE_JSON(json_root);

    return game;
}
