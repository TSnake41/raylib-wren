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
  //
  // module: core
  //
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

  //foreign static getMonitorSize(monitor)
  //foreign static getMonitorPhysicalSize(monitor)
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

  /* No filesystem functions, they will instead be implemented as a separate module. */

  foreign static storageSaveValue(position, value)
  foreign static storageLoadValue(position)

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

  static mousePosition { RlVector2.new(mouseX, mouseY) }

  foreign static mousePosition=(position)
  foreign static mouseOffset=(offset)
  foreign static mouseScale=(scale)
  foreign static mouseWheelMove

  foreign static targetFPS=(fps)
  foreign static fps
  foreign static frameTime
  foreign static time

  static screenSize { RlVector2.new(screenWidth, screenHeight) }

  //
  // module: shapes
  //
  foreign static drawPixel(position, color)

  foreign static drawLine(start, end, color)
  foreign static drawLine(start, end, thick, color)
  foreign static drawLineBezier(start, end, thick, color)
  foreign static drawLineStrip(points, color)

  foreign static drawCircle(center, radius, color)
  foreign static drawCircleLines(center, radius, color)
  foreign static drawCircleSector(center, radius, start, end, segments, color)
  foreign static drawCircleSectorLines(center, radius, start, end, segments, color)
  foreign static drawCircleGradient(center, radius, color1, color2)

  foreign static drawRing(center, inner, outer, start, end, segments, color)
  foreign static drawRingLines(center, inner, outer, start, end, segments, color)

  foreign static drawRectangle(rectangle, color)
  foreign static drawRectangleLines(rectangle, color)
  foreign static drawRectangleLines(rectangle, thick, color)
  foreign static drawRectangleRounded(rectangle, roundness, segments, color)
  foreign static drawRectangleRoundedLines(rectangle, roundness, segments, color)

  foreign static drawRectangleGradient(rectangle, c1, c2, c3, c4)
  foreign static drawRectangleGradientV(rectangle, color1, color2)
  foreign static drawRectangleGradientH(rectangle, color1, color2)

  foreign static drawTriangle(v1, v2, v3, color)
  foreign static drawTriangleLines(v1, v2, v3, color)
  foreign static drawTriangleFan(points, color)
  foreign static drawPoly(center, sides, radius, rotation, color)

  foreign static drawTexture(texture, position, color)
  foreign static setShapesTexture(texture, source)

  // Some rectangle/vector-less variants.
  static drawPixel(x, y, color) {
    drawPixel(RlVector2.new(x, y), color)
  }

  static drawLine(sx, sy, ex, ey, color) {
    drawLine(RlVector2.new(sx, sy), RlVector2.new(ex, ey), color)
  }

  static drawLine(sx, sy, ex, ey, thick, color) {
    drawLine(RlVector2.new(sx, sy), RlVector2.new(ex, ey), thick, color)
  }

  static drawLineBezier(sx, sy, ex, ey, thick, color) {
    drawLineBezier(RlVector2.new(sx, sy), RlVector2.new(ex, ey), thick, color)
  }

  static drawCircle(cx, cy, radius, color) {
    drawCircle(RlVector2.new(cx, cy), radius, color)
  }

  static drawCircleLines(cx, cy, radius, color) {
    drawCircleLines(RlVector2.new(cx, cy), radius, color)
  }

  static drawCircleSector(cx, cy, radius, start, end, segments, color) {
    drawCircleSector(RlVector2.new(cx, cy), radius, start, end, segments, color)
  }

  static drawCircleSectorLines(cx, cy, radius, start, end, segments, color) {
    drawCircleSectorLines(RlVector2.new(cx, cy), radius, start, end, segments, color)
  }

  static drawCircleGradient(cx, cy, radius, color1, color2) {
    drawCircleGradient(RlVector2.new(cx, cy), radius, color1, color2)
  }

  static drawRing(cx, cy, inner, outer, start, end, segments, color) {
    drawRing(RlVector2.new(cx, cy), inner, outer, start, end, segments, color)
  }

  static drawRingLines(cx, cy, inner, outer, start, end, segments, color) {
    drawRingLines(RlVector2.new(cx, cy), inner, outer, start, end, segments, color)
  }

  static drawRectangle(x, y, w, h, color) {
    drawRectangle(RlRectangle.new(x, y, w, h), color)
  }

  // TODO: drawRectangle, pro version
  // foreign static drawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color)

  static drawRectangleLines(x, y, w, h, color) {
    drawRectangleLines(RlRectangle.new(x, y, w, h), color)
  }

  static drawRectangleLines(x, y, w, h, thick, color) {
    drawRectangleLines(RlRectangle.new(x, y, w, h), thick, color)
  }

  static drawRectangleRounded(x, y, w, h, roundness, segments, color) {
    return drawRectangleRounded(RlRectangle.new(x, y, w, h), roundness, segments, color)
  }

  static drawRectangleRoundedLines(x, y, w, h, roundness, segments, color) {
    return drawRectangleRoundedLines(RlRectangle.new(x, y, w, h), roundness, segments, color)
  }

  static drawRectangleGradientV(x, y, w, h, color1, color2) {
    drawRectangleGradientV(RlRectangle.new(x, y, w, h), color1, color2)
  }

  static drawRectangleGradientH(x, y, w, h, color1, color2) {
    drawRectangleGradientH(RlRectangle.new(x, y, w, h), color1, color2)
  }

  static drawRectangleGradient(x, y, w, h, c1, c2, c3, c4) {
    drawRectangleGradient(RlRectangle.new(x, y, w, h), c1, c2, c3, c4)
  }

  //
  // module: text
  //
  foreign static drawText(text, x, y, font_size, color)

  // WTF ?
  foreign static drawText(font, text, position, font_size, spacing, color)
  foreign static drawText(font, text, rect, font_size, spacing, do_wrap, color)
  foreign static drawText(font, text, rect, font_size, spacing, do_wrap, color, select_range, select_color, select_back)

  //
  // module: audio
  //
  /*foreign static initAudioDevice()
  foreign static closeAudioDevice()
  foreign static isAudioDeviceReady
  foreign static masterVolume=(volume)*/
}
