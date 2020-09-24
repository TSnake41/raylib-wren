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
#include "wray_class.h"

#define STATIC_FN(name, sig) { wray_##name, true, sig },

#define STATIC_GET(name, sig) { wray_##name##_get, true, sig },
#define STATIC_SET(name, sig) { wray_##name##_set, true, sig },

const wray_binding_class wray_raylib_class = {
  "Raylib", { NULL, NULL }, {
    /* core */
    STATIC_FN(InitWindow, "initWindow(_,_,_)")
    STATIC_FN(CloseWindow, "closeWindow()")

    STATIC_GET(WindowShouldClose, "windowShouldClose")

    STATIC_GET(IsWindowReady, "isWindowReady")
    STATIC_GET(IsWindowMinimized, "isWindowMinimized")
    STATIC_GET(IsWindowResized, "isWindowResized")
    STATIC_GET(IsWindowHidden, "isWindowHidden")

    STATIC_FN(ToggleFullscreen, "toggleFullscreen()")

    STATIC_SET(WindowTitle, "windowTitle=(_)")
    STATIC_FN(SetWindowPosition, "setWindowPosition(_,_)")
    STATIC_SET(WindowIcon, "windowIcon=(_)")
    STATIC_FN(SetWindowMinSize, "setWindowMinSize(_,_)")

    STATIC_FN(SetWindowMonitor, "setWindowMonitor(_)")
    STATIC_FN(SetWindowSize, "setWindowSize(_,_)")

    STATIC_GET(ScreenWidth, "screenWidth")
    STATIC_GET(ScreenHeight, "screenHeight")
    STATIC_GET(MonitorCount, "monitorCount")
    STATIC_GET(ClipboardText, "clipboardText")
    STATIC_SET(ClipboardText, "clipboardText=(_)")

    STATIC_FN(GetMonitorName, "getMonitorName(_)")

    STATIC_GET(CursorVisible, "cursorVisible")
    STATIC_SET(CursorVisible, "cursorVisible=(_)")

    STATIC_SET(CursorLocked, "cursorLocked=(_)")

    STATIC_FN(ClearBackground, "clearBackground(_)")
    STATIC_FN(BeginDrawing, "beginDrawing()")
    STATIC_FN(EndDrawing, "endDrawing()")

    STATIC_SET(ConfigFlags, "configFlags=(_)")
    STATIC_FN(TakeScreenshot, "takeScreenshot(_)")

    STATIC_FN(SaveStorageValue, "saveStorageValue(_,_)")
    STATIC_FN(LoadStorageValue, "loadStorageValue(_)")

    STATIC_FN(OpenURL, "openURL(_)")
    STATIC_FN(DrawFPS, "drawFPS(_,_)")

    /* input */
    STATIC_FN(IsKeyUp, "isKeyUp(_)")
    STATIC_FN(isKeyDown, "isKeyDown(_)")
    STATIC_FN(IsKeyPressed, "isKeyPressed(_)")
    STATIC_FN(IsKeyReleased, "isKeyReleased(_)")

    STATIC_FN(IsMouseButtonPressed, "isMouseButtonPressed(_)")
    STATIC_FN(IsMouseButtonDown, "isMouseButtonDown(_)")
    STATIC_FN(IsMouseButtonReleased, "isMouseButtonReleased(_)")
    STATIC_FN(IsMouseButtonUp, "isMouseButtonUp(_)")

    STATIC_SET(ExitKey, "exitKey=(_)")
    STATIC_GET(KeyPressed, "keyPressed")

    STATIC_GET(MouseX, "mouseX")
    STATIC_GET(MouseY, "mouseY")
    STATIC_GET(MouseWheelMove, "mouseWheelMove")

    STATIC_FN(SetMousePosition, "setMousePosition(_,_)")
    STATIC_FN(SetMouseOffset, "setMouseOffset(_,_)")
    STATIC_FN(SetMouseScale, "setMouseScale(_,_)")

    /* misc */
    STATIC_SET(TargetFPS, "targetFPS=(_)")
    STATIC_GET(FPS, "fps")
    STATIC_GET(FrameTime, "frameTime")
    STATIC_GET(Time, "time")
    { NULL, NULL, NULL }
  }
};
