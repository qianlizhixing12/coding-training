set(module llt_test)

add_executable(${module}
  main.c
  test.c
  leetcode.c
  projecteuler.c
  $<TARGET_OBJECTS:leetcode>
  $<TARGET_OBJECTS:projecteuler>
)

target_include_directories(${module} PUBLIC
  ${PROJECT_SOURCE_DIR}/leetcode
  ${PROJECT_SOURCE_DIR}/projecteuler
  ${PROJECT_SOURCE_DIR}/test
)

install(TARGETS ${module} RUNTIME DESTINATION bin)
