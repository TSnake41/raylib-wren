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
