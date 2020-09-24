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

  foreign static setWindowPosition(x, y)
  foreign static setWindowSize(x, y)

  foreign static windowTitle=(title)
  foreign static windowIcon=(image)
  static windowPosition=(position) { setWindowPosition(position.x, position.y) }
  static windowMinSize=(size) { setWindowSize(size.x, size.y) }

  foreign static setWindowMonitor(monitor)

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

  foreign static setMousePosition(x, y)
  foreign static setMouseOffset(x, y)
  foreign static setMouseScale(x, y)

  static mousePosition=(position) { setMousePosition(position.x, position.y) }
  static mouseOffset=(offset) { setMouseOffset(offset.x, offset.y) }
  static mouseScale=(scale) { setMouseScale(scale.x, scale.y) }

  foreign static mouseWheelMove

  foreign static targetFPS=(fps)
  foreign static fps
  foreign static frameTime
  foreign static time

  static screenSize { Vector2.new(screenWidth, screenHeight) }

  // Low level draw functions
  foreign static drawPixel(x, y, color)
  foreign static drawLine(ax, ay, bx, by, color, thick, bezier)
  foreign static drawCircle(x, y, radius, color, lines, startAngle, endAngle, segments)
  foreign static drawEllipse(x, y, w, h, color, lines)
  foreign static drawRing(x, y, inner, outer, start, end, segments, color, lines)
  foreign static drawRectanglePro(x, y, w, h, ox, oy, rotation, color)
  foreign static drawRectangleLines(x, y, w, h, color, thick)
  foreign static drawRectangleRounded(x, y, w, h, roundness, segments, color, lines_thick)
  foreign static drawRectangleGradient(x, y, w, h, c1, c2, c3, c4)
  foreign static drawTriangle(x1, y1, x2, y2, x3, y3, color, lines)
  foreign static drawPoly(x, y, sides, radius, rotation, color, lines)
  foreign static drawTexture(texture, x, y, color, rotation, scale)
  foreign static drawTexturePro(texture, sx, sy, sw, sh, dx, dy, dw, dh, ox, oy, rotation, color)
  foreign static drawText(text, x, y, size, color)
  // foreign static drawText(font, text, x, y, size, spacing, color)

  // Higher level draw functions.
  static drawPixel(v, color) { drawPixel(v.x, v.y, color) }

  static drawLine(ax, ay, bx, by, color) {
    drawLine(ax, ay, bx, by, color, null, false)
  }

  static drawLine(a, b, color) {
    drawLine(a.x, a.y, b.x, b.y, color, null, false)
  }

  static drawLine(a, b, color, thick) {
    drawLine(a.x, a.y, b.x, b.y, color, thick, false)
  }

  static drawLineBezier(a, b, color, thick) {
    drawLine(a.x, a.y, b.x, b.y, color, thick, true)
  }

  static drawCircle(x, y, radius, color) {
    drawCircle(x, y, radius, color, false, null, null, null)
  }

  static drawCircle(center, radius, color) {
    drawCircle(center.x, center.y, radius, color, false, null, null, null)
  }

  static drawCircleLines(x, y, radius, color) {
    drawCircle(x, y, radius, color, true, null, null, null)
  }

  static drawCircleLines(center, radius, color) {
    drawCircle(center.x, center.y, radius, color, true, null, null, null)
  }

  static drawCircleSector(center, radius, start, end, segments, color) {
    drawCircle(center.x, center.y, radius, color, false, start, end, segments)
  }

  static drawCircleSectorLines(center, radius, start, end, segments, color) {
    drawCircle(center.x, center.y, radius, color, true, start, end, segments)
  }

  static drawEllipse(x, y, w, h, color) {
    drawEllipse(x, y, w, h, color, false)
  }

  static drawEllipseLines(x, y, w, h, color) {
    drawEllipse(x, y, w, h, color, true)
  }

  static drawRing(x, y, inner, outer, start, end, segments, color) {
    drawRing(x, y, inner, outer, start, end, segments, color, false)
  }

  static drawRingLines(x, y, inner, outer, start, end, segments, color) {
    drawRing(x, y, inner, outer, start, end, segments, color, true)
  }

  static drawRectangle(x, y, w, h, color) {
    drawRectanglePro(x, y, w, h, 0, 0, 0, color)
  }

  static drawRectangle(pos, size, color) {
    drawRectanglePro(pos.x, pos.y, size.x, size.y, 0, 0, 0, color)
  }

  static drawRectangle(rect, color) {
    drawRectanglePro(rect.x, rect.y, rect.w, rect.h, 0, 0, 0, color)
  }

  static drawRectanglePro(rect, origin, rotation, color) {
    drawRectanglePro(rect.x, rect.y, rect.w, rect.h, origin.x, origin.y, rotation, color)
  }

  static drawRectangleLines(x, y, w, h, color) {
    drawRectangleLines(x, y, w, h, color, null)
  }

  static drawRectangleLines(rect, thick, color) {
    drawRectangleLines(rect.x, rect.y, rect.w, rect.h, color, thick)
  }

  static drawRectangleRounded(rect, roundness, segments, color) {
    drawRectangleRounded(rect.x, rect.y, rect.w, rect.h, roundness,
      segments, color, false)
  }

  static drawRectangleRoundedLines(rect, roundness, segments, color) {
    drawRectangleRounded(rect.x, rect.y, rect.w, rect.h, roundness,
      segments, color, true)
  }

  static drawRectangleGradient(rect, c1, c2, c3, c4) {
    drawRectangleGradient(rect.x, rect.y, rect.w, rect.h, c1, c2, c3, c4)
  }

  static drawRectangleGradientV(x, y, w, h, c1, c2) {
    drawRectangleGradient(x, y, w, h, c1, c1, c2, c2)
  }

  static drawRectangleGradientH(x, y, w, h, c1, c2) {
    drawRectangleGradient(x, y, w, h, c1, c2, c1, c2)
  }

  static drawTriangle(v1, v2, v3, color) {
    drawTriangle(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y, color, false)
  }

  static drawTriangleLines(v1, v2, v3, color) {
    drawTriangle(v1.x, v1.y, v2.x, v2.y, v3.x, v3.y, color, true)
  }

  static drawPoly(center, sides, radius, rotation, color) {
    drawPoly(center.x, center.y, sides, radius, rotation, color, false)
  }

  static drawPolyLines(center, sides, radius, rotation, color) {
    drawPoly(center.x, center.y, sides, radius, rotation, color, true)
  }

  static drawTexture(texture, x, y, color) {
    drawTexture(texture, x, y, color, 0, 1)
  }

  static drawTexture(texture, position, color) {
    drawTexture(texture, position.x, position.y, color, 0, 1)
  }

  static drawTexture(texture, position, rotation, scale, color) {
    drawTexture(texture, position.x, position.y, color, rotation, scale)
  }

  static drawTextureRec(texture, srcRec, position, color) {
    drawTexture(texture, srcRec.x, srcRec.y, srcRec.w, srcRec.h,
      position.x, position.y, srcRec.w.abs, srcRec.h.abs, 0, 0, color)
  }

  static drawTextureQuad(texture, tiling, offset, quad, color) {
    drawTexture(
      offset.x * texture.w, offset.y * texture.h,
      tiling.x * texture.w, tiling.y * texture.h,
      0, 0, 0, color)
  }

  static drawTextureTiled(texture, srcRec, dstRec, origin, rotation, scale, tint) {
    // NYI
    Fiber.abort("This function is not yet implemented.")
  }
}
