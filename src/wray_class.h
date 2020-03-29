/*
  Copyright (C) 2019 Astie Teddy

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

#ifndef H_WRAY_CLASS
#define H_WRAY_CLASS

#include <wren.h>

typedef struct wray_binding_func {
  WrenForeignMethodFn func;
  bool is_static;

  const char *sig;
} wray_binding_func;

typedef struct wray_binding_class {
  const char *class;
  WrenForeignClassMethods methods;
  wray_binding_func funcs[];
} wray_binding_class;

extern const wray_binding_class *wray_classes[];
extern const size_t wray_classes_count;
extern const char *wray_api;

typedef struct wray_class_handles {
  WrenHandle *color;
  WrenHandle *image;
  WrenHandle *texture2d;
  WrenHandle *rectangle;
  WrenHandle *vec2;
  WrenHandle *vec3;
  WrenHandle *vec4;
} wray_class_handles;

void wray_release_class_handles(WrenVM *vm, wray_class_handles *handles);
void wray_make_class_handles(WrenVM *vm, wray_class_handles *handles);

#endif /* H_WRAY_CLASS */
