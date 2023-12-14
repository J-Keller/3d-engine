//
// Created by Jonas on 5/29/23.
//

#include <stack>
#include <fstream>
#include "Scene.h"

void Scene::render() {
  Scene::renderSceneTree(this->root);
}

void Scene::addEntity(const Entity *parent, Entity *entity) {
  auto parentNode = Scene::findSceneNode(this->root, parent->getId());
  parentNode->addEntity(entity);
}

void Scene::addEntityToRoot(Entity *entity) {
  this->root->addEntity(entity);
}

void Scene::removeEntity(const Entity *entity) {
  auto entityNode = Scene::findSceneNode(this->root, entity->getId());
  delete entityNode;
}

void Scene::renderSceneTree(SceneNode *node) {
  std::stack<SceneNode *> stack;
  stack.push(node);
  while (!stack.empty()) {
    auto v = stack.top();
    stack.pop();

    v->getEntity()->render();

    for (const auto &vNode : v->getChildren()) {
      stack.push(vNode);
    }
  }
}

SceneNode *Scene::findSceneNode(SceneNode *node, uint64_t id) {
  std::stack<SceneNode *> stack;
  stack.push(node);
  while (!stack.empty()) {
    auto v = stack.top();
    stack.pop();

    if (v->getEntity()->getId() == id) {
      return v;
    }
    for (const auto &vNode : v->getChildren()) {
      stack.push(vNode);
    }
  }
  return nullptr;
}

#ifdef DEBUG
void Scene::generateGraphvizOutput() {
  std::string output;
  std::string nodeId;
  std::stack<SceneNode *> stack;
  stack.push(this->root);
  while (!stack.empty()) {
    auto v = stack.top();
    stack.pop();

    nodeId = v->getEntity()->getName();

    for (const auto &vNode : v->getChildren()) {
      output.append(nodeId + " -> " + vNode->getEntity()->getName() + "\n");
      stack.push(vNode);
    }
  }

  std::ofstream outputFile("debug_output/scene_tree.gv");
  outputFile << "// https://dreampuf.github.io/GraphvizOnline graphviz online viewer\n";
  outputFile << "digraph {\n" << output << "}\n";
  outputFile.close();
}
#endif
