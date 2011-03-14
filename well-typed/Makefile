include ./ghc_info.mk

dyn: loadfoo libfoo.dynamic-dynamic.so

all: loadfoo libfoo.static-static.so libfoo.dynamic-dynamic.so

loadfoo: loadfoo.c
	gcc ./loadfoo.c -ldl -o loadfoo

libfoo.static-static.so: Foo.hs fooinit.c
	ghc -fPIC -c fooinit.c
	ghc --make -fPIC -c Foo.hs
	ghc -shared -o libfoo.static-static.so \
	    Foo.o Foo_stub.o fooinit.o \
            -L/usr/lib/ghc-6.12.1/base-4.2.0.0 \
            -L/usr/lib/ghc-6.12.1/integer-gmp-0.2.0.0 \
            -L/usr/lib/ghc-6.12.1/ghc-prim-0.2.0.0 \
            -L/usr/lib/ghc-6.12.1 \
            -lHSrtsmain \
            -lHSbase-4.2.0.0 \
            -lHSinteger-gmp-0.2.0.0 \
            -lgmp \
            -lHSghc-prim-0.2.0.0 \
            -lHSrts \
            -lm -lffi -lrt -ldl

libfoo.dynamic-dynamic.so: Foo.hs fooinit.c
	ghc -fPIC -c fooinit.c
	ghc --make -dynamic -fPIC -c Foo.hs
	ghc -shared -dynamic -o libfoo.dynamic-dynamic.so \
	    Foo.o Foo_stub.o fooinit.o \
            -L${GHC_LIB_RTS} \
            -optl-Wl,-rpath,${GHC_LIB_RTS} \
            -lHSrts-ghc${GHC_VERSION}

clean:
	rm -f *_stub.c *_stub.h *.hi *.o *.so loadfoo

