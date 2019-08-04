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

void wray_InitWindow(WrenVM *vm);
void wray_CloseWindow(WrenVM *vm);

void wray_WindowShouldClose_get(WrenVM *vm);
void wray_IsWindowReady_get(WrenVM *vm);
void wray_IsWindowMinimized_get(WrenVM *vm);
void wray_IsWindowResized_get(WrenVM *vm);
void wray_IsWindowHidden_get(WrenVM *vm);

void wray_ToggleFullscreen(WrenVM *vm);
void wray_WindowTitle_set(WrenVM *vm);
void wray_WindowIcon_set(WrenVM *vm);
void wray_SetWindowSize(WrenVM *vm);
void wray_SetWindowMonitor(WrenVM *vm);
void wray_WindowMinSize_set(WrenVM *vm);
void wray_ScreenSize_get(WrenVM *vm);
void wray_MonitorCount_get(WrenVM *vm);
void wray_WindowPosition_set(WrenVM *vm);

void wray_ClipboardText_get(WrenVM *vm);
void wray_ClipboardText_set(WrenVM *vm);

void wray_CursorVisible_get(WrenVM *vm);
void wray_CursorVisible_set(WrenVM *vm);
void wray_CursorLocked_set(WrenVM *vm);

void wray_ClearBackgroundList(WrenVM *vm);
void wray_ClearBackgroundColor(WrenVM *vm);

void wray_BeginDrawing(WrenVM *vm);
void wray_EndDrawing(WrenVM *vm);

void wray_TargetFPS_set(WrenVM *vm);
void wray_FPS_get(WrenVM *vm);
void wray_FrameTime_get(WrenVM *vm);
void wray_Time_get(WrenVM *vm);

#endif /* H_WRAY_CORE */
