/*
  Copyright (C) 2019-2021 Astie Teddy

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
*/

#include <stdio.h>
#include <string.h>

#include <wren.h>
#include "wray_class.h"

WrenForeignMethodFn wray_bind_foreign_method(WrenVM *vm, const char* module,
  const char *class, bool is_static, const char *sig)
{
  if (strcmp(module, "raylib") != 0)
    return NULL;

  /* Check each wray binding class. */
  for (size_t i = 0; i < wray_classes_count; i++) {
    const wray_binding_class *c = wray_classes[i];

    if (strcmp(c->class, class) == 0) {
      const wray_binding_func *f = c->funcs;

      /* Check each functions of the binding class. */
      for (; f->func; f++)
        if ((f->is_static == is_static) && (strcmp(f->sig, sig) == 0))
          return f->func;
    }
  }
  return NULL;
}

WrenForeignClassMethods wray_bind_foreign_class(WrenVM *vm, const char *module,
  const char *class)
{
  if (strcmp(module, "raylib") != 0)
    return (WrenForeignClassMethods){ NULL, NULL };

  /* Check each wray binding class. */
  for (size_t i = 0; i < wray_classes_count; i++) {
    const wray_binding_class *c = wray_classes[i];

    if (strcmp(c->class, class) == 0)
      return c->methods;
  }

  return (WrenForeignClassMethods){ NULL, NULL };
}

extern const wray_binding_class wray_raylib_class;
extern const wray_binding_class wray_draw_class;

extern const wray_binding_class wray_image_class;
extern const wray_binding_class wray_texture_class;
extern const wray_binding_class wray_color_class;
extern const wray_binding_class wray_sound_class;
extern const wray_binding_class wray_music_class;

const wray_binding_class *wray_classes[] = {
  /* Default static class */
  &wray_raylib_class,
  &wray_draw_class,

  &wray_image_class,
  &wray_texture_class,
  &wray_color_class,
  &wray_sound_class,
  &wray_music_class,
};
const size_t wray_classes_count = sizeof(wray_classes) / sizeof(wray_classes[0]);

void wray_make_class_handles(WrenVM *vm, wray_class_handles *handles)
{
  puts("WRAY: Making class handles");

  wrenEnsureSlots(vm, 1);

  #define MAKE_CLASS_HANDLE(field, classname) \
    wrenGetVariable(vm, "raylib", classname, 0); \
    handles->field = wrenGetSlotHandle(vm, 0);

  MAKE_CLASS_HANDLE(image, "Image");
  MAKE_CLASS_HANDLE(texture, "Texture");
  MAKE_CLASS_HANDLE(color, "Color");
  MAKE_CLASS_HANDLE(sound, "Sound");
  MAKE_CLASS_HANDLE(music, "Music");

  #undef MAKE_HANDLE
}

void wray_release_class_handles(WrenVM *vm, wray_class_handles *handles)
{
  puts("WRAY: Releasing class handles");

  wrenReleaseHandle(vm, handles->image);
  wrenReleaseHandle(vm, handles->texture);
  wrenReleaseHandle(vm, handles->color);
  wrenReleaseHandle(vm, handles->sound);
  wrenReleaseHandle(vm, handles->music);
}
