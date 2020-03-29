import "raylib" for Raylib, RlVector2, RlColor, RlConfigFlags

var screenWidth = 800
var screenHeight = 450

// Set config flags.
Raylib.configFlags = RlConfigFlags.vsync
Raylib.targetFPS = 60

Raylib.initWindow(screenWidth, screenHeight, "raylib [shapes] example - basic shapes drawing")

while (!Raylib.windowShouldClose) {
	Raylib.beginDrawing()

  Raylib.clearBackground(RlColor.rayWhite)

	Raylib.drawText("some basic shapes available on raylib (and raylib-wren :D)", 20, 20, 20, RlColor.darkGray)

	Raylib.drawCircle(screenWidth/4, 120, 35, RlColor.darkBlue)

	Raylib.drawRectangle(screenWidth/4*2 - 60, 100, 120, 60, RlColor.red)
	Raylib.drawRectangleLines(screenWidth/4*2 - 40, 320, 80, 60, RlColor.orange)
	Raylib.drawRectangleGradientH(screenWidth/4*2 - 90, 170, 180, 130, RlColor.maroon, RlColor.gold)

	Raylib.drawTriangle(RlVector2.new(screenWidth/4*3, 80),
		RlVector2.new(screenWidth/4*3 - 60, 150),
		RlVector2.new(screenWidth/4*3 + 60, 150), RlColor.violet)

	Raylib.drawPoly(RlVector2.new(screenWidth/4*3, 320), 6, 80, 0, RlColor.brown)

	Raylib.drawCircleGradient(screenWidth/4, 220, 60, RlColor.green, RlColor.skyBlue)

	// NOTE: We draw all LINES based shapes together to optimize internal drawing,
	// this way, all LINES are rendered in a single draw pass
	Raylib.drawLine(18, 42, screenWidth - 18, 42, RlColor.black)
	Raylib.drawCircleLines(screenWidth/4, 340, 80, RlColor.darkBlue)
	Raylib.drawTriangleLines(RlVector2.new(screenWidth/4*3, 160),
		RlVector2.new(screenWidth/4*3 - 20, 230),
		RlVector2.new(screenWidth/4*3 + 20, 230), RlColor.darkBlue)

	Raylib.endDrawing()
}

Raylib.closeWindow()
