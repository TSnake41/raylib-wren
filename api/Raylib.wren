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

class Raylib {
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

  //foreign static getMonitorSize(monitor)
  //foreign static getMonitorPhysicalSize(monitor)
  foreign static getMonitorName(monitor)

  foreign static cursorVisible
  foreign static cursorVisible=(shown)

  foreign static cursorLocked=(locked)

  foreign static clearBackground_Color(color)
  foreign static clearBackground_List(color)

  static clearBackground(color) {
    if (color is RlColor) {
      clearBackground_Color(color)
    } else if (color is List) {
      clearBackground_List(color)
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

  // WTF ?
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

  //foreign static isKeyUp_kc(keycode)
  //foreign static isKeyDown_kc(keycode)
  //foreign static IsKeyPressed_kc(keycode)
  //foreign static IsKeyReleased_kc(keycode)

  static isKeyUp_kc(keycode) {

  }

  static isKeyDown_kc(keycode) {

  }

  static IsKeyPressed_kc(keycode) {

  }

  static IsKeyReleased_kc(keycode) {

  }

  // Some more stuff ...
}
