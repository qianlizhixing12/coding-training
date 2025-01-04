#! /usr/bin/bash

root_path=$(pwd)
build=${root_path}/build
output=${root_path}/output
feature="release"
compile_flag="-Wall -Werror -O1 -pie -fPIE -fstack-protector"
link_flag=""

function help() {
  echo "Usage:"
  echo "build.sh [-f asan/tsan/gcov]"
  exit 0
}

function make_workspace()
{
  if [ -d "${output}" ]; then
    rm -rf "${output}"
  fi

  if [ -d "${build}" ]; then
    rm -rf "${build}"
  fi

  mkdir "${output}"
  mkdir "${build}"
}

function set_asan()
{
  compile_flag="${compile_flag} -g -fsanitize=address -fno-omit-frame-pointer -fsanitize-recover=address -fno-common"
  # export ASAN_OPTIONS="stack_trace_format='  #%n %p in %f (%m+%o)':detect_leaks=1:halt_on_error=0:alloc_dealloc_mismatch=0:log_path=${output}/asan/asan_report.log"
  export ASAN_OPTIONS="stack_trace_format='  #%n %p in %f (%s:%l)':detect_leaks=1:halt_on_error=0:alloc_dealloc_mismatch=0:log_path=${output}/asan/asan_report.log"
}

function set_tasn()
{
  compile_flag="${compile_flag} -g -fsanitize=thread"
}

function set_gcov()
{
  compile_flag="${compile_flag} -g -fprofile-arcs -ftest-coverage"
  link_flag="${link_flag} -lgcov"
}

function set_feature()
{
  feature="$1"

  if [ "${feature}" == "asan" ]; then
    set_asan
  elif [ "${feature}" == "tsan" ]; then
    set_tasn
  elif [ "${feature}" == "gcov" ]; then
    set_asan && set_gcov
  else
    echo "not support ${feature}"
    help
  fi
}

function get_coverage()
{
  mkdir "${output}/coverage"

  pushd "${output}/coverage"
    lcov --rc branch_coverage=1 -c -d ${build} -o coverage_all.info
    lcov --rc branch_coverage=1 --remove coverage_all.info '/usr/*' '*/test/*' -o coverage.info
    genhtml --branch-coverage -o ./ coverage.info
  popd
}

function main()
{
  while getopts 'f:h' opt; do
    case $opt in
      f) set_feature ${OPTARG};;
      h) help;;
      ?) help;;
    esac
  done

  make_workspace

  pushd "${build}"
    cmake -B ${build} -S ../ -DCMAKE_INSTALL_PREFIX="${output}" -DUSER_FLAG="${compile_flag}" -DUSER_LINK_FLAG="${link_flag}"
    # make VERBOSE=1
    make
  popd

  pushd "${output}/bin"
    ./llt_test
  popd

  if [ "${feature}" == "gcov" ]; then
    get_coverage
  fi
}

main $@
