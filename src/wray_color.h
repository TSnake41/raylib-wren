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

#ifndef H_WRAY_COLOR
#define H_WRAY_COLOR

#include <wren.h>
#include "wray_internal.h"

void wray_color_initialize(WrenVM *vm);
void wray_color_new_hex(WrenVM *vm);
void wray_color_new_rgba(WrenVM *vm);
void wray_color_new_rgb(WrenVM *vm);

void wray_color_hex_get(WrenVM *vm);

void wray_color_r_get(WrenVM *vm);
void wray_color_g_get(WrenVM *vm);
void wray_color_b_get(WrenVM *vm);
void wray_color_a_get(WrenVM *vm);

void wray_color_r_set(WrenVM *vm);
void wray_color_g_set(WrenVM *vm);
void wray_color_b_set(WrenVM *vm);
void wray_color_a_set(WrenVM *vm);

extern const wray_binding_class wray_color_class;

#endif /* H_WRAY_COLOR */
