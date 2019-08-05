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

  // foreign construct fromHSV()
  // foreign toHSV()

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

  static lightGray { new(200, 200, 200) }
  static gray { new(200, 200, 200) }
  static drakGray { new(200, 200, 200) }
  static yellow { new(200, 200, 200) }
  static gold { new(200, 200, 200) }
  static orange { new(200, 200, 200) }
  static pink { new(200, 200, 200) }
  static red { new(230, 41, 55) }
  static maroon { new(190, 33, 55) }
  static green { new(0, 228, 48) }
  static lime { new(0, 158, 47) }
  static darkGreen { new(0, 117, 44) }
  static skyBlue  { new(102, 191, 255) }
  static blue { new(0, 121, 241) }
  static darkBlue { new(0, 82, 172) }
  static purple { new(200, 122, 255) }
  static violet { new(135, 60, 190) }
  static darkPurple { new(112, 31, 126) }
  static beige { new(211, 176, 131) }
  static brown { new(127, 106, 79) }
  static darkBrown { new(76, 63, 47) }

  static white { new(255, 255, 255) }
  static black { new(0, 0, 0) }
  static megenta { new(255, 0, 255) }
  static rayWhite { new(245, 245, 245) }

  static blank { new(0, 0, 0, 0) }
}

foreign class RlVector2 {
  foreign [index]
  foreign [index]=(value)

  x { this[0] }
  y { this[1] }

  x=(value) { this[0] = value }
  y=(value) { this[1] = value }

  construct new() {
    return new(0, 0)
  }
  foreign construct new(x, y)

  static zero { new() }
}

foreign class RlVector3 {
  foreign [index]
  foreign [index]=(value)

  x { this[0] }
  y { this[1] }
  z { this[2] }

  x=(value) { this[0] = value }
  y=(value) { this[1] = value }
  z=(value) { this[2] = value }

  construct new() {
    return new(0, 0, 0)
  }
  foreign construct new(x, y, z)

  static zero { new() }
}

foreign class RlVector4 {
  foreign [index]
  foreign [index]=(value)

  x { this[0] }
  y { this[1] }
  z { this[2] }
  w { this[3] }

  x=(value) { this[0] = value }
  y=(value) { this[1] = value }
  z=(value) { this[2] = value }
  w=(value) { this[3] = value }

  construct new() {
    return new(0, 0, 0, 0)
  }
  foreign construct new(x, y, z, w)

  static zero { new() }
}

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
  // Alphanumeric keys
  "apostrophe": 39,
  "comma": 44,
  "minus": 45,
  "period": 46,
  "slash": 47,
  "zero": 48,
  "one": 49,
  "two": 50,
  "three": 51,
  "four": 52,
  "five": 53,
  "six": 54,
  "seven": 55,
  "eight": 56,
  "nine": 57,
  "semicolon": 59,
  "equal": 61,
  "a": 65,
  "b": 66,
  "c": 67,
  "d": 68,
  "e": 69,
  "f": 70,
  "g": 71,
  "h": 72,
  "i": 73,
  "j": 74,
  "k": 75,
  "l": 76,
  "m": 77,
  "n": 78,
  "o": 79,
  "p": 80,
  "q": 81,
  "r": 82,
  "s": 83,
  "t": 84,
  "u": 85,
  "v": 86,
  "w": 87,
  "x": 88,
  "y": 89,
  "z": 90,

  // Function keys
  "space": 32,
  "escape": 256,
  "enter": 257,
  "tab": 258,
  "backspace": 259,
  "insert": 260,
  "delete": 261,
  "right": 262,
  "left": 263,
  "down": 264,
  "up": 265,
  "page_up": 266,
  "page_down": 267,
  "home": 268,
  "end": 269,
  "caps_lock": 280,
  "scroll_lock": 281,
  "num_lock": 282,
  "print_screen": 283,
  "pause": 284,
  "f1": 290,
  "f2": 291,
  "f3": 292,
  "f4": 293,
  "f5": 294,
  "f6": 295,
  "f7": 296,
  "f8": 297,
  "f9": 298,
  "f10": 299,
  "f11": 300,
  "f12": 301,
  "left_shift": 340,
  "left_control": 341,
  "left_alt": 342,
  "left_super": 343,
  "right_shift": 344,
  "right_control": 345,
  "right_alt": 346,
  "right_super": 347,
  "kb_menu": 348,
  "left_bracket": 91,
  "backslash": 92,
  "right_bracket": 93,
  "grave": 96,

  // Keypad keys
  "kp_0": 320,
  "kp_1": 321,
  "kp_2": 322,
  "kp_3": 323,
  "kp_4": 324,
  "kp_5": 325,
  "kp_6": 326,
  "kp_7": 327,
  "kp_8": 328,
  "kp_9": 329,
  "kp_decimal": 330,
  "kp_divide": 331,
  "kp_multiply": 332,
  "kp_subtract": 333,
  "kp_add": 334,
  "kp_enter": 335,
  "kp_equal": 336,

  // Android buttons (?)
  // TODO: Move them ?
  "back": 4,
  "menu": 82,
  "volume_up": 24,
  "volume_down": 25
}

class RlKey {
  static keyboard { keyboard_keys }
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

  // Some more stuff ...
}
