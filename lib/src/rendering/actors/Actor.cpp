//
// Created by Jonas on 6/29/23.
//

#include <glm/ext/matrix_transform.hpp>
#include "Actor.h"

void Actor::setMesh(Mesh m) {
  // TODO: expect mesh to be already initialized / add initialized state to mesh class
  this->mesh = std::move(m);
}

void Actor::setShader(Shader *shader) {
  this->shader = shader;
}

void Actor::rotate(float angle, glm::vec3 direction) {
  this->mesh.model = glm::rotate(this->mesh.model, glm::degrees(angle), direction);
}

void Actor::translate(float amount, glm::vec3 direction) {
  this->mesh.model = glm::translate(this->mesh.model, direction * amount);
}

void Actor::scale(float amount, glm::vec3 direction) {
  this->mesh.model = glm::scale(this->mesh.model, direction * amount);
}

void Actor::render() {
  shader->setMat4("model", this->mesh.model);

  // TODO: phongShader stuff
  shader->setVec3("baseColor", this->mesh.getMaterial().getColor());
  shader->setFloat("specularIntensity", this->mesh.getMaterial().getSpecularIntensity());
  shader->setFloat("specularPower", this->mesh.getMaterial().getSpecularPower());

  this->mesh.draw();
}