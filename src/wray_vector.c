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

#include <stdint.h>

#include <raylib.h>
#include <raymath.h>

#include <wren.h>
#include "wray_internal.h"

#define WRAY_VECN_GET(n, vm) \
  wrenEnsureSlots(vm, 1); \
  uint32_t i = wrenGetSlotDouble(vm, 1); \
  if (i > n) { \
    wrenSetSlotString(vm, 0, "Vector index out of bounds."); \
    wrenAbortFiber(vm, 0); \
  } \
  /* NOTE: Assumes VectorN struct is packed and ordered. */ \
  float *vec = wrenGetSlotForeign(vm, 0); \
  wrenSetSlotDouble(vm, 0, vec[i])

#define WRAY_VECN_SET(n, vm) \
  uint32_t i = wrenGetSlotDouble(vm, 1); \
  if (i > n) { \
    wrenSetSlotString(vm, 0, "Vector index out of bounds."); \
    wrenAbortFiber(vm, 0); \
  } \
  /* NOTE: Assumes VectorN struct is packed and ordered. */ \
  float *vec = wrenGetSlotForeign(vm, 0); \
  vec[i] = wrenGetSlotDouble(vm, 2);

/*
 * Vector2 binding
 */

void wray_vec2_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Vector2));
}

void wray_vec2_new(WrenVM *vm)
{
  Vector2 *v = wrenGetSlotForeign(vm, 0);

  v->x = wrenGetSlotDouble(vm, 1);
  v->y = wrenGetSlotDouble(vm, 2);
}

void wray_vec2_index_get(WrenVM *vm)
{
  WRAY_VECN_GET(2, vm);
}

void wray_vec2_index_set(WrenVM *vm)
{
  WRAY_VECN_SET(2, vm);
}

/*
 * Vector3 binding
 */

void wray_vec3_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Vector3));
}

void wray_vec3_new(WrenVM *vm)
{
  Vector3 *v = wrenGetSlotForeign(vm, 0);

  v->x = wrenGetSlotDouble(vm, 1);
  v->y = wrenGetSlotDouble(vm, 2);
  v->z = wrenGetSlotDouble(vm, 3);
}

void wray_vec3_index_get(WrenVM *vm)
{
  WRAY_VECN_GET(3, vm);
}

void wray_vec3_index_set(WrenVM *vm)
{
  WRAY_VECN_SET(3, vm);
}

/*
 * Vector4 binding
 */

void wray_vec4_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Vector4));
}

void wray_vec4_new(WrenVM *vm)
{
  Vector4 *v = wrenGetSlotForeign(vm, 0);

  v->x = wrenGetSlotDouble(vm, 1);
  v->y = wrenGetSlotDouble(vm, 2);
  v->z = wrenGetSlotDouble(vm, 3);
  v->w = wrenGetSlotDouble(vm, 4);
}

void wray_vec4_index_get(WrenVM *vm)
{
  WRAY_VECN_GET(4, vm);
}

void wray_vec4_index_set(WrenVM *vm)
{
  WRAY_VECN_SET(4, vm);
}
