//
// Created by Jonas on 5/26/23.
//

#include "OverWorldGenerator.h"
#include "../../../lib/src/util/PerlinNoise2D.h"

std::vector<Mesh> OverWorldGenerator::generateMesh(int chunksX, int chunksY) {

  std::vector<Mesh> result;
  Mesh ground;
  std::vector<float> vertices;

  for (int x = 0; x < chunksX * chunkSize; x++) {
    for (int y = 0; y < chunksY * chunkSize; y++) {
      auto fx = (float) x;
      auto fy = (float) y;

      auto px0 = fx * noiseScale;
      auto px1 = (fx + 1) * noiseScale;
      auto py0 = fy * noiseScale;
      auto py1 = (fy + 1) * noiseScale;
      auto perlTL = PerlinNoise2D::perlin(px0, py0) * noiseAmplification;
      auto perlTR = PerlinNoise2D::perlin(px1, py0) * noiseAmplification;
      auto perlBL = PerlinNoise2D::perlin(px0, py1) * noiseAmplification;
      auto perlBR = PerlinNoise2D::perlin(px1, py1) * noiseAmplification;

      auto vecTL = glm::vec3(1.0f * fx, perlTL, 1.0f * fy);
      auto vecTR = glm::vec3(1.0f * (fx + 1), perlTR, 1.0f * fy);
      auto vecBL = glm::vec3(1.0f * fx, perlBL, 1.0f * (fy + 1));
      auto vecBR = glm::vec3(1.0f * (fx + 1), perlBR, 1.0f * (fy + 1));

      auto normal0 = glm::normalize(glm::cross(vecBR - vecTL, vecTR - vecTL));
      auto normal1 = glm::normalize(glm::cross(vecTL - vecBR, vecBL - vecBR));

      vertices.insert(vertices.end(), {
          1.0f * fx, perlTL, 1.0f * fy, 1.0f, 0.0f, normal0.x, normal0.y, normal0.z, // top left
          1.0f * (fx + 1), perlBR, 1.0f * (fy + 1), 0.0f, 1.0f, normal0.x, normal0.y, normal0.z, // bottom right
          1.0f * (fx + 1), perlTR, 1.0f * fy, 1.0f, 1.0f, normal0.x, normal0.y, normal0.z, // top right

          1.0f * (fx + 1), perlBR, 1.0f * (fy + 1), 0.0f, 1.0f, normal1.x, normal1.y, normal1.z, // bottom right
          1.0f * fx, perlTL, 1.0f * fy, 1.0f, 0.0f, normal1.x, normal1.y, normal1.z, // top left
          1.0f * fx, perlBL, 1.0f * (fy + 1), 0.0f, 0.0f, normal1.x, normal1.y, normal1.z, // bottom left
      });
    }
  }

  ground.addVertices(vertices);

  result.insert(result.end(), {ground});

  return result;
}
