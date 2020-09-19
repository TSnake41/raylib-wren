/*
  Copyright (C) 2020 Astie Teddy

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

#include <stdio.h>

#include <wren.h>
#include <raylib.h>

#include "wray_internal.h"

void wray_rectangle_draw(WrenVM *vm)
{
  wray_CheckForeignType(vm, 5, "Color");

  double x = wrenGetSlotDouble(vm, 1);
  double y = wrenGetSlotDouble(vm, 2);
  double w = wrenGetSlotDouble(vm, 3);
  double h = wrenGetSlotDouble(vm, 4);

  Color c = *(Color *)wrenGetSlotForeign(vm, 5);

  bool lines = wrenGetSlotBool(vm, 6);

  if (lines)
    DrawRectangleLines(x, y, w, h, c);
  else
    DrawRectangle(x, y, w, h, c);
}

void wray_circle_draw(WrenVM *vm)
{
  double x = wrenGetSlotDouble(vm, 1);
  double y = wrenGetSlotDouble(vm, 2);
  double radius = wrenGetSlotDouble(vm, 3);

  wray_CheckForeignType(vm, 5, "Color");
  Color c = *(Color *)wrenGetSlotForeign(vm, 4);

  bool lines = wrenGetSlotBool(vm, 5);

  if (lines)
    DrawCircleLines(x, y, radius, c);
  else
    DrawCircle(x, y, radius, c);
}

void wray_text_draw(WrenVM *vm)
{
  wray_CheckForeignType(vm, 6, "color");

  DrawText(
    wrenGetSlotString(vm, 3),
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2),
    wrenGetSlotDouble(vm, 4),
    *(Color *)wrenGetSlotForeign(vm, 5)
  );
}

const wray_binding_class wray_rectangle_class = {
  "Rectangle", { NULL, NULL }, {
    { wray_rectangle_draw, true, "draw(_,_,_,_,_,_)" },
    { NULL, NULL, NULL }
  }
};

const wray_binding_class wray_circle_class = {
  "Circle", { NULL, NULL }, {
    { wray_circle_draw, true, "draw(_,_,_,_,_)" },
    { NULL, NULL, NULL }
  }
};

const wray_binding_class wray_text_class = {
  "Text", { NULL, NULL }, {
    { wray_text_draw, true, "draw(_,_,_,_,_)" },
    { NULL, NULL, NULL }
  }
};
