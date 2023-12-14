//
// Created by Jonas on 2/14/20.
//

#ifndef INC_3D_ENGINE_FPSCAMERA_H
#define INC_3D_ENGINE_FPSCAMERA_H

#include <glm/glm.hpp>
#include "../../../lib/src/rendering/actors/AbstractCamera.h"

class FPSCamera : public AbstractCamera {
 public:

  FPSCamera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
            float yaw = YAW,
            float pitch = PITCH);
  FPSCamera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

  glm::mat4 GetViewMatrix() override;

  void Sprint() override;
  void StopSprint() override;
  void ProcessKeyboard(Camera_Movement direction, float deltaTime) override;
  void ProcessKeyboard2(Camera_Movement direction, float deltaTime, glm::vec3 &position) override;
  void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true) override;
  void ProcessMouseScroll(float yoffset) override;

 private:
  void updateCameraVectors();
};

#endif //INC_3D_ENGINE_FPSCAMERA_H
