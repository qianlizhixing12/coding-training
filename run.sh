#! /usr/bin/bash

root_path=$(pwd)
build=${root_path}/build
output=${root_path}/output

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
  # export ASAN_OPTIONS="stack_trace_format='  #%n %p in %f (%m+%o)':detect_leaks=1:halt_on_error=0:alloc_dealloc_mismatch=0:log_path=${output}/asan/asan_report.log"
  export ASAN_OPTIONS="stack_trace_format='  #%n %p in %f (%s:%l)':detect_leaks=1:halt_on_error=0:alloc_dealloc_mismatch=0:log_path=${output}/asan/asan_report.log"

  pushd "${output}/bin"
    ./llt_test "--select"
  popd

  get_coverage
}

main $@