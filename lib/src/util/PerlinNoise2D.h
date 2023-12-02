//
// Created by Jonas on 5/26/23.
//

#ifndef INC_3D_ENGINE_PERLINNOISE2D_H
#define INC_3D_ENGINE_PERLINNOISE2D_H

// Using Implementation from https://en.wikipedia.org/wiki/Perlin_noise
class PerlinNoise2D {
 public:
  static float perlin(float x, float y);
 private:
  typedef struct {
    float x, y;
  } vector2;

  static float interpolate(float a0, float a1, float w);
  static vector2 randomGradient(int ix, int iy);
  static float dotGridGradient(int ix, int iy, float x, float y);
};

#endif //INC_3D_ENGINE_PERLINNOISE2D_H
