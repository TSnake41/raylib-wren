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

#ifndef H_WRAY_DRAW
#define H_WRAY_DRAW

#include <wren.h>

void wray_DrawPixel(WrenVM *vm);

void wray_DrawLine(WrenVM *vm);
void wray_DrawLineThick(WrenVM *vm);
void wray_DrawLineBezier(WrenVM *vm);
void wray_DrawLineStrip(WrenVM *vm);

void wray_DrawCircle(WrenVM *vm);
void wray_DrawCircleLines(WrenVM *vm);
void wray_DrawCircleSector(WrenVM *vm);
void wray_DrawCircleSectorLines(WrenVM *vm);
void wray_DrawCircleGradient(WrenVM *vm);

void wray_DrawRing(WrenVM *vm);
void wray_DrawRingLines(WrenVM *vm);

void wray_DrawRectangle(WrenVM *vm);
void wray_DrawRectangleLines(WrenVM *vm);
void wray_DrawRectangleLinesThick(WrenVM *vm);
void wray_DrawRectangleRounded(WrenVM *vm);
void wray_DrawRectangleRoundedLines(WrenVM *vm);

void wray_DrawRectangleGradient(WrenVM *vm);
void wray_DrawRectangleGradientV(WrenVM *vm);
void wray_DrawRectangleGradientH(WrenVM *vm);

void wray_DrawTriangle(WrenVM *vm);
void wray_DrawTriangleLines(WrenVM *vm);
void wray_DrawTriangleFan(WrenVM *vm);
void wray_DrawPoly(WrenVM *vm);

void wray_ShapesTexture(WrenVM *vm);

#endif /* H_WRAY_DRAW */
