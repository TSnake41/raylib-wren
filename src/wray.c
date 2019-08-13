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

#include <stdio.h>
#include <string.h>

#include <wren.h>
#include "wray_internal.h"

static void write_func(struct WrenVM *vm, const char *str)
{
  puts(str ? str : "");
}

static void error_func(WrenVM* vm, WrenErrorType type, const char* module, int line,
      const char* message)
{
  switch (type) {
    case WREN_ERROR_COMPILE:
      printf("[WREN] Compiler error in %s:%d\n[WREN] -> %s\n", module, line, message);
      break;
    case WREN_ERROR_RUNTIME:
      printf("[WREN] Runtime error : %s\n[WREN] Stacktrace : \n", message);
      break;
    case WREN_ERROR_STACK_TRACE:
      printf("[WREN] -> %s:%d - %s\n", module, line, message);
      break;
  }
}

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

void wray_init(WrenVM *vm)
{
  puts("[WRAY] Initialize API.");

  wrenInterpret(vm, "raylib", wray_api);
}

WrenVM *wray_new_vm(WrenConfiguration *user_config)
{
  WrenConfiguration config;

  if (user_config)
    config = *user_config;
  else
    wrenInitConfiguration(&config);

  config.writeFn = write_func;
  config.errorFn = error_func;

  config.bindForeignMethodFn = wray_bind_foreign_method;
  config.bindForeignClassFn = wray_bind_foreign_class;

  WrenVM *vm = wrenNewVM(&config);
  if (vm)
    wray_init(vm);

  return vm;
}
