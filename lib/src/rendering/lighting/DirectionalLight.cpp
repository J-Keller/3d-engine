//
// Created by Jonas on 10/12/19.
//

#include "DirectionalLight.h"

BaseLight DirectionalLight::getBaseLight() {
  return base;
}

void DirectionalLight::setBaseLight(BaseLight b) {
  base = b;
}

glm::vec3 DirectionalLight::getDirection() {
  return direction;
}

void DirectionalLight::setDirection(glm::vec3 d) {
  direction = d;
}