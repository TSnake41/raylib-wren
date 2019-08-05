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

#ifndef H_WRAY_VECTOR
#define H_WRAY_VECTOR

#include <wray.h>

void wray_vec2_initialize(WrenVM *);
void wray_vec2_new(WrenVM *);
void wray_vec2_index_get(WrenVM *);
void wray_vec2_index_set(WrenVM *);

void wray_vec3_initialize(WrenVM *);
void wray_vec3_new(WrenVM *);
void wray_vec3_index_get(WrenVM *);
void wray_vec3_index_set(WrenVM *);

void wray_vec4_initialize(WrenVM *);
void wray_vec4_new(WrenVM *);
void wray_vec4_index_get(WrenVM *);
void wray_vec4_index_set(WrenVM *);

#endif /* H_WRAY_VECTOR */
