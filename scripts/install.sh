#!/bin/sh

install_cmocka() {
  git clone git://git.cryptomilk.org/projects/cmocka.git .deps/cmocka
  mkdir -p .build-deps
  cd .build-deps
  cmake -DCMAKE_INSTALL_PREFIX=../libs/cmocka -DWITH_STATIC_LIB=ON ../.deps/cmocka
  make && make install
  cd ..
  rm -rf .build-deps
  rm -rf .deps
}

install_libtesting() {
  git clone https://github.com/wingyplus/libtesting.git libs/libtesting
}

install_cmocka && install_libtesting
