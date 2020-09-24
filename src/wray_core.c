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

void wray_SetWindowPosition(WrenVM *vm)
{
  SetWindowPosition(
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  );
}

void wray_WindowIcon_set(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "Image");
  SetWindowIcon(*(Image *)wrenGetSlotForeign(vm, 1));
}

void wray_SetWindowMonitor(WrenVM *vm)
{
  SetWindowMonitor(wrenGetSlotDouble(vm, 1));
}

void wray_SetWindowSize(WrenVM *vm)
{
  SetWindowSize(
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  );
}

void wray_SetWindowMinSize(WrenVM *vm)
{
  SetWindowMinSize(
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  );
}

void wray_ScreenWidth_get(WrenVM *vm)
{
  wrenSetSlotDouble(vm, 0, GetScreenWidth());
}

void wray_ScreenHeight_get(WrenVM *vm)
{
  wrenSetSlotDouble(vm, 0, GetScreenHeight());
}

void wray_MonitorCount_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotDouble(vm, 0, GetMonitorCount());
}

void wray_GetMonitorName(WrenVM *vm)
{
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

void wray_ClearBackground(WrenVM *vm)
{
  wray_CheckForeignType(vm, 1, "Color");

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

void wray_DrawFPS(WrenVM *vm)
{
  DrawFPS(
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  );
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


void wray_SaveStorageValue(WrenVM *vm)
{
  SaveStorageValue(
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  );
}

void wray_LoadStorageValue(WrenVM *vm)
{
  int index = wrenGetSlotDouble(vm, 1);
  wrenSetSlotDouble(vm, 0, LoadStorageValue(index));
}

void wray_OpenURL(WrenVM *vm)
{
  OpenURL(wrenGetSlotString(vm, 1));
}

void wray_IsKeyUp(WrenVM *vm)
{
  int key = wrenGetSlotDouble(vm, 1);
  wrenSetSlotBool(vm, 0, IsKeyUp(key));
}

void wray_isKeyDown(WrenVM *vm)
{
  int key = wrenGetSlotDouble(vm, 1);
  wrenSetSlotBool(vm, 0, IsKeyDown(key));
}

void wray_IsKeyPressed(WrenVM *vm)
{
  int key = wrenGetSlotDouble(vm, 1);
  wrenSetSlotBool(vm, 0, IsKeyPressed(key));
}

void wray_IsKeyReleased(WrenVM *vm)
{
  int key = wrenGetSlotDouble(vm, 1);
  wrenSetSlotBool(vm, 0, IsKeyReleased(key));
}

void wray_IsMouseButtonPressed(WrenVM *vm)
{
  int button = wrenGetSlotDouble(vm, 1);
  wrenSetSlotBool(vm, 0, IsMouseButtonPressed(button));
}

void wray_IsMouseButtonDown(WrenVM *vm)
{
  int button = wrenGetSlotDouble(vm, 1);
  wrenSetSlotBool(vm, 0, IsMouseButtonDown(button));
}

void wray_IsMouseButtonReleased(WrenVM *vm)
{
  int button = wrenGetSlotDouble(vm, 1);
  wrenSetSlotBool(vm, 0, IsMouseButtonReleased(button));
}

void wray_IsMouseButtonUp(WrenVM *vm)
{
  int button = wrenGetSlotDouble(vm, 1);
  wrenSetSlotBool(vm, 0, IsMouseButtonUp(button));
}

void wray_ExitKey_set(WrenVM *vm)
{
  SetExitKey(wrenGetSlotDouble(vm, 1));
}

void wray_KeyPressed_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotDouble(vm, 0, GetKeyPressed());
}

void wray_MouseX_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotDouble(vm, 0, GetMouseX());
}

void wray_MouseY_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotDouble(vm, 0, GetMouseY());
}

void wray_MouseWheelMove_get(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotDouble(vm, 0, GetMouseWheelMove());
}

void wray_SetMousePosition(WrenVM *vm)
{
  SetMousePosition(
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  );
}

void wray_SetMouseOffset(WrenVM *vm)
{
  SetMouseOffset(
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  );
}

void wray_SetMouseScale(WrenVM *vm)
{
  SetMouseScale(
    wrenGetSlotDouble(vm, 1),
    wrenGetSlotDouble(vm, 2)
  );
}
