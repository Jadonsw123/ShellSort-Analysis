
# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

# Create the executable (s)
add_executable(main shellTest.cpp stuff.cpp)



set(CMAKE_VERBOSE_MAKEFILE OFF)