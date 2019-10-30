foreign class RlImage {
  foreign construct new(path)

  foreign width
  foreign height
  foreign format
  foreign mipmaps

  foreign toPOT(fill_color)
}

foreign class RlTexture2D {
  foreign construct new(path)

  foreign width
  foreign height
  foreign format
  foreign mipmaps
}
