//
// Created by Jonas on 19/7/18.
//

#ifndef INC_3D_ENGINE_PERLINNOISE3D_H
#define INC_3D_ENGINE_PERLINNOISE3D_H

#include <vector>

class PerlinNoise3D {

  //permutation vector
  std::vector<int> p;

 public:

  PerlinNoise3D();
  PerlinNoise3D(unsigned int seed);

  /**
   * noise
   *
   * Compute Perlin noise at coordinates x, y, z
   *
   * @param x coordinate
   * @param y coordinate
   * @param z coordinate
   * @return perlin noise at the given coordinates
   */
  double noise(double x, double y, double z);

 protected:
 private:

  double fade(double t);
  double lerp(double t, double a, double b);
  double grad(int hash, double x, double y, double z);

};

#endif //INC_3D_ENGINE_PERLINNOISE3D_H
