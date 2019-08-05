import "raylib" for Raylib, RlColor, RlConfigFlags

// Set config flags.
Raylib.configFlags = RlConfigFlags.vsync
Raylib.targetFPS = 60

Raylib.initWindow(800, 450, "raylib [core] example - basic window")

while (!Raylib.windowShouldClose) {
	Raylib.beginDrawing()

	Raylib.clearBackground(RlColor.rayWhite)
	Raylib.drawText("Congrats! You created your first window!", 190, 200, 20, RlColor.lightGray)

	Raylib.endDrawing()
}
