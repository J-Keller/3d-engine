//
// Created by Jonas on 1/4/20.
//

#ifndef INC_3D_ENGINE_SPOTLIGHT_H
#define INC_3D_ENGINE_SPOTLIGHT_H

#include <glm/vec3.hpp>
#include "BaseLight.h"
#include "PointLight.h"

class SpotLight {
 public:

  SpotLight() = default;

  PointLight &getPointLight();
  void setPointLight(PointLight pointLight);
  glm::vec3 getDirection();
  void setDirection(glm::vec3 direction);
  float getCutOff();
  void setCutOff(float cutOff);

 private:

  PointLight pointLight;

  glm::vec3 direction = glm::vec3(0, 0, 1);
  float cutOff = glm::cos(glm::radians(12.5f));

};

#endif //INC_3D_ENGINE_SPOTLIGHT_H
