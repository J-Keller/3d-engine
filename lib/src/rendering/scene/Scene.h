//
// Created by Jonas on 5/29/23.
//

#ifndef INC_3D_ENGINE_SCENE_H
#define INC_3D_ENGINE_SCENE_H

#include "SceneNode.h"

class Scene {
 public:
  void render(); // renders the whole scene tree hierarchically
  void addEntity(const Entity *parent, Entity *entity);
  void addEntityToRoot(Entity *entity);
  void removeEntity(const Entity *entity);

#ifdef DEBUG
  void generateGraphvizOutput();
#endif

  ~Scene() {
    delete root;
  }
 private:
  void renderSceneTree(SceneNode *node);
  static SceneNode *findSceneNode(SceneNode *node, uint64_t id);
  // Scene is always the root and has n SceneNodes as children
  SceneNode *root = new SceneNode(new Entity("root"));
};

#endif //INC_3D_ENGINE_SCENE_H
