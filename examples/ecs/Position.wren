class Position {
  construct new(x, y, rotation) {
    _x = x
    _y = y
    _rotation = rotation
  }

  x { _x }
  x=(value) { _x = value }

  y { _y }
  y=(value) { _y = value }

  rotation { _rotation }
  rotation=(value) { _rotation = value }
}
