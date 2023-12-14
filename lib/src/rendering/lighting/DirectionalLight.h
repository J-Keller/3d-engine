//
// Created by Jonas on 10/12/19.
//

#ifndef INC_3D_ENGINE_DIRECTIONALLIGHT_H
#define INC_3D_ENGINE_DIRECTIONALLIGHT_H

#include "BaseLight.h"

class DirectionalLight {
 public:
  DirectionalLight() = default;

  BaseLight getBaseLight();
  void setBaseLight(BaseLight b);
  glm::vec3 getDirection();
  void setDirection(glm::vec3 d);

 private:
  BaseLight base;
  glm::vec3 direction = glm::vec3(1.0f, 1.0f, 1.0f);
};

#endif //INC_3D_ENGINE_DIRECTIONALLIGHT_H
