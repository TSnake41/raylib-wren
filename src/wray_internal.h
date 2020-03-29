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

#ifndef H_WRAY_INTERNAL
#define H_WRAY_INTERNAL

#include <wren.h>
#include <wray.h>

#include "wray_class.h"

typedef struct wray_internal {
  wray_class_handles handles;
} wray_internal;

#define NYI \
  wrenEnsureSlots(vm, 1); \
  wrenSetSlotString(vm, 0, "This function is not yet implemented."); \
  wrenAbortFiber(vm, 0);

/* Get a field, and return it, make the function associated to it. */
#define MAKE_FIELD_GETTER(type_internal, wren_type, type, name) \
void wray_##type_internal##_##name##_get(WrenVM *vm) \
{ \
  wrenSetSlot##wren_type(vm, 0, ((type *)wrenGetSlotForeign(vm, 0))->name); \
}

#define WRAY_GET_CLASSES(vm) (&((wray_internal *)wrenGetUserData(vm))->handles)

#ifdef WRAY_TYPE_CHECK
#include "wray_typecheck.h"

/* Replace wrenGetSlot* with typechecked procedures. */
#define wrenGetSlotBool    wray_GetSlotBool_tc
#define wrenGetSlotDouble  wray_GetSlotDouble_tc
#define wrenGetSlotBytes   wray_GetSlotBytes_tc
#define wrenGetSlotForeign wray_GetSlotForeign_tc
#define wrenGetSlotString  wray_GetSlotString_tc
#define wrenGetIsInstance  wray_GetIsInstance_tc
#define wrenGetListCount   wray_GetListCount_tc
#define wrenGetListElement wray_GetListElement_tc
#define wrenInsertInList   wray_InsertInList_tc
#else
#define wray_CheckForeignType(vm, slot, type) /* Do nothing */
#endif

#endif /* H_WRAY_INTERNAL */
