
import "raylib" for Raylib, Color, ConfigFlags

var screenWidth = 800
var screenHeight = 450

// Set config flags.
Raylib.configFlags = ConfigFlags.vsync
Raylib.targetFPS = 60

var wrenColor = Color.new(0x383838FF)

Raylib.initWindow(screenWidth, screenHeight, "raylib [shapes] example - raylib logo using shapes")

while (!Raylib.windowShouldClose) {
	Raylib.beginDrawing()

  Raylib.clearBackground(Color.rayWhite)

  Raylib.drawRectangle(screenWidth/2 - 128, screenHeight/2 - 128, 256, 256, wrenColor)
  Raylib.drawRectangle(screenWidth/2 - 112, screenHeight/2 - 112, 224, 224, Color.rayWhite)
  Raylib.drawText("raylib", screenWidth/2 - 44, screenHeight/2 + 24, 50, wrenColor)
  Raylib.drawText("wren", screenWidth/2 - 44, screenHeight/2 + 54, 50, wrenColor)

  Raylib.drawText("this is NOT a texture!", 350, 370, 10, Color.gray)

	Raylib.endDrawing()
}

Raylib.closeWindow()
