import "raylib" for Raylib, RlColor, RlConfigFlags
import "random" for Random

Raylib.initWindow(800, 450, "raylib [core] example - generate random values")

var random = Random.new()

var frames_counter = 0
var rand_value = random.int(-8, 5)

Raylib.targetFPS = 60
Raylib.configFlags = RlConfigFlags.vsync

while (!Raylib.windowShouldClose) {
  frames_counter = frames_counter + 1

  if ( ((frames_counter / 120) % 2) == 1) {
    rand_value = random.int(-8, 5)
    frames_counter = 0
  }

  Raylib.beginDrawing()

  Raylib.clearBackground(RlColor.rayWhite)

  Raylib.drawText("Every 2 seconds a new random value is generated:", 130, 100, 20, RlColor.maroon)
  Raylib.drawText("%(rand_value)", 360, 180, 80, RlColor.lightGray)

  Raylib.endDrawing()
}
