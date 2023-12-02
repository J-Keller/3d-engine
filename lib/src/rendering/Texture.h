//
// Created by Jonas on 7/21/18.
//

#ifndef INC_3D_ENGINE_TEXTURE_H
#define INC_3D_ENGINE_TEXTURE_H

#include <iostream>
#include <cstring>
#include "../include/stb_image.h"

class Texture {

 public:

  unsigned char *data;
  int width;
  int height;
  int nrChannels;

  Texture();
  explicit Texture(const char *imagePath);

 protected:
 private:

};

#endif //INC_3D_ENGINE_TEXTURE_H
