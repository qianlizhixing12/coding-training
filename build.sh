#! /usr/bin/bash

workpace=$(pwd)
build=${workpace}/build
output=${workpace}/output

if [ -d "${output}" ]; then
  rm -rf "${output}"
fi
mkdir "${output}"

if [ -d "${build}" ]; then
  rm -rf "${build}"
fi
mkdir "${build}"

pushd "${build}"
  cmake -B ${build} -S ../ -DCMAKE_INSTALL_PREFIX="${output}"
  make verbose=1
popd

pushd "${output}/bin"
  ./llt_test
popd
