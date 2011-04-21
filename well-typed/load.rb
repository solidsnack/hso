
require 'dl/import'

module Foo
extend DL::Importable
  DL_PATH = File.dirname(__FILE__) + '/libfoo.dynamic-dynamic.so'
  dlload(DL_PATH)
  extern 'int foo(int)'
end

