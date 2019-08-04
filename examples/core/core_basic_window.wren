import "wray_api" for rl, rlColor

rl.InitWindow(800, 450, "raylib [core] example - basic window")

while (!rl.WindowShouldClose) {
	rl.BeginDrawing()

	var color = rlColor.RAYWHITE

	rl.ClearBackground(color)

	//rl.DrawText("Congrats! You created your first window!", 190, 200, 20, rl.LightGray)

	rl.EndDrawing()
}

rl.CloseWindow()
