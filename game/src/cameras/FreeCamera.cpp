//
// Created by Jonas on 13/7/18.
//

#include "FreeCamera.h"

FreeCamera::FreeCamera(glm::vec3 position, glm::vec3 up, float yaw, float pitch) {

  front = glm::vec3(0.0f, 0.0f, -1.0f);
  movementSpeed = SPEED;
  mouseSensitivity = SENSITIVITY;
  zoom = ZOOM;

  this->position = position;
  this->worldUp = up;
  this->yaw = yaw;
  this->pitch = pitch;
  updateCameraVectors();
}

FreeCamera::FreeCamera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) {

  front = glm::vec3(0.0f, 0.0f, -1.0f);
  movementSpeed = SPEED;
  mouseSensitivity = SENSITIVITY;
  zoom = ZOOM;

  this->position = glm::vec3(posX, posY, posZ);
  this->worldUp = glm::vec3(upX, upY, upZ);
  this->yaw = yaw;
  this->pitch = pitch;
  updateCameraVectors();
}

// Returns the view matrix calculated using Euler Angles and the LookAt Matrix
glm::mat4 FreeCamera::GetViewMatrix() {
  return glm::lookAt(position, position + front, up);
}

// Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
void FreeCamera::ProcessKeyboard(Camera_Movement direction, float deltaTime) {
  float velocity = movementSpeed * deltaTime;
  if (direction == FORWARD)
    position += front * velocity;
  if (direction == BACKWARD)
    position -= front * velocity;
  if (direction == LEFT)
    position -= right * velocity;
  if (direction == RIGHT)
    position += right * velocity;
}

void FreeCamera::ProcessKeyboard2(Camera_Movement direction, float deltaTime, glm::vec3 &position) {
  float velocity = movementSpeed * deltaTime;
  if (direction == FORWARD)
    position += front * velocity;
  if (direction == BACKWARD)
    position -= front * velocity;
  if (direction == LEFT)
    position -= right * velocity;
  if (direction == RIGHT)
    position += right * velocity;
}

// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void FreeCamera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch) {
  xoffset *= mouseSensitivity;
  yoffset *= mouseSensitivity;

  yaw += xoffset;
  pitch += yoffset;

  // Make sure that when pitch is out of bounds, screen doesn't get flipped
  if (constrainPitch) {
    if (pitch > 89.0f)
      pitch = 89.0f;
    if (pitch < -89.0f)
      pitch = -89.0f;
  }

  // Update Front, Right and up Vectors using the updated Euler angles
  updateCameraVectors();
}

// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void FreeCamera::ProcessMouseScroll(float yoffset) {
  if (zoom >= 1.0f && zoom <= 45.0f)
    zoom -= yoffset;
  if (zoom <= 1.0f)
    zoom = 1.0f;
  if (zoom >= 45.0f)
    zoom = 45.0f;
}

void FreeCamera::updateCameraVectors() {
  glm::vec3 locFront;
  locFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
  locFront.y = sin(glm::radians(pitch));
  locFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
  front = glm::normalize(locFront);
  // Also re-calculate the Right and Up vector
  right = glm::normalize(glm::cross(front,
                                    worldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
  up = glm::normalize(glm::cross(right, front));
}

void FreeCamera::Sprint() {
  this->movementSpeed = SPEED * 10;
}

void FreeCamera::StopSprint() {
  this->movementSpeed = SPEED;
}
