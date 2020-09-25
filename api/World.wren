class GameEntity {
  construct new(components) {
    _components = components.toList
    _componentsTypes = _components.map {|c| c.type }.toList
  }

  construct new() {
    _components = []
    _componentsTypes = []
  }

  components { _components }
  componentsTypes { _componentsTypes }

  [filter] {
    if (filter is Class) {
      for (c in _components) {
        if (c is filter) return c
      }
    } else if (filter is String) {
      for (c in _components) {
        if (c.name == filter) return c
      }
    } else Fiber.abort("Invalid component lookup, expects Class or String.")
  }

  all(filter) {
    if (filter is Class) {
      return _components.where {|c| c is filter }
    } else if (filter is String) {
      return _components.where {|c| c.name == filter}
    }
  }

  remove(component) {
    Fiber.abort("NYI")
  }

  add(component) {
    _components.add(component)

    if (!_componentsType.contains(component.type)) {
      _componentsTypes.add(component.type)
    }
  }
}

class GameSystem {
  construct new(filter, fn) {
    _filter = filter
    _fn = fn
    _active = true
  }

  construct new(fn) {
    _filter = null
    _fn = fn
    _active = true
  }

  fn { _fn }
  filter { _filter }
  active { _active }
}

class World {
  //
  // World instance
  //
  construct new(entities, systems) {
    _entities = entities
    _systems = systems
  }

  static new() { new([], []) }

  entities { _entities }
  systems { _systems }

  add(e) {
    _entities.add(e)
  }

  remove(e) {
    // Look for e
    // TODO: Optimize it, custom garbage collector ?
    for (i in 0...(_entities.count)) {
      if (_entities[i] == e) {
        _entities.removeAt(i)
        return
      }
    }
  }

  emit(event, a, b, c, d, e, f, g) {
    _systems.where {|s| s.active }.each {|s|
      var filter = s.filter

      if (filter is List) {
        s.fn.call(_entities.where {|e|
          return filter.all {|c| e.componentsTypes.contains(c) }
        }, event, a, b, c, d, e, f)

      } else if (filter is Class) {
        s.fn.call(_entities.where {|e|
          return e.componentsTypes.contains(filter)
        }, event, a, b, c, d, e, f)

      } else Fiber.abort("Invalid system filter")

      return
    }
  }

  emit(event, a, b, c, d, e, f) { emit(event, a, b, c, d, e, f, null) }
  emit(event, a, b, c, d, e) { emit(event, a, b, c, d, e, null, null) }
  emit(event, a, b, c, d) { emit(event, a, b, c, d, null, null, null) }

  emit(event, a, b, c) {
    _systems.where {|s| s.active }.each {|s|
      var filter = s.filter

      if (filter is List) {
        s.fn.call(_entities.where {|e|
          return filter.all {|c| e.componentsTypes.contains(c) }
        }, event, a, b, c)
      } else if (filter is Class) {
        s.fn.call(_entities.where {|e|
          return e.componentsTypes.contains(filter)
        }, event, a, b, c)

      } else Fiber.abort("Invalid system filter")

      return
    }
  }
  emit(event, a, b) { emit(event, a, b, null) }

  emit(event, a) {
    _systems.where {|s| s.active }.each {|s|
      var filter = s.filter

      if (filter is List) {
        s.fn.call(_entities.where {|e|
          return filter.all {|c| e.componentsTypes.contains(c) }
        }, event, a)

      } else if (filter is Class) {
        s.fn.call(_entities.where {|e|
          return e.componentsTypes.contains(filter)
        }, event, a)

      } else Fiber.abort("Invalid system filter")

      return
    }
  }
  emit(event) { emit(event, null) }

  //
  // Global world
  //
  static globalWorld { __globalWorld }
  static globalWorld=(value) { __globalWorld = value }

  static entities { __globalWorld.entities }
  static systems { __globalWorld.systems }

  static add(entity) { globalWorld.add(entity) }
  static remove(entity) { globalWorld.remove(entity) }

  static emit(event, a, b, c, d, e, f, g) {
    __globalWorld.emit(event, a, b, c, d, e, f, g)
  }
  static emit(event, a, b, c, d, e, f) {
    __globalWorld.emit(event, a, b, c, d, e, f)
  }
  static emit(event, a, b, c, d, e) { __globalWorld.emit(event, a, b, c, d, e) }
  static emit(event, a, b, c, d) { __globalWorld.emit(event, a, b, c, d) }
  static emit(event, a, b, c) { __globalWorld.emit(event, a, b, c) }
  static emit(event, a, b) { __globalWorld.emit(event, a, b) }
  static emit(event, a) { __globalWorld.emit(event, a) }
  static emit(event) { __globalWorld.emit(event) }
}

// Create global world.
World.globalWorld = World.new()
