cmake_minimum_required(VERSION 3.28)
project(trees C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED YES)

set(SOURCE bstree.c)

add_library(trees OBJECT ${SOURCE})

Include(FetchContent)
FetchContent_Declare(
        clove-unit
        GIT_REPOSITORY https://github.com/fdefelici/clove-unit.git
        GIT_TAG v2.4.5
)
FetchContent_MakeAvailable(clove-unit)

set(ALL_TESTS all_tests.c bstree_tests.c)
add_executable(all_tests ${ALL_TESTS})
target_link_libraries(all_tests PRIVATE clove-unit trees)
