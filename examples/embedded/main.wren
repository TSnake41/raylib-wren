import "raylib" for Raylib, Color, ConfigFlags, Texture

// Set config flags.
Raylib.configFlags = ConfigFlags.vsync
Raylib.targetFPS = 60

Raylib.initWindow(800, 450, "raylib [wren] example - basic window (embedded)")
var logo = Texture.new("logo.png")

while (!Raylib.windowShouldClose) {
	Raylib.beginDrawing()

	Raylib.clearBackground(Color.rayWhite)
	Raylib.drawTexture(logo, Raylib.screenWidth / 2 - logo.width / 2, Raylib.screenHeight / 2 - logo.height / 2, Color.white)
	Raylib.drawText("this is a texture!", 350, 370, 10, Color.gray)
	
	Raylib.endDrawing()
}

Raylib.closeWindow()
