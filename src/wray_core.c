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

#include <stdio.h>
#include <string.h>

#include "wray_internal.h"

void wray_InitWindow(WrenVM *vm)
{
  InitWindow(
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2),
    wrenGetSlotString(vm, 3)
  );
}

void wray_CloseWindow(WrenVM *vm)
{
  CloseWindow();
}

void wray_WindowShouldClose_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotBool(vm, 0, WindowShouldClose());
}

void wray_IsWindowReady_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotBool(vm, 0, IsWindowReady());
}

void wray_IsWindowMinimized_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotBool(vm, 0, IsWindowMinimized());
}

void wray_IsWindowResized_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotBool(vm, 0, IsWindowResized());
}

void wray_IsWindowHidden_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotBool(vm, 0, IsWindowHidden());
}

void wray_ToggleFullscreen(WrenVM *vm)
{
  ToggleFullscreen();
}

void wray_WindowTitle_set(WrenVM *vm)
{
  SetWindowTitle(wrenGetSlotString(vm, 1));
}

void wray_WindowPosition_set(WrenVM *vm)
{
  wrenEnsureSlots(vm, 3);
  wrenGetListElement(vm, 0, 0, 1); /* x */
  wrenGetListElement(vm, 0, 1, 2); /* y */

  SetWindowPosition(wrenGetSlotDouble(vm, 1), wrenGetSlotDouble(vm, 2));
}

void wray_WindowIcon_set(WrenVM *vm)
{
  NYI
}

void wray_SetWindowMonitor(WrenVM *vm)
{
  SetWindowMonitor(wrenGetSlotDouble(vm, 1));
}

void wray_SetWindowSize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 3);
  wrenGetListElement(vm, 0, 0, 1); /* w */
  wrenGetListElement(vm, 0, 1, 2); /* h */

  SetWindowSize(wrenGetSlotDouble(vm, 1), wrenGetSlotDouble(vm, 2));
}

void wray_WindowMinSize_set(WrenVM *vm)
{
  wrenEnsureSlots(vm, 3);
  wrenGetListElement(vm, 0, 0, 1); /* w */
  wrenGetListElement(vm, 0, 1, 2); /* h */

  SetWindowMinSize(wrenGetSlotDouble(vm, 1), wrenGetSlotDouble(vm, 2));
}

void wray_ScreenSize_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 3);
  wrenSetSlotNewList(vm, 0);

  wrenSetSlotDouble(vm, 1, GetScreenWidth());
  wrenSetSlotDouble(vm, 2, GetScreenHeight());

  wrenInsertInList(vm, 0, -1, 1); /* w */
  wrenInsertInList(vm, 0, -1, 2); /* h */
}

void wray_MonitorCount_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotDouble(vm, 0, GetMonitorCount());
}

void wray_GetMonitorName(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotString(vm, 0, GetMonitorName(wrenGetSlotDouble(vm, 1)));
}

void wray_ClipboardText_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotString(vm, 0, GetClipboardText());
}

void wray_ClipboardText_set(WrenVM *vm)
{
  SetClipboardText(wrenGetSlotString(vm, 0));
}

void wray_CursorVisible_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotBool(vm, 0, !IsCursorHidden());
}

void wray_CursorVisible_set(WrenVM *vm)
{
  wrenGetSlotBool(vm, 1) ? ShowCursor() : HideCursor();
}

void wray_CursorLocked_set(WrenVM *vm)
{
  wrenGetSlotBool(vm, 0) ? DisableCursor() : EnableCursor();
}

void wray_ClearBackgroundList(WrenVM *vm)
{
  wrenEnsureSlots(vm, 5);

  size_t elem_count = wrenGetListCount(vm, 0);

  if (elem_count < 3) {
    wrenSetSlotString(vm, 0, "List must have at least 3 numbers.");
    wrenAbortFiber(vm, 0);
  }

  wrenGetListElement(vm, 0, 0, 1); /* r */
  wrenGetListElement(vm, 0, 1, 2); /* g */
  wrenGetListElement(vm, 0, 2, 3); /* b */

  if (elem_count > 3)
    wrenGetListElement(vm, 0, 3, 4); /* a */

  Color color;

  color.r = wrenGetSlotDouble(vm, 1);
  color.g = wrenGetSlotDouble(vm, 2);
  color.b = wrenGetSlotDouble(vm, 3);

  if (elem_count > 3)
    color.r = wrenGetSlotDouble(vm, 4);

  ClearBackground(color);
}

void wray_ClearBackgroundColor(WrenVM *vm)
{
  Color *c = wrenGetSlotForeign(vm, 1);
  ClearBackground(*c);
}

void wray_BeginDrawing(WrenVM *vm)
{
  BeginDrawing();
}

void wray_EndDrawing(WrenVM *vm)
{
  EndDrawing();
}

void wray_TargetFPS_set(WrenVM *vm)
{
  SetTargetFPS(wrenGetSlotDouble(vm, 1));
}

void wray_FPS_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotDouble(vm, 0, GetFPS());
}

void wray_FrameTime_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotDouble(vm, 0, GetFrameTime());
}

void wray_Time_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotDouble(vm, 0, GetTime());
}

void wray_ConfigFlags_set(WrenVM *vm)
{
  SetConfigFlags(wrenGetSlotDouble(vm, 1));
}

void wray_TakeScreenshot(WrenVM *vm)
{
  TakeScreenshot(wrenGetSlotString(vm, 1));
}

void wray_StorageSaveValue(WrenVM *vm)
{
  StorageSaveValue(
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  );
}

void wray_StorageLoadValue(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  int index = wrenGetSlotDouble(vm, 1);
  wrenSetSlotDouble(vm, 0, StorageLoadValue(index));
}

void wray_OpenURL(WrenVM *vm)
{
  OpenURL(wrenGetSlotString(vm, 1));
}

void wray_DrawFPS(WrenVM *vm)
{
  DrawFPS(
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  );
}

void wray_DrawText(WrenVM *vm)
{
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
