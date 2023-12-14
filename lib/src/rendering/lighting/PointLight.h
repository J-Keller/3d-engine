//
// Created by Jonas on 12/31/19.
//

#ifndef INC_3D_ENGINE_POINTLIGHT_H
#define INC_3D_ENGINE_POINTLIGHT_H

#include "BaseLight.h"

class PointLight {
 public:
  PointLight() = default;

  glm::vec3 getPosition();
  void setPosition(glm::vec3 position);
  BaseLight getBaseLight();
  void setBaseLight(BaseLight base);
  float getRange();
  void setRange(float range);
  float getConstant();
  void setConstant(float constant);
  float getLinear();
  void setLinear(float linear);
  float getQuadratic();
  void setQuadratic(float quadratic);

 private:
  glm::vec3 position = glm::vec3(1.0f, 1.0f, 1.0f);

  BaseLight base;

  float range = 20;

  //Attenuation
  float constant = 1.0f;
  float linear = 0.09f;
  float quadratic = 0.032f;
};

#endif //INC_3D_ENGINE_POINTLIGHT_H
