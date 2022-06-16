// a simple rendertexture test for raylib-wren
import "raylib" for Raylib, ConfigFlags, Color, Key, Vector2, Texture, RenderTexture

Raylib.configFlags = ConfigFlags.vsync
Raylib.targetFPS = 60

Raylib.initWindow(800, 600, "raylib [core] example - rendertexture")

var renderTexture = RenderTexture.new()

while (!Raylib.windowShouldClose) {
  Raylib.beginDrawing()

  Raylib.beginTextureMode(renderTexture)
  Raylib.clearBackground(Color.rayWhite)
  
  Raylib.drawFPS(10, 10)

  Raylib.drawText("Congrats! You created your first window!", 190, 200, 20, Color.lightGray)
  Raylib.endTextureMode()

  Raylib.drawTexture(renderTexture.texture, 0, 0, Color.white)

  Raylib.endDrawing()
}

Raylib.closeWindow()
