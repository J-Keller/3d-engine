//
// Created by Jonas on 11/25/23.
//

#ifndef MCCLONE_SPHERECOLLIDER_H
#define MCCLONE_SPHERECOLLIDER_H

#include <glm/vec3.hpp>

class SphereCollider {
 public:
  float x, y, z;
  float r;

  SphereCollider(float x, float y, float z, float r);
  SphereCollider(glm::vec3 pos, float r);
};

#endif //MCCLONE_SPHERECOLLIDER_H
