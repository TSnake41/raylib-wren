import "raylib" for Raylib, RlKey, RlColor, RlTexture2D, RlVector2, RlRectangle
import "random" for Random

var random = Random.new()

var maxBunnies = 100000
var maxBatchElements = 8192

class Bunny {
  construct new(position, speed, color) {
    _position = position
    _speed = speed
    _color = color
  }

  // Assumes RlVector2 and RlColor are mutable.
  position { _position }
  speed { _speed }
  color { _color }
}

var screenWidth = 800
var screenHeight = 450

Raylib.initWindow(screenWidth, screenHeight, "raylib [textures] example - bunnymark")
Raylib.targetFPS = 60

var texBunny = RlTexture2D.new("resources/wabbit_alpha.png")
var bunnies = []
var bunniesCount = 0

for (i in 1..maxBunnies) {
  bunnies.add(Bunny.new(RlVector2.new(0, 0), RlVector2.new(0, 0), RlColor.new(0)))
}

while (!Raylib.windowShouldClose) {
  if (Raylib.isKeyDown(RlKey.keyboard["a"])) {
    for (i in 1..100) {
      if (bunniesCount < maxBunnies) {
        var bunny = bunnies[bunniesCount]
        bunny.position.x = random.int(0, screenWidth)
        bunny.position.y = random.int(0, screenHeight)

        bunny.speed.x = random.float(-250, 250) / 60
        bunny.speed.y = random.float(-250, 250) / 60

        bunny.color.r = random.int(50, 240)
        bunny.color.g = random.int(80, 240)
        bunny.color.b = random.int(100, 240)

        bunny.color.a = 255

        bunniesCount = bunniesCount + 1
      }
    }
  }

  for (i in 0..(bunniesCount - 1)) {
    var bunny = bunnies[i]

    bunny.position.x = bunny.position.x + bunny.speed.x
    bunny.position.y = bunny.position.y + bunny.speed.y

    if (((bunny.position.x + 16) > screenWidth) || ((bunny.position.x + 16) < 0)) {
      bunny.speed.x = -bunny.speed.x
    }

    if (((bunny.position.y + 16) > screenHeight) || ((bunny.position.y + 16) < 0)) {
      bunny.speed.y = -bunny.speed.y
    }
  }

  Raylib.beginDrawing()
  Raylib.clearBackground(RlColor.rayWhite)

  for (i in 0..(bunniesCount - 1)) {
    texBunny.draw(bunnies[i].position, bunnies[i].color)
  }

  Raylib.drawRectangle(RlRectangle.new(0, 0, screenWidth, 40), RlColor.black)
  Raylib.drawText("bunnies: %(bunniesCount)", 120, 10, 20, RlColor.green)
  Raylib.drawText("batched draw calls: %(1 + (bunniesCount/maxBatchElements).ceil)", 320, 10, 20, RlColor.maroon)
  Raylib.drawFPS(10, 10)

  Raylib.endDrawing()
}

Raylib.closeWindow()
