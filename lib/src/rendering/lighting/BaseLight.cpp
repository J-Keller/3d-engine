//
// Created by Jonas on 10/12/19.
//

#include "BaseLight.h"

glm::vec3 BaseLight::getColor() {
  return color;
}

void BaseLight::setColor(glm::vec3 c) {
  color = c;
}

float BaseLight::getIntensity() {
  return intensity;
}

void BaseLight::setIntensity(float f) {
  intensity = f;
}