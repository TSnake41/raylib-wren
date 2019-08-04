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

/* Wray standalone executable */
#include <stdio.h>
#include <string.h>

#include <wren.h>
#include <wray.h>

static char *load_mod_fs_func(WrenVM *vm, const char *name)
{
  /* TODO: Bundling */

  /* Append .wren to the path */
  size_t path_size = strlen(name) + 6;
  char *path = malloc(path_size + 1);

  if (path == NULL)
    return NULL;

  snprintf(path, path_size, "%s.wren", name);

  FILE *f = fopen(path, "rb");
  free(path);

  if (f == NULL) {
    printf("[WRAY_STANDALONE] Can't load %s.\n", name);
    return NULL;
  }

  fseek(f, 0, SEEK_END);
  size_t size = ftell(f);
  fseek(f, 0, 0);

  char *buffer = malloc(size + 1);
  if (buffer == NULL) {
    /* Oh common... */
    printf("[WRAY_STANDALONE] %s: Can't allocate file buffer.\n", path);

    fclose(f);
    return NULL;
  }

  fread(buffer, size, 1, f);
  buffer[size] = '\0';

  return buffer;
}

int main(int argc, const char **argv)
{
  WrenConfiguration config;
  wrenInitConfiguration(&config);

  config.loadModuleFn = load_mod_fs_func;

  if (argc > 1) {
    WrenVM *vm = wray_new_vm(&config);

    char *code = load_mod_fs_func(vm, argv[1]);

    if (code) {
      wrenInterpret(vm, argv[1], code);
      free(code);
    }

    wrenFreeVM(vm);
  } else
    puts("Usage : wray_standalone [module]");

  return 0;
}
