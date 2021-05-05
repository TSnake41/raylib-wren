import "raylib" for Raylib, Key, Color, Texture, Vector2
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

  // Assumes Vector2 and Color are mutable.
  position { _position }
  speed { _speed }
  color { _color }
}

var screenWidth = 800
var screenHeight = 450

Raylib.initWindow(screenWidth, screenHeight, "raylib [textures] example - bunnymark")
Raylib.targetFPS = 60

var texBunny = Texture.new("ressources/wabbit_alpha.png")
var bunnies = []
var bunniesCount = 0

for (i in 1..maxBunnies) {
  bunnies.add(Bunny.new(Vector2.new(0, 0), Vector2.new(0, 0), Color.new(0)))
}

while (!Raylib.windowShouldClose) {
  if (Raylib.isMouseButtonDown(Key.mouseButton["left"])) {
    for (i in 1..100) {
      if (bunniesCount < maxBunnies) {
        var bunny = bunnies[bunniesCount]
        bunny.position.x = Raylib.mouseX
        bunny.position.y = Raylib.mouseY

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
  Raylib.clearBackground(Color.rayWhite)

  for (i in 0..(bunniesCount - 1)) {
    var bunny = bunnies[i]
    Raylib.drawTexture(texBunny, bunny.position, bunnies[i].color)
  }

  Raylib.drawRectangle(0, 0, screenWidth, 40, Color.black)
  Raylib.drawText("bunnies: %(bunniesCount)", 120, 10, 20, Color.green)
  Raylib.drawText("batched draw calls: %(1 + (bunniesCount/maxBatchElements).ceil)", 320, 10, 20, Color.maroon)
  Raylib.drawFPS(10, 10)

  Raylib.endDrawing()
}

Raylib.closeWindow()
