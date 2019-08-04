import "wray_api" for Raylib, RlColor

Raylib.initWindow(800, 450, "raylib [core] example - basic window")

var current = 0
var counter = 0
var colors = [ RlColor.RAYWHITE, RlColor.RED, RlColor.BLUE ]

while (!Raylib.windowShouldClose) {
	Raylib.beginDrawing()

  counter = counter + Raylib.frameTime

  if (counter > 1.0) {
    current = (current + 1) % colors.count
    counter = counter - 2.0
  }

	Raylib.clearBackground(colors[current])
	//Raylib.DrawText("Congrats! You created your first window!", 190, 200, 20, rl.LightGray)
	Raylib.endDrawing()
}

Raylib.closeWindow()
