#include "HsFFI.h"

extern void __stginit_Foo(void);
static void Foo_init (void) __attribute__ ((constructor));
void Foo_init (void) {
  char *arg1 = "fake-main";
  char *argv[1] = { arg1 };
  char **argv_p = argv;
  char ***pargv_p = &argv_p;
  int argc = sizeof(argv) / sizeof(char *);
  hs_init(&argc, pargv_p);
  hs_add_root(__stginit_Foo);
}

