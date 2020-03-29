import "raylib" for Raylib, RlColor, RlConfigFlags

// Set config flags.
Raylib.configFlags = RlConfigFlags.vsync
Raylib.targetFPS = 60

Raylib.initWindow(800, 450, "raylib [wren] example - basic window (embedded)")

while (!Raylib.windowShouldClose) {
	Raylib.beginDrawing()

	Raylib.clearBackground(RlColor.rayWhite)
	Raylib.drawText("Congrats! You made a embedded wray executable!", 190, 200, 20, RlColor.lightGray)

	Raylib.endDrawing()
}

Raylib.closeWindow()
