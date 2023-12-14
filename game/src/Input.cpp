//
// Created by Jonas on 9/28/19.
//

#include <iostream>
#include "Input.h"
#include "cameras/FreeCamera.h"

// initial camera
AbstractCamera *Input::camera = new FreeCamera(glm::vec3(0.0f, 1.0f, 3.0f));

float mLastX = 100.0f;
float mLastY = 100.0f;
bool mFirstMouse = true;

bool cursorIsLocked = false;
bool fixCursorIsPressed = false;

//TODO: Think about a cleaner way to solve Input (without handing variables around)

bool Input::getKeyPressed(GLFWwindow *window, int key) {
  return glfwGetKey(window, key) == GLFW_PRESS;
}

bool Input::getKeyReleased(GLFWwindow *window, int key) {
  return glfwGetKey(window, key) == GLFW_RELEASE;
}

void Input::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, true);

  // TODO: This can probably be solved nicer
  if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS && !fixCursorIsPressed) {
    if (cursorIsLocked) {
      glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
      cursorIsLocked = false;
    } else {
      glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
      cursorIsLocked = true;
    }
    fixCursorIsPressed = true;
  }
  if (glfwGetKey(window, GLFW_KEY_X) == GLFW_RELEASE) {
    fixCursorIsPressed = false;
  }

}

void Input::mouse_callback(GLFWwindow *window, int button, int action, int mods) {

}

void Input::cursor_position_callback(GLFWwindow *window, double xpos, double ypos) {
  if (mFirstMouse) {
    mLastX = (float) xpos;
    mLastY = (float) ypos;
    mFirstMouse = false;
  }

  float xoffset = (float) xpos - mLastX;
  float yoffset = mLastY - (float) ypos; // reversed since y-coordinates go from bottom to top

  mLastX = (float) xpos;
  mLastY = (float) ypos;

  camera->ProcessMouseMovement(xoffset, yoffset);
}

void Input::scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
  camera->ProcessMouseScroll((float) yoffset);
}

void Input::setCamera(AbstractCamera *cam) {
  camera = cam;
}
