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

#include "wray_internal.h"
#include "wray_core.h"
#include "wray_color.h"

#define WRAY_STATIC_FN(name, sig) { wray_##name, true, "rl", sig },

#define WRAY_STATIC_GET(name, sig) { wray_##name##_get, true, "rl", sig },
#define WRAY_STATIC_SET(name, sig) { wray_##name##_set, true, "rl", sig },

wray_binding_func wray_funcs[] = {
  /* core */
  WRAY_STATIC_FN(InitWindow, "InitWindow(_,_,_)")
  WRAY_STATIC_FN(CloseWindow, "CloseWindow()")

  WRAY_STATIC_GET(WindowShouldClose, "WindowShouldClose")

  WRAY_STATIC_GET(IsWindowReady, "IsWindowReady")
  WRAY_STATIC_GET(IsWindowMinimized, "IsWindowMinimized")
  WRAY_STATIC_GET(IsWindowResized, "IsWindowResized")
  WRAY_STATIC_GET(IsWindowHidden, "IsWindowHidden")

  WRAY_STATIC_FN(ToggleFullscreen, "ToggleFullscreen()")

  WRAY_STATIC_SET(WindowTitle, "WindowTitle=(_)")
  WRAY_STATIC_SET(WindowPosition, "WindowPosition=(_)")
  WRAY_STATIC_SET(WindowIcon, "WindowIcon=(_)")
  WRAY_STATIC_SET(WindowMinSize, "WindowMinSize=(_)")

  WRAY_STATIC_FN(SetWindowMonitor, "SetWindowMonitor(_)")
  WRAY_STATIC_FN(SetWindowSize, "SetWindowSize(_)")

  WRAY_STATIC_GET(ScreenSize, "ScreenSize")
  WRAY_STATIC_GET(MonitorCount, "MonitorCount")
  WRAY_STATIC_GET(ClipboardText, "ClipboardText")
  WRAY_STATIC_SET(ClipboardText, "ClipboardText=(_)")

  WRAY_STATIC_GET(CursorVisible, "CursorVisible")
  WRAY_STATIC_SET(CursorVisible, "CursorVisible=(_)")

  WRAY_STATIC_SET(CursorLocked, "CursorLocked=(_)")

  WRAY_STATIC_FN(ClearBackground, "ClearBackground(_)")
  WRAY_STATIC_FN(BeginDrawing, "BeginDrawing()")
  WRAY_STATIC_FN(EndDrawing, "EndDrawing()")

  WRAY_STATIC_SET(TargetFPS, "TargetFPS=(_)")
  WRAY_STATIC_GET(FPS, "FPS")
  WRAY_STATIC_GET(FrameTime, "FrameTime")
  WRAY_STATIC_GET(Time, "Time")

  { NULL, NULL, NULL, NULL }
};
