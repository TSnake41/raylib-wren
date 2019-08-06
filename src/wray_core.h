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
void wray_WindowMinSize_set(WrenVM *);
void wray_ScreenSize_get(WrenVM *);
void wray_MonitorCount_get(WrenVM *);
void wray_WindowPosition_set(WrenVM *);

void wray_ClipboardText_get(WrenVM *);
void wray_ClipboardText_set(WrenVM *);

void wray_GetMonitorName(WrenVM *);

void wray_CursorVisible_get(WrenVM *);
void wray_CursorVisible_set(WrenVM *);
void wray_CursorLocked_set(WrenVM *);

void wray_ClearBackgroundList(WrenVM *);
void wray_ClearBackgroundColor(WrenVM *);

void wray_BeginDrawing(WrenVM *);
void wray_EndDrawing(WrenVM *);

void wray_TargetFPS_set(WrenVM *);
void wray_FPS_get(WrenVM *);
void wray_FrameTime_get(WrenVM *);
void wray_Time_get(WrenVM *);

void wray_ConfigFlags_set(WrenVM *);
void wray_TakeScreenshot(WrenVM *);

void wray_StorageSaveValue(WrenVM *);
void wray_StorageLoadValue(WrenVM *);

void wray_OpenURL(WrenVM *);

void wray_DrawFPS(WrenVM *);
void wray_DrawText(WrenVM *);
void wray_DrawTextEx(WrenVM *);
void wray_DrawTextRec(WrenVM *);
void wray_DrawTextRecEx(WrenVM *);

void wray_IsKeyUp(WrenVM *vm);
void wray_isKeyDown(WrenVM *vm);
void wray_IsKeyPressed(WrenVM *vm);
void wray_IsKeyReleased(WrenVM *vm);

#endif /* H_WRAY_CORE */
