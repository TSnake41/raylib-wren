import "raylib" for Raylib, RlColor, RlConfigFlags, RlVector2
import "random" for Random

var random = Random.new()

var screenWidth = 800
var screenHeight = 450

// Set config flags.
Raylib.configFlags = RlConfigFlags.vsync
Raylib.targetFPS = 60

var a = RlVector2.new(random.int(-10, 10), random.int(-10, 10))
var b = RlVector2.new(random.int(-10, 10), random.int(-10, 10))

var frames_counter = 0

var display = Fn.new {|v| "(%(v.x);%(v.y))" }

Raylib.initWindow(screenWidth, screenHeight, "raylib [math] example - vector computation")

while (!Raylib.windowShouldClose) {
  frames_counter = frames_counter + 1

  if ( ((frames_counter / 180) % 2) == 1) {
    a = RlVector2.new(random.int(-10, 10), random.int(-10, 10))
    b = RlVector2.new(random.int(-10, 10), random.int(-10, 10))
    frames_counter = 0
  }

	Raylib.beginDrawing()

  Raylib.clearBackground(RlColor.rayWhite)

  Raylib.drawText("Every 3 seconds new vectors are generated:", 30, 20, 20, RlColor.blue)

  Raylib.drawText("A = %(display.call(a))", 40, 60, 20, RlColor.black)
  Raylib.drawText("B = %(display.call(b))", 40, 80, 20, RlColor.black)
  Raylib.drawText("A + B = %(display.call(a + b))", 40, 100, 20, RlColor.black)
  Raylib.drawText("A - B = %(display.call(a - b))", 40, 120, 20, RlColor.black)
  Raylib.drawText("A . B = %(a.dot(b))", 40, 140, 20, RlColor.black)
  Raylib.drawText("||A|| = %(a.length)", 40, 160, 20, RlColor.black)
  Raylib.drawText("||B|| = %(b.length)", 40, 180, 20, RlColor.black)
  Raylib.drawText("AB = %(a.distance(b))", 40, 200, 20, RlColor.black)
  Raylib.drawText("-A = %(display.call(-a))", 40, 220, 20, RlColor.black)

	Raylib.endDrawing()
}

Raylib.closeWindow()
