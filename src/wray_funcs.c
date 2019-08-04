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

#define WRAY_STATIC_FN(name, sig) { wray_##name, true, "Raylib", sig },

#define WRAY_STATIC_GET(name, sig) { wray_##name##_get, true, "Raylib", sig },
#define WRAY_STATIC_SET(name, sig) { wray_##name##_set, true, "Raylib", sig },

wray_binding_func wray_funcs[] = {
  /* core */
  WRAY_STATIC_FN(InitWindow, "initWindow(_,_,_)")
  WRAY_STATIC_FN(CloseWindow, "closeWindow()")

  WRAY_STATIC_GET(WindowShouldClose, "windowShouldClose")

  WRAY_STATIC_GET(IsWindowReady, "isWindowReady")
  WRAY_STATIC_GET(IsWindowMinimized, "isWindowMinimized")
  WRAY_STATIC_GET(IsWindowResized, "isWindowResized")
  WRAY_STATIC_GET(IsWindowHidden, "isWindowHidden")

  WRAY_STATIC_FN(ToggleFullscreen, "toggleFullscreen()")

  WRAY_STATIC_SET(WindowTitle, "windowTitle=(_)")
  WRAY_STATIC_SET(WindowPosition, "windowPosition=(_)")
  WRAY_STATIC_SET(WindowIcon, "windowIcon=(_)")
  WRAY_STATIC_SET(WindowMinSize, "windowMinSize=(_)")

  WRAY_STATIC_FN(SetWindowMonitor, "setWindowMonitor(_)")
  WRAY_STATIC_FN(SetWindowSize, "setWindowSize(_)")

  WRAY_STATIC_GET(ScreenSize, "screenSize")
  WRAY_STATIC_GET(MonitorCount, "monitorCount")
  WRAY_STATIC_GET(ClipboardText, "clipboardText")
  WRAY_STATIC_SET(ClipboardText, "clipboardText=(_)")

  WRAY_STATIC_GET(CursorVisible, "cursorVisible")
  WRAY_STATIC_SET(CursorVisible, "cursorVisible=(_)")

  WRAY_STATIC_SET(CursorLocked, "cursorLocked=(_)")

  WRAY_STATIC_FN(ClearBackgroundColor, "clearBackground_Color(_)")
  WRAY_STATIC_FN(ClearBackgroundList, "clearBackground_List(_)")

  WRAY_STATIC_FN(BeginDrawing, "beginDrawing()")
  WRAY_STATIC_FN(EndDrawing, "endDrawing()")

  WRAY_STATIC_SET(TargetFPS, "targetFPS=(_)")
  WRAY_STATIC_GET(FPS, "fps")
  WRAY_STATIC_GET(FrameTime, "frameTime")
  WRAY_STATIC_GET(Time, "time")

  /* Color class */
  { wray_color_hex_get, false, "RlColor", "hex" },
  { wray_color_r_get, false, "RlColor", "r" },
  { wray_color_g_get, false, "RlColor", "g" },
  { wray_color_b_get, false, "RlColor", "b" },
  { wray_color_a_get, false, "RlColor", "a" },

  { wray_color_r_set, false, "RlColor", "r=(_)" },
  { wray_color_g_set, false, "RlColor", "g=(_)" },
  { wray_color_b_set, false, "RlColor", "b=(_)" },
  { wray_color_a_set, false, "RlColor", "a=(_)" },

  { wray_color_r_set, false, "RlColor", "r=(_)" },
  { wray_color_g_set, false, "RlColor", "g=(_)" },
  { wray_color_b_set, false, "RlColor", "b=(_)" },
  { wray_color_a_set, false, "RlColor", "a=(_)" },

  { wray_color_new_hex, false, "RlColor", "init new(_)" },
  { wray_color_new_rgba, false, "RlColor", "init new(_,_,_,_)" },
  { wray_color_new_rgb, false, "RlColor", "init new(_,_,_)" },

  { NULL, NULL, NULL, NULL }
};

wray_class_binding_func wray_class_funcs[] = {
  { "RlColor", { wray_color_initialize, NULL } },

  { NULL, { NULL, NULL } }
};
