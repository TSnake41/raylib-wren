import "raylib" for Raylib, World, Circle, Text, Color, WObject, ConfigFlags, Key, FpsDisplay

Raylib.configFlags = ConfigFlags.vsync
Raylib.targetFPS = 60

Raylib.initWindow(800, 450, "raylib [core] example - keyboard input")

var ball = WObject.new(400, 225, 0, [
  Circle.new(50, Color.maroon),
  Text.new("", 20, Color.black)
]) {|self|
  self["Text"].text = "%(self.x) %(self.y)"

  if (Raylib.isKeyDown(Key.keyboard["right"])) {
    self.x = self.x + 2.0
  }
  if (Raylib.isKeyDown(Key.keyboard["left"])) {
    self.x = self.x - 2.0
  }
  if (Raylib.isKeyDown(Key.keyboard["up"])) {
    self.y = self.y - 2.0
  }
  if (Raylib.isKeyDown(Key.keyboard["down"])) {
    self.y = self.y + 2.0
  }
}

var ball_text = ball["Text"]

ball_text.ox = -45
ball_text.oy = -75

World.add(ball)

World.add(WObject.new(10, 10, 0, [
  Text.new("move the ball with arrow keys", 20, Color.darkGray)
]))

World.add(WObject.new(0, 0, 0, [ FpsDisplay.new() ]))

World.background = Color.rayWhite

World.loop {}

Raylib.closeWindow()
