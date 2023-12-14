//
// Created by Jonas on 1/4/20.
//

#include "SpotLight.h"

PointLight &SpotLight::getPointLight() {
  return this->pointLight;
}

void SpotLight::setPointLight(PointLight pointLight) {
  this->pointLight = pointLight;
}

glm::vec3 SpotLight::getDirection() {
  return this->direction;
}

void SpotLight::setDirection(glm::vec3 direction) {
  this->direction = direction;
}

float SpotLight::getCutOff() {
  return this->cutOff;
}

void SpotLight::setCutOff(float cutOff) {
  this->cutOff = cutOff;
}
