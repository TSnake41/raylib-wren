![raylib-wren logo](assets/logo.png)

# raylib-wren (wray)

Wren binding for [raylib](https://www.raylib.com/), a simple and easy-to-use
library to learn videogames programming.

This binding supports raylib 3.0, previous version may support raylib 2.6.

## Usage (wray_standalone)

wray_standalone is the simplest way to use raylib-wren.
You need to give it a module path which is script file without '.wren'.

```shell
./wray_standalone examples/core_basic_window
```

## Usage (wray_embedded)

wray_embedded is the embedding-mode binary of raylib-wren.
It allows you to build a autonomous executable which can be ran on any computer
without the need of any runtime which can be very useful to distribute your
game.

To use it, you need to make a project directory containing your code with a
main.wren file which is the entry point of your application.

Then, call wray_embedded on it to build the project as a autonomous executable.

```shell
./wray_embedded examples/embedded
```

Currently, there is no support for loading embedded assets, so if your game
needs to use any of them, they must be provided externally.

## Use as a external library (advanced)

Wray may be interesting to implement scripting in a raylib-based game.
Wray doesn't make any assumtion in raylib state in initialization (it is a bare
binding with few changes to work with Wren).

When building wray, you get a libwray.a, it requires `libwren.a` to work.
You can get `libwren.a` from `wren/lib/`

You can get wray header from `include/` and wren headers from `wren/src/include`.
You need to use `wray_new_vm` to make a Wren VM with wray loaded in.

A loader must be provided to properly load functions, otherwise, Wren will not
be able to load anything.

Check `src/wray_standalone.c` for an example.

## Building

To build raylib-wren from source, you need to take care that submodules are
imported, if not or you are unsure :

```shell
git submodule init
git submodule update
```

A Lua working interpreter is needed, by default luajit is used, to override it,
edit LUA variable in `makefile`.

## Example

```wren
import "raylib" for Raylib, RlColor, RlConfigFlags

// Set config flags.
Raylib.configFlags = RlConfigFlags.vsync
Raylib.targetFPS = 60

Raylib.initWindow(800, 450, "raylib [core] example - basic window")

while (!Raylib.windowShouldClose) {
	Raylib.beginDrawing()

	Raylib.clearBackground(RlColor.rayWhite)
	Raylib.drawText("Congrats! You created your first window!", 190, 200, 20, RlColor.lightGray)

	Raylib.endDrawing()
}

Raylib.closeWindow()
```

## Compatibility

raylib-wren is currently compatible with raylib 3.0 API.
Only a subset of the API supported, any contribution on API is welcome.

There is currently no support for rlgl, physac and raygui.

## Note for contributors / maintainers

### Adding/remove a function

- modify src/raylib/wray_api.wren
- modify corresponding src/wray_\*.c and src/wray_\*.h
- modify api/\*.wren

### Type-checking

With WRAY_TYPE_CHECK build option, each call on the Wren C API check if the
type is the one expected, therefore, it will report errors and abort when an
invalid argument type is encountered.

The wray_CheckForeignType functions checks if the foreign is in the right type,
it should be used only if the foreign type could be wrong (e.g static class
method) call.

This option should only be used when developping a game with wray, it has a very
significant overhead.

If this option is disabled, Wren C API behave normally so no typecheck are made
and wray_CheckForeignType is no-op.

### Licence

Copyright (C) 2019-2020 Astie Teddy

Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
