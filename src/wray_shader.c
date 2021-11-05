/*
  Copyright (C) 2021 Astie Teddy

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

#include <raylib.h>

#include <wren.h>
#include "wray_internal.h"

static void wray_shader_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Shader));
}

static void wray_shader_finalize(void *ptr)
{
  if (IsWindowReady())
    UnloadShader(*(Shader *)ptr);
}

static void wray_shader_new(WrenVM *vm)
{
  Shader *s = wrenGetSlotForeign(vm, 0);
  *s = LoadShader(wrenGetSlotString(vm, 1), wrenGetSlotString(vm, 2));
}

static void wray_shader_new_frag(WrenVM *vm)
{
  Shader *s = wrenGetSlotForeign(vm, 0);
  *s = LoadShader(wrenGetSlotString(vm, 1), NULL);
}

MAKE_FIELD_GETTER(shader, Double, Shader, id);

const wray_binding_class wray_shader_class = {
  "Shader", { wray_shader_initialize, wray_shader_finalize }, {
    { wray_shader_new, false, "init new(_,_)" },
    { wray_shader_new_frag, false, "init new(_)" },
    { wray_shader_id_get, false, "id" },
    { NULL, NULL, NULL }
  }
};