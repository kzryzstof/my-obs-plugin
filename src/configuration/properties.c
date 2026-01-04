#include "configuration/properties.h"

#include <graphics/graphics.h>

#include "sources/achievements-tracker-source.h"
#include "io/state.h"
#include "oauth/xbox-live.h"
#include "diagnostics/log.h"

/*
 * Forward declarations for the source callbacks.
 *
 * They’re implemented in sources/achievements-tracker-source.c, but we keep the obs_source_info
 * structure itself isolated in this file.
 */
void *text_src_create(obs_data_t *settings, obs_source_t *source);
void text_src_destroy(void *data);
void text_src_update(void *data, obs_data_t *settings);
uint32_t text_src_get_width(void *data);
uint32_t text_src_get_height(void *data);
void text_src_video_render(void *data, gs_effect_t *effect);

static bool on_sign_out_clicked(obs_properties_t *props, obs_property_t *property, void *data)
{
	UNUSED_PARAMETER(props);
	UNUSED_PARAMETER(property);
	UNUSED_PARAMETER(data);

	clear_xid_xsts_token();

	return true;
}

static bool on_sign_in_xbox_clicked(obs_properties_t *props, obs_property_t *property, void *data)
{
	UNUSED_PARAMETER(props);
	UNUSED_PARAMETER(property);
	UNUSED_PARAMETER(data);

	/* TODO: move to OBS settings UI */
	const char *client_id = "c02dcb46-80c5-477a-8dbc-8e98df2c06c1";
	const char *scope = "XboxLive.signin offline_access";

	char *xid = NULL;
	char *uhs = NULL;
	char *xsts_token = NULL;
	if (!xbox_auth_interactive_get_xsts(client_id, scope, &uhs, &xid, &xsts_token)) {
		obs_log(LOG_WARNING, "Xbox sign-in failed");
		return true;
	}

	char* token = bzalloc(1024);
	snprintf(token, 1024, "XBL3.0 x=%s;%s", uhs, xsts_token);
	set_xid_xsts_token(xid, token);

	bfree(uhs);
	bfree(xsts_token);
	return true;
}

obs_properties_t *get_properties(
	void *data
)
{
	UNUSED_PARAMETER(data);
	obs_properties_t *p = obs_properties_create();
	obs_properties_add_text(p, "text", "Text", OBS_TEXT_DEFAULT);

	const char* token = get_xsts_token();

	obs_property_t *xboxSignInButton = obs_properties_add_button(p, "sign-in-xbox", "Sign in with Xbox", &on_sign_in_xbox_clicked);
	obs_property_t *xboxSignOutButton = obs_properties_add_button(p, "sign-out-xbox", "Sign out from Xbox", &on_sign_out_clicked);

	if (token != NULL && strlen(token) > 0) {
		obs_property_set_enabled(xboxSignInButton, false);
		obs_property_set_enabled(xboxSignOutButton, true);
		obs_log(LOG_WARNING, "Found token %s", token);
	}
	else {
		obs_property_set_enabled(xboxSignInButton, true);
		obs_property_set_enabled(xboxSignOutButton, false);
	}
	return p;
}

/* Gets the name of the source */
const char *text_src_get_name(
	void *unused
)
{
	UNUSED_PARAMETER(unused);
	return "Achievements Tracker";
}

static struct obs_source_info text_src_info = {
	.id = "template_text_source",
	.type = OBS_SOURCE_TYPE_INPUT,
	.output_flags = OBS_SOURCE_VIDEO,
	.get_name = text_src_get_name,
	.create = text_src_create,
	.destroy = text_src_destroy,
	.update = text_src_update,
	.get_properties = get_properties,
	.get_width = text_src_get_width,
	.get_height = text_src_get_height,
	.video_tick = NULL,
	.video_render = text_src_video_render,
};

const struct obs_source_info *get_plugin_properties(void)
{
	return &text_src_info;
}
