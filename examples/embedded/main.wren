import "raylib" for Raylib, Color, ConfigFlags, Texture

// Set config flags.
Raylib.configFlags = ConfigFlags.vsync
Raylib.targetFPS = 60

Raylib.initWindow(800, 450, "raylib [wren] example - basic window (embedded)")
var logo = Texture.new("logo.png")

while (!Raylib.windowShouldClose) {
	Raylib.beginDrawing()

	Raylib.clearBackground(Color.rayWhite)
	Raylib.drawText("Congrats! You made a embedded wray executable!", 190, 200, 20, Color.lightGray)
	Raylib.endDrawing()
}

Raylib.closeWindow()
