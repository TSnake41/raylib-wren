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
  // Finalizer is called by CloseWindow.
  // UnloadImage(*(Image *)ptr);
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

static void wray_texture2d_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Texture2D));
}

static void wray_texture2d_finalize(void *ptr)
{
  UnloadTexture(*(Texture2D *)ptr);
}

static void wray_texture2d_new(WrenVM *vm)
{
  Texture2D *i = wrenGetSlotForeign(vm, 0);

  if (wrenGetSlotType(vm, 1) == WREN_TYPE_STRING) {
    /* Load from path */
    *i = LoadTexture(wrenGetSlotString(vm, 1));
  } else {
    /* Load from Image */
    wray_CheckForeignType(vm, 1, "Image");
    *i = LoadTextureFromImage(*(Image *)wrenGetSlotForeign(vm, 1));
  }
}

MAKE_FIELD_GETTER(texture2d, Double, Texture2D, width)
MAKE_FIELD_GETTER(texture2d, Double, Texture2D, height)
MAKE_FIELD_GETTER(texture2d, Double, Texture2D, format)
MAKE_FIELD_GETTER(texture2d, Double, Texture2D, mipmaps)

void wray_texture2d_draw(WrenVM *vm)
{
  wray_CheckForeignType(vm, 3, "Color");

  DrawTextureEx(
    *(Texture2D *)wrenGetSlotForeign(vm, 0),
    (Vector2){
      wrenGetSlotDouble(vm, 1),
      wrenGetSlotDouble(vm, 2),
    },
    wrenGetSlotDouble(vm, 3),
    wrenGetSlotDouble(vm, 4),
    *(Color *)wrenGetSlotForeign(vm, 5)
  );
}

const wray_binding_class wray_texture2d_class = {
  "Texture2D", { wray_texture2d_initialize, wray_texture2d_finalize }, {
    { wray_texture2d_new, false, "init new(_)" },
    { wray_texture2d_width_get, false, "width" },
    { wray_texture2d_height_get, false, "height" },
    { wray_texture2d_format_get, false, "format" },
    { wray_texture2d_mipmaps_get, false, "mipmaps" },
    { wray_texture2d_draw, false, "draw(_,_,_,_,_)" },
    { NULL, NULL, NULL }
  }
};
