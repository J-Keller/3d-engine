//
// Created by Jonas on 11/25/23.
//

#include "SphereCollider.h"

SphereCollider::SphereCollider(float x, float y, float z, float r) {
  this->x = x;
  this->y = y;
  this->z = z;
  this->r = r;
}

SphereCollider::SphereCollider(glm::vec3 pos, float r) {
  this->x = pos.x;
  this->y = pos.y;
  this->z = pos.z;
  this->r = r;
}
