//
// Created by Jonas on 11/25/23.
//

#ifndef INC_3D_ENGINE_BOXCOLLIDER_H
#define INC_3D_ENGINE_BOXCOLLIDER_H

#include <glm/vec3.hpp>

class BoxCollider {
 public:
  float minX, maxX;
  float minY, maxY;
  float minZ, maxZ;

  BoxCollider(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
  BoxCollider(glm::vec3 min, glm::vec3 max);
};

#endif //INC_3D_ENGINE_BOXCOLLIDER_H
