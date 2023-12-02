include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/b796f7d44681514f58a683a3a71ff17c94edb0c1.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

link_directories(usr/lib/x86_64-linux-gnu)

set(SOURCE_FILES src/library.cpp src/library.h
        src/math/types/Mat.h
        src/math/types/Mat4.h
        src/math/types/Vec2.h
        src/math/types/Vec3.h
        src/math/types/Vec4.h)

add_library(lib ${SOURCE_FILES})

target_link_libraries(lib glfw dl gtest_main)

enable_testing()

add_executable(
        Engine_Test
        test/hello_test.cpp
        test/Vec2.cpp
)
target_link_libraries(
        Engine_Test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Engine_Test)