//
// Created by Jonas on 12/2/23.
//

#include "../../lib/src/gameplay/MainLoop.h"
#include "Wolfenstein3DClone.h"
#include "Input.h"

extern "C" {
#include "../../lib/src/audio/audio.h"
}

int main() {
  playSound();

  Game *game = new Wolfenstein3DClone();
  MainLoop main_loop(game, 2400, 1600, "Engine");
  main_loop.registerInputCallbacks(Input::key_callback, Input::mouse_callback, Input::cursor_position_callback, Input::scroll_callback);
  main_loop.start();
  return 0;
}