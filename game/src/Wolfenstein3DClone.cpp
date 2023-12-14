//
// Created by Jonas on 7/1/23.
//

#include "Wolfenstein3DClone.h"
#include "Input.h"
#include "../../lib/src/physics/collision/colliders/BoxCollider.h"
#include "../../lib/src/physics/collision/CollisionChecker.h"
#include "generators/DungeonGenerator.h"
#include "cameras/FreeCamera.h"
#include "cameras/FPSCamera.h"
#include "../../lib/src/rendering/actors/Light.h"
#include "../../lib/src/rendering/actors/Camera.h"
#include "../../lib/src/rendering/actors/Actor.h"
#include "../../lib/src/util/Time.h"

BoxCollider playerCollider(0, 0, 0, 0, 0, 0);
std::vector<BoxCollider> worldColliders;
CollisionChecker collisionChecker;
AbstractCamera *fpsCam;

glm::vec3 playerUpdatedPosition;

int Wolfenstein3DClone::init() {

  AbstractCamera *camera = new FreeCamera(glm::vec3(10.0f, 10.0f, 30.0f));

  DungeonGenerator dg(79, 24);
  glm::vec3 spawn = dg.generate(50);

  playerCollider = BoxCollider(glm::vec3(spawn.x - 0.1, spawn.y - 0.1, spawn.z - 0.1),
                               glm::vec3(spawn.x + 0.1, spawn.y + 0.1, spawn.z + 0.1));
  std::cout << "min: " << playerCollider.minX << " " << playerCollider.minY << " " << playerCollider.minZ << " "
            << "max: " << playerCollider.maxX << " " << playerCollider.maxY << " " << playerCollider.maxZ << " "
            << std::endl;

  fpsCam = new FPSCamera(spawn);
  Input::setCamera(fpsCam);

  auto dungeon = dg.generateMesh(50);
  worldColliders = dungeon.second;
  for (auto c : worldColliders) {
    std::cout << "min: " << c.minX << " " << c.minY << " " << c.minZ << " "
              << "max: " << c.maxX << " " << c.maxY << " " << c.maxZ << " " << std::endl;
  }

  auto ambientLight = glm::vec3(0.4f, 0.4f, 0.4f);
  shader =
      PhongShader("../lib/assets/shaders/phongVertex.glsl", "../lib/assets/shaders/phongFragment.glsl");

  Texture t0 = Texture("./assets/textures/prototype-textures/PNG/Purple/texture_04.png");
  Texture t1 = Texture("./assets/textures/prototype-textures/PNG/Dark/texture_13.png");

  dungeon.first[0].setMaterial(Material(t0, glm::vec3(.5f, .5f, .5f)));
  dungeon.first[1].setMaterial(Material(t1, glm::vec3(1.0f, 1.0f, 1.0f)));

  dungeon.first[0].init();
  dungeon.first[1].init();

  auto *dungeonFloor = new Actor();
  dungeonFloor->setMesh(dungeon.first[0]);
  dungeonFloor->setShader(&shader);
  auto *dungeonWalls = new Actor();
  dungeonWalls->setMesh(dungeon.first[1]);
  dungeonWalls->setShader(&shader);

  auto *playerCam = new Camera();
  playerCam->setCamera(fpsCam);
  playerCam->setIsActive(true);
  playerCam->setShader(&shader);

  auto *light = new Light();
  light->setAmbientLight(ambientLight);
  light->setDirectionalLight(DirectionalLight());
  light->setShader(&shader);

  scene.addEntityToRoot(dungeonFloor);
  scene.addEntityToRoot(dungeonWalls);
  scene.addEntityToRoot(playerCam);
  scene.addEntityToRoot(light);

  return 0;
}

void Wolfenstein3DClone::input() {
  playerUpdatedPosition = fpsCam->position;
  //std::cout << playerUpdatedPosition.x << " " << playerUpdatedPosition.y << " " << playerUpdatedPosition.z << std::endl;
  if (Input::getKeyPressed(Window::window, GLFW_KEY_W))
    Input::camera->ProcessKeyboard2(FORWARD,
                                    (float) Time::getDelta(),
                                    playerUpdatedPosition);
  if (Input::getKeyPressed(Window::window, GLFW_KEY_S))
    Input::camera->ProcessKeyboard2(BACKWARD,
                                    (float) Time::getDelta(),
                                    playerUpdatedPosition);
  if (Input::getKeyPressed(Window::window, GLFW_KEY_A))
    Input::camera->ProcessKeyboard2(LEFT,
                                    (float) Time::getDelta(),
                                    playerUpdatedPosition);
  if (Input::getKeyPressed(Window::window, GLFW_KEY_D))
    Input::camera->ProcessKeyboard2(RIGHT,
                                    (float) Time::getDelta(),
                                    playerUpdatedPosition);
  //std::cout << playerUpdatedPosition.x << " " << playerUpdatedPosition.y << " " << playerUpdatedPosition.z << std::endl;
  //if(Input::getKeyPressed(Window::window, GLFW_KEY_W)) Input::camera->ProcessKeyboard(FORWARD, (float)Time::getDelta());
  //if(Input::getKeyPressed(Window::window, GLFW_KEY_S)) Input::camera->ProcessKeyboard(BACKWARD, (float)Time::getDelta());
  //if(Input::getKeyPressed(Window::window, GLFW_KEY_A)) Input::camera->ProcessKeyboard(LEFT, (float)Time::getDelta());
  //if(Input::getKeyPressed(Window::window, GLFW_KEY_D)) Input::camera->ProcessKeyboard(RIGHT, (float)Time::getDelta());
  if (Input::getKeyPressed(Window::window, GLFW_KEY_LEFT_SHIFT)) Input::camera->Sprint();
  if (Input::getKeyReleased(Window::window, GLFW_KEY_LEFT_SHIFT)) Input::camera->StopSprint();
}

void Wolfenstein3DClone::update() {
//    playerCollider.minX = fpsCam->position.x - 0.1;
//    playerCollider.minY = fpsCam->position.y - 0.1;
//    playerCollider.minZ = fpsCam->position.z - 0.1;
//    playerCollider.maxX = fpsCam->position.x + 0.1;
//    playerCollider.maxY = fpsCam->position.y + 0.1;
//    playerCollider.maxZ = fpsCam->position.z + 0.1;

  playerCollider.minX = playerUpdatedPosition.x - 0.1;
  playerCollider.minY = playerUpdatedPosition.y - 0.1;
  playerCollider.minZ = playerUpdatedPosition.z - 0.1;
  playerCollider.maxX = playerUpdatedPosition.x + 0.1;
  playerCollider.maxY = playerUpdatedPosition.y + 0.1;
  playerCollider.maxZ = playerUpdatedPosition.z + 0.1;
}

void Wolfenstein3DClone::render() {
  shader.use();
  scene.render();
  // check collision
  // TODO: only check colliders that are close to the player
  for (auto collider : worldColliders) {
    if (collisionChecker.collide(playerCollider, collider)) {
      // TODO: this is probably the worst type of collision handling ever lol
      playerUpdatedPosition = fpsCam->position;
      std::cout << "Player is colliding with something" << std::endl;
    }
  }
  fpsCam->position = playerUpdatedPosition;
}

void Wolfenstein3DClone::dispose() {

}
