#include "state.h"

#include <obs-module.h>
#include <diagnostics/log.h>
#include <util/config-file.h>
#include <util/platform.h>

#define PERSIST_FILE "state.json"
#define XSTS_TOKEN_KEY "xsts_token"

static obs_data_t *g_state = NULL;

static char *get_state_path(void)
{
	/* Put state under: <OBS config dir>/plugins/<plugin_name>/ */
	char *dir = obs_module_config_path("");

	if (!dir)
		return NULL;

	/* Ensure directory exists */
	os_mkdirs(dir);

	char *path = (char *)bzalloc(1024);
	snprintf(path, 1024, "%s/%s", dir, PERSIST_FILE);
	bfree(dir);

	return path;
}

static obs_data_t *load_state(void)
{
	char *path = get_state_path();

	if (!path)
		return NULL;

	obs_data_t *data = obs_data_create_from_json_file(path);
	bfree(path);

	/* If file doesn’t exist yet, return an empty object */
	if (!data) {
		obs_log(LOG_INFO, "no state found: creating a new one");
		data = obs_data_create();
	}

	return data;
}

static void save_state(obs_data_t *data)
{
	if (!data)
		return;

	char *path = get_state_path();

	if (!path)
		return;

	obs_data_save_json_safe(data, path, ".tmp", ".bak");
	bfree(path);
}

void io_load(void)
{
	g_state = load_state();

	/* Read values */
	const char *token = obs_data_get_string(g_state, "oauth_token");
	int64_t last_sync = obs_data_get_int(g_state, "last_sync_unix");

	(void)token;
	(void)last_sync;
}

const char* get_xsts_token(void)
{
	return obs_data_get_string(g_state, XSTS_TOKEN_KEY);
}

void set_xsts_token(const char* token)
{
	obs_data_set_string(g_state, XSTS_TOKEN_KEY, token);

	/* Immediately save the state to disk */
	save_state(g_state);
}
