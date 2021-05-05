/*
foreign class RlWave {
  foreign construct new()
  foreign construct new(path)

  foreign sampleCount
  foreign sampleRate
  foreign sampleSize
  foreign channels
  foreign data

  foreign crop(begin, end)
  foreign copy(dest)
  foreign format(sampleRate, sampleSize, channels)

  clone { copy(new()) }
}
*/

foreign class Sound {
  foreign construct new(path) /* TODO: Consider wave support */

  foreign play()
  foreign stop()
  foreign pause()
  foreign resume()
  
  foreign playMulti()

  foreign playing
  foreign volume=(v)
  foreign pitch=(p)  
}

foreign class Music {
  foreign construct new(path)

  foreign update()

  foreign play()
  foreign stop()
  foreign pause()
  foreign resume()

  foreign playing
  foreign volume=(v)
  foreign pitch=(p)
  
  foreign length
  foreign played
}


// NOTE: This has yet to be considered.
// raudio uses AudioStream as a common interface but with different
// fashions, so to reduce code redudancy and the multiplication of
// foreign classes, I will not repeat myself as much as possible.
// Only expose RlAudioStream as a foreign class, very specific methods
// will be implemented as foreign method on class.

/*
foreign class RlAudioStream {
  foreign construct new(sampleRate, sampleSize, channels)

  foreign update(data, sampleCount)
  foreign play()
  foreign stop()
  foreign resume()
  foreign pause()

  foreign volume=(volume)
  foreign pitch=(pitch)

  foreign playing
  foreign processed
}
*/