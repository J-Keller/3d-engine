//
// Created by Jonas on 6/30/23.
//

#ifndef INC_3D_ENGINE_CAMERA_H
#define INC_3D_ENGINE_CAMERA_H

#include "AbstractCamera.h"
#include "../scene/Entity.h"
#include "../shader/Shader.h"
#include "../Window.h"

class Camera : public Entity {
 public:
  void setCamera(AbstractCamera *cam);
  void setShader(Shader *shader);
  void setIsActive(bool active);

  void render() override;
 private:
  bool isActive = false;
  AbstractCamera *camera = nullptr;
  Shader *shader;
};

#endif //INC_3D_ENGINE_CAMERA_H
