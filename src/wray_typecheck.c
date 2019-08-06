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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <wren.h>

#ifdef WRAY_TYPE_CHECK

#ifndef WRAY_USE_ABORT
#define abort() exit(1)
#endif

// TODO: Expose this function to Wren C API ?
void wrenDebugPrintStackTrace(WrenVM *vm);

static void wray_type_error_abort(WrenVM *vm, int slot, const char *expected)
{
  wrenEnsureSlots(vm, 1);
  const char *format = "Expected parameter of slot %d to be '%s', got '%s'.";
  const char *got_type = wrenGetSlotTypeName(vm, slot);

  size_t len = snprintf(NULL, 0, format, slot, expected, got_type) + 1;
  char *str = malloc(len);

  if (str)
    snprintf(str, len, format, slot, expected, got_type);
  else
    str = "Argument error (can't allocate error).";

  wrenSetSlotString(vm, 0, str);
  wrenAbortFiber(vm, 0);

  wrenDebugPrintStackTrace(vm);
  abort();

  /* unreachable */
}

void wray_CheckForeignType(WrenVM *vm, int slot, const char *type)
{
  if (wrenGetSlotType(vm, slot) != WREN_TYPE_FOREIGN ||
      strcmp(wrenGetSlotTypeName(vm, slot), type) != 0)
    wray_type_error_abort(vm, slot, type);
}

bool wray_GetSlotBool_tc(WrenVM *vm, int slot)
{
  if (wrenGetSlotType(vm, slot) != WREN_TYPE_BOOL)
    wray_type_error_abort(vm, slot, "Bool");

  return wrenGetSlotBool(vm, slot);
}

double wray_GetSlotDouble_tc(WrenVM *vm, int slot)
{
  if (wrenGetSlotType(vm, slot) != WREN_TYPE_NUM)
    wray_type_error_abort(vm, slot, "Num");

  return wrenGetSlotDouble(vm, slot);
}

const char *wray_GetSlotBytes_tc(WrenVM *vm, int slot, int *length)
{
  if (wrenGetSlotType(vm, slot) != WREN_TYPE_STRING)
    wray_type_error_abort(vm, slot, "String");

  return wrenGetSlotBytes(vm, slot, length);
}

void *wray_GetSlotForeign_tc(WrenVM *vm, int slot)
{
  if (wrenGetSlotType(vm, slot) != WREN_TYPE_FOREIGN)
    wray_type_error_abort(vm, slot, "Foreign");

  return wrenGetSlotForeign(vm, slot);
}

const char *wray_GetSlotString_tc(WrenVM *vm, int slot)
{
  if (wrenGetSlotType(vm, slot) != WREN_TYPE_STRING)
    wray_type_error_abort(vm, slot, "String");

  return wrenGetSlotString(vm, slot);
}

void wray_GetIsInstance_tc(WrenVM *vm, int slot, int classSlot)
{
  if (wrenGetSlotType(vm, classSlot) != WREN_TYPE_CLASS)
    wray_type_error_abort(vm, slot, "Class");

  return wrenGetSlotClass(vm, slot, classSlot);
}

int wray_GetListCount_tc(WrenVM *vm, int slot)
{
  if (wrenGetSlotType(vm, slot) != WREN_TYPE_LIST)
    wray_type_error_abort(vm, slot, "List");

  return wrenGetListCount(vm, slot);
}

void wray_GetListElement_tc(WrenVM *vm, int listSlot, int index, int elementSlot)
{
  if (wrenGetSlotType(vm, listSlot) != WREN_TYPE_LIST)
    wray_type_error_abort(vm, listSlot, "List");

  wrenGetListElement(vm, listSlot, index, elementSlot);
}

void wray_InsertInList_tc(WrenVM *vm, int listSlot, int index, int elementSlot)
{
  if (wrenGetSlotType(vm, listSlot) != WREN_TYPE_LIST)
    wray_type_error_abort(vm, listSlot, "List");

  wrenInsertInList(vm, listSlot, index, elementSlot);
}

#endif /* WRAY_TYPE_CHECK */
