//
// Created by Jonas on 11/25/23.
//

#include "PointCollider.h"

PointCollider::PointCollider(float x, float y, float z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

PointCollider::PointCollider(glm::vec3 pos) {
  this->x = pos.x;
  this->y = pos.y;
  this->z = pos.z;
}
