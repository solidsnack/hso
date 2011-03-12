#include "HsFFI.h"

extern void __stginit_Foo(void);
static void Foo_init (void) __attribute__ ((constructor));
void Foo_init (void) {
  int argc = 1;
  char *argv[] = {""};
  char **argv_p = argv;
  hs_init(&argc, &argv_p);
  hs_add_root(__stginit_Foo);
}

