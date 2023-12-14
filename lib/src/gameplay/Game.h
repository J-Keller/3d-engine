//
// Created by Jonas on 12/14/23.
//

#ifndef INC_3D_ENGINE_LIB_SRC_GAMEPLAY_GAME_H_
#define INC_3D_ENGINE_LIB_SRC_GAMEPLAY_GAME_H_

class Game {
 public:
  virtual int init() = 0;
  virtual void input() = 0;
  virtual void update() = 0;
  virtual void render() = 0;
  virtual void dispose() = 0;
};

#endif //INC_3D_ENGINE_LIB_SRC_GAMEPLAY_GAME_H_
