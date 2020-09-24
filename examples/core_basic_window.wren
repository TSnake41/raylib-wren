import "raylib" for Raylib, Color, ConfigFlags

// some basic setup
Raylib.configFlags = ConfigFlags.vsync
Raylib.targetFPS = 60

Raylib.initWindow(800, 450, "raylib [core] example - basic window")

while (!Raylib.windowShouldClose) {
  Raylib.beginDrawing()
  Raylib.clearBackground(Color.rayWhite)

  Raylib.drawText("Congrats! You created your first window!", 190, 200, 20, Color.lightGray)

  Raylib.endDrawing()
}

Raylib.closeWindow()
