foreign class RlColor {
  foreign hex

  foreign r
  foreign g
  foreign b
  foreign a

  foreign r=(value)
  foreign g=(value)
  foreign b=(value)
  foreign a=(value)

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

class Raylib {
  // core
  foreign static initWindow(width, height, title)
  foreign static closeWindow()
  foreign static windowShouldClose
  foreign static isWindowReady
  foreign static isWindowMinimized
  foreign static isWindowResized
  foreign static isWindowHidden
  foreign static toggleFullscreen()

  foreign static windowTitle=(title)
  foreign static windowPosition=(position)
  foreign static windowIcon=(image)
  foreign static windowMinSize=(size)

  foreign static setWindowMonitor(monitor)
  foreign static setWindowSize(size)

  foreign static screenSize
  foreign static monitorCount
  foreign static clipboardText
  foreign static clipboardText=(text)

  //foreign static GetMonitorSize(monitor)
  //foreign static GetMonitorPhysicalSize(monitor)
  //foreign static GetMonitorName(monitor)

  foreign static cursorVisible
  foreign static cursorVisible=(shown)

  foreign static cursorLocked=(locked)

  foreign static clearBackground_Color(color)
  foreign static clearBackground_List(color)

  static clearBackground(color) {
    if (color is List) {
      clearBackground_List(color)
    } else if (color.type.name == "RlColor") {
      clearBackground_Color(color)
    } else {
      Fiber.abort("Invalid argument.")
    }
  }

  foreign static beginDrawing()
  foreign static endDrawing()

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

  foreign static targetFPS=(fps)
  foreign static fps
  foreign static frameTime
  foreign static time

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
