foreign class RlVector2 {
  foreign [index]
  foreign [index]=(value)

  x { this[0] }
  y { this[1] }

  x=(value) { this[0] = value }
  y=(value) { this[1] = value }

  foreign construct new(x, y)

  // These functions modifies 'this'.
  foreign add_(v)
  foreign sub_(v)
  foreign mul_(v)
  foreign div_(v)
  foreign lerp_(v,a,b)
  foreign negated_
  foreign normalized_

  foreign dot(vec)
  foreign copy(dst)
  foreign distance(vec)
  foreign length

  static new() { new(0, 0) }
  static zero { new() }

  clone { copy(RlVector2.new()) }
  normalized { clone.normalized_ }

  - { clone.negated_ }

  +(v) { clone.add_(v) }
  -(v) { clone.sub_(v) }
  *(v) { clone.mul_(v) }
  /(v) { clone.div_(clone) }

  lerp(start, end, count) { clone.lerp_(start, end, count) }
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

  foreign construct new(x, y, z)

  foreign add_(v)
  foreign sub_(v)
  foreign mul_(v)
  foreign div_(v)
  foreign lerp_(v,a,b)
  foreign negated_
  foreign normalized_

  foreign dot(vec)
  foreign copy(dst)
  foreign distance(vec)
  foreign length

  static new() { new(0, 0, 0) }
  static zero { new() }

  clone { copy(RlVector3.new()) }

  - { clone.negated_ }
  normalized { clone.normalized_ }

  +(v) { clone.add_(v) }
  -(v) { clone.sub_(v) }
  *(v) { clone.mul_(v) }
  /(v) { clone.div_(clone) }

  lerp(start, end, count) { clone.lerp_(start, end, count) }
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

  foreign construct new(x, y, z, w)

  static new() { new(0, 0, 0, 0) }
  static zero { new() }
}

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

  static new(pos, size) {
    return new(pos.x, pos.y, size.x, size.y)
  }
}
