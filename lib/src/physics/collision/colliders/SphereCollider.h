//
// Created by Jonas on 11/25/23.
//

#ifndef INC_3D_ENGINE_SPHERECOLLIDER_H
#define INC_3D_ENGINE_SPHERECOLLIDER_H

#include <glm/vec3.hpp>

class SphereCollider {
 public:
  float x, y, z;
  float r;

  SphereCollider(float x, float y, float z, float r);
  SphereCollider(glm::vec3 pos, float r);
};

#endif //INC_3D_ENGINE_SPHERECOLLIDER_H
