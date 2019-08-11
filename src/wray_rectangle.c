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
#include <raymath.h>

#include <wren.h>
#include "wray_internal.h"

void wray_rectangle_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Rectangle));
}

void wray_rectangle_new(WrenVM *vm)
{
  Rectangle *rect = wrenGetSlotForeign(vm, 0);

  rect->x = wrenGetSlotDouble(vm, 1);
  rect->y = wrenGetSlotDouble(vm, 2);
  rect->width = wrenGetSlotDouble(vm, 3);
  rect->height = wrenGetSlotDouble(vm, 4);
}

/* NOTE: This part assumes Rectangle struct is packed and ordered. */
void wray_rectangle_index_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  unsigned int i = wrenGetSlotDouble(vm, 1);

  if (i > 4) {
    wrenSetSlotString(vm, 0, "Rectangle index out of bounds.");
    wrenAbortFiber(vm, 0);
    return;
  }

  float *vec = wrenGetSlotForeign(vm, 0);
  wrenSetSlotDouble(vm, 0, vec[i]);
}

void wray_rectangle_index_set(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  unsigned int i = wrenGetSlotDouble(vm, 1);

  if (i > 4) {
    wrenSetSlotString(vm, 0, "Rectangle index out of bounds.");
    wrenAbortFiber(vm, 0);
    return;
  }

  float *vec = wrenGetSlotForeign(vm, 0);
  vec[i] = wrenGetSlotDouble(vm, 2);
}
