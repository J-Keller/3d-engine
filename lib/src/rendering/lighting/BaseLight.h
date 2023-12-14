//
// Created by Jonas on 10/12/19.
//

#ifndef INC_3D_ENGINE_BASELIGHT_H
#define INC_3D_ENGINE_BASELIGHT_H

#include <glm/glm.hpp>

class BaseLight {
 public:
  BaseLight() = default;

  glm::vec3 getColor();
  void setColor(glm::vec3 c);
  float getIntensity();
  void setIntensity(float f);

 private:
  glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
  float intensity = 1.0f;
};

#endif //INC_3D_ENGINE_BASELIGHT_H
