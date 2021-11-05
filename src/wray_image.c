/*
  Copyright (C) 2019 Astie Teddy

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted, provided that the above
  copyright notice and this permission notice appear in all copies.

  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
  OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
  CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include <raylib.h>

#include <wren.h>
#include "wray_internal.h"

static void wray_image_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Image));
}

static void wray_image_finalize(void *ptr)
{
  if (IsWindowReady())
    UnloadImage(*(Image *)ptr);
}

static void wray_image_new(WrenVM *vm)
{
  Image *i = wrenGetSlotForeign(vm, 0);
  *i = LoadImage(wrenGetSlotString(vm, 1));
}

/* Automagically make getters. */
MAKE_FIELD_GETTER(image, Double, Image, width)
MAKE_FIELD_GETTER(image, Double, Image, height)
MAKE_FIELD_GETTER(image, Double, Image, format)
MAKE_FIELD_GETTER(image, Double, Image, mipmaps)

const wray_binding_class wray_image_class = {
  "Image", { wray_image_initialize, wray_image_finalize }, {
    { wray_image_new, false, "init new(_)" },
    { wray_image_width_get, false, "width" },
    { wray_image_height_get, false, "height" },
    { wray_image_format_get, false, "format" },
    { wray_image_mipmaps_get, false, "mipmaps" },
    { NULL, NULL, NULL }
  }
};

static void wray_texture_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Texture));
}

static void wray_texture_finalize(void *ptr)
{
  if (IsWindowReady())
    UnloadTexture(*(Texture2D *)ptr);
}

static void wray_texture_new(WrenVM *vm)
{
  Texture *i = wrenGetSlotForeign(vm, 0);

  if (wrenGetSlotType(vm, 1) == WREN_TYPE_STRING) {
    /* Load from path */
    *i = LoadTexture(wrenGetSlotString(vm, 1));
  } else {
    /* Load from Image */
    wray_CheckForeignType(vm, 1, "Image");
    *i = LoadTextureFromImage(*(Image *)wrenGetSlotForeign(vm, 1));
  }
}

MAKE_FIELD_GETTER(texture, Double, Texture, width)
MAKE_FIELD_GETTER(texture, Double, Texture, height)
MAKE_FIELD_GETTER(texture, Double, Texture, format)
MAKE_FIELD_GETTER(texture, Double, Texture, mipmaps)

void wray_texture_draw(WrenVM *vm)
{
  wray_CheckForeignType(vm, 5, "Color");

  DrawTextureEx(
    *(Texture *)wrenGetSlotForeign(vm, 0),
    (Vector2){
      wrenGetSlotDouble(vm, 1),
      wrenGetSlotDouble(vm, 2),
    },
    wrenGetSlotDouble(vm, 3),
    wrenGetSlotDouble(vm, 4),
    *(Color *)wrenGetSlotForeign(vm, 5)
  );
}

const wray_binding_class wray_texture_class = {
  "Texture", { wray_texture_initialize, wray_texture_finalize }, {
    { wray_texture_new, false, "init new(_)" },
    { wray_texture_width_get, false, "width" },
    { wray_texture_height_get, false, "height" },
    { wray_texture_format_get, false, "format" },
    { wray_texture_mipmaps_get, false, "mipmaps" },
    { wray_texture_draw, false, "draw(_,_,_,_,_)" },
    { NULL, NULL, NULL }
  }
};

static void wray_rendertexture_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct RenderTexture));
}

static void wray_rendertexture_finalize(void *ptr)
{
  if (IsWindowReady())
    UnloadRenderTexture(*(RenderTexture2D *)ptr);
}

static void wray_rendertexture_new(WrenVM *vm)
{
  RenderTexture *rt = wrenGetSlotForeign(vm, 0);
  *rt = LoadRenderTexture(wrenGetSlotDouble(vm, 1), wrenGetSlotDouble(vm, 2));
}

MAKE_FIELD_GETTER(rendertexture, Double, RenderTexture, id)

static void wray_rendertexture_texture_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 2);
  wray_internal *internal = wrenGetUserData(vm);
  
  RenderTexture *rt = wrenGetSlotForeign(vm, 0);

  // Create a Texture class at slot 0.
  wrenSetSlotHandle(vm, 1, internal->class_handles.texture);
  Texture *texture = wrenSetSlotNewForeign(vm, 0, 1, sizeof(struct Texture));
  *texture = rt->texture;
}

static void wray_rendertexture_depth_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 2);
  wray_internal *internal = wrenGetUserData(vm);
  
  RenderTexture *rt = wrenGetSlotForeign(vm, 0);

  // Create a Texture class at slot 0.
  wrenSetSlotHandle(vm, 1, internal->class_handles.texture);
  Texture *depth = wrenSetSlotNewForeign(vm, 0, 1, sizeof(struct Texture));
  *depth = rt->depth;
}

const wray_binding_class wray_rendertexture_class = {
  "RenderTexture", { wray_rendertexture_initialize, wray_rendertexture_finalize }, {
    { wray_rendertexture_new, false, "init new(_,_)" },
    { wray_rendertexture_id_get, false, "id" },
    { wray_rendertexture_texture_get, false, "texture" },
    { wray_rendertexture_depth_get, false, "depth" },
    { NULL, NULL, NULL }
  }
};