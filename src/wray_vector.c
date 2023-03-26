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
#include <string.h>

#include <raylib.h>
#include <raymath.h>

#include <wren.h>
#include "wray_internal.h"

#define Vector2Multiply Vector2MultiplyV

#define WRAY_VECN_GET(n, vm) \
  wrenEnsureSlots(vm, 1); \
  unsigned int i = wrenGetSlotDouble(vm, 1); \
  if (i > n) { \
    wrenSetSlotString(vm, 0, "Vector index out of bounds."); \
    wrenAbortFiber(vm, 0); \
    return; \
  } \
  /* NOTE: Assumes VectorN struct is packed and ordered. */ \
  float *vec = wrenGetSlotForeign(vm, 0); \
  wrenSetSlotDouble(vm, 0, vec[i])

#define WRAY_VECN_SET(n, vm) \
  unsigned int i = wrenGetSlotDouble(vm, 1); \
  if (i > n) { \
    wrenSetSlotString(vm, 0, "Vector index out of bounds."); \
    wrenAbortFiber(vm, 0); \
    return; \
  } \
  /* NOTE: Assumes VectorN struct is packed and ordered. */ \
  float *vec = wrenGetSlotForeign(vm, 0); \
  vec[i] = wrenGetSlotDouble(vm, 2);

#define WRAY_VECN_OP(n, op, vm) \
  wray_CheckForeignType(vm, 1, "RlVector" #n) \
  Vector##n *a = wrenGetSlotForeign(vm, 0); \
  Vector##n *b = wrenGetSlotForeign(vm, 1); \
  *a = Vector##n##op(*a, *b)

/* Generate most operators functions (add, sub, mul, div, dot, length, dist, negate). */
#define WRAY_VECN_GENOP(n) \
  static void wray_vec##n##_add(WrenVM *vm) { WRAY_VECN_OP(n, Add, vm); } \
  static void wray_vec##n##_sub(WrenVM *vm) { WRAY_VECN_OP(n, Subtract, vm); } \
  static void wray_vec##n##_mul(WrenVM *vm) { \
    if (wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) { \
      Vector##n *a = wrenGetSlotForeign(vm, 0); \
      *a = Vector##n##Scale(*a, wrenGetSlotDouble(vm, 1)); \
    } else { WRAY_VECN_OP(n, Multiply, vm); } \
  } \
  static void wray_vec##n##_div(WrenVM *vm) { \
    if (wrenGetSlotType(vm, 1) == WREN_TYPE_NUM) { \
      Vector##n *a = wrenGetSlotForeign(vm, 0); \
      *a = Vector##n##Divide(*a, wrenGetSlotDouble(vm, 1)); \
    } else { WRAY_VECN_OP(n, DivideV, vm); } \
  } \
  static void wray_vec##n##_dot(WrenVM *vm) { \
    wray_CheckForeignType(vm, 1, "RlVector" #n); \
    wrenSetSlotDouble(vm, 0, Vector##n##DotProduct( \
      *(Vector##n *)wrenGetSlotForeign(vm, 0), \
      *(Vector##n *)wrenGetSlotForeign(vm, 1) \
    )); \
  } \
  static void wray_vec##n##_dist(WrenVM *vm) { \
    wray_CheckForeignType(vm, 1, "RlVector" #n); \
    wrenSetSlotDouble(vm, 0, Vector##n##Distance( \
      *(Vector##n *)wrenGetSlotForeign(vm, 0), \
      *(Vector##n *)wrenGetSlotForeign(vm, 1) \
    )); \
  } \
  static void wray_vec##n##_length(WrenVM *vm) { \
    wrenSetSlotDouble(vm, 0, Vector##n##Length( \
      *(Vector##n *)wrenGetSlotForeign(vm, 0) \
    )); \
  } \
  static void wray_vec##n##_negate(WrenVM *vm) { \
    Vector##n *a = wrenGetSlotForeign(vm, 0); \
    *a = Vector##n##Negate(*a); \
  } \
  static void wray_vec##n##_normalize(WrenVM *vm) { \
    Vector##n *a = wrenGetSlotForeign(vm, 0); \
    *a = Vector##n##Normalize(*a); \
  } \
  static void wray_vec##n##_lerp(WrenVM *vm) { \
    wray_CheckForeignType(vm, 1, "RlVector" #n); \
    Vector##n *a = wrenGetSlotForeign(vm, 0); \
    Vector##n *b = wrenGetSlotForeign(vm, 1); \
    *a = Vector##n##Lerp(*a, *b, wrenGetSlotDouble(vm, 2)); \
  } \
  static void wray_vec##n##_copy(WrenVM *vm) { \
    wray_CheckForeignType(vm, 1, "RlVector" #n); \
    Vector##n *a = wrenGetSlotForeign(vm, 0); \
    Vector##n *b = wrenGetSlotForeign(vm, 1); \
    memcpy(b, a, sizeof(Vector##n)); \
    wrenSetSlotHandle(vm, 0, wrenGetSlotHandle(vm, 1)); /* Move b to slot 0. */ \
  }

/*
 * Vector2 binding
 */

static void wray_vec2_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Vector2));
}

static void wray_vec2_new(WrenVM *vm)
{
  Vector2 *v = wrenGetSlotForeign(vm, 0);

  v->x = wrenGetSlotDouble(vm, 1);
  v->y = wrenGetSlotDouble(vm, 2);
}

static void wray_vec2_index_get(WrenVM *vm)
{
  WRAY_VECN_GET(2, vm);
}

static void wray_vec2_index_set(WrenVM *vm)
{
  WRAY_VECN_SET(2, vm);
}

WRAY_VECN_GENOP(2)

const wray_binding_class wray_vec2_class = {
  "RlVector2", { wray_vec2_initialize, NULL }, {
    { wray_vec2_new, false, "init new(_,_)" },
    { wray_vec2_index_get, false, "[_]" },
    { wray_vec2_index_set, false, "[_]=(_)" },
    /* NOTE: _ suffixed functions modify self value. */
    { wray_vec2_add, false, "add_(_)" },
    { wray_vec2_sub, false, "sub_(_)" },
    { wray_vec2_mul, false, "mul_(_)" },
    { wray_vec2_div, false, "div_(_)" },
    { wray_vec2_dot, false, "dot(_)" },
    { wray_vec2_lerp, false, "lerp_(_,_,_)" },
    { wray_vec2_negate, false, "negated_" },
    { wray_vec2_normalize, false, "normalized_" },
    { wray_vec2_dist, false, "distance(_)" },
    { wray_vec2_length, false, "length" },
    { wray_vec2_copy, false, "copy(_)" },
    { NULL, NULL, NULL }
  }
};

/*
 * Vector3 binding
 */

static void wray_vec3_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Vector3));
}

static void wray_vec3_new(WrenVM *vm)
{
  Vector3 *v = wrenGetSlotForeign(vm, 0);

  v->x = wrenGetSlotDouble(vm, 1);
  v->y = wrenGetSlotDouble(vm, 2);
  v->z = wrenGetSlotDouble(vm, 3);
}

static void wray_vec3_index_get(WrenVM *vm)
{
  WRAY_VECN_GET(3, vm);
}

static void wray_vec3_index_set(WrenVM *vm)
{
  WRAY_VECN_SET(3, vm);
}

WRAY_VECN_GENOP(3)

const wray_binding_class wray_vec3_class = {
  "RlVector3", { wray_vec3_initialize, NULL }, {
    { wray_vec3_new, false, "init new(_,_,_)" },
    { wray_vec3_index_get, false, "[_]" },
    { wray_vec3_index_set, false, "[_]=(_)" },
    { wray_vec3_add, false, "add_(_)" },
    { wray_vec3_sub, false, "sub_(_)" },
    { wray_vec3_mul, false, "mul_(_)" },
    { wray_vec3_div, false, "div_(_)" },
    { wray_vec3_dot, false, "dot(_)" },
    { wray_vec3_lerp, false, "lerp_(_,_,_)" },
    { wray_vec3_negate, false, "negated_" },
    { wray_vec3_normalize, false, "normalized_" },
    { wray_vec3_dist, false, "distance(_)" },
    { wray_vec3_length, false, "length" },
    { wray_vec3_copy, false, "copy(_)" },
    { NULL, NULL, NULL }
  }
};

/*
 * Vector4 binding
 */

static void wray_vec4_initialize(WrenVM *vm)
{
  wrenEnsureSlots(vm, 1);
  wrenSetSlotNewForeign(vm, 0, 0, sizeof(struct Vector4));
}

static void wray_vec4_new(WrenVM *vm)
{
  Vector4 *v = wrenGetSlotForeign(vm, 0);

  v->x = wrenGetSlotDouble(vm, 1);
  v->y = wrenGetSlotDouble(vm, 2);
  v->z = wrenGetSlotDouble(vm, 3);
  v->w = wrenGetSlotDouble(vm, 4);
}

static void wray_vec4_index_get(WrenVM *vm)
{
  WRAY_VECN_GET(4, vm);
}

static void wray_vec4_index_set(WrenVM *vm)
{
  WRAY_VECN_SET(4, vm);
}

const wray_binding_class wray_vec4_class = {
  "RlVector4", { wray_vec4_initialize, NULL }, {
    { wray_vec4_new, false, "init new(_,_,_,_)" },
    { wray_vec4_index_get, false, "[_]" },
    { wray_vec4_index_set, false, "[_]=(_)" },
    { NULL, NULL, NULL }
  }
};
