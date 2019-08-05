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
  const char *class, bool is_static, const char *signature)
{
  for (wray_binding_func *current = wray_funcs; current->class != NULL; current++) {
    if (strcmp(class, current->class) == 0
      && strcmp(signature, current->signature) == 0
      && is_static == current->is_static
    ) {
      return current->func;
    }
  }

  return NULL;
}

WrenForeignClassMethods wray_bind_foreign_class(WrenVM *vm, const char *module,
  const char *class)
{
  for (wray_class_binding_func *current = wray_class_funcs; current->class != NULL; current++)
    if (strcmp(class, current->class) == 0)
      return current->methods;

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
