//
// Created by Jonas on 7/1/23.
//

#ifndef INC_3D_ENGINE_VEC4_H
#define INC_3D_ENGINE_VEC4_H

template<class T>
class Vec4 {
 public:
  Vec4(T w, T x, T y, T z);

  T w;
  T x;
  T y;
  T z;
};

template<class T>
Vec4<T>::Vec4(T w, T x, T y, T z) {
  this->w = w;
  this->x = x;
  this->y = y;
  this->z = z;
}

// Operator overloads
template<class T>
bool operator==(Vec4<T> a, Vec4<T> b) {
  return a.w == b.w && a.x == b.x && a.y == b.y && a.z == b.z;
}

template<class T>
bool operator!=(Vec4<T> a, Vec4<T> b) {
  return a.w != b.w || a.x != b.x || a.y != b.y || a.z != b.z;
}

template<class T>
Vec4<T> operator+(Vec4<T> a, Vec4<T> b) {
  return Vec4<T>(a.w + b.w, a.x + b.x, a.y + b.y, a.z + b.z);
}

// Dot product
template<class T>
T operator*(Vec4<T> a, Vec4<T> b) {
  return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
}

template<class T>
Vec4<T> operator*(Vec4<T> a, T b) {
  return Vec4<T>(a.w * b, a.x * b, a.y * b, a.z * b);
};

template<class T>
Vec4<T> operator/(Vec4<T> a, T b) {
  return Vec4<T>(a.w / b, a.x / b, a.y / b, a.z / b);
};

typedef Vec4<int> Vec4i;
typedef Vec4<float> Vec4f;

#endif //INC_3D_ENGINE_VEC4_H
