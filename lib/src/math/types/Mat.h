//
// Created by Jonas on 7/1/23.
//

#ifndef MCCLONE_MAT_H
#define MCCLONE_MAT_H

#include <cstdint>
#include <iostream>
#include "Vec3.h"

// General Matrix class, see Mat3 or Mat4 for classes with use in gamedev
// Columns, Rows, Type
template<uint8_t C, uint8_t R, class T>
class Mat {
 public:
  Mat();
  explicit Mat(T initializer);

  T entries[R][C];

  Mat<C, R, T> &operator=(const Mat<C, R, T> &other) {
    // Guard self assignment
    if (this == &other) {
      return *this;
    }

    for (uint8_t n = 0; n < C; n++) {
      for (uint8_t m = 0; m < R; m++) {
        entries[m][n] = other.entries[m][n];
      }
    }

    return *this;
  }

  void toString();
};

// Constructors
template<uint8_t C, uint8_t R, class T>
Mat<C, R, T>::Mat() {
  for (uint8_t n = 0; n < C; n++) {
    for (uint8_t m = 0; m < R; m++) {
      entries[m][n] = 0;
    }
  }
}

template<uint8_t C, uint8_t R, class T>
Mat<C, R, T>::Mat(T initializer) {
  for (uint8_t n = 0; n < C; n++) {
    for (uint8_t m = 0; m < R; m++) {
      entries[m][n] = initializer;
    }
  }
}

// Functions
template<uint8_t C, uint8_t R, class T>
void Mat<C, R, T>::toString() {
  for (uint8_t m = 0; m < R; m++) {
    for (uint8_t n = 0; n < C; n++) {
      std::cout << entries[m][n] << ' ';
    }
    std::cout << "\n";
  }
  std::cout << std::flush;

}

// Operator overloads
template<uint8_t C1, uint8_t R1, uint8_t C2, uint8_t R2, class T>
Mat<C2, R1, T> operator*(Mat<C1, R1, T> a, Mat<C2, R2, T> b) {
  if (C1 != R2) {
    return Mat<C2, R1, float>(); // TODO: How to handle Math Errors correctly?
  }

  Mat<C2, R1, T> result;
  for (uint8_t i = 0; i < R1; i++) {
    for (uint8_t k = 0; k < C2; k++) {
      T value = 0;
      for (uint8_t j = 0; j < C1; j++) { // Multiplication Vector iterator
        value += a.entries[i][j] * b.entries[j][k];
      }
      result.entries[i][k] = value;
    }
  }

  return result;
}

template<uint8_t C, uint8_t R, class T>
Mat<C, R, T> operator+(Mat<C, R, T> m1, Mat<C, R, T> m2) {
  Mat<C, R, T> result;
  for (uint8_t i = 0; i < R; i++) {
    for (uint8_t k = 0; k < C; k++) {

      result.entries[i][k] = m1[i][k] + m2[i][k];
    }
  }

  return result;
}

template<uint8_t C, uint8_t R, class T>
Mat<C, R, T> operator+(Mat<C, R, T> m1, T s) {
  Mat<C, R, T> result;
  for (uint8_t i = 0; i < R; i++) {
    for (uint8_t k = 0; k < C; k++) {

      result.entries[i][k] = m1[i][k] + s;
    }
  }

  return result;
}

template<uint8_t C, uint8_t R, class T>
Mat<C, R, T> operator-(Mat<C, R, T> m1, Mat<C, R, T> m2) {
  Mat<C, R, T> result;
  for (uint8_t i = 0; i < R; i++) {
    for (uint8_t k = 0; k < C; k++) {

      result.entries[i][k] = m1[i][k] - m2[i][k];
    }
  }

  return result;
}

template<uint8_t C, uint8_t R, class T>
Mat<C, R, T> operator-(Mat<C, R, T> m1, T s) {
  Mat<C, R, T> result;
  for (uint8_t i = 0; i < R; i++) {
    for (uint8_t k = 0; k < C; k++) {

      result.entries[i][k] = m1[i][k] - s;
    }
  }

  return result;
}

#endif //MCCLONE_MAT_H
