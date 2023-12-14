//
// Created by Jonas on 5/26/23.
//

#ifndef INC_3D_ENGINE_OVERWORLDGENERATOR_H
#define INC_3D_ENGINE_OVERWORLDGENERATOR_H

#include "../../../lib/src/rendering/Mesh.h"

class OverWorldGenerator {
 public:
  static std::vector<Mesh> generateMesh(int chunksX, int chunksY);
 private:
  static const int chunkSize = 16; // TODO: maybe set via constructor
  constexpr static const float noiseScale = 0.1;
  constexpr static const float noiseAmplification = 10;
};

#endif //INC_3D_ENGINE_OVERWORLDGENERATOR_H
