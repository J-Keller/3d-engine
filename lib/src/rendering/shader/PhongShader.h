//
// Created by Jonas on 10/17/19.
//

#ifndef INC_3D_ENGINE_PHONGSHADER_H
#define INC_3D_ENGINE_PHONGSHADER_H

#include <vector>
#include "Shader.h"
#include "../surface/Material.h"
#include "../lighting/DirectionalLight.h"
#include "../lighting/PointLight.h"
#include "../lighting/SpotLight.h"

class PhongShader : public Shader {
 public:
  PhongShader() = default;
  PhongShader(const GLchar *vertexPath, const GLchar *fragmentPath);

  void setLight(glm::vec3 ambientLight, DirectionalLight directionalLight);
  void setPointLights(std::vector<PointLight> pointLights);
  void setSpotLight(SpotLight spotLight);
  void setMaterial(Material material);
 private:
};

#endif //INC_3D_ENGINE_PHONGSHADER_H
