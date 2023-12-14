//
// Created by Jonas on 12/31/19.
//

#include <utility>
#include "PointLight.h"

glm::vec3 PointLight::getPosition() {
  return this->position;
}

void PointLight::setPosition(glm::vec3 position) {
  this->position = position;
}

BaseLight PointLight::getBaseLight() {
  return this->base;
}

void PointLight::setBaseLight(BaseLight base) {
  this->base = base;
}

float PointLight::getRange() {
  return this->range;
}

void PointLight::setRange(float range) {
  this->range = range;
}

float PointLight::getConstant() {
  return this->constant;
}

void PointLight::setConstant(float constant) {
  this->constant = constant;
}

float PointLight::getLinear() {
  return this->linear;
}

void PointLight::setLinear(float linear) {
  this->linear = linear;
}

float PointLight::getQuadratic() {
  return this->quadratic;
}

void PointLight::setQuadratic(float quadratic) {
  this->quadratic = quadratic;
}
