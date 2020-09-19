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
  fputs(str ? str : "", stdout);
}

static void error_func(WrenVM* vm, WrenErrorType type, const char* module, int line,
      const char* message)
{
  switch (type) {
    case WREN_ERROR_COMPILE:
      printf("WREN: Compiler error in %s:%d\nWREN: -> %s\n", module, line, message);
      break;
    case WREN_ERROR_RUNTIME:
      printf("WREN: Runtime error : %s\nWREN: Stacktrace : \n", message);
      break;
    case WREN_ERROR_STACK_TRACE:
      printf("WREN: -> %s:%d - %s\n", module, line, message);
      break;
  }
}

static void wray_init(WrenVM *vm)
{
  puts("WRAY: Initialize API.");

  if (wrenInterpret(vm, "raylib", wray_api) != WREN_RESULT_SUCCESS)
    /* API interpretation failed. */
    return;

  wray_internal *internal = malloc(sizeof(wray_internal));
  if (!internal) {
    /* Allocation failed. */
    wrenSetSlotString(vm, 0, "Internal structure alloction failed.");
    wrenAbortFiber(vm, 0);
    return;
  }

  /* Make class handles. */
  wray_make_class_handles(vm, &internal->class_handles);

  wrenSetUserData(vm, internal);
}

static void wray_finalizer(WrenVM *vm)
{
  puts("WRAY: Freeing VM");

  wray_internal *internal = wrenGetUserData(vm);

  if (internal) {
    wray_release_class_handles(vm, &internal->class_handles);

    free(internal);
  }
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

  config.finalizerFn = wray_finalizer;

  WrenVM *vm = wrenNewVM(&config);
  if (vm)
    wray_init(vm);

  return vm;
}
