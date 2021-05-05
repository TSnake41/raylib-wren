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
