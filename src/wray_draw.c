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

/* drawPixel(x, y, color) */
void wray_draw_pixel(WrenVM *vm)
{
  wray_CheckForeignType(vm, 3, "Color");

  DrawPixel(
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2),
    *(Color *)wrenGetSlotForeign(vm, 3)
  );
}

/* drawLine(ax, ay, bx, by, color, thick, bezier) */
void wray_draw_line(WrenVM *vm)
{
  Vector2 start = (Vector2){
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  };

  Vector2 end = (Vector2){
    wrenGetSlotDouble(vm, 3),
    wrenGetSlotDouble(vm, 4)
  };

  wray_CheckForeignType(vm, 5, "Color");
  Color color = *(Color *)wrenGetSlotForeign(vm, 5);

  bool has_thick = false;
  bool is_bezier = false;
  double thick = 0;

  if (wrenGetSlotType(vm, 6) == WREN_TYPE_NUM) {
    has_thick = true;
    thick = wrenGetSlotDouble(vm, 6);

    if (wrenGetSlotType(vm, 7) == WREN_TYPE_BOOL)
      is_bezier = wrenGetSlotBool(vm, 7);
  }

  if (has_thick) {
    if (is_bezier)
      DrawLineBezier(start, end, thick, color);
    else
      DrawLineEx(start, end, thick, color);
  } else
    DrawLineV(start, end, color);
}

/* drawCircle(x, y, radius, color, lines, startAngle, endAngle, segments) */
void wray_draw_circle(WrenVM *vm)
{
  Vector2 center = {
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  };

  double radius = wrenGetSlotDouble(vm, 3);

  wray_CheckForeignType(vm, 4, "Color");
  Color color = *(Color *)wrenGetSlotForeign(vm, 4);

  bool is_lines = wrenGetSlotBool(vm, 5);
  bool is_sector = false;

  if (wrenGetSlotType(vm, 6) == WREN_TYPE_NUM) {
    is_sector = true;

    double start = wrenGetSlotDouble(vm, 6);
    double end = wrenGetSlotDouble(vm, 7);

    int segments = wrenGetSlotDouble(vm, 8);

    if (is_lines)
      DrawCircleSectorLines(center, radius, start, end, segments, color);
    else
      DrawCircleSector(center, radius, start, end, segments, color);
  } else {
    if (is_lines)
      DrawCircleLines(center.x, center.y, radius, color);
    else
      DrawCircleV(center, radius, color);
  }
}

/* drawCircleGradient(x, y, radius, c1, c2) */
void wray_draw_circle_gradient(WrenVM *vm)
{
  Vector2 position = (Vector2){
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  };

  double radius = wrenGetSlotDouble(vm, 3);

  wray_CheckForeignType(vm, 4, "Color");
  Color c1 = *(Color *)wrenGetSlotForeign(vm, 4);

  wray_CheckForeignType(vm, 5, "Color");
  Color c2 = *(Color *)wrenGetSlotForeign(vm, 5);

  DrawCircleGradient(position.x, position.y, radius, c1, c2);
}

/* drawEllipse(x, y, w, h, color, lines) */
void wray_draw_ellipse(WrenVM *vm)
{
  Vector2 center = {
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  };

  double w = wrenGetSlotDouble(vm, 3);
  double h = wrenGetSlotDouble(vm, 4);

  wray_CheckForeignType(vm, 5, "Color");
  Color color = *(Color *)wrenGetSlotForeign(vm, 5);

  if (wrenGetSlotBool(vm, 6)) /* lines */
    DrawEllipseLines(center.x, center.y, w, h, color);
  else
    DrawEllipse(center.x, center.y, w, h, color);
}

/* drawRing(x, y, innerRadius, outerRadius, startAngle, endAngle, segments,
    color, lines)
*/
void wray_draw_ring(WrenVM *vm)
{
  Vector2 center = {
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  };

  double innerRadius = wrenGetSlotDouble(vm, 3);
  double outerRadius = wrenGetSlotDouble(vm, 4);

  double start = wrenGetSlotDouble(vm, 5);
  double end = wrenGetSlotDouble(vm, 6);

  int segments = wrenGetSlotDouble(vm, 7);

  wray_CheckForeignType(vm, 8, "Color");
  Color color = *(Color *)wrenGetSlotForeign(vm, 8);

  if (wrenGetSlotBool(vm, 9)) /* lines */
    DrawRingLines(center, innerRadius, outerRadius, start, end, segments, color);
  else
    DrawRing(center, innerRadius, outerRadius, start, end, segments, color);
}

/* drawRectanglePro(x, y, w, h, ox, oy, rotation, color) */
void wray_draw_rectangle_pro(WrenVM *vm)
{
  Rectangle rectangle = (Rectangle){
    .x = wrenGetSlotDouble(vm, 1),
    .y = wrenGetSlotDouble(vm, 2),
    .width = wrenGetSlotDouble(vm, 3),
    .height = wrenGetSlotDouble(vm, 4)
  };

  Vector2 origin = (Vector2){
    wrenGetSlotDouble(vm, 5),
    wrenGetSlotDouble(vm, 6)
  };

  double rotation = wrenGetSlotDouble(vm, 7);

  wray_CheckForeignType(vm, 8, "Color");
  Color color = *(Color *)wrenGetSlotForeign(vm, 8);

  DrawRectanglePro(rectangle, origin, rotation, color);
}

/* drawRectangleLines(x, y, w, h, color, thick) */
void wray_draw_rectangle_lines(WrenVM *vm)
{
  Rectangle rect = (Rectangle){
    .x = wrenGetSlotDouble(vm, 1),
    .y = wrenGetSlotDouble(vm, 2),
    .width = wrenGetSlotDouble(vm, 3),
    .height = wrenGetSlotDouble(vm, 4)
  };

  wray_CheckForeignType(vm, 5, "Color");
  Color color = *(Color *)wrenGetSlotForeign(vm, 5);

  if (wrenGetSlotType(vm, 6) == WREN_TYPE_NUM) {
    int thick = wrenGetSlotDouble(vm, 6);

    DrawRectangleLinesEx(rect, thick, color);
  } else
    DrawRectangleLines(rect.x, rect.y, rect.width, rect.height, color);
}

/* drawRectangleRounded(x, y, w, h, roundness, segments, color, lines_thick) */
void wray_draw_rectangle_rounded(WrenVM *vm)
{
  Rectangle rectangle = (Rectangle){
    .x = wrenGetSlotDouble(vm, 1),
    .y = wrenGetSlotDouble(vm, 2),
    .width = wrenGetSlotDouble(vm, 3),
    .height = wrenGetSlotDouble(vm, 4)
  };

  double roundness = wrenGetSlotDouble(vm, 5);
  int segments = wrenGetSlotDouble(vm, 6);

  wray_CheckForeignType(vm, 6, "Color");
  Color color = *(Color *)wrenGetSlotForeign(vm, 6);

  if (wrenGetSlotType(vm, 7) == WREN_TYPE_NUM) {
    int thick = wrenGetSlotDouble(vm, 8);

    DrawRectangleRoundedLines(rectangle, roundness, segments, thick, color);
  } else
    DrawRectangleRounded(rectangle, roundness, segments, color);
}

/* drawRectangleGradient(x, y, w, h, c1, c2, c3, c4) */
void wray_draw_rectangle_gradient(WrenVM *vm)
{
   Rectangle rectangle = (Rectangle){
    .x = wrenGetSlotDouble(vm, 1),
    .y = wrenGetSlotDouble(vm, 2),
    .width = wrenGetSlotDouble(vm, 3),
    .height = wrenGetSlotDouble(vm, 4)
  };

  wray_CheckForeignType(vm, 5, "Color");
  Color c1 = *(Color *)wrenGetSlotForeign(vm, 5);

  wray_CheckForeignType(vm, 6, "Color");
  Color c2 = *(Color *)wrenGetSlotForeign(vm, 6);

  wray_CheckForeignType(vm, 7, "Color");
  Color c3 = *(Color *)wrenGetSlotForeign(vm, 7);

  wray_CheckForeignType(vm, 8, "Color");
  Color c4 = *(Color *)wrenGetSlotForeign(vm, 8);

  DrawRectangleGradientEx(rectangle, c1, c2, c3, c4);
}

/* drawTriangle(x1, y1, x2, y2, x3, y3, color, lines) */
void wray_draw_triangle(WrenVM *vm)
{
  Vector2 v1 = (Vector2){
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  };

  Vector2 v2 = (Vector2){
    wrenGetSlotDouble(vm, 3),
    wrenGetSlotDouble(vm, 4)
  };

  Vector2 v3 = (Vector2){
    wrenGetSlotDouble(vm, 5),
    wrenGetSlotDouble(vm, 6)
  };

  wray_CheckForeignType(vm, 7, "Color");
  Color color = *(Color *)wrenGetSlotForeign(vm, 7);

  if (wrenGetSlotBool(vm, 8)) /* lines */
    DrawTriangleLines(v1, v2, v3, color);
  else
    DrawTriangle(v1, v2, v3, color);
}

/* drawPoly(x, y, sides, radius, rotation, color, lines) */
void wray_draw_poly(WrenVM *vm)
{
  Vector2 center = (Vector2){
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  };

  int sides = wrenGetSlotDouble(vm, 3);
  double radius = wrenGetSlotDouble(vm, 4);
  double rotation = wrenGetSlotDouble(vm, 5);

  wray_CheckForeignType(vm, 6, "Color");
  Color color = *(Color *)wrenGetSlotForeign(vm, 6);

  if (wrenGetSlotBool(vm, 7)) /* lines */
    DrawPolyLines(center, sides, radius, rotation, color);
  else
    DrawPoly(center, sides, radius, rotation, color);
}

/* drawTexture(texture, x, y, color, rotation, scale) */
void wray_draw_texture(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "Texture2D");
  Texture2D texture = *(Texture2D *)wrenGetSlotForeign(vm, 1);

  Vector2 position = (Vector2){
    wrenGetSlotDouble(vm, 2),
    wrenGetSlotDouble(vm, 3)
  };

  wray_CheckForeignType(vm, 4, "Color");
  Color color = *(Color *)wrenGetSlotForeign(vm, 4);

  double rotation = wrenGetSlotDouble(vm, 5);
  double scale = wrenGetSlotDouble(vm, 6);

  DrawTextureEx(texture, position, rotation, scale, color);
}

/* drawTexturePro(texture, sx, sy, sw, sh, dx, dy, dw, dh, ox, oy, rotation, color) */
void wray_draw_texture_pro(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "Texture2D");
  Texture2D texture = *(Texture2D *)wrenGetSlotForeign(vm, 1);

  Rectangle src = (Rectangle){
    wrenGetSlotDouble(vm, 2),
    wrenGetSlotDouble(vm, 3),
    wrenGetSlotDouble(vm, 4),
    wrenGetSlotDouble(vm, 5)
  };

  Rectangle dest = (Rectangle){
    wrenGetSlotDouble(vm, 6),
    wrenGetSlotDouble(vm, 7),
    wrenGetSlotDouble(vm, 8),
    wrenGetSlotDouble(vm, 9)
  };

  Vector2 origin = (Vector2){
    wrenGetSlotDouble(vm, 10),
    wrenGetSlotDouble(vm, 11)
  };

  double rotation = wrenGetSlotDouble(vm, 12);

  wray_CheckForeignType(vm, 13, "Color");
  Color color = *(Color *)wrenGetSlotForeign(vm, 13);

  DrawTexturePro(texture, src, dest, origin, rotation, color);
}

/* drawText(text, x, y, size, color) */
void wray_draw_text(WrenVM *vm)
{
  const char *text = wrenGetSlotString(vm, 1);

  Vector2 position = (Vector2){
    wrenGetSlotDouble(vm, 2),
    wrenGetSlotDouble(vm, 3)
  };

  int size = wrenGetSlotDouble(vm, 4);

  wray_CheckForeignType(vm, 5, "Color");
  Color color = *(Color *)wrenGetSlotForeign(vm, 5);

  DrawText(text, position.x, position.y, size, color);
}

const wray_binding_class wray_draw_class = {
  "Raylib", { NULL, NULL }, {
    { wray_draw_pixel, true, "drawPixel(_,_,_)" },
    { wray_draw_line, true, "drawLine(_,_,_,_,_,_,_)" },
    { wray_draw_circle, true, "drawCircle(_,_,_,_,_,_,_,_)" },
    { wray_draw_circle_gradient, true, "drawCircleGradient(_,_,_,_,_)" },
    { wray_draw_ellipse, true, "drawEllipse(_,_,_,_,_,_)" },
    { wray_draw_ring, true, "drawRing(_,_,_,_,_,_,_,_,_)" },
    { wray_draw_rectangle_pro, true, "drawRectanglePro(_,_,_,_,_,_,_,_)" },
    { wray_draw_rectangle_lines, true, "drawRectangleLines(_,_,_,_,_,_)" },
    { wray_draw_rectangle_rounded, true, "drawRectangleRounded(_,_,_,_,_,_,_,_)" },
    { wray_draw_rectangle_gradient, true, "drawRectangleGradient(_,_,_,_,_,_,_,_)" },
    { wray_draw_triangle, true, "drawTriangle(_,_,_,_,_,_,_,_)" },
    { wray_draw_poly, true, "drawPoly(_,_,_,_,_,_,_)" },
    { wray_draw_texture, true, "drawTexture(_,_,_,_,_,_)" },
    { wray_draw_texture_pro, true, "drawTexturePro(_,_,_,_,_,_,_,_,_,_,_,_,_)" },
    { wray_draw_text, true, "drawText(_,_,_,_,_)" },
    { NULL, NULL, NULL }
  }
};
