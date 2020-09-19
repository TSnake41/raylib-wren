class Rectangle {
  name { "Rectangle" }

  construct new(w, h, color, lines) {
    _w = w
    _h = h
    _color = color
    _lines = lines
  }

  construct new(w, h, color) {
    _w = w
    _h = h
    _color = color
    _lines = false
  }

  construct new(w, h) {
    _w = w
    _h = h
    _color = Color.white
    _lines = false
  }

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
    Rectangle.draw(x, y, _w, _h, _color, _lines)
  }

  update(p, dt) {}
}

class Circle {
  name { "Circle" }

  construct new(radius, color, lines) {
    _r = radius
    _color = color
    _lines = lines
  }

  construct new(radius, color) {
    _r = radius
    _color = color
    _lines = false
  }

  construct new(radius) {
    _r = radius
    _color = Color.white
    _lines = false
  }

  radius { _r }
  radius=(value) { _r = value }

  color { _color }
  color=(c) { _color = c }

  lines { _lines }
  lines=(value) { _lines = value }

  foreign static draw(x, y, radius, color, lines)

  draw(p, x, y, z) {
    Circle.draw(x, y, _radius, _color, _lines)
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
  }

  static new(image) { new(image, Color.white) }

  rotation { _r }
  rotation=(value) { _r = value }

  scale { _scale }
  scale=(value) { _scale = value }

  color { _color }
  color=(value) { _color = value }

  draw(p, x, y, z) {
    _texture.draw(x, y, _color, _r, _scale)
  }

  update(p, dt) {}
}

class Text {
  name { "Text" }

  construct new(text, size, color) {
    _text = text
    _size = size
    _color = color
  }

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
    Text.draw(x, y, _text, _size, _color)
  }

  update(p, dt) {}
}
