//
// Created by Jonas on 7/1/23.
//

#ifndef INC_3D_ENGINE_Mat4_H
#define INC_3D_ENGINE_Mat4_H

#include <cstdint>
#include <iostream>
#include "Vec3.h"

template<class T>
class Mat4 {
 public:
  Mat4();
  explicit Mat4(T initializer);

  static const uint8_t C = 4;
  static const uint8_t R = 4;

  T entries[C][R];

  Mat4<T> &operator=(const Mat4<T> &other) {
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

  Mat4<T> clone();

  // TODO: Mat4rix functions
  float determinant(Mat4<T> Mat4);
  Mat4<T> &identity();
  Mat4<T> &rotate(float angle, Vec3<T> r);
  Mat4<T> &translate(Vec3<T> t);
  Mat4<T> &scale(Vec3<T> s);
  //      - Frustum
  //      - lookAt
  //      - Orthogonal
  //      - Project
  //      - Perspective

 private:
  void setEntries(T e[C][R]);
};

// Constructors
template<class T>
Mat4<T>::Mat4() {
  for (uint8_t n = 0; n < C; n++) {
    for (uint8_t m = 0; m < R; m++) {
      entries[m][n] = 0;
    }
  }
}

template<class T>
Mat4<T>::Mat4(T initializer) {
  for (uint8_t n = 0; n < C; n++) {
    for (uint8_t m = 0; m < R; m++) {
      entries[m][n] = initializer;
    }
  }
}

// Functions
template<class T>
void Mat4<T>::setEntries(T e[4][4]) {
  for (uint8_t n = 0; n < C; n++) {
    for (uint8_t m = 0; m < R; m++) {
      this->entries[m][n] = e[m][n];
    }
  }
}

template<class T>
void Mat4<T>::toString() {
  for (uint8_t m = 0; m < R; m++) {
    std::cout << "| ";
    for (uint8_t n = 0; n < C; n++) {
      std::cout << entries[m][n] << ' ';
    }
    std::cout << "|\n";
  }
  std::cout << "\n";
  std::cout << std::flush;

}

template<class T>
Mat4<T> Mat4<T>::clone() {
  Mat4<T> clone;

  for (uint8_t n = 0; n < C; n++) {
    for (uint8_t m = 0; m < R; m++) {
      clone.entries[m][n] = entries[m][n];
    }
  }

  return clone;
}

template<class T>
Mat4<T> &Mat4<T>::identity() {
  for (uint8_t n = 0; n < C; n++) {
    for (uint8_t m = 0; m < R; m++) {
      entries[m][n] = 0;
      if (m == n) {
        entries[m][n] = 1;
      }
    }
  }
  return *this;
}

template<class T>
Mat4<T> &Mat4<T>::rotate(float angle, Vec3<T> r) {
  // TODO
  return *this;
}

template<class T>
Mat4<T> &Mat4<T>::translate(Vec3<T> t) {
  Mat4<T> trans;
  for (uint8_t n = 0; n < C; n++) {
    for (uint8_t m = 0; m < R; m++) {
      if (n == 3) {
        switch (m) {
          case 0:trans.entries[m][n] = t.x;
            break;
          case 1:trans.entries[m][n] = t.y;
            break;
          case 2:trans.entries[m][n] = t.z;
            break;
          default:trans.entries[m][n] = 1;
            break;
        }
      } else if (m == n) {
        trans.entries[m][n] = 1;
      } else {
        trans.entries[m][n] = 0;
      }
    }
  }

  Mat4<T> result = clone() * trans;
  setEntries(result.entries);
  return *this;
}

template<class T>
Mat4<T> &Mat4<T>::scale(Vec3<T> s) {
  Mat4<T> scale;
  for (uint8_t n = 0; n < C; n++) {
    for (uint8_t m = 0; m < R; m++) {
      if (m == n) {
        switch (m) {
          case 0:scale.entries[m][n] = s.x;
            break;
          case 1:scale.entries[m][n] = s.y;
            break;
          case 2:scale.entries[m][n] = s.z;
            break;
          default:scale.entries[m][n] = 1;
            break;
        }
      } else {
        scale.entries[m][n] = 0;
      }
    }
  }
  Mat4<T> result = clone() * scale;

  setEntries(result.entries);
  return *this;
}

template<class T>
float Mat4<T>::determinant(Mat4<T> Mat4) {
  // TODO
  return 0;
}

// Operator overloads
template<class T>
Mat4<T> operator*(Mat4<T> a, Mat4<T> b) {

  Mat4<T> result;
  for (uint8_t i = 0; i < Mat4<T>::R; i++) {
    for (uint8_t k = 0; k < Mat4<T>::C; k++) {
      T value = 0;
      for (uint8_t j = 0; j < Mat4<T>::C; j++) { // Multiplication Vector iterator
        value += a.entries[i][j] * b.entries[j][k];
      }
      result.entries[i][k] = value;
    }
  }

  return result;
}

template<class T>
Mat4<T> operator+(Mat4<T> m1, Mat4<T> m2) {
  Mat4<T> result;
  for (uint8_t i = 0; i < Mat4<T>::R; i++) {
    for (uint8_t k = 0; k < Mat4<T>::C; k++) {

      result.entries[i][k] = m1[i][k] + m2[i][k];
    }
  }

  return result;
}

template<class T>
Mat4<T> operator+(Mat4<T> m1, T s) {
  Mat4<T> result;
  for (uint8_t i = 0; i < Mat4<T>::R; i++) {
    for (uint8_t k = 0; k < Mat4<T>::C; k++) {

      result.entries[i][k] = m1[i][k] + s;
    }
  }

  return result;
}

template<class T>
Mat4<T> operator-(Mat4<T> m1, Mat4<T> m2) {
  Mat4<T> result;
  for (uint8_t i = 0; i < Mat4<T>::R; i++) {
    for (uint8_t k = 0; k < Mat4<T>::C; k++) {

      result.entries[i][k] = m1[i][k] - m2[i][k];
    }
  }

  return result;
}

template<class T>
Mat4<T> operator-(Mat4<T> m1, T s) {
  Mat4<T> result;
  for (uint8_t i = 0; i < Mat4<T>::R; i++) {
    for (uint8_t k = 0; k < Mat4<T>::C; k++) {

      result.entries[i][k] = m1[i][k] - s;
    }
  }

  return result;
}

typedef Mat4<int> Mat4i;
typedef Mat4<float> Mat4f;

#endif //INC_3D_ENGINE_Mat4_H
