//
// Created by Jonas on 7/1/23.
//

#ifndef MCCLONE_VEC3_H
#define MCCLONE_VEC3_H

template<class T>
class Vec3 {
 public:
  Vec3(T x, T y, T z);

  static Vec3<T> cross(Vec3<T> a, Vec3<T> b);

  T x;
  T y;
  T z;
};

template<class T>
Vec3<T>::Vec3(T x, T y, T z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

// Static functions
template<class T>
Vec3<T> Vec3<T>::cross(Vec3<T> a, Vec3<T> b) {
  return Vec3<T>(a.y * b.z - a.z * b.y,
                 a.z * b.x - a.x * b.z,
                 a.x * b.y - a.y * b.x);
}

// Operator overloads
template<class T>
bool operator==(Vec3<T> a, Vec3<T> b) {
  return a.x == b.x && a.y == b.y && a.z == b.z;
}

template<class T>
bool operator!=(Vec3<T> a, Vec3<T> b) {
  return a.x != b.x || a.y != b.y || a.z != b.z;
}

template<class T>
Vec3<T> operator+(Vec3<T> a, Vec3<T> b) {
  return Vec3<T>(a.x + b.x, a.y + b.y, a.z + b.z);
}

// Dot product
template<class T>
T operator*(Vec3<T> a, Vec3<T> b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

template<class T>
Vec3<T> operator*(Vec3<T> a, T b) {
  return Vec3<T>(a.x * b, a.y * b, a.z * b);
};

template<class T>
Vec3<T> operator/(Vec3<T> a, T b) {
  return Vec3<T>(a.x / b, a.y / b, a.z / b);
};

typedef Vec3<int> Vec3i;
typedef Vec3<float> Vec3f;

#endif //MCCLONE_VEC3_H
