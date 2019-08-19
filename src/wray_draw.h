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

void wray_DrawPixel(WrenVM *);

void wray_DrawLine(WrenVM *);
void wray_DrawLineThick(WrenVM *);
void wray_DrawLineBezier(WrenVM *);
void wray_DrawLineStrip(WrenVM *);

void wray_DrawCircle(WrenVM *);
void wray_DrawCircleLines(WrenVM *);
void wray_DrawCircleSector(WrenVM *);
void wray_DrawCircleSectorLines(WrenVM *);
void wray_DrawCircleGradient(WrenVM *);

void wray_DrawRing(WrenVM *);
void wray_DrawRingLines(WrenVM *);

void wray_DrawRectangle(WrenVM *);
void wray_DrawRectangleLines(WrenVM *);
void wray_DrawRectangleLinesThick(WrenVM *);
void wray_DrawRectangleRounded(WrenVM *);
void wray_DrawRectangleRoundedLines(WrenVM *);

void wray_DrawRectangleGradient(WrenVM *);
void wray_DrawRectangleGradientV(WrenVM *);
void wray_DrawRectangleGradientH(WrenVM *);

void wray_DrawTriangle(WrenVM *);
void wray_DrawTriangleLines(WrenVM *);
void wray_DrawTriangleFan(WrenVM *);
void wray_DrawPoly(WrenVM *);

void wray_DrawTexture(WrenVM *);
void wray_SetShapesTexture(WrenVM *);

#endif /* H_WRAY_DRAW */
