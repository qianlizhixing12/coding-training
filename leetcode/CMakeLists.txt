set(module leetcode)

add_library(${module} OBJECT
  leetcode.c
  1.c
  2.c
)

target_include_directories(${module} PUBLIC ${PROJECT_SOURCE_DIR}/uthash/src)

install(TARGETS ${module} ARCHIVE DESTINATION lib)
