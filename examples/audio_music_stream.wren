import "raylib" for Raylib, Color, ConfigFlags, Music, Sound

// some basic setup
Raylib.configFlags = ConfigFlags.vsync
Raylib.targetFPS = 60

Raylib.initWindow(800, 450, "raylib-wren [audio] example - music stream")
Raylib.initAudioDevice()

var music = Music.new("ressources/mini1111.xm")
music.play()

while (!Raylib.windowShouldClose) {
  music.update()

  Raylib.beginDrawing()
  Raylib.clearBackground(Color.rayWhite)
  
  Raylib.drawFPS(10, 10)

  Raylib.drawText("Playing some music !", 300, 200, 20, Color.lightGray)

  Raylib.endDrawing()
}

Raylib.closeAudioDevice()
Raylib.closeWindow()
