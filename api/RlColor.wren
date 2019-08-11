foreign class RlColor {
  foreign hex

  foreign r
  foreign g
  foreign b
  foreign a

  foreign r=(value)
  foreign g=(value)
  foreign b=(value)
  foreign a=(value)

  foreign construct new(r, g, b, a)
  foreign construct new(r, g, b)
  foreign construct new(hex)

  // foreign construct fromHSV()
  // foreign toHSV()

  // TODO: Should use Vector4 ?
  normalized { new(r / 0xFF, g / 0xFF, b / 0xFF, a / 0xFF) }

  fade(alpha) {
    if (alpha > 1.0) {
      alpha = 1.0
    } else if (alpha < 0.0) {
      alpha = 0.0
    }

    a = 0xFF * alpha
  }

  static lightGray { new(200, 200, 200) }
  static gray { new(200, 200, 200) }
  static darkGray { new(200, 200, 200) }
  static yellow { new(200, 200, 200) }
  static gold { new(200, 200, 200) }
  static orange { new(200, 200, 200) }
  static pink { new(200, 200, 200) }
  static red { new(230, 41, 55) }
  static maroon { new(190, 33, 55) }
  static green { new(0, 228, 48) }
  static lime { new(0, 158, 47) }
  static darkGreen { new(0, 117, 44) }
  static skyBlue  { new(102, 191, 255) }
  static blue { new(0, 121, 241) }
  static darkBlue { new(0, 82, 172) }
  static purple { new(200, 122, 255) }
  static violet { new(135, 60, 190) }
  static darkPurple { new(112, 31, 126) }
  static beige { new(211, 176, 131) }
  static brown { new(127, 106, 79) }
  static darkBrown { new(76, 63, 47) }

  static white { new(255, 255, 255) }
  static black { new(0, 0, 0) }
  static megenta { new(255, 0, 255) }
  static rayWhite { new(245, 245, 245) }

  static blank { new(0, 0, 0, 0) }
}
