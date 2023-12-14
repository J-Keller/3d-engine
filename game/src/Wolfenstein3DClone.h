//
// Created by Jonas on 6/26/23.
//

#ifndef INC_3D_ENGINE_GAME_H
#define INC_3D_ENGINE_GAME_H

#include "../../lib/src/rendering/shader/PhongShader.h"
#include "../../lib/src/rendering/scene/Scene.h"
#include "../../lib/src/gameplay/Game.h"

class Wolfenstein3DClone : public Game {
 public:
  int init() override;
  void input() override;
  void update() override;
  void render() override;
  void dispose() override;

 private:
  PhongShader shader;
  Scene scene;
};

#endif //INC_3D_ENGINE_GAME_H
