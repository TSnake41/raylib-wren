// TODO: Implement systems

class World {
  //
  // World instance
  //
  construct new(entities) {
    _entities = []
    // _systems = []

    _interupted = true
  }
  static new() { new([]) }

  entities { _entities }
  // systems { _systems }

  add(e) {
    _entities.add(e)
  }

  update(p, dt) {
    _entities.each {|c| c.update(this, dt)}
  }

  draw(p, px, py, pz) {
    _entities.each {|c| c.draw(this, px, py, pz)}
  }

  //
  // Global world
  //
  static globalWorld { __globalWorld }
  static globalWorld=(value) { __globalWorld = value }

  static background { __background }
  static background=(value) { __background = value }

  static interupted { __interupted }

  static add(entity) { globalWorld.add(entity) }
  static draw() { globalWorld.draw() }

  static interupt() {
    __interupted = true
  }

  static loop(f) {
    __interupted = false

    while (!interupted) {
      if (Raylib.windowShouldClose) break

      if (f != null) f.call()

      globalWorld.update(globalWorld, Raylib.frameTime)

      Raylib.beginDrawing()
      Raylib.clearBackground(background)

      globalWorld.draw(globalWorld, 0, 0, 0)
      Raylib.endDrawing()
    }
  }

  static loop() { loop(null) }
}

// World initial state.
World.interupt()
World.background = Color.white

// Create global world.
World.globalWorld = World.new()

class Entity {
  construct new(x, y, z, components, update) {
    _x = x
    _y = y
    _z = z

    _components = [] + components
    _update = update
  }

  static new(x, y, z, components) { new(x, y, z, components, null) }
  static new(x, y, z) { new(x, y, z, [], null) }
  static new(x, y) { new(x, y, 0, [], null) }
  static new() { new(0, 0, 0, [], null) }

  x { _x }
  x=(value) { _x = value }

  y { _y }
  y=(value) { _y = value }

  z { _z }
  z=(value) { _z = value }

  position { Vector3.new(x, y, z) }

  components { _components }

  [name] {
    for (c in _components) {
      if (c.name == name) {
        return c
      }
    }

    return null
  }

  find(name) { _components.where {|c| c.name == name} }

  update(parent, dt) {
    if (_update != null) _update.call(this, dt)

    _components.each {|c| c.update(this, dt)}
  }

  draw(parent, px, py, pz) {
    _components.each {|c| c.draw(this, px + _x, py + _y, pz + _z)}
  }
}
