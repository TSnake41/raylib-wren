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

void wray_color_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Color));
}

void wray_color_hex_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  Color *c = wrenGetSlotForeign(vm, 0);

  /* hack as int is signed */
  uint32_t hex;
  *(int32_t *)(&hex) = ColorToInt(*c);

  wrenSetSlotDouble(vm, 0, hex);
}

void wray_color_r_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotDouble(vm, 0, ((Color *)wrenGetSlotForeign(vm, 0))->r);
}

void wray_color_g_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotDouble(vm, 0, ((Color *)wrenGetSlotForeign(vm, 0))->g);
}

void wray_color_b_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotDouble(vm, 0, ((Color *)wrenGetSlotForeign(vm, 0))->b);
}

void wray_color_a_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotDouble(vm, 0, ((Color *)wrenGetSlotForeign(vm, 0))->a);
}

void wray_color_r_set(WrenVM *vm)
{
  ((Color *)wrenGetSlotForeign(vm, 0))->r = wrenGetSlotDouble(vm, 1);
}

void wray_color_g_set(WrenVM *vm)
{
  ((Color *)wrenGetSlotForeign(vm, 0))->g = wrenGetSlotDouble(vm, 1);
}

void wray_color_b_set(WrenVM *vm)
{
  ((Color *)wrenGetSlotForeign(vm, 0))->b = wrenGetSlotDouble(vm, 1);
}

void wray_color_a_set(WrenVM *vm)
{
  ((Color *)wrenGetSlotForeign(vm, 0))->a = wrenGetSlotDouble(vm, 1);
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
