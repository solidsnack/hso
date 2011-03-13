#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void dldie(void) {
  char* e = dlerror();
  if ( e != NULL ) {
    printf("**** %s: %s\n", "dynamic loading error", e);
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char* argv[]) {
  char* so = argv[1];
  printf("**** %s %s\n", "trying to load", so);
  void *dl = dlopen(so, RTLD_NOW);
  dldie();
  printf("**** %s\n", ".so load okay");
  int (*foo)(int) = dlsym(dl, "foo");
  dldie();
  printf("**** %s\n", "symbol lookup okay");
  printf("**** foo(7) -> %d\n", foo(7));
  exit(EXIT_SUCCESS);
}

