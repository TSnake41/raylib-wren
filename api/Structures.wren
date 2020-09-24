foreign class Image {
  foreign construct new(path)

  foreign width
  foreign height
  foreign format
  foreign mipmaps
}

foreign class Texture2D {
  foreign construct new(image)

  foreign width
  foreign height
  foreign format
  foreign mipmaps
}
