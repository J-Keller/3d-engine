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

set(SOURCE_FILES
        src/include/glad.c
        src/include/stb_image.cpp src/include/stb_image.h
        src/library.cpp src/library.h
        src/math/types/Mat.h
        src/math/types/Mat4.h
        src/math/types/Vec2.h
        src/math/types/Vec3.h
        src/math/types/Vec4.h
        src/util/ModelLoader.cpp src/util/ModelLoader.h
        src/util/PerlinNoise2D.cpp src/util/PerlinNoise2D.h
        src/util/PerlinNoise3D.cpp src/util/PerlinNoise3D.h
        src/util/Time.cpp src/util/Time.h
        src/physics/collision/colliders/BoxCollider.cpp src/physics/collision/colliders/BoxCollider.h
        src/physics/collision/colliders/PointCollider.cpp src/physics/collision/colliders/PointCollider.h
        src/physics/collision/colliders/SphereCollider.cpp src/physics/collision/colliders/SphereCollider.h
        src/physics/collision/CollisionChecker.cpp src/physics/collision/CollisionChecker.h
        src/rendering/Window.cpp src/rendering/Window.h
        src/rendering/surface/Texture.cpp src/rendering/surface/Texture.h
        src/rendering/surface/Material.cpp src/rendering/surface/Material.h
        src/rendering/Mesh.cpp src/rendering/Mesh.h
        src/rendering/scene/SceneNode.cpp src/rendering/scene/SceneNode.h
        src/rendering/scene/Scene.cpp src/rendering/scene/Scene.h
        src/rendering/scene/Entity.cpp src/rendering/scene/Entity.h
        src/rendering/shader/PhongShader.cpp src/rendering/shader/PhongShader.h
        src/rendering/shader/Shader.cpp src/rendering/shader/Shader.h
        src/rendering/lighting/BaseLight.cpp src/rendering/lighting/BaseLight.h
        src/rendering/lighting/DirectionalLight.cpp src/rendering/lighting/DirectionalLight.h
        src/rendering/lighting/PointLight.cpp src/rendering/lighting/PointLight.h
        src/rendering/lighting/SpotLight.cpp src/rendering/lighting/SpotLight.h
        src/rendering/actors/Actor.cpp src/rendering/actors/Actor.h
        src/rendering/actors/Camera.cpp src/rendering/actors/Camera.h
        src/rendering/actors/Light.cpp src/rendering/actors/Light.h
        src/rendering/actors/AbstractCamera.cpp src/rendering/actors/AbstractCamera.h
)

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