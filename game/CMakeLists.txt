set(SOURCE_FILES src/main.cpp
        src/cameras/FPSCamera.cpp src/cameras/FPSCamera.h
        src/cameras/FreeCamera.cpp src/cameras/FreeCamera.h
        src/generators/AbstractGenerator.cpp src/generators/AbstractGenerator.h
        src/generators/DungeonGenerator.cpp src/generators/DungeonGenerator.h
        src/generators/OverWorldGenerator.cpp src/generators/OverWorldGenerator.h
        src/fpsgame/Wolfenstein3DClone.cpp src/fpsgame/Wolfenstein3DClone.h
        src/Input.cpp src/Input.h
        src/fpsgame/Player.cpp
        src/fpsgame/Player.h
)
add_executable(game ${SOURCE_FILES})
target_link_libraries(game lib)