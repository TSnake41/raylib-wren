foreign class Image {
  foreign construct new(path)

  foreign width
  foreign height
  foreign format
  foreign mipmaps
}

foreign class Texture {
  foreign construct new(image)

  foreign width
  foreign height
  foreign format
  foreign mipmaps
}

var Texture2D = Texture
var TextureCubemap = Texture

foreign class RenderTexture {
  foreign construct new(width, height)
  static new() { new(Raylib.screenWidth, Raylib.screenHeight) }

  foreign id
  foreign texture
  foreign depth
}

var RenderTexture2D = RenderTexture

foreign class Shader {
  foreign construct new(frag, vert)
  foreign construct new(frag)

  foreign id
}