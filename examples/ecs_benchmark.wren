// Inspired of Tjakka5/love-ecs-benchmarks
import "raylib" for Raylib, ConfigFlags, Color, Key, Vector2, Texture,
  World, GameEntity, GameSystem

import "random" for Random

var random = Random.new()

Raylib.initWindow(800, 450, "raylib-wren [ecs] example - ecs benchmark")

var entityLimit = 10000
var maxX = 800
var maxY = 450

class Position {
  construct new(x, y) {
    _v = Vector2.new(x, y)
  }

  construct new(v) {
    _v = v
  }

  v { _v }
  v=(value) { _v = value }
}
class Velocity {
  construct new(x, y) {
    _v = Vector2.new(x, y)
  }

  construct new(v) {
    _v = v
  }

  v { _v }
  v=(value) { _v = value }
}

class Sprite {
  construct new(r, g, b) {
    _color = Color.new(r, g, b)
  }

  color { _color }
}

var Physics = GameSystem.new([Position, Velocity]) {|entities, event, dt|
  if (event == "update") {
    entities.each {|e|
      var pos = e[Position]
      var vel = e[Velocity]

      pos.v.x = pos.v.x + vel.v.x * dt
      pos.v.y = pos.v.y + vel.v.y * dt

      if (pos.v.x > maxX || pos.v.y > maxY) {
        if (random.float() < 0.4) {
          World.remove(e)
        } else {
          pos.v.x = 0
          pos.v.y = 0
        }
      }
    }
  }
}

var testSprite = Texture.new("resources/wabbit_alpha.png")

var SpriteRenderer = GameSystem.new([Position, Sprite]) {|entities, event|
  if (event == "draw") {
    entities.each {|e|
      var pos = e[Position]
      Raylib.drawRectangle(pos.v.x, pos.v.y, 3, 3, e[Sprite].color)
    }
  }
}

World.systems.add(Physics)
World.systems.add(SpriteRenderer)

while (!Raylib.windowShouldClose) {
  Raylib.beginDrawing()

  for (i in 1..100) {
    if (World.entities.count >= entityLimit) break

    World.add(GameEntity.new([
      Position.new(0, 0),
      Velocity.new(random.float(10, 30), random.float(10, 30)),
      Sprite.new(random.int(0, 255), random.int(0, 255), random.int(0, 255))
    ]))
  }

  World.emit("update", Raylib.frameTime)

  Raylib.clearBackground(Color.black)
  World.emit("draw")

  Raylib.drawFPS(710, 5)
  Raylib.drawText("%(World.entities.count)", 710, 25, 20, Color.green)
  Raylib.endDrawing()
}

Raylib.closeWindow()
