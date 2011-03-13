#include "HsFFI.h"

extern void __stginit_Foo(void);
static void Foo_init (void) __attribute__ ((constructor));
void Foo_init (void) {
  int argc = 1;
  char *arg = "";
  char **argv = &arg;
  hs_init(&argc, &argv);
  hs_add_root(__stginit_Foo);
}

