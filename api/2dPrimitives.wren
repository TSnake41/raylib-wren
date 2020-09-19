class Rectangle {
  name { "Rectangle" }

  construct new(w, h, color, lines) {
    _w = w
    _h = h
    _color = color
    _lines = lines

    _ox = 0
    _oy = 0
  }

  construct new(w, h, color) {
    _w = w
    _h = h
    _color = color
    _lines = false

    _ox = 0
    _oy = 0
  }

  construct new(w, h) {
    _w = w
    _h = h
    _color = Color.white
    _lines = false

    _ox = 0
    _oy = 0
  }

  ox { _ox }
  ox=(value) { _ox = value }
  oy { _oy }
  oy=(value) { _oy = value }

  w { _w }
  w=(value) { _w = value }

  h { _h }
  h=(value) { _h = value }

  color { _color }
  color=(c) { _color = c }

  lines { _lines }
  lines=(value) { _lines = value }

  foreign static draw(x, y, w, h, color, lines)

  draw(p, x, y, z) {
    Rectangle.draw(x + _ox, y + _oy, _w, _h, _color, _lines)
  }

  update(p, dt) {}
}

class Circle {
  name { "Circle" }

  construct new(radius, color, lines) {
    _radius = radius
    _color = color
    _lines = lines

    _ox = 0
    _oy = 0
  }

  construct new(radius, color) {
    _radius = radius
    _color = color
    _lines = false

    _ox = 0
    _oy = 0
  }

  construct new(radius) {
    _radius = radius
    _color = Color.white
    _lines = false

    _ox = 0
    _oy = 0
  }

  ox { _ox }
  ox=(value) { _ox = value }
  oy { _oy }
  oy=(value) { _oy = value }

  radius { _radius }
  radius=(value) { _radius = value }

  color { _color }
  color=(c) { _color = c }

  lines { _lines }
  lines=(value) { _lines = value }

  foreign static draw(x, y, radius, color, lines)

  draw(p, x, y, z) {
    Circle.draw(x + _ox, y + _oy, _radius, _color, _lines)
  }

  update(p, dt) {}
}

foreign class Texture2D {
  foreign construct new(image)

  foreign width
  foreign height
  foreign format
  foreign mipmaps

  foreign draw(x, y, rotation, scale, color)
}

class Sprite {
  name { "Sprite" }

  construct new(image, color) {
    _texture = Texture2D.new(image)
    _color = color

    _ox = 0
    _oy = 0
  }

  ox { _ox }
  ox=(value) { _ox = value }
  oy { _oy }
  oy=(value) { _oy = value }

  static new(image) { new(image, Color.white) }

  rotation { _r }
  rotation=(value) { _r = value }

  scale { _scale }
  scale=(value) { _scale = value }

  color { _color }
  color=(value) { _color = value }

  draw(p, x, y, z) {
    _texture.draw(x + _ox, y + _oy, _color, _r, _scale)
  }

  update(p, dt) {}
}

class Text {
  name { "Text" }

  construct new(text, size, color) {
    _text = text
    _size = size
    _color = color

    _ox = 0
    _oy = 0
  }

  ox { _ox }
  ox=(value) { _ox = value }
  oy { _oy }
  oy=(value) { _oy = value }

  static new(text, size) { new(text, size, Color.white) }
  static new(text) { new(text, 20, Color.white) }
  static new() { new("", 20, Color.white) }

  text { _text }
  text=(value) { _text = value }

  size { size }
  size=(value) { _size = value }

  color { _color }
  color=(value) { _color = value }

  foreign static draw(x, y, text, size, color)

  draw(p, x, y, z) {
    Text.draw(x + _ox, y + _oy, _text, _size, _color)
  }

  update(p, dt) {}
}

class FpsDisplay {
  construct new() {
    _ox = 0
    _oy = 0
  }

  ox { _ox }
  ox=(value) { _ox = value }
  oy { _oy }
  oy=(value) { _oy = value }

  draw(p, x, y, z) {
    Raylib.drawFPS(x + _ox, y + _oy)
  }
  update(p, dt) {}
}
