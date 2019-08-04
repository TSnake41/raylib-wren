/*
 * This is bin2c program, which allows you to convert binary file to
 * C language array, for use as embedded resource, for instance you can
 * embed graphics or audio file directly into your program.
 * This is public domain software, use it on your own risk.
 * Contact Serge Fukanchik at fuxx@mail.ru  if you have any questions.
 *
 * Some modifications were made by Gwilym Kuiper (kuiper.gwilym@gmail.com)
 * I have decided not to change the licence.
 */

/* With some modifications by Astie Teddy.
 * Licence is left unchanged.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef USE_LZ4
#include "lib/lz4.h"
#include "lib/lz4hc.h"
#endif

int main(int argc, char *argv[])
{
  char *src, *ident;
  size_t i, file_size, need_comma;

  FILE *f_input, *f_output;

  #ifdef USE_LZ4
  char *lz4_buf;
  unsigned int uncompressed_size;
  int lz4_size, lz4_buf_size;
  #endif

  if (argc < 4) {
    fprintf(stderr, "Usage: %s binary_file output_file array_name\n", argv[0]);
    return -1;
  }

  f_input = fopen(argv[1], "rb");
  if (f_input == NULL) {
    fprintf(stderr, "%s: can't open %s for reading\n", argv[0], argv[1]);
    return -1;
  }

  // Get the file length
  fseek(f_input, 0, SEEK_END);
  file_size = ftell(f_input);
  fseek(f_input, 0, SEEK_SET);

  src = malloc(file_size);
  if (!src) {
    perror("malloc(file_size)");
    exit(1);
  }

  fread(src, file_size, 1, f_input);
  fclose(f_input);

  #ifdef USE_LZ4
  // allocate for lz4.
  lz4_buf_size = LZ4_compressBound(file_size);

  lz4_buf = malloc(lz4_buf_size);
  if (!lz4_buf) {
    perror("malloc(lz4_buf_size)");
    exit(1);
  }

  // compress the data
  #ifndef LZ4_FAST
  lz4_size = LZ4_compress_HC(src, lz4_buf, file_size, lz4_buf_size, LZ4HC_CLEVEL_MAX);
  #else
  lz4_size = LZ4_compress_default(src, lz4_buf, file_size, lz4_buf_size);
  #endif

  if (lz4_size == 0) {
    fputs("Failed to compress data.\n", stderr);
    return -1;
  }

  // and be very lazy
  free(src);
  uncompressed_size = file_size;
  file_size = lz4_size;
  src = lz4_buf;
  #endif

  f_output = fopen(argv[2], "w");
  if (f_output == NULL) {
    fprintf(stderr, "%s: can't open %s for writing\n", argv[0], argv[1]);
    return -1;
  }

  ident = argv[3];

  need_comma = 0;

  fprintf(f_output, "const char %s[%lu] = {", ident, file_size);
  for (i = 0; i < file_size; ++i) {
    if (need_comma)
      fprintf(f_output, ", ");
    else
      need_comma = 1;
    if ((i % 11) == 0)
      fprintf(f_output, "\n\t");
    fprintf(f_output, "0x%.2x", src[i] & 0xff);
  }
  fprintf(f_output, "\n};\n\n");

  fprintf(f_output, "const int %s_length = %lu;\n", ident, file_size);

  #ifdef USE_LZ4
  fprintf(f_output, "const int %s_length_uncompressed = %lu;\n", ident, uncompressed_size);
  fprintf(f_output, "#define %s_LZ4", ident);
  #endif

  fclose(f_output);

  return 0;
}
