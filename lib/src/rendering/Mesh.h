//
// Created by Jonas on 10/10/19.
//

#ifndef INC_3D_ENGINE_MESH_H
#define INC_3D_ENGINE_MESH_H

#include <vector>
#include "shader/Shader.h"
#include "surface/Material.h"

class Mesh {
 public:
  glm::mat4 model;

  Mesh();

  void addVertices(const std::vector<float> &v);
  void init();
  void draw();

  Material getMaterial();
  void setMaterial(Material m);
 private:
  Material material;
  unsigned int textureId;

  std::vector<float> vertices;

  unsigned int vao;
  unsigned int vbo;
  unsigned int ebo;

  void applyTexture();
};

#endif //INC_3D_ENGINE_MESH_H
