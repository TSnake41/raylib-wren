import "raylib" for Raylib, RlColor, RlConfigFlags

var screenWidth = 800
var screenHeight = 450

// Set config flags.
Raylib.configFlags = RlConfigFlags.vsync
Raylib.targetFPS = 60

Raylib.initWindow(screenWidth, screenHeight, "raylib [shapes] example - raylib logo using shapes")

while (!Raylib.windowShouldClose) {
	Raylib.beginDrawing()

  Raylib.clearBackground(RlColor.rayWhite)

  Raylib.drawRectangle(screenWidth/2 - 128, screenHeight/2 - 128, 256, 256, RlColor.new(0x383838FF))
  Raylib.drawRectangle(screenWidth/2 - 112, screenHeight/2 - 112, 224, 224, RlColor.rayWhite)
  Raylib.drawText("raylib", screenWidth/2 - 44, screenHeight/2 + 24, 50, RlColor.new(0x383838FF))
  Raylib.drawText("wren", screenWidth/2 - 44, screenHeight/2 + 54, 50, RlColor.new(0x383838FF))

  Raylib.drawText("this is NOT a texture!", 350, 370, 10, RlColor.gray)

	Raylib.endDrawing()
}

Raylib.closeWindow()
