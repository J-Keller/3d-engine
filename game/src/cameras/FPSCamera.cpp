//
// Created by Jonas on 2/14/20.
//

#include <glm/gtc/matrix_transform.hpp>
#include "FPSCamera.h"

FPSCamera::FPSCamera(glm::vec3 position, glm::vec3 up, float yaw, float pitch) {
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

FPSCamera::FPSCamera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) {
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
glm::mat4 FPSCamera::GetViewMatrix() {
  return glm::lookAt(position, position + front, up);
}

// Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
void FPSCamera::ProcessKeyboard(Camera_Movement direction, float deltaTime) {
  float velocity = movementSpeed * deltaTime;

  if (direction == FORWARD)
    position += glm::vec3(front.x, 0.0f, front.z) * velocity;
  if (direction == BACKWARD)
    position -= glm::vec3(front.x, 0.0f, front.z) * velocity;
  if (direction == LEFT)
    position -= glm::vec3(right.x, 0.0f, right.z) * velocity;
  if (direction == RIGHT)
    position += glm::vec3(right.x, 0.0f, right.z) * velocity;

}

void FPSCamera::ProcessKeyboard2(Camera_Movement direction, float deltaTime, glm::vec3 &pos) {
  float velocity = movementSpeed * deltaTime;

  if (direction == FORWARD)
    pos += glm::vec3(front.x, 0.0f, front.z) * velocity;
  if (direction == BACKWARD)
    pos -= glm::vec3(front.x, 0.0f, front.z) * velocity;
  if (direction == LEFT)
    pos -= glm::vec3(right.x, 0.0f, right.z) * velocity;
  if (direction == RIGHT)
    pos += glm::vec3(right.x, 0.0f, right.z) * velocity;
}

// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void FPSCamera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch) {
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
void FPSCamera::ProcessMouseScroll(float yoffset) {
  if (zoom >= 1.0f && zoom <= 45.0f)
    zoom -= yoffset;
  if (zoom <= 1.0f)
    zoom = 1.0f;
  if (zoom >= 45.0f)
    zoom = 45.0f;
}

void FPSCamera::updateCameraVectors() {
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

void FPSCamera::Sprint() {
  this->movementSpeed = SPEED * 10;
}

void FPSCamera::StopSprint() {
  this->movementSpeed = SPEED;
}
