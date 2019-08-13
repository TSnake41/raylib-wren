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

void wray_image_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Image));
}

void wray_image_new(WrenVM *vm)
{
  Image *i = wrenGetSlotForeign(vm, 0);
  *i = LoadImage(wrenGetSlotString(vm, 1));
}

const wray_binding_class wray_image_class = {
  "RlImage", { wray_image_initialize, NULL }, {
    { wray_image_new, false, "init new(_)" },
    { NULL, NULL, NULL }
  }
};

void wray_texture2d_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Texture2D));
}

void wray_texture2d_new(WrenVM *vm)
{
  /* TODO: Add constructor from Image */

  Texture2D *i = wrenGetSlotForeign(vm, 0);
  *i = LoadTexture(wrenGetSlotString(vm, 1));
}

void wray_texture2d_draw(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlVector2");
  wray_CheckForeignType(vm, 2, "RlColor");

  DrawTextureV(
    *(Texture2D *)wrenGetSlotForeign(vm, 0),
    *(Vector2 *)wrenGetSlotForeign(vm, 1),
    *(Color *)wrenGetSlotForeign(vm, 2)
  );
}

const wray_binding_class wray_texture2d_class = {
  "RlTexture2D", { wray_texture2d_initialize, NULL }, {
    { wray_texture2d_new, false, "init new(_)" },
    { wray_texture2d_draw, false, "draw(_,_)" },
    { NULL, NULL, NULL }
  }
};
