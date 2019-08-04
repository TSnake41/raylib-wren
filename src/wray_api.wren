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

  // TODO: Should use Vector4 ?
  normalized { new(r / 0xFF, g / 0xFF, b / 0xFF, a / 0xFF) }

  fade(alpha) {
    if (alpha > 1.0) {
      alpha = 1.0
    } else if (alpha < 0.0) {
      alpha = 0.0
    }

    a = 0xFF * alpha
  }

    /*
      Vector3 ColorToHSV(Color color);
      Color ColorFromHSV(Vector3 hsv);
    */

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

/*
foreign class RlVector4 {
  foreign [index]
  foreign [index]=(value)


}

foreign class RlVector3 {

}

foreign class RlVector2 {

}
*/

class RlConfigFlags {
  static showLogo { 1 }
  static fullscreenMode { 2 }
  static resizable { 4 }
  static undecorated { 8 }
  static transparent { 16 }
  static msaa4x { 32 }
  static vsync { 64 }
  static hidden { 128 }
  static alwaysRun { 256 }
}

var keyboard_keys = {
  "apostrophe": 39,
  "comma": 44
  /* ... */
}

class RlKey {
  /* TODO: Implement keys enum as map or constants ? */
  static keyboard { keyboard_keys }
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

  foreign static configFlags=(flags)
  /* TODO: Implement trace functions ? */

  foreign static takeScreenshot(path)

  /* No filesystem functions, they will instead be implemented as a separate module. */

  foreign static storageSaveValue(position, value)
  foreign static storageLoadValue(position)

  foreign static openURL(url)

  foreign static drawFPS(x, y)
  foreign static drawText(text, x, y, font_size, color)
  foreign static drawText(font, text, position, font_size, spacing, color)
  foreign static drawText(font, text, rect, font_size, spacing, do_wrap, color)
  foreign static drawText(font, text, rect, font_size, spacing, do_wrap, color, select_range, select_color, select_back)

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

  // Some more stuff ...
}
