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

#ifndef H_WRAY_CORE
#define H_WRAY_CORE

#include <wren.h>

void wray_InitWindow(WrenVM *);
void wray_CloseWindow(WrenVM *);

void wray_WindowShouldClose_get(WrenVM *);
void wray_IsWindowReady_get(WrenVM *);
void wray_IsWindowMinimized_get(WrenVM *);
void wray_IsWindowResized_get(WrenVM *);
void wray_IsWindowHidden_get(WrenVM *);

void wray_ToggleFullscreen(WrenVM *);
void wray_WindowTitle_set(WrenVM *);
void wray_WindowIcon_set(WrenVM *);
void wray_SetWindowSize(WrenVM *);
void wray_SetWindowMonitor(WrenVM *);
void wray_SetWindowMinSize(WrenVM *);

void wray_ScreenWidth_get(WrenVM *);
void wray_ScreenHeight_get(WrenVM *);

void wray_MonitorCount_get(WrenVM *);
void wray_SetWindowPosition(WrenVM *);

void wray_ClipboardText_get(WrenVM *);
void wray_ClipboardText_set(WrenVM *);

void wray_GetMonitorName(WrenVM *);

void wray_CursorVisible_get(WrenVM *);
void wray_CursorVisible_set(WrenVM *);
void wray_CursorLocked_set(WrenVM *);

void wray_ClearBackground(WrenVM *);
void wray_BeginDrawing(WrenVM *);
void wray_EndDrawing(WrenVM *);

void wray_TargetFPS_set(WrenVM *);
void wray_FPS_get(WrenVM *);
void wray_FrameTime_get(WrenVM *);
void wray_Time_get(WrenVM *);

void wray_ConfigFlags_set(WrenVM *);
void wray_TakeScreenshot(WrenVM *);

void wray_SaveStorageValue(WrenVM *);
void wray_LoadStorageValue(WrenVM *);

void wray_OpenURL(WrenVM *);

void wray_DrawFPS(WrenVM *);

void wray_IsKeyUp(WrenVM *);
void wray_isKeyDown(WrenVM *);
void wray_IsKeyPressed(WrenVM *);
void wray_IsKeyReleased(WrenVM *);

void wray_ExitKey_set(WrenVM *vm);
void wray_KeyPressed_get(WrenVM *vm);

void wray_IsMouseButtonPressed(WrenVM *);
void wray_IsMouseButtonDown(WrenVM *);
void wray_IsMouseButtonReleased(WrenVM *);
void wray_IsMouseButtonUp(WrenVM *);

void wray_MouseX_get(WrenVM *);
void wray_MouseY_get(WrenVM *);
void wray_MouseWheelMove_get(WrenVM *);

void wray_SetMousePosition(WrenVM *);
void wray_SetMouseOffset(WrenVM *);
void wray_SetMouseScale(WrenVM *);

#endif /* H_WRAY_CORE */
