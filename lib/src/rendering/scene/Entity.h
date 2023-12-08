//
// Created by Jonas on 11/1/21.
//

#ifndef INC_3D_ENGINE_ENTITY_H
#define INC_3D_ENGINE_ENTITY_H

#include <cstdint>
#include <string>

class Entity {
 public:
  Entity();
  explicit Entity(std::string name);
  uint64_t getId() const;
  std::string getName() const;

  virtual void render();
 private:
  uint64_t id;
  std::string name;

};

#endif //INC_3D_ENGINE_ENTITY_H
