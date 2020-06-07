project(test)

add_library(test SHARED test.c)
add_executable(main main.c)
#target_compile_options(main PRIVATE -fPIC)
target_link_libraries(main PRIVATE test)
