//
// Created by Jonas on 11/25/23.
//

#include "BoxCollider.h"

BoxCollider::BoxCollider(float minX, float maxX, float minY, float maxY, float minZ, float maxZ) {
  this->minX = minX;
  this->maxX = maxX;
  this->minY = minY;
  this->maxY = maxY;
  this->minZ = minZ;
  this->maxZ = maxZ;
}

BoxCollider::BoxCollider(glm::vec3 min, glm::vec3 max) {
  this->minX = min.x;
  this->maxX = max.x;
  this->minY = min.y;
  this->maxY = max.y;
  this->minZ = min.z;
  this->maxZ = max.z;
}
