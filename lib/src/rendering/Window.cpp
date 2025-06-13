//
// Created by Jonas on 10/2/19.
//

#include "Window.h"

#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int w, int h);

GLFWwindow *Window::window;
int Window::width;
int Window::height;

void Window::createWindow(int w, int h, const std::string &title) {
  Window::width = w;
  Window::height = h;

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

  if (window == nullptr) {
    std::cerr << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    exit(-1);
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    glfwTerminate();
    exit(-1);
  }

  glViewport(0, 0, width, height);

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  initGraphics();

}

void Window::registerInputCallbacks(GLFWkeyfun keyCallback,
                                    GLFWmousebuttonfun mouseCallback,
                                    GLFWcursorposfun cursorPositionCallback,
                                    GLFWscrollfun scrollCallback) {
  glfwSetKeyCallback(window, keyCallback);
  glfwSetMouseButtonCallback(window, mouseCallback);
  glfwSetCursorPosCallback(window, cursorPositionCallback);
  glfwSetScrollCallback(window, scrollCallback);
}

void Window::clear() {
  //TODO: Stencil Buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::initGraphics() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  glFrontFace(GL_CW);
  glCullFace(GL_FRONT);
  glEnable(GL_CULL_FACE);
  glEnable(GL_DEPTH_TEST);

  glEnable(GL_DEPTH_CLAMP);

  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

}

void Window::render() {
  glfwSwapBuffers(window);
  glfwPollEvents();
}

void Window::dispose() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

bool Window::isCloseRequested() {
  return glfwWindowShouldClose(window);
}

float Window::getAspectRatio() {
  return (float) width / (float) height;
}

// Callback Methods
void framebuffer_size_callback(GLFWwindow *window, int w, int h) {
  Window::width = w;
  Window::height = h;
  glViewport(0, 0, w, h);
}
