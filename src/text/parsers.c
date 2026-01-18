#include "parsers.h"

#include <obs-module.h>

#include <cJSON.h>
#include <cJSON_Utils.h>
#include <string.h>
#include <common/types.h>

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

bool is_achievement_message(const char *json_string) {

    return contains_node(json_string, "/serviceConfigId");
}

bool is_presence_message(const char *json_string) {

    return contains_node(json_string, "/presenceDetails");
}
