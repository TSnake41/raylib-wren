## For binding mainteners

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
