foreign class RlRectangle {
  foreign [index]
  foreign [index]=(value)

  x { this[0] }
  y { this[1] }
  width { this[2] }
  height { this[3] }

  x=(value) { this[0] = (value) }
  y=(value) { this[1] = (value) }
  width=(value) { this[2] = (value) }
  height=(value) { this[3] = (value) }

  foreign construct new(x, y, w, h)

  new(pos, size) {
    return new(pos.x, pos.y, size.x, size.y)
  }
}
