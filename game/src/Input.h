//
// Created by Jonas on 9/28/19.
//

#ifndef INC_3D_ENGINE_INPUT_H
#define INC_3D_ENGINE_INPUT_H

#include "../../lib/src/rendering/actors/AbstractCamera.h"

class Input {

 public:
  static AbstractCamera *camera;

  static void setCamera(AbstractCamera *cam);

  static bool getKeyPressed(GLFWwindow *, int key);
  static bool getKeyReleased(GLFWwindow *, int key);

  static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
  static void mouse_callback(GLFWwindow *window, int button, int action, int mods);
  static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
  static void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

};

#endif //INC_3D_ENGINE_INPUT_H
