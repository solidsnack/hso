
require 'dl/import'

module Foo
extend DL::Importable
  DL_PATH = File.dirname(__FILE__) + '/libfoo.static-static.so'
  dlload(DL_PATH)
  extern 'int foo(int)'
end

