class Vector2 {
  construct new() {
    _x = 0
    _y = 0
  }

  construct new(x, y) {
    _x = x
    _y = y
   }

  x { _x }
  x=(value) { _x = value }

  y { _y }
  y=(value) { _y = value }

  length { (_x*_x + _y*_y).sqrt }

  normalized {
    var l = this.length
    return new(_x / l, _y / l)
  }

  dot(v) {
    return _x * v.x + _y * v.y
  }

  distance(v) { (this - v).length }

  - { Vector2.new(-_x, -_y) }

  +(v) { Vector2.new(_x + v.x, _y + v.y) }
  -(v) { Vector2.new(_x - v.x, _y - v.y) }
}

class Vector3 {
  construct new() {
    _x = 0
    _y = 0
    _z = 0
  }

  construct new(x, y, z) {
    _x = x
    _y = y
    _z = z
  }

  x { _x }
  x=(value) { _x = value }

  y { _y }
  y=(value) { _y = value }

  z { _y }
  z=(value) { _y = value }

  length { (_x*_x + _y*_y + _z*_z).sqrt }
  normalized {
    var l = this.length
    return new(_x / l, _y / l, _z / l)
  }

  - { new(-_x, -_y, -_z) }

  +(v) { new(_x + v.x, _y + v.y, _z + v.z) }
  -(v) { new(_x - v.x, _y - v.y, _z - v.z) }
}

class Rectangle {
  construct new() {
    _x = 0
    _y = 0
    _w = 0
    _h = 0
  }

  construct new(x, y, w, h) {
    _x = x
    _y = y
    _w = w
    _h = h
  }

  construct new(position, size) {
    _x = position.x
    _y = position.y
    _w = size.x
    _h = size.y
  }

  x { _x }
  x=(value) { _x = value }

  y { _y }
  y=(value) { _y = value }

  w { _w }
  w=(value) { _w = value }

  h { _h }
  h=(value) { _h = value }
}
