//
// Created by Jonas on 10/3/19.
//

#ifndef INC_3D_ENGINE_MAINCOMPONENT_H
#define INC_3D_ENGINE_MAINCOMPONENT_H

#include <string>
#include "Game.h"
#include "../rendering/Window.h"

class MainLoop {
 public:

  constexpr static const double FRAME_CAP = 5000.0;

  MainLoop(Game *game, int width, int height, const std::string &title);
  void registerInputCallbacks(GLFWkeyfun keyCallback,
                                     GLFWmousebuttonfun mouseCallback,
                                     GLFWcursorposfun cursorPositionCallback,
                                     GLFWscrollfun scrollCallback);

  void start();
  void stop();

 private:
  Game *game;
  bool isRunning;

  void run();
  void render();
  void cleanUp();

};

#endif //INC_3D_ENGINE_MAINCOMPONENT_H
