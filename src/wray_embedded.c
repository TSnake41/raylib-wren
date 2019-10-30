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

/* Wray embedded executable */
#include <stdio.h>
#include <string.h>

#include <wren.h>
#include <wray.h>

#include "lib/miniz.h"

#ifndef WRAY_NO_BUILDER
int wray_build_executable(const char *self_path, const char *input_path);
#endif

static mz_zip_archive zip_file;

static char *load_mod_zip_func(WrenVM *vm, const char *name)
{
  int index = mz_zip_reader_locate_file(&zip_file, name, NULL, 0);
  if (index == -1) {
    printf("[WRAY_EMBEDDED] %s: File not found.\n", name);
    return NULL;
  }

  mz_zip_archive_file_stat stat;
  if (!mz_zip_reader_file_stat(&zip_file, index, &stat)) {
    printf("[WRAY_STANDALONE] %s: Can't get file information.\n", name);
    return NULL;
  }

  size_t size = stat.m_uncomp_size;
  char *buffer = malloc(size + 1);
  if (buffer == NULL) {
    printf("[WRAY_STANDALONE] %s: Can't allocate file buffer.\n", name);
    return NULL;
  }
  buffer[size] = '\0';

  mz_zip_reader_extract_to_mem(&zip_file, index, buffer, size, 0);
  return buffer;
}

int main(int argc, const char **argv)
{
  mz_zip_zero_struct(&zip_file);
  bool ready = false;

  FILE *f = fopen(argv[0], "rb");

  if (f != NULL) {
    /* Read offset at the end of the file */
    fpos_t offset;
    fseek(f, -(long)sizeof(fpos_t), SEEK_END);
    fread(&offset, sizeof(fpos_t), 1, f);

    fsetpos(f, &offset);

    if (mz_zip_reader_init_cfile(&zip_file, f, 0, 0))
      ready = true;
  }

  if (!ready) {
    if (argc < 2) {
      puts("Usage: wray_embedded <input>");
      return 0;
    } else
      return wray_build_executable(argv[0], argv[1]);  
  }

  WrenConfiguration config;
  wrenInitConfiguration(&config);

  config.loadModuleFn = load_mod_zip_func;

  WrenVM *vm = wray_new_vm(&config);

  char *code = load_mod_zip_func(vm, "main");

  if (code) {
    wrenInterpret(vm, "main", code);
    free(code);
  }

  wrenFreeVM(vm);

  return 0;
}
