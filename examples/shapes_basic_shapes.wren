import "raylib" for Raylib, Vector2, Color, ConfigFlags

var screenWidth = 800
var screenHeight = 450

// Set config flags.
Raylib.configFlags = ConfigFlags.vsync
Raylib.targetFPS = 60

Raylib.initWindow(screenWidth, screenHeight, "raylib [shapes] example - basic shapes drawing")

while (!Raylib.windowShouldClose) {
	Raylib.beginDrawing()

  Raylib.clearBackground(Color.rayWhite)

	Raylib.drawText("some basic shapes available on raylib (and raylib-wren :D)", 20, 20, 20, Color.darkGray)

	Raylib.drawCircle(screenWidth/4, 120, 35, Color.darkBlue)

	Raylib.drawRectangle(screenWidth/4*2 - 60, 100, 120, 60, Color.red)
	Raylib.drawRectangleLines(screenWidth/4*2 - 40, 320, 80, 60, Color.orange)
	Raylib.drawRectangleGradientH(screenWidth/4*2 - 90, 170, 180, 130, Color.maroon, Color.gold)

	Raylib.drawTriangle(
		screenWidth/4*3, 80,
		screenWidth/4*3 - 60, 150,
		screenWidth/4*3 + 60, 150,
		Color.violet, false)

	Raylib.drawPoly(screenWidth/4*3, 320, 6, 80, 0, Color.brown, false)

	Raylib.drawCircleGradient(screenWidth/4, 220, 60, Color.green, Color.skyBlue)

	// NOTE: We draw all LINES based shapes together to optimize internal drawing,
	// this way, all LINES are rendered in a single draw pass
	Raylib.drawLine(18, 42, screenWidth - 18, 42, Color.black)
	Raylib.drawCircleLines(screenWidth/4, 340, 80, Color.darkBlue)
	Raylib.drawTriangle(
		screenWidth/4*3, 160,
		screenWidth/4*3 - 20, 230,
		screenWidth/4*3 + 20, 230,
		Color.darkBlue, true)

	Raylib.endDrawing()
}

Raylib.closeWindow()
