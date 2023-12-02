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
  /**
   * loadOBJ
   *
   * loads an .obj model file into OpenGL compatible form
   *
   * @param fileName the path to an .obj file with UVs and normals
   * @return a vector of OpenGL compatible float vertices with uv texture coordinates and normals,
   *         or an empty vector if the file could not be read
   */
  static std::vector<float> loadOBJ(const std::string &fileName);
 private:
  static std::vector<std::string> split(std::string s, const std::string &delimiter);
};

#endif //INC_3D_ENGINE_MODELLOADER_H
