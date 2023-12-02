//
// Created by Jonas on 10/2/19.
//

#ifndef INC_3D_ENGINE_WINDOW_H
#define INC_3D_ENGINE_WINDOW_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <string>

class Window {
 public:
  static GLFWwindow *window;

  static int width;
  static int height;

  static void createWindow(int w, int h, const std::string &title);
  static void registerInputCallbacks(GLFWkeyfun keyCallback,
                                     GLFWmousebuttonfun mouseCallback,
                                     GLFWcursorposfun cursorPositionCallback,
                                     GLFWscrollfun scrollCallback);
  static void clear();
  static void initGraphics();
  static void render();
  static void dispose();
  static float getAspectRatio();

  static bool isCloseRequested();
 private:
};

#endif //INC_3D_ENGINE_WINDOW_H
