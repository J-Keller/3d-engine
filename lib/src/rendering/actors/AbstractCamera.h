//
// Created by Jonas on 2/14/20.
//

#ifndef INC_3D_ENGINE_ABSTRACTCAMERA_H
#define INC_3D_ENGINE_ABSTRACTCAMERA_H

#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <glm/detail/type_mat4x4.hpp>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
};

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 20.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

class AbstractCamera {
 public:
  // Camera Attributes
  glm::vec3 position;
  glm::vec3 front;
  glm::vec3 up;
  glm::vec3 right;
  glm::vec3 worldUp;
  // Euler Angles
  float yaw;
  float pitch;
  // Camera options
  float movementSpeed;
  float mouseSensitivity;
  float zoom;

  virtual glm::mat4 GetViewMatrix() = 0;

  virtual void Sprint() = 0;
  virtual void StopSprint() = 0;
  virtual void ProcessKeyboard(Camera_Movement direction, float deltaTime) = 0;
  virtual void ProcessKeyboard2(Camera_Movement direction, float deltaTime, glm::vec3 &position) = 0;
  virtual void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true) = 0;
  virtual void ProcessMouseScroll(float yoffset) = 0;
};

#endif //INC_3D_ENGINE_ABSTRACTCAMERA_H
