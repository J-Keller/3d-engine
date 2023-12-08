//
// Created by Jonas on 11/1/21.
//

#include "Entity.h"

#include <utility>

Entity::Entity() {
  this->name = "unnamed-entity";
  this->id = reinterpret_cast<uint64_t>(this);
}

Entity::Entity(std::string name) {
  this->name = std::move(name);
  this->id = reinterpret_cast<uint64_t>(this);
}

void Entity::render() {
#ifdef DEBUG
  // std::cout << this->name << "_" <<this->id << std::endl;
#endif
}

uint64_t Entity::getId() const {
  return this->id;
}

std::string Entity::getName() const {
  return this->name;
}




