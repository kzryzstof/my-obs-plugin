#pragma once

#include <obs-module.h>
#include <graphics/graphics.h>

#ifdef __cplusplus
extern "C" {
#endif

void draw_texture(gs_texture_t *texture, uint32_t width, uint32_t height, gs_effect_t *effect);

#ifdef __cplusplus
}
#endif
