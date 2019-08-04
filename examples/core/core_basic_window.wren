import "raylib" for Raylib, RlColor, RlConfigFlags

Raylib.initWindow(800, 450, "raylib [core] example - basic window")

// Set config flags.
Raylib.configFlags = RlConfigFlags.vsync | RlConfigFlags.showLogo
Raylib.targetFPS = 60

while (!Raylib.windowShouldClose) {
	Raylib.beginDrawing()

	Raylib.clearBackground(RlColor.RAYWHITE)
	Raylib.drawText("Congrats! You created your first window!", 190, 200, 20, RlColor.LIGHTGRAY)

	Raylib.endDrawing()
}
