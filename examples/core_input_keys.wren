import "raylib" for Raylib, RlVector2, RlRectangle, RlColor, RlKey, RlConfigFlags

// Set config flags.
Raylib.configFlags = RlConfigFlags.vsync
Raylib.targetFPS = 60
Raylib.initWindow(800, 450, "raylib [core] example - keyboard input")

var ballPosition = RlVector2.new(800/2, 450/2)

// Extract keyboard map from RlKey to make key lookup more readable.
var keys = RlKey.keyboard

while (!Raylib.windowShouldClose) {
  // Update
  if (Raylib.isKeyDown(keys["right"])) {
    ballPosition.x = ballPosition.x + 2.0
  }
  if (Raylib.isKeyDown(keys["left"])) {
    ballPosition.x = ballPosition.x - 2.0
  }
  if (Raylib.isKeyDown(keys["up"])) {
    ballPosition.y = ballPosition.y - 2.0
  }
  if (Raylib.isKeyDown(keys["down"])) {
    ballPosition.y = ballPosition.y + 2.0
  }

  Raylib.beginDrawing()

  Raylib.clearBackground(RlColor.rayWhite)

  Raylib.drawFPS(0, 0)
  Raylib.drawText("move the ball with arrow keys", 10, 10, 20, RlColor.darkGray)
  Raylib.drawCircle(ballPosition, 50, RlColor.maroon)

  Raylib.endDrawing()
}

Raylib.closeWindow()
