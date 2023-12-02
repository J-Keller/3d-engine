//
// Created by Jonas on 7/21/18.
//

#ifndef MCCLONE_TEXTURE_H
#define MCCLONE_TEXTURE_H

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

#endif //MCCLONE_TEXTURE_H
