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

/* Wray embedded executable */
#include <stdio.h>
#include <string.h>

#include <wren.h>
#include <wray.h>

#include <raylib.h>

#include "lib/miniz.h"

#ifndef WRAY_NO_BUILDER
int wray_build_executable(const char *self_path, const char *input_path);
#endif

static mz_zip_archive zip_file;

static void mod_load_complete(WrenVM *vm, const char *module, WrenLoadModuleResult result)
{
  if(result.source)
    free(result.source);
}

static WrenLoadModuleResult load_mod_zip_func(WrenVM *vm, const char *name)
{
  struct WrenLoadModuleResult result = {
    .onComplete = &mod_load_complete,
    .source = NULL,
    .userData = NULL
  };


  int index = mz_zip_reader_locate_file(&zip_file, name, NULL, 0);
  if (index == -1) {
    printf("WRAY_E: %s: File not found.\n", name);
    return result;
  }

  mz_zip_archive_file_stat stat;
  if (!mz_zip_reader_file_stat(&zip_file, index, &stat)) {
    printf("WRAY_E: %s: Can't get file information.\n", name);
    return result;
  }

  size_t size = stat.m_uncomp_size;
  char *buffer = malloc(size + 1);
  if (buffer == NULL) {
    printf("WRAY_E: %s: Can't allocate file buffer.\n", name);
    return result;
  }
  buffer[size] = '\0';

  mz_zip_reader_extract_to_mem(&zip_file, index, buffer, size, 0);
  result.source = buffer;
  return result;
}

unsigned char *wray_loadFileData(const char *path, unsigned int *out_size)
{
  int index = mz_zip_reader_locate_file(&zip_file, path, NULL, 0);
  if (index == -1) {
    printf("WRAY_E: File not found in payload. '%s'\n", path);
    return NULL;
  }

  mz_zip_archive_file_stat stat;
  if (!mz_zip_reader_file_stat(&zip_file, index, &stat)) {
    printf("WRAY_E: Can't get file information in payload. '%s'\n", path);
    return NULL;
  }

  size_t size = stat.m_uncomp_size;
  unsigned char *buffer = RL_MALLOC(size);
  if (buffer == NULL) {
    printf("WRAY_E: Can't allocate file buffer. '%s'\n", path);
    return NULL;
  }

  if (!mz_zip_reader_extract_to_mem(&zip_file, index, buffer, size, 0)) {
    free(buffer);
    printf("WRAY_E: Can't extract file. '%s'\n", path);
    return NULL;
  }

  *out_size = size;
  return buffer;
}

char *wray_loadFileText(const char *path)
{
  int index = mz_zip_reader_locate_file(&zip_file, path, NULL, 0);
  if (index == -1) {
    printf("WRAY_E: WARN: File not found in payload. '%s'\n", path);
    return NULL;
  }

  mz_zip_archive_file_stat stat;
  if (!mz_zip_reader_file_stat(&zip_file, index, &stat)) {
    printf("WRAY_E: WARN: Can't get file information in payload. '%s'\n", path);
    return NULL;
  }

  size_t size = stat.m_uncomp_size;
  char *buffer = RL_MALLOC(size + 1);
  if (buffer == NULL) {
    printf("WRAY_E: WARN: Can't allocate file buffer. '%s'\n", path);
    return NULL;
  }

  buffer[size] = '\0';

  if (!mz_zip_reader_extract_to_mem(&zip_file, index, buffer, size, 0)) {
    free(buffer);
    printf("WRAY_E: WARN: Can't extract file. '%s'\n", path);
    return NULL;
  }

  return buffer;
}

int main(int argc, char **argv)
{
  mz_zip_zero_struct(&zip_file);

  if (!mz_zip_reader_init_file(&zip_file, argv[0], 0)) {
    if (argc < 2) {
      puts("Usage: wray_e <input>");
      return 0;
    } else
      return wray_build_executable(argv[0], argv[1]);
  }

  SetLoadFileDataCallback(wray_loadFileData);
  SetLoadFileTextCallback(wray_loadFileText);

  WrenConfiguration config;
  wrenInitConfiguration(&config);

  config.loadModuleFn = (WrenLoadModuleFn)load_mod_zip_func;

  WrenVM *vm = wray_new_vm(&config);

  char *code = load_mod_zip_func(vm, "main").source;

  if (code) {
    wrenInterpret(vm, "main", code);
    free(code);
  }

  wrenFreeVM(vm);

  return 0;
}
