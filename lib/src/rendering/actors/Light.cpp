//
// Created by Jonas on 6/29/23.
//

#include "Light.h"


void Light::setShader(Shader *shader) {
  this->shader = shader;
}

void Light::setAmbientLight(glm::vec3 ambient) {
    this->ambientLight = ambient;
}

void Light::setDirectionalLight(DirectionalLight directional) {
    this->light = directional;
}

void Light::render() {
    // TODO: PhongShader::setLight -> fix lighting abstraction for scene tree rendering
    shader->setVec3("ambientLight", this->ambientLight);
    shader->setVec3("dLight.base.color", this->light.getBaseLight().getColor());
    shader->setFloat("dLight.base.intensity", this->light.getBaseLight().getIntensity());
    shader->setVec3("dLight.direction", this->light.getDirection());
}
