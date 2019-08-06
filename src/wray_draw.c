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

#include <wren.h>
#include <raylib.h>

#include "wray_internal.h"

void wray_DrawFPS(WrenVM *vm)
{
  DrawFPS(
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  );
}

void wray_DrawText(WrenVM *vm)
{
  wray_CheckForeignType(vm, 5, "RlColor");

  DrawText(
    wrenGetSlotString(vm, 1), /* text */
    wrenGetSlotDouble(vm, 2), /* x */
    wrenGetSlotDouble(vm, 3), /* y */
    wrenGetSlotDouble(vm, 4), /* font_size */
    *((Color *)wrenGetSlotForeign(vm, 5)) /* color */
  );
}

void wray_DrawTextEx(WrenVM *vm)
{
  NYI
}

void wray_DrawTextRec(WrenVM *vm)
{
  NYI
}

void wray_DrawTextRecEx(WrenVM *vm)
{
  NYI
}
