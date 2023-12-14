//
// Created by Jonas on 6/30/23.
//

#include <glm/ext/matrix_clip_space.hpp>
#include "Camera.h"

void Camera::setCamera(AbstractCamera *cam) {
  this->camera = cam;
}

void Camera::setShader(Shader *shader) {
  this->shader = shader;
}

void Camera::setIsActive(bool active) {
  this->isActive = active;
}

void Camera::render() {
  shader->setMat4("view", camera->GetViewMatrix());
  shader->setMat4("projection", glm::perspective(glm::radians(camera->zoom), Window::getAspectRatio(), 0.1f, 100.0f));
  shader->setVec3("eyePos", camera->position);
}
