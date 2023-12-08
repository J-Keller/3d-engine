//
// Created by Jonas on 5/29/23.
//

#include "SceneNode.h"

SceneNode::SceneNode(Entity *entity) {
  this->entity = entity;
}

Entity *SceneNode::getEntity() {
  return this->entity;
}

std::vector<SceneNode *> SceneNode::getChildren() {
  return this->children;
}

void SceneNode::addEntity(Entity *entityToAdd) {
  this->children.emplace_back(new SceneNode(entityToAdd));
}
