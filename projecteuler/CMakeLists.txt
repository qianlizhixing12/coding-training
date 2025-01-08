set(module projecteuler)


file(GLOB_RECURSE SRC_LIST "./*.c")	
add_library(${module} OBJECT ${SRC_LIST})

target_link_libraries(${module} PUBLIC m)

# target_include_directories(${module} PUBLIC ${PROJECT_SOURCE_DIR}/uthash/src)

install(TARGETS ${module} ARCHIVE DESTINATION lib)
