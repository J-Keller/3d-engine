//
// Created by Jonas on 6/29/23.
//

#ifndef INC_3D_ENGINE_ACTOR_H
#define INC_3D_ENGINE_ACTOR_H

#include "../Mesh.h"
#include "../scene/Entity.h"
#include "../shader/Shader.h"

class Actor : public Entity {
 public:
  void setShader(Shader *shader);
  void setMesh(Mesh mesh);
  void rotate(float angle, glm::vec3 direction);
  void translate(float amount, glm::vec3 direction);
  void scale(float amount, glm::vec3 direction);
  void render() override;
 private:
  Mesh mesh;
  Shader *shader;
};

#endif //INC_3D_ENGINE_ACTOR_H
