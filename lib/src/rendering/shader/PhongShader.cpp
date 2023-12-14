//
// Created by Jonas on 10/17/19.
//

#include "PhongShader.h"

const int MAX_POINT_LIGHTS = 4;

PhongShader::PhongShader(const GLchar *vertexPath, const GLchar *fragmentPath)
    : Shader(vertexPath, fragmentPath) {}

void PhongShader::setLight(glm::vec3 ambientLight, DirectionalLight directionalLight) {
  setVec3("ambientLight", ambientLight);
  setVec3("dLight.base.color", directionalLight.getBaseLight().getColor());
  setFloat("dLight.base.intensity", directionalLight.getBaseLight().getIntensity());
  setVec3("dLight.direction", directionalLight.getDirection());
}

void PhongShader::setPointLights(std::vector<PointLight> pointLights) {

  int pointLightCount = pointLights.size() < MAX_POINT_LIGHTS ? (int) pointLights.size() : MAX_POINT_LIGHTS;

  for (int i = 0; i < pointLightCount; i++) {
    setVec3("pLight[" + std::to_string(i) + "].position", pointLights[i].getPosition());
    setVec3("pLight[" + std::to_string(i) + "].base.color", pointLights[i].getBaseLight().getColor());
    setFloat("pLight[" + std::to_string(i) + "].base.intensity", pointLights[i].getBaseLight().getIntensity());
    setFloat("pLight[" + std::to_string(i) + "].range", pointLights[i].getRange());
    setFloat("pLight[" + std::to_string(i) + "].constant", pointLights[i].getConstant());
    setFloat("pLight[" + std::to_string(i) + "].linear", pointLights[i].getLinear());
    setFloat("pLight[" + std::to_string(i) + "].quadratic", pointLights[i].getQuadratic());
  }

}

void PhongShader::setSpotLight(SpotLight spotLight) {
  setVec3("sLight.pLight.position", spotLight.getPointLight().getPosition());
  setVec3("sLight.pLight.base.color", spotLight.getPointLight().getBaseLight().getColor());
  setFloat("sLight.pLight.base.intensity", spotLight.getPointLight().getBaseLight().getIntensity());
  setFloat("sLight.pLight.range", spotLight.getPointLight().getRange());
  setFloat("sLight.pLight.constant", spotLight.getPointLight().getConstant());
  setFloat("sLight.pLight.linear", spotLight.getPointLight().getLinear());
  setFloat("sLight.pLight.quadratic", spotLight.getPointLight().getQuadratic());

  setVec3("sLight.direction", spotLight.getDirection());
  setFloat("sLight.cutOff", spotLight.getCutOff());
}

void PhongShader::setMaterial(Material material) {
  setVec3("baseColor", material.getColor());
  setFloat("specularIntensity", material.getSpecularIntensity());
  setFloat("specularPower", material.getSpecularPower());
}