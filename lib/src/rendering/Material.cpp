//
// Created by Jonas on 10/6/19.
//

#include "Material.h"

Material::Material(glm::vec3 c) {
  this->color = c;
}

Material::Material(Texture t, glm::vec3 c) {
  this->color = c;
  this->texture = t;
}

glm::vec3 Material::getColor() {
  return color;
}

void Material::setColor(glm::vec3 c) {
  this->color = c;
}

void Material::setTexture(Texture t) {
  this->texture = t;
}

Texture Material::getTexture() {
  return texture;
}

float Material::getSpecularIntensity() {
  return specularIntensity;
}

void Material::setSpecularIntensity(float s) {
  this->specularIntensity = s;
}

float Material::getSpecularPower() {
  return specularPower;
}

void Material::setSpecularPower(float s) {
  this->specularPower = s;
}
