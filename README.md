# 3D Engine

Small 3D Engine to learn engine programming, OpenGL and software development in general
The original repo can be found at: https://gitlab.com/VikingCoder/MCClone
This will be a rewrite of that version to clean up the architecture, code style, etc.

# [WIP] Setup Guide

- install glfw with apt-get install libglfw3-dev
- install glm with libglm-dev
- download stb_image.f from https://github.com/nothings/stb/blob/master/stb_image.h
    - create stb_image.cpp file with contents:
    - #define STB_IMAGE_IMPLEMENTATION
    - #include "stb_image.h"
- download glad from https://glad.dav1d.de/