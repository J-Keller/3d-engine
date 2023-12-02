//
// Created by Jonas on 11/25/23.
//

#ifndef INC_3D_ENGINE_POINTCOLLIDER_H
#define INC_3D_ENGINE_POINTCOLLIDER_H

#include <glm/vec3.hpp>

class PointCollider {
 public:
  float x, y, z;

  PointCollider(float x, float y, float z);
  PointCollider(glm::vec3 pos);
};

#endif //INC_3D_ENGINE_POINTCOLLIDER_H
