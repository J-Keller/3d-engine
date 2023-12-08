//
// Created by Jonas on 5/29/23.
//

#ifndef INC_3D_ENGINE_SCENENODE_H
#define INC_3D_ENGINE_SCENENODE_H

#include <vector>
#include "Entity.h"

class SceneNode {
 public:
  explicit SceneNode(Entity *entity);
  void addEntity(Entity *entityToAdd);
  Entity *getEntity();
  std::vector<SceneNode *> getChildren();
  ~SceneNode() {
    for (auto child : children) {
      delete child;
    }
  }
 private:
  Entity *entity;
  std::vector<SceneNode *> children;
};

#endif //INC_3D_ENGINE_SCENENODE_H
