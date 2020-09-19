class ConfigFlags {
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

  foreign static screenWidth
  foreign static screenHeight
  foreign static monitorCount
  foreign static clipboardText
  foreign static clipboardText=(text)

  foreign static getMonitorName(monitor)

  foreign static cursorVisible
  foreign static cursorVisible=(shown)
  foreign static cursorLocked=(locked)

  foreign static clearBackground(color)
  foreign static beginDrawing()
  foreign static endDrawing()

  foreign static configFlags=(flags)
  /* TODO: Implement trace functions ? */

  foreign static takeScreenshot(path)

  foreign static saveStorageValue(position, value)
  foreign static loadStorageValue(position)

  foreign static openURL(url)
  foreign static drawFPS(x, y)

  foreign static isKeyUp(keycode)
  foreign static isKeyDown(keycode)
  foreign static isKeyPressed(keycode)
  foreign static isKeyReleased(keycode)
  foreign static exitKey=(key)
  foreign static keyPressed

  foreign static isMouseButtonPressed(button)
  foreign static isMouseButtonDown(button)
  foreign static isMouseButtonReleased(button)
  foreign static isMouseButtonUp(button)

  foreign static mouseX
  foreign static mouseY

  static mousePosition { Vector2.new(mouseX, mouseY) }

  foreign static mousePosition=(position)
  foreign static mouseOffset=(offset)
  foreign static mouseScale=(scale)
  foreign static mouseWheelMove

  foreign static targetFPS=(fps)
  foreign static fps
  foreign static frameTime
  foreign static time

  static screenSize { Vector2.new(screenWidth, screenHeight) }
}
