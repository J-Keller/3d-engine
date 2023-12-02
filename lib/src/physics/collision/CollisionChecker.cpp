//
// Created by Jonas on 11/25/23.
//

#include <algorithm>
#include "CollisionChecker.h"

bool CollisionChecker::collide(BoxCollider a, BoxCollider b) {
  return a.minX <= b.maxX &&
         a.maxX >= b.minX &&
         a.minY <= b.maxY &&
         a.maxY >= b.minY &&
         a.minZ <= b.maxZ &&
         a.maxZ >= b.minZ;
}

bool CollisionChecker::collide(BoxCollider a, PointCollider b) {
  return b.x >= a.minX &&
         b.x <= a.maxX &&
         b.y >= a.minY &&
         b.y <= a.maxY &&
         b.z >= a.minZ &&
         b.z <= a.maxZ;
}

bool CollisionChecker::collide(BoxCollider a, SphereCollider b) {
  // get box closest point to sphere center by clamping
  float x = std::max(a.minX, std::min(b.x, a.maxX));
  float y = std::max(a.minY, std::min(b.y, a.maxY));
  float z = std::max(a.minZ, std::min(b.z, a.maxZ));

  float squareDistance = (x - b.x) * (x - b.x) +
                         (y - b.y) * (y - b.y) +
                         (z - b.z) * (z - b.z);

  return squareDistance < (b.r * b.r);
}

bool CollisionChecker::collide(PointCollider a, PointCollider b) {
  return a.x == b.x &&
         a.y == b.y &&
         a.z == b.z;
}

bool CollisionChecker::collide(PointCollider a, SphereCollider b) {
  float squareDistance = (a.x - b.x) * (a.x - b.x) +
                         (a.y - b.y) * (a.y - b.y) +
                         (a.z - b.z) * (a.z - b.z);

  return squareDistance < (b.r * b.r);
}

bool CollisionChecker::collide(SphereCollider a, SphereCollider b) {
  float squareDistance = (a.x - b.x) * (a.x - b.x) +
                         (a.y - b.y) * (a.y - b.y) +
                         (a.z - b.z) * (a.z - b.z);

  return squareDistance < ((a.r + b.r) * (a.r + b.r));
}
