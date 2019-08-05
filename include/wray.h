#ifndef H_WRAY
#define H_WRAY

#include <wren.h>

WrenForeignMethodFn wray_bind_foreign_method(WrenVM *, const char *,
  const char *, bool, const char *);

WrenForeignClassMethods wray_bind_foreign_class(WrenVM *, const char *,
  const char *);

WrenVM *wray_new_vm(WrenConfiguration *);

void wray_init_vm(void);

#endif /* H_WRAY */
