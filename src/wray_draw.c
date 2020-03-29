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

void wray_DrawPixel(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlVector2");
  wray_CheckForeignType(vm, 2, "RlColor");

  DrawPixelV(
    *((Vector2 *)wrenGetSlotForeign(vm, 1)),
    *((Color *)wrenGetSlotForeign(vm, 2))
  );
}

void wray_DrawLine(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlVector2");
  wray_CheckForeignType(vm, 2, "RlVector2");
  wray_CheckForeignType(vm, 3, "RlColor");

  DrawLineV(
    *((Vector2 *)wrenGetSlotForeign(vm, 1)),
    *((Vector2 *)wrenGetSlotForeign(vm, 2)),
    *((Color *)wrenGetSlotForeign(vm, 3))
  );
}

void wray_DrawLineThick(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlVector2");
  wray_CheckForeignType(vm, 2, "RlVector2");
  wray_CheckForeignType(vm, 4, "RlColor");

  DrawLineEx(
    *((Vector2 *)wrenGetSlotForeign(vm, 1)),
    *((Vector2 *)wrenGetSlotForeign(vm, 2)),
    wrenGetSlotDouble(vm, 3),
    *((Color *)wrenGetSlotForeign(vm, 4))
  );
}

void wray_DrawLineBezier(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlVector2");
  wray_CheckForeignType(vm, 2, "RlVector2");
  wray_CheckForeignType(vm, 4, "RlColor");

  DrawLineBezier(
    *((Vector2 *)wrenGetSlotForeign(vm, 1)),
    *((Vector2 *)wrenGetSlotForeign(vm, 2)),
    wrenGetSlotDouble(vm, 3),
    *((Color *)wrenGetSlotForeign(vm, 4))
  );
}

void wray_DrawCircle(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlVector2");
  wray_CheckForeignType(vm, 3, "RlColor");

  DrawCircleV(
    *(Vector2 *)wrenGetSlotForeign(vm, 1),
    wrenGetSlotDouble(vm, 2),
    *(Color *)wrenGetSlotForeign(vm, 3)
  );
}

void wray_DrawCircleLines(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlVector2");
  wray_CheckForeignType(vm, 3, "RlColor");

  Vector2 *v = wrenGetSlotForeign(vm, 1);

  DrawCircleLines(
    v->x, v->y,
    wrenGetSlotDouble(vm, 2),
    *(Color *)wrenGetSlotForeign(vm, 3)
  );
}

void wray_DrawCircleSector(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlVector2");
  wray_CheckForeignType(vm, 6, "RlColor");

  DrawCircleSector(
    *(Vector2 *)wrenGetSlotForeign(vm, 1),
    wrenGetSlotDouble(vm, 2),
    wrenGetSlotDouble(vm, 3),
    wrenGetSlotDouble(vm, 4),
    wrenGetSlotDouble(vm, 5),
    *(Color *)wrenGetSlotForeign(vm, 6)
  );
}

void wray_DrawCircleSectorLines(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlVector2");
  wray_CheckForeignType(vm, 6, "RlColor");

  DrawCircleSectorLines(
    *(Vector2 *)wrenGetSlotForeign(vm, 1),
    wrenGetSlotDouble(vm, 2),
    wrenGetSlotDouble(vm, 3),
    wrenGetSlotDouble(vm, 4),
    wrenGetSlotDouble(vm, 5),
    *(Color *)wrenGetSlotForeign(vm, 6)
  );
}

void wray_DrawCircleGradient(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlVector2");
  wray_CheckForeignType(vm, 3, "RlColor");
  wray_CheckForeignType(vm, 4, "RlColor");

  Vector2 *v = wrenGetSlotForeign(vm, 1);

  DrawCircleGradient(
    v->x, v->y,
    wrenGetSlotDouble(vm, 2),
    *(Color *)wrenGetSlotForeign(vm, 3),
    *(Color *)wrenGetSlotForeign(vm, 4)
  );
}

void wray_DrawRing(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlVector2");
  wray_CheckForeignType(vm, 7, "RlColor");

  DrawRing(
    *(Vector2 *)wrenGetSlotForeign(vm, 1),
    wrenGetSlotDouble(vm, 2),
    wrenGetSlotDouble(vm, 3),
    wrenGetSlotDouble(vm, 4),
    wrenGetSlotDouble(vm, 5),
    wrenGetSlotDouble(vm, 6),
    *(Color *)wrenGetSlotForeign(vm, 7)
  );
}

void wray_DrawRingLines(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlVector2");
  wray_CheckForeignType(vm, 7, "RlColor");

  DrawRingLines(
    *(Vector2 *)wrenGetSlotForeign(vm, 1),
    wrenGetSlotDouble(vm, 2),
    wrenGetSlotDouble(vm, 3),
    wrenGetSlotDouble(vm, 4),
    wrenGetSlotDouble(vm, 5),
    wrenGetSlotDouble(vm, 6),
    *(Color *)wrenGetSlotForeign(vm, 7)
  );
}

void wray_DrawRectangle(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlRectangle");
  wray_CheckForeignType(vm, 2, "RlColor");

  DrawRectangleRec(
    *(Rectangle *)wrenGetSlotForeign(vm, 1),
    *(Color *)wrenGetSlotForeign(vm, 2)
  );
}

void wray_DrawRectangleLines(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlRectangle");
  wray_CheckForeignType(vm, 2, "RlColor");

  Rectangle *rectangle = wrenGetSlotForeign(vm, 1);

  DrawRectangleLines(
    rectangle->x, rectangle->y,
    rectangle->width, rectangle->height,
    *(Color *)wrenGetSlotForeign(vm, 2)
  );
}

void wray_DrawRectangleLinesThick(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlRectangle");
  wray_CheckForeignType(vm, 3, "RlColor");

  DrawRectangleLinesEx(
    *(Rectangle *)wrenGetSlotForeign(vm, 1),
    wrenGetSlotDouble(vm, 2),
    *(Color *)wrenGetSlotForeign(vm, 3)
  );
}

void wray_DrawRectangleRounded(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlRectangle");
  wray_CheckForeignType(vm, 4, "RlColor");

  DrawRectangleRounded(
    *(Rectangle *)wrenGetSlotForeign(vm, 1),
    wrenGetSlotDouble(vm, 2),
    wrenGetSlotDouble(vm, 3),
    *(Color *)wrenGetSlotForeign(vm, 4)
  );
}

void wray_DrawRectangleRoundedLines(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlRectangle");
  wray_CheckForeignType(vm, 5, "RlColor");

  DrawRectangleRoundedLines(
    *(Rectangle *)wrenGetSlotForeign(vm, 1),
    wrenGetSlotDouble(vm, 2),
    wrenGetSlotDouble(vm, 3),
    wrenGetSlotDouble(vm, 4),
    *(Color *)wrenGetSlotForeign(vm, 5)
  );
}

void wray_DrawRectangleGradient(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlRectangle");
  wray_CheckForeignType(vm, 2, "RlColor");
  wray_CheckForeignType(vm, 3, "RlColor");
  wray_CheckForeignType(vm, 4, "RlColor");
  wray_CheckForeignType(vm, 5, "RlColor");

  DrawRectangleGradientEx(
    *(Rectangle *)wrenGetSlotForeign(vm, 1),
    *(Color *)wrenGetSlotForeign(vm, 2),
    *(Color *)wrenGetSlotForeign(vm, 3),
    *(Color *)wrenGetSlotForeign(vm, 4),
    *(Color *)wrenGetSlotForeign(vm, 5)
  );
}

void wray_DrawRectangleGradientV(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlRectangle");
  wray_CheckForeignType(vm, 2, "RlColor");
  wray_CheckForeignType(vm, 3, "RlColor");

  Rectangle *rectangle = wrenGetSlotForeign(vm, 1);

  DrawRectangleGradientV(
    rectangle->x, rectangle->y,
    rectangle->width, rectangle->height,
    *(Color *)wrenGetSlotForeign(vm, 3),
    *(Color *)wrenGetSlotForeign(vm, 4)
  );
}

void wray_DrawRectangleGradientH(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlRectangle");
  wray_CheckForeignType(vm, 2, "RlColor");
  wray_CheckForeignType(vm, 3, "RlColor");

  Rectangle *rectangle = wrenGetSlotForeign(vm, 1);

  DrawRectangleGradientH(
    rectangle->x, rectangle->y,
    rectangle->width, rectangle->height,
    *(Color *)wrenGetSlotForeign(vm, 2),
    *(Color *)wrenGetSlotForeign(vm, 3)
  );
}

void wray_DrawTriangle(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlVector2");
  wray_CheckForeignType(vm, 2, "RlVector2");
  wray_CheckForeignType(vm, 3, "RlVector2");
  wray_CheckForeignType(vm, 4, "RlColor");

  DrawTriangle(
    *(Vector2 *)wrenGetSlotForeign(vm, 1),
    *(Vector2 *)wrenGetSlotForeign(vm, 2),
    *(Vector2 *)wrenGetSlotForeign(vm, 3),
    *(Color *)wrenGetSlotForeign(vm, 4)
  );
}

void wray_DrawTriangleLines(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlVector2");
  wray_CheckForeignType(vm, 2, "RlVector2");
  wray_CheckForeignType(vm, 3, "RlVector2");
  wray_CheckForeignType(vm, 4, "RlColor");

  DrawTriangleLines(
    *(Vector2 *)wrenGetSlotForeign(vm, 1),
    *(Vector2 *)wrenGetSlotForeign(vm, 2),
    *(Vector2 *)wrenGetSlotForeign(vm, 3),
    *(Color *)wrenGetSlotForeign(vm, 4)
  );
}

void wray_DrawLineStrip(WrenVM *vm)
{
  wrenEnsureSlots(vm, 3);

  /* color */
  wray_CheckForeignType(vm, 2, "RlColor");
  Color *color = wrenGetSlotForeign(vm, 2);

  /* points */
  int count = wrenGetListCount(vm, 1);
  Vector2 *points = calloc(count, sizeof(Vector2));

  for (int i = 0; i < count; i++) {
    wrenGetListElement(vm, 1, i, 3);

    wray_CheckForeignType(vm, 3, "RlVector2");
    points[i] = *(Vector2 *)wrenGetSlotForeign(vm, 3);
  }

  DrawLineStrip(points, count, *color);
  free(points);
}

void wray_DrawTriangleFan(WrenVM *vm)
{
  wrenEnsureSlots(vm, 3);

  /* color */
  wray_CheckForeignType(vm, 2, "RlColor");
  Color *color = wrenGetSlotForeign(vm, 2);

  /* points */
  int count = wrenGetListCount(vm, 1);
  Vector2 *points = calloc(count, sizeof(Vector2));

  for (int i = 0; i < count; i++) {
    wrenGetListElement(vm, 1, i, 3);

    wray_CheckForeignType(vm, 3, "RlVector2");
    points[i] = *(Vector2 *)wrenGetSlotForeign(vm, 3);
  }

  DrawTriangleFan(points, count, *color);
  free(points);
}

void wray_DrawPoly(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlVector2");
  wray_CheckForeignType(vm, 5, "RlColor");

  DrawPoly(
    *(Vector2 *)wrenGetSlotForeign(vm, 1),
    wrenGetSlotDouble(vm, 2),
    wrenGetSlotDouble(vm, 3),
    wrenGetSlotDouble(vm, 4),
    *(Color *)wrenGetSlotForeign(vm, 5)
  );
}

void wray_DrawTexture(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlTexture2D");
  wray_CheckForeignType(vm, 2, "RlVector2");
  wray_CheckForeignType(vm, 3, "RlColor");

  DrawTextureV(
    *(Texture2D *)wrenGetSlotForeign(vm, 1),
    *(Vector2 *)wrenGetSlotForeign(vm, 2),
    *(Color *)wrenGetSlotForeign(vm, 3)
  );
}

void wray_SetShapesTexture(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "RlTexture2D");
  wray_CheckForeignType(vm, 2, "RlRectangle");

  SetShapesTexture(
    *(Texture2D *)wrenGetSlotForeign(vm, 1),
    *(Rectangle *)wrenGetSlotForeign(vm, 2)
  );
}
