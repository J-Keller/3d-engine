//
// Created by Jonas on 10/6/19.
//

#ifndef INC_3D_ENGINE_MATERIAL_H
#define INC_3D_ENGINE_MATERIAL_H


//#include "Texture.h"
#include <glm/glm.hpp>
#include "Texture.h"

class Material {

 public:
  Material() = default;
  explicit Material(glm::vec3 c);
  Material(Texture t, glm::vec3 c);

  Texture getTexture();
  void setTexture(Texture t);
  glm::vec3 getColor();
  void setColor(glm::vec3 c);
  float getSpecularIntensity();
  void setSpecularIntensity(float s);
  float getSpecularPower();
  void setSpecularPower(float s);

 private:
  Texture texture;
  glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);

  float specularIntensity = 2;
  float specularPower = 32;

};

#endif //INC_3D_ENGINE_MATERIAL_H
