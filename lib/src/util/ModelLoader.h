//
// Created by Jonas on 10/9/19.
//

#ifndef INC_3D_ENGINE_MODELLOADER_H
#define INC_3D_ENGINE_MODELLOADER_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

class ModelLoader {
 public:
  static std::vector<float> loadMesh(const std::string &fileName);
 private:
  static std::vector<std::string> split(std::string s, const std::string &delimiter);
};

#endif //INC_3D_ENGINE_MODELLOADER_H
