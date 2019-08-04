class rl {
  // core
  foreign static InitWindow(width, height, title)
  foreign static CloseWindow()
  foreign static WindowShouldClose
  foreign static IsWindowReady
  foreign static IsWindowMinimized
  foreign static IsWindowResized
  foreign static IsWindowHidden
  foreign static ToggleFullscreen()

  foreign static WindowTitle=(title)
  foreign static WindowPosition=(position)
  foreign static WindowIcon=(image)
  foreign static WindowMinSize=(size)

  foreign static SetWindowMonitor(monitor)
  foreign static SetWindowSize(size)

  foreign static ScreenSize
  foreign static MonitorCount
  foreign static ClipboardText
  foreign static ClipboardText=(text)

  //foreign static GetMonitorSize(monitor)
  //foreign static GetMonitorPhysicalSize(monitor)
  //foreign static GetMonitorName(monitor)

  foreign static CursorVisible
  foreign static CursorVisible=(shown)

  foreign static CursorLocked=(locked)

  foreign static ClearBackground(color)

  foreign static BeginDrawing()
  foreign static EndDrawing()

/*
  foreign static BeginMode2D(camera)
  foreign static EndMode2D()
  foreign static BeginMode3D(camera)
  foreign static EndMode3D()
  foreign static BeginTextureMode(target)
  foreign static EndTextureMode()
*/
  /*
    Implemented in rlCamera class

    foreign static GetMouseRay(Vector2 mousePosition);
    foreign static GetWorldToScreen(Vector3 position);
    foreign static GetCameraMatrix(camera);
  */

  foreign static TargetFPS=(fps)
  foreign static FPS
  foreign static FrameTime
  foreign static Time

  /*
    Implemented as rlColor class.

    int ColorToInt(Color color);
    Vector4 ColorNormalize(Color color);
    Vector3 ColorToHSV(Color color);
    Color ColorFromHSV(Vector3 hsv);
    Color GetColor(int hexValue);
    Color Fade(Color color, float alpha);
  */


  // Some more stuff ...
}

foreign class rlColor {
  foreign hex

  foreign r
  foreign g
  foreign b
  foreign a

  foreign r=(_)
  foreign g=(_)
  foreign b=(_)
  foreign a=(_)

  foreign construct new(r, g, b, a)
  foreign construct new(r, g, b)
  foreign construct new(hex)

  static LIGHTGRAY { new(200, 200, 200) }
  static GRAY { new(200, 200, 200) }
  static DARKGRAY { new(200, 200, 200) }
  static YELLOW { new(200, 200, 200) }
  static GOLD { new(200, 200, 200) }
  static ORANGE { new(200, 200, 200) }
  static PINK { new(200, 200, 200) }
  static RED { new(230, 41, 55) }
  static MAROON { new(190, 33, 55) }
  static GREEN { new(0, 228, 48) }
  static LIME { new(0, 158, 47) }
  static DARKGREEN { new(0, 117, 44) }
  static SKYBLUE  { new(102, 191, 255) }
  static BLUE { new(0, 121, 241) }
  static DARKBLUE { new(0, 82, 172) }
  static PURPLE { new(200, 122, 255) }
  static VIOLET { new(135, 60, 190) }
  static DARKPURPLE { new(112, 31, 126) }
  static BEIGE { new(211, 176, 131) }
  static BROWN { new(127, 106, 79) }
  static DARKBROWN { new(76, 63, 47) }

  static WHITE { new(255, 255, 255) }
  static BLACK { new(0, 0, 0) }
  static MAGENTA { new(255, 0, 255) }
  static RAYWHITE { new(245, 245, 245) }

  static BLANK { new(0, 0, 0, 0) }
}
