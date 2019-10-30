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
#include "wray_draw.h"
#include "wray_classes.h"

#define STATIC_FN(name, sig) { wray_##name, true, sig },

#define STATIC_GET(name, sig) { wray_##name##_get, true, sig },
#define STATIC_SET(name, sig) { wray_##name##_set, true, sig },

static const wray_binding_class wray_raylib_class = {
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
    STATIC_SET(WindowPosition, "windowPosition=(_)")
    STATIC_SET(WindowIcon, "windowIcon=(_)")
    STATIC_SET(WindowMinSize, "windowMinSize=(_)")

    STATIC_FN(SetWindowMonitor, "setWindowMonitor(_)")
    STATIC_FN(SetWindowSize, "setWindowSize(_)")

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

    STATIC_FN(StorageSaveValue, "storageSaveValue(_,_)")
    STATIC_FN(StorageLoadValue, "storageLoadValue(_)")

    STATIC_FN(OpenURL, "openURL(_)")
    STATIC_FN(DrawFPS, "drawFPS(_,_)")

    STATIC_FN(DrawText, "drawText(_,_,_,_,_)")

    /* draw */
    /* TODO: Move these overloads to RlFont, they are hardly implementable as it is. */
    STATIC_FN(DrawTextEx, "drawText(_,_,_,_,_,_)")
    STATIC_FN(DrawTextRec, "drawText(_,_,_,_,_,_,_)")
    STATIC_FN(DrawTextRecEx, "drawText(_,_,_,_,_,_,_,_,_,_)")

    STATIC_FN(DrawPixel, "drawPixel(_,_)")

    STATIC_FN(DrawLine, "drawLine(_,_,_)")
    STATIC_FN(DrawLineThick, "drawLine(_,_,_,_)")
    STATIC_FN(DrawLineBezier, "drawLineBezier(_,_,_,_)")
    STATIC_FN(DrawLineStrip, "drawLineStrip(_,_)")

    STATIC_FN(DrawCircle, "drawCircle(_,_,_)")
    STATIC_FN(DrawCircleLines, "drawCircleLines(_,_,_)")
    STATIC_FN(DrawCircleSector, "drawCircleSector(_,_,_,_,_,_)")
    STATIC_FN(DrawCircleSectorLines, "drawCircleSectorLines(_,_,_,_,_,_)")
    STATIC_FN(DrawCircleGradient, "drawCircleGradient(_,_,_,_)")

    STATIC_FN(DrawRing, "drawRing(_,_,_,_,_,_,_)")
    STATIC_FN(DrawRingLines, "drawRingLines(_,_,_,_,_,_,_)")

    STATIC_FN(DrawRectangle, "drawRectangle(_,_)")
    STATIC_FN(DrawRectangleLines, "drawRectangleLines(_,_)")
    STATIC_FN(DrawRectangleLinesThick, "drawRectangleLines(_,_,_)")
    STATIC_FN(DrawRectangleRounded, "drawRectangleRounded(_,_,_,_)")
    STATIC_FN(DrawRectangleRoundedLines, "drawRectangleRoundedLines(_,_,_,_)")

    STATIC_FN(DrawRectangleGradient, "drawRectangleGradient(_,_,_,_,_)")
    STATIC_FN(DrawRectangleGradientV, "drawRectangleGradientV(_,_,_)")
    STATIC_FN(DrawRectangleGradientH, "drawRectangleGradientH(_,_,_)")

    STATIC_FN(DrawTriangle, "drawTriangle(_,_,_,_)")
    STATIC_FN(DrawTriangleLines, "drawTriangleLines(_,_,_,_)")
    STATIC_FN(DrawTriangleFan, "drawTriangleFan(_,_)")
    STATIC_FN(DrawPoly, "drawPoly(_,_,_,_,_)")

    STATIC_FN(SetShapesTexture, "setShapesTexture(_,_)")
    STATIC_FN(DrawTexture, "drawTexture(_,_,_)")

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

    STATIC_SET(MousePosition, "mousePosition=(_)")
    STATIC_SET(MouseOffset, "mouseOffset=(_)")
    STATIC_SET(MouseScale, "mouseScale=(_)")

    /* misc */
    STATIC_SET(TargetFPS, "targetFPS=(_)")
    STATIC_GET(FPS, "fps")
    STATIC_GET(FrameTime, "frameTime")
    STATIC_GET(Time, "time")
    { NULL, NULL, NULL }
  }
};

const wray_binding_class *wray_classes[] = {
  /* Default static class */
  &wray_raylib_class,

  &wray_vec2_class,
  &wray_vec3_class,
  &wray_vec4_class,
  &wray_rectangle_class,
  &wray_color_class,
  &wray_image_class,
  &wray_texture2d_class
};
const size_t wray_classes_count = sizeof(wray_classes) / sizeof(wray_classes[0]);
