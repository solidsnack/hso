{-# LANGUAGE ForeignFunctionInterface #-}
module Foo where

import Foreign.C


foreign export ccall foo    ::  CInt -> CInt

foo                         ::  CInt -> CInt
foo                          =  (+1)

