import "raylib" for Raylib, World, Text, Color, WObject, ConfigFlags

// some basic setup
Raylib.configFlags = ConfigFlags.vsync
Raylib.targetFPS = 60

Raylib.initWindow(800, 450, "raylib [core] example - basic window")

// Create a object that contains this text component.
World.add(WObject.new(190, 200, 0, [
	// Create a text component, this component indicate that this object
	// draws text.
	Text.new("Congrats! You created your first window!", 20, Color.lightGray)
]))

World.background = Color.rayWhite

World.loop()

Raylib.closeWindow()
