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

#include <stdint.h>

#include <raylib.h>
#include <wren.h>

#include "wray_internal.h"

void wray_color_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Color));
}

void wray_color_new_hex(WrenVM *vm)
{
  Color *c = wrenGetSlotForeign(vm, 0);
  uint32_t n = wrenGetSlotDouble(vm, 1);

  c->r = (n >> 24) & 0xFF;
  c->g = (n >> 16) & 0xFF;
  c->b = (n >> 8) & 0xFF;
  c->a = (n >> 0) & 0xFF;
}

void wray_color_new_rgba(WrenVM *vm)
{
  Color *c = wrenGetSlotForeign(vm, 0);

  c->r = wrenGetSlotDouble(vm, 1);
  c->g = wrenGetSlotDouble(vm, 2);
  c->b = wrenGetSlotDouble(vm, 3);
  c->a = wrenGetSlotDouble(vm, 4);
}

void wray_color_new_rgb(WrenVM *vm)
{
  Color *c = wrenGetSlotForeign(vm, 0);

  c->r = wrenGetSlotDouble(vm, 1);
  c->g = wrenGetSlotDouble(vm, 2);
  c->b = wrenGetSlotDouble(vm, 3);
  c->a = 0xFF;
}

void wray_color_hex_get(WrenVM *vm)
{
  Color *c = wrenGetSlotForeign(vm, 0);

  /* hack as int is signed */
  uint32_t hex;
  *(int32_t *)(&hex) = ColorToInt(*c);

  wrenSetSlotDouble(vm, 0, hex);
}

/* NOTE: This part assumes Color struct is packed and ordered. */
void wray_color_index_get(WrenVM *vm)
{
  unsigned int i = wrenGetSlotDouble(vm, 1);

  if (i > 4) {
    wrenSetSlotString(vm, 0, "Color index out of bounds.");
    wrenAbortFiber(vm, 0);
    return;
  }

  unsigned char *vec = wrenGetSlotForeign(vm, 0);
  wrenSetSlotDouble(vm, 0, vec[i]);
}

void wray_color_index_set(WrenVM *vm)
{
  unsigned int i = wrenGetSlotDouble(vm, 1);

  if (i > 4) {
    wrenSetSlotString(vm, 0, "Color index out of bounds.");
    wrenAbortFiber(vm, 0);
    return;
  }

  unsigned char *vec = wrenGetSlotForeign(vm, 0);
  vec[i] = wrenGetSlotDouble(vm, 2);
}

const wray_binding_class wray_color_class = {
  "RlColor", { wray_color_initialize, NULL }, {
    { wray_color_new_hex, false, "init new(_)" },
    { wray_color_new_rgba, false, "init new(_,_,_,_)" },
    { wray_color_new_rgb, false, "init new(_,_,_)" },

    { wray_color_hex_get, false, "hex" },
    { wray_color_index_get, false, "[_]" },
    { wray_color_index_set, false, "[_]=(_)" },
    { NULL, NULL, NULL }
  }
};
