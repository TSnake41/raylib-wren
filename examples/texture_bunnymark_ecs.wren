import "raylib" for Raylib, Key, Color, Texture2D, FpsDisplay, Sprite, Rectangle, WObject, World, Text
import "random" for Random

var random = Random.new()

var maxBunnies = 100000
var MaxBatchElements = 8192

var ScreenWidth = 800
var ScreenHeight = 450

var BunniesCount = 0

class BunnyMovement {
  construct new(vx, vy) {
    _vx = vx
    _vy = vy
  }

  update(p, dt) {
    p.x = p.x + _vx
    p.y = p.y + _vy

    if (((p.x + 16) > ScreenWidth) || ((p.x + 16) < 0)) {
      _vx = -_vx
    }

    if (((p.y + 16) > ScreenHeight) || ((p.y + 16) < 0)) {
      _vy = -_vy
    }
  }
  draw(p, x, y, z) {}
}

Raylib.initWindow(ScreenWidth, ScreenHeight, "raylib [textures] example - bunnymark")
Raylib.targetFPS = 60

var texBunny = Texture2D.new("resources/wabbit_alpha.png")

World.add(WObject.new(0, 0, 0, [ Rectangle.new(ScreenWidth, 40, Color.black)]))

World.add(WObject.new(120, 10, 0, [ Text.new("", 20, Color.green) ]) {|self|
  self["Text"].text = "bunnies: %(BunniesCount)"
})

World.add(WObject.new(320, 10, 0, [ Text.new("", 20, Color.maroon) ]) {|self|
  self["Text"].text = "batched draw calls: %(1 + (BunniesCount/MaxBatchElements.ceil))"
})

World.add(WObject.new(10, 10, 0, [ FpsDisplay.new() ]))

World.background = Color.rayWhite

World.loop {
  // Left mouse button to create a bunny.
  if (Raylib.isMouseButtonDown(Key.mouseButton["left"])) {
    for (i in 1..100) {
      if (BunniesCount < maxBunnies) {

        World.add(WObject.new(Raylib.mouseX, Raylib.mouseY, 0, [
          Sprite.new(texBunny, Color.new(
            random.int(50, 240),
            random.int(80, 240),
            random.int(100, 240),
            255
          )),
          BunnyMovement.new(
            random.float(-250, 250) / 60,
            random.float(-250, 250) / 60
          )
        ]))

      }
    }
  }
}

Raylib.closeWindow()
