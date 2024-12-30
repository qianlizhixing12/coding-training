set(module projecteuler)

add_library(${module} OBJECT
  1.c
  2.c
  3.c
)

target_link_libraries(${module} PUBLIC m)

# target_include_directories(${module} PUBLIC ${PROJECT_SOURCE_DIR}/uthash/src)

install(TARGETS ${module} ARCHIVE DESTINATION lib)
