set(module llt_test)

add_executable(${module}
  main.c
  test.c
  leetcode_unit.c
  $<TARGET_OBJECTS:leetcode> 
)

target_include_directories(${module} PUBLIC
  ${PROJECT_SOURCE_DIR}/leetcode
  ${PROJECT_SOURCE_DIR}/test
)

install(TARGETS ${module} RUNTIME DESTINATION bin)
