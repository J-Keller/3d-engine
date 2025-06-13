//
// Created by Jonas on 7/21/18.
//


#include "Texture.h"

Texture::Texture(const char *imagePath) {
  std::cout << "loading texture " << imagePath << std::endl;

  int w, h, nrCh;
  stbi_set_flip_vertically_on_load(1);
  unsigned char *tex_data = stbi_load(imagePath, &w, &h, &nrCh, 0);
  if (tex_data) {
    this->width = w;
    this->height = h;
    this->nrChannels = nrCh;

    size_t imgSize = w * h * nrCh;

    this->data = (unsigned char *) malloc(imgSize);
    memcpy(this->data, tex_data, imgSize);
  } else {
    std::cout << "Failed to load texture" << std::endl;
  }
  stbi_image_free(tex_data);

}

Texture::Texture() :
    data{},
    width{0},
    height{0},
    nrChannels{0} {}
