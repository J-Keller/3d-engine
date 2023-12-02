//
// Created by Jonas on 10/9/19.
//

#include "ModelLoader.h"

std::vector<std::string> ModelLoader::split(std::string s, const std::string &delimiter) {
  std::vector<std::string> result;

  size_t pos = 0;
  std::string token;
  while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    result.emplace_back(token);
    s.erase(0, pos + delimiter.length());
  }

  result.emplace_back(s);

  return result;
}

std::vector<float> ModelLoader::loadOBJ(const std::string &fileName) {
  std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
  std::vector<glm::vec3> tmp_vertices;
  std::vector<glm::vec2> tmp_uvs;
  std::vector<glm::vec3> tmp_normals;

  std::ifstream file(fileName);

  std::string line;
  std::vector<std::string> splitLine;
  while (std::getline(file, line)) {
    if (line[0] == 'v') {

      splitLine = split(line, " ");

      if (line[1] == 't') {
        glm::vec2 uv;

        if (splitLine.size() != 3) {
          std::cout << "ERROR::MODEL_LOADER::BAD_FILE_CONTENT " << fileName << std::endl;
          return {};
        }

        uv.x = std::stof(splitLine[1]);
        uv.y = std::stof(splitLine[2]);

        tmp_uvs.emplace_back(uv);
      } else if (line[1] == 'n') {
        glm::vec3 normal;

        if (splitLine.size() != 4) {
          std::cout << "ERROR::MODEL_LOADER::BAD_FILE_CONTENT " << fileName << std::endl;
          return {};
        }

        normal.x = std::stof(splitLine[1]);
        normal.y = std::stof(splitLine[2]);
        normal.z = std::stof(splitLine[3]);

        tmp_normals.emplace_back(normal);
      } else {
        glm::vec3 vertex;

        if (splitLine.size() != 4) {
          std::cout << "ERROR::MODEL_LOADER::BAD_FILE_CONTENT " << fileName << std::endl;
          return {};
        }

        vertex.x = std::stof(splitLine[1]);
        vertex.y = std::stof(splitLine[2]);
        vertex.z = std::stof(splitLine[3]);

        tmp_vertices.emplace_back(vertex);
      }

    }
    if (line[0] == 'f') {
      splitLine = split(line, " ");

      if (splitLine.size() != 4) {
        std::cout << "ERROR::MODEL_LOADER::BAD_FILE_CONTENT " << fileName << std::endl;
        return {};
      }

      std::vector<std::string> splitLine2;
      for (unsigned long i = 1; i < splitLine.size(); i++) {

        splitLine2 = split(splitLine[i], "/");

        if (splitLine2.size() != 3) {
          std::cout << "ERROR::MODEL_LOADER::BAD_FILE_CONTENT " << fileName << std::endl;
          return {};
        }

        vertexIndices.emplace_back(std::stoi(splitLine2[0]) - 1);
        uvIndices.emplace_back(std::stoi(splitLine2[1]) - 1);
        normalIndices.emplace_back(std::stoi(splitLine2[2]) - 1);

      }

    }
  }

  std::vector<float> vertices;

  for (unsigned long i = 0; i < vertexIndices.size(); i++) {
    vertices.emplace_back(tmp_vertices[vertexIndices[i]].x);
    vertices.emplace_back(tmp_vertices[vertexIndices[i]].y);
    vertices.emplace_back(tmp_vertices[vertexIndices[i]].z);

    vertices.emplace_back(tmp_uvs[uvIndices[i]].x);
    vertices.emplace_back(tmp_uvs[uvIndices[i]].y);

    vertices.emplace_back(tmp_normals[normalIndices[i]].x);
    vertices.emplace_back(tmp_normals[normalIndices[i]].y);
    vertices.emplace_back(tmp_normals[normalIndices[i]].z);
  }

  file.close();

  return vertices;
}
