//
// Created by Jonas on 6/29/23.
//

#ifndef INC_3D_ENGINE_LIGHT_H
#define INC_3D_ENGINE_LIGHT_H

#include <glm/vec3.hpp>
#include "../scene/Entity.h"
#include "../lighting/DirectionalLight.h"
#include "../shader/Shader.h"
class Light : public Entity {
 public:

  void setShader(Shader *shader);
  void setAmbientLight(glm::vec3 ambient);
  void setDirectionalLight(DirectionalLight directional);

  void render() override;
 private:
  // TODO: Make abstract Light and allow more different types of lighting to be rendered from scene tree
  glm::vec3 ambientLight{};
  DirectionalLight light{};
  Shader *shader;
};

#endif //INC_3D_ENGINE_LIGHT_H
